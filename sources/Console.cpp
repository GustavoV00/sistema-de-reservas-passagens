#include <iostream>
#include <string>
#include "./../includes/Console.hpp"
#include "./../includes/Utils.hpp"
#include "./../includes/Pessoa.hpp"
#include "./../includes/RG.hpp"
#include "./../includes/CPF.hpp"
#include "./../includes/DocumentoInvalidoException.hpp"
#include "./../includes/DadoIncorretoException.hpp"

Console::Console(Pessoa* usuario, const bool& usuarioEhAgente)
    :usuario{usuario}, usuarioEhAgente{usuarioEhAgente}{

}

Pessoa* Console::getUsuario() const {
    return this->usuario;
}
void Console::setCodigo(Pessoa* usuario){
    this->usuario = usuario;
}

bool Console::getUsuarioEhAgente() const {
    return this->usuarioEhAgente;
}
void Console::setUsuarioEhAgente(const bool& usuarioEhAgente) {
    this->usuarioEhAgente = usuarioEhAgente;
}

void Console::imprimeStatusLogin(){
    std::cout << std::endl;
    if(this->usuario != nullptr){
        if(this->usuarioEhAgente){
            std::cout << "Logado como: " << usuario->getNome() << " - AGENTE" << std::endl;
        } else {
            std::cout << "Logado como: " << usuario->getNome() << " - PASSAGEIRO" << std::endl;
        }
    }
}

void Console::imprimirComandosTelaPrincipal() {
    imprimeStatusLogin();
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << " 1) FAZER LOGIN COMO AGENTE" << std::endl;
    std::cout << " 2) FAZER LOGIN COMO PASSAGEIRO" << std::endl;
    std::cout << " 3) GERENCIAR PASSAGEIROS" << std::endl;
    std::cout << " 4) GERENCIAR RESERVAS" << std::endl;
    std::cout << "10) SAIR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

Pessoa* Console::loginAgente(std::list<AgenteViagem*>& agentes){
    std::cout << "----------------------LOGIN----------------------" << std::endl;
    std::string resposta;
    std::cout << "Deseja listar novamente os agentes? (S/n): ";
    std::getline(std::cin, resposta);
    while(resposta.compare("S") != 0 && resposta.compare("n") != 0){
        std::cout << "Deseja listar novamente os agentes? (S/n): ";
        std::getline(std::cin, resposta);
    }

    if(resposta.compare("S") == 0){
        Utils::imprimirListaAgentes(agentes);
    }

    std::cout << std::endl;

    std::string login{""}, senha{""};
    bool logado = false;
    std::cout << "Digite o login (CPF, Email ou Código): ";
    std::getline(std::cin, login);
    while(!logado && login.compare("SAIR") != 0){
        //pesquisa na lista de agentes
        std::list<AgenteViagem*>::iterator it;
        for (it = agentes.begin(); it != agentes.end(); it++){
            if(std::to_string((*it)->getCpf().getNumero()).compare(login) == 0 || (*it)->getEmail().compare(login) == 0 
                                || (*it)->getCodigo().compare(login) == 0){
                std::cout << "Encontrou agente! Logando..." << std::endl;
                return *it;
            } else {
                std::cout << "Não encontrou agente com esse login!" << std::endl;
            }
        }

        std::cout << "Digite o login (CPF, Email ou Código): ";
        std::getline(std::cin, login);
    }

    return nullptr;
}

Pessoa* Console::loginPassageiro(std::list<Passageiro*>& passageiros){
    std::cout << "----------------------LOGIN----------------------" << std::endl;
    std::string resposta;
    std::cout << "Deseja listar novamente os passageiros? (S/n): ";
    std::getline(std::cin, resposta);
    while(resposta.compare("S") != 0 && resposta.compare("n") != 0){
        std::cout << "Deseja listar novamente os passageiros? (S/n): ";
        std::getline(std::cin, resposta);
    }

    if(resposta.compare("S") == 0){
        Utils::imprimirListaPassageiros(passageiros);
    }

    std::cout << std::endl;

    if(passageiros.empty()){
        std::cout << "Nenhum passageiro encontrado!" << std::endl;
        return nullptr;
    }

    std::string login{""}, senha{""};
    bool logado = false;
    std::cout << "Digite o login (CPF ou Email): ";
    std::getline(std::cin, login);
    while(!logado && login.compare("SAIR") != 0){
        //pesquisa na lista de agentes
        std::list<Passageiro*>::iterator it;
        for (it = passageiros.begin(); it != passageiros.end(); it++){
            if(std::to_string((*it)->getCpf().getNumero()).compare(login) == 0 || (*it)->getEmail().compare(login) == 0){
                std::cout << "Encontrou passageiro! Logando..." << std::endl;
                return *it;
            } else {
                std::cout << "Não encontrou passageiro com esse login!" << std::endl;
            }
        }

        std::cout << "Digite o login (CPF ou Email): ";
        std::getline(std::cin, login);
    }

    return nullptr;
}

void Console::imprimirOpcoesGerenciamentoPassageiros(){
    std::cout << std::endl;
    std::cout << "----------------------GERENCIAMENTO DE PASSAGEIROS--------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) LISTAR PASSAGEIROS" << std::endl;
    std::cout << "2) CADASTRAR PASSAGEIRO" << std::endl;
    std::cout << "3) EDITAR PASSAGEIRO" << std::endl;
    std::cout << "4) EXCLUIR PASSAGEIRO" << std::endl;
    std::cout << "5) VOLTAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void Console::cadastrarPassageiro(std::list<Passageiro*>& passageiros){
    std::string nomePassageiro = Utils::lerStringTratada("Digite o nome do passageiro a ser adicionado");
    
    CPF *cpfPassageiro = Utils::lerCPFTratado("Digite o CPF (sem pontuação) do passageiro a ser adicionado");
    if(cpfPassageiro == nullptr){
        std::cout << "Falha ao ler CPF!" << std::endl;
        return;
    }
    RG *rgPassageiro = Utils::lerRGTratado("Digite o RG (sem pontuação) do passageiro a ser adicionado");
    if(rgPassageiro == nullptr){
        std::cout << "Falha ao ler RG!" << std::endl;
        return;
    }
            
    std::string dataDeNascimento = Utils::lerDataNascimentoTratada("Digite a data de nascimento (dd/MM/yyyy) do passageiro a ser adicionado");
    
    unsigned long contato = Utils::lerTelefoneTratado("Digite o telefone de contato (apenas números) do passageiro a ser adicionado");
    
    std::string email = Utils::lerStringTratada("Digite o email do passageiro a ser adicionado");

    //verifica se já não existe passageiro com esse CPF, RG ou email
    std::list<Passageiro*>::iterator it;
    for (it = passageiros.begin(); it != passageiros.end(); it++){
        if((*it)->getCpf() == *cpfPassageiro || (*it)->getRg() == *rgPassageiro || (*it)->getEmail().compare(email) == 0){
            std::cout << std::endl << "\tATENÇÃO! Já existe passageiro com esse CPF, RG ou email! Passageiro não vai ser cadastrado!" << std::endl;
            return;
        }
    }

    Passageiro *novoPas = new Passageiro{nomePassageiro, *cpfPassageiro, *rgPassageiro, dataDeNascimento, contato, email};

    passageiros.push_back(novoPas);

    std::cout << "Passageiro '" << novoPas->getNome() << "' adicionado com sucesso!" << std::endl;
}
bool Console::mensagemConfirmacao(std::string mensagem){
    std::string retorno{""};
    std::cout << mensagem << "(S/n): ";
    std::getline(std::cin, retorno);
    while(retorno.compare("SAIR") != 0 && retorno.compare("S") != 0 && retorno.compare("n") != 0){
        
        std::cout << mensagem << "(S/n): ";
        std::getline(std::cin, retorno);
    }

    if(retorno.compare("S") == 0){
        return true;
    }

    return false;
}

void Console::excluirPassageiro(std::list<Passageiro*>& passageiros){
    std::string termoBusca = Utils::lerStringTratada("Digite o Nome completo, CPF, RG ou Email do passageiro a ser excluído");

    try {
        std::list<Passageiro*>::iterator it;
        for (it = passageiros.begin(); it != passageiros.end(); it++){
            if((*it)->getNome() == termoBusca || (*it)->getEmail().compare(termoBusca) == 0 || std::to_string((*it)->getCpf().getNumero()).compare(termoBusca) == 0 || std::to_string((*it)->getRg().getNumero()).compare(termoBusca) == 0){
                std::cout << std::endl << "Encontrou passageiro para excluir: " << std::endl;
                (*it)->imprimirDadosFormatados();

                if(mensagemConfirmacao("Tem certeza que deseja excluir o passageiro acima?")){
                    std::cout << "Excluindo passageiro..." << std::endl;

                    passageiros.erase(it);
                    delete *it;

                    std::cout  << std::endl << "Passageiro excluído com sucesso!" << std::endl;
                    break;
                } else {
                    std::cout << "NÃO vai excluir passageiro..." << std::endl;
                }
            }
        }
    } catch (std::exception &e){
        std::cout << "Falha ao encontrar Passageiro para excluir! " << std::endl;
    }
    
}

void Console::editarPassageiro(std::list<Passageiro*>& passageiros){
    std::string termoBusca = Utils::lerStringTratada("Digite o Nome completo, CPF, RG ou Email do passageiro a ser editado");

    try {
        bool encontrouPassageiro = false;
        std::list<Passageiro*>::iterator it;
        for (it = passageiros.begin(); it != passageiros.end(); it++){
            if((*it)->getNome() == termoBusca || (*it)->getEmail().compare(termoBusca) == 0 || std::to_string((*it)->getCpf().getNumero()).compare(termoBusca) == 0 || std::to_string((*it)->getRg().getNumero()).compare(termoBusca) == 0){
                std::cout << std::endl << "Encontrou passageiro para editar: " << std::endl;
                encontrouPassageiro = true;
                (*it)->imprimirDadosFormatados();

                if(mensagemConfirmacao("Tem certeza que deseja editar o passageiro acima?")){
                    std::cout << "Editando passageiro... Escolha o campo que deseja editar: " << std::endl;
                    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
                    std::cout << "1) NOME" << std::endl;
                    std::cout << "2) CPF" << std::endl;
                    std::cout << "3) RG" << std::endl;
                    std::cout << "4) EMAIL" << std::endl;
                    std::cout << "5) DATA DE NASCIMENTO " << std::endl;
                    std::cout << "6) TELEFONE " << std::endl;
                    std::cout << "7) VOLTAR " << std::endl;
                    std::cout << "----------------------------------------------------------------------------" << std::endl;

                    std::string comando{""};
                    std::cout << "Digite o NÚMERO da opção escolhida: " << std::endl << "> ";
                    std::getline(std::cin, comando);
                    while(comando.compare("SAIR") != 0){
                        if(comando.compare("1") == 0){
                            (*it)->setNome(Utils::lerStringTratada("Digite o Nome"));
                            break;
                        } else if(comando.compare("2") == 0){
                            CPF *novoCpf = Utils::lerCPFTratado("Digite o CPF");
                            //verifica se já não existe passageiro com esse CPF
                            std::list<Passageiro*>::iterator it2;
                            for (it2 = passageiros.begin(); it2 != passageiros.end(); it2++){
                                if((*it2)->getCpf() == *novoCpf){
                                    std::cout << std::endl << "\tATENÇÃO! Já existe passageiro com esse CPF! Passageiro não vai ser editado!" << std::endl;
                                    return;
                                }
                            }
                            std::cout << "Atualizando CPF..." << std::endl;
                            (*it)->setCpf(*novoCpf);
                            break;
                        } else if(comando.compare("3") == 0){
                            RG *novoRg = Utils::lerRGTratado("Digite o RG");
                            //verifica se já não existe passageiro com esse RG
                            std::list<Passageiro*>::iterator it2;
                            for (it2 = passageiros.begin(); it2 != passageiros.end(); it2++){
                                if((*it2)->getRg() == *novoRg){
                                    std::cout << std::endl << "\tATENÇÃO! Já existe passageiro com esse RG! Passageiro não vai ser editado!" << std::endl;
                                    return;
                                }
                            }
                            std::cout << "Atualizando RG..." << std::endl;
                            (*it)->setRg(*novoRg);
                            break;
                        } else if(comando.compare("4") == 0){
                            (*it)->setEmail(Utils::lerStringTratada("Digite o Email"));
                            break;
                        } else if(comando.compare("5") == 0){
                            (*it)->setDataDeNascimento(Utils::lerDataNascimentoTratada("Digite a Data de Nascimento"));
                            break;
                        } else if(comando.compare("6") == 0){
                            (*it)->setContato(Utils::lerTelefoneTratado("Digite o Telefone"));
                            break;
                        } else if(comando.compare("7") == 0){
                            break;
                        }
                    }

                    std::cout  << std::endl << "Passageiro editado com sucesso!" << std::endl;
                    break;
                } else {
                    std::cout << "NÃO vai editar passageiro..." << std::endl;
                }
            }
        }

        if(!encontrouPassageiro){
            std::cout << "Não encontrou passageiro com os dados especificados!" << std::endl;
        }
    } catch (std::exception &e){
        std::cout << "Falha ao encontrar Passageiro para editar! " << std::endl;
    }
    
}

void Console::gerenciarPassageiros(std::list<Passageiro*>& passageiros){
    imprimeStatusLogin();
    imprimirOpcoesGerenciamentoPassageiros();

    std::string comando{""};
    std::cout << "Digite o NÚMERO da opção escolhida: " << std::endl << "> ";
    std::getline(std::cin, comando);
    while(comando.compare("SAIR") != 0){
        if(comando.compare("1") == 0){
            Utils::imprimirListaPassageiros(passageiros);
        } else if(comando.compare("2") == 0){
            try {
                cadastrarPassageiro(passageiros);
            } catch(std::exception &e){
                std::cout << "Falha ao cadastrar passageiro: " << e.what() << std::endl;
            }
        } else if(comando.compare("3") == 0){
            try {
                editarPassageiro(passageiros);
            } catch(std::exception &e){
                std::cout << "Falha ao excluir passageiro: " << e.what() << std::endl;
            }
        } else if(comando.compare("4") == 0){
            try {
                excluirPassageiro(passageiros);
            } catch(std::exception &e){
                std::cout << "Falha ao excluir passageiro: " << e.what() << std::endl;
            }
        } else if(comando.compare("5") == 0){
            break;
        }

        imprimirOpcoesGerenciamentoPassageiros();
        std::cout << "> ";
        std::getline(std::cin, comando);
    }
}
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
    std::string cpfPassageiroStr = Utils::lerStringTratada("Digite o CPF (sem pontuação) do passageiro a ser adicionado");
    CPF cpfPassageiro{11111111111};

    try {
        cpfPassageiro.setNumero(stoul(cpfPassageiroStr));
    } catch(DocumentoInvalidoException &die) {
        std::cout << die.what() << std::endl;
    } catch(std::exception &e) {
        std::cout << "Erro ao ler CPF! Tente novamente!" << std::endl;
    }

    std::string rgPassageiroStr = Utils::lerStringTratada("Digite o RG (sem pontuação) do passageiro a ser adicionado");
    RG rgPassageiro{111111111};

    try {
        rgPassageiro.setNumero(stoul(rgPassageiroStr));
    } catch(DocumentoInvalidoException &die) {
        std::cout << die.what() << std::endl;
    } catch(std::exception &e) {
        std::cout << "Erro ao ler RG! Tente novamente!" << std::endl;
    }
            
    std::string dataDeNascimento = Utils::lerStringTratada("Digite a data de nascimento (dd/MM/yyyy) do passageiro a ser adicionado");
    unsigned long contato{0};
    try {
        contato = stoul(Utils::lerStringTratada("Digite o telefone de contato (apenas números) do passageiro a ser adicionado"));
    } catch (std::exception &e) {
        std::cout << "Erro ao ler contato de telefone! Tente novamente!" << std::endl;
    }
            
    std::string email = Utils::lerStringTratada("Digite o email do passageiro a ser adicionado");

    Passageiro *novoPas = new Passageiro{nomePassageiro, cpfPassageiro, rgPassageiro, dataDeNascimento, contato, email};

    passageiros.push_back(novoPas);

    std::cout << "Passageiro '" << novoPas->getNome() << "' adicionado com sucesso!" << std::endl;
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
        } else if(comando.compare("5") == 0){
            break;
        }


        imprimirOpcoesGerenciamentoPassageiros();
        std::cout << "> ";
        std::getline(std::cin, comando);
    }
}
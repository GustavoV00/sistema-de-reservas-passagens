#include <iostream>
#include <string>
#include "./../includes/Console.hpp"
#include "./../includes/Utils.hpp"
#include "./../includes/Pessoa.hpp"
#include "./../includes/RG.hpp"
#include "./../includes/CPF.hpp"
#include "./../includes/DocumentoInvalidoException.hpp"
#include "./../includes/DadoIncorretoException.hpp"

Console::Console(Pessoa *usuario, const bool &usuarioEhAgente)
    : usuario{usuario}, usuarioEhAgente{usuarioEhAgente}
{
}

Pessoa *Console::getUsuario() const
{
    return this->usuario;
}
void Console::setUsuario(Pessoa *usuario)
{
    this->usuario = usuario;
}

bool Console::getUsuarioEhAgente() const
{
    return this->usuarioEhAgente;
}
void Console::setUsuarioEhAgente(const bool &usuarioEhAgente)
{
    this->usuarioEhAgente = usuarioEhAgente;
}

void Console::imprimeStatusLogin()
{
    std::cout << std::endl;
    if (this->usuario != nullptr)
    {
        if (this->usuarioEhAgente)
        {
            std::cout << "Logado como: " << usuario->getNome() << " - AGENTE" << std::endl;
        }
        else
        {
            std::cout << "Logado como: " << usuario->getNome() << " - PASSAGEIRO" << std::endl;
        }
    }
    else
    {
        std::cout << "Logado como: CONVIDADO" << std::endl;
    }
}

void Console::imprimirComandosTelaPrincipal()
{
    imprimeStatusLogin();
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << " 1) FAZER LOGIN COMO AGENTE" << std::endl;
    std::cout << " 2) FAZER LOGIN COMO PASSAGEIRO" << std::endl;
    std::cout << " 3) GERENCIAR PASSAGEIROS" << std::endl;
    std::cout << " 4) GERENCIAR RESERVAS" << std::endl;
    if (verificaUsuarioEhAgente())
    {
        std::cout << " 5) GERENCIAR VOOS" << std::endl;
    }
    std::cout << "10) SAIR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

Pessoa *Console::loginAgente(std::list<AgenteViagem *> &agentes)
{
    std::cout << "----------------------LOGIN----------------------" << std::endl;
    std::string resposta;
    std::cout << "Deseja listar novamente os agentes? (S/n): ";
    std::getline(std::cin, resposta);
    while (resposta.compare("S") != 0 && resposta.compare("n") != 0)
    {
        std::cout << "Deseja listar novamente os agentes? (S/n): ";
        std::getline(std::cin, resposta);
    }

    if (resposta.compare("S") == 0)
    {
        Utils::imprimirListaAgentes(agentes);
    }

    std::cout << std::endl;

    std::string login{""}, senha{""};
    bool logado = false;
    std::cout << "Digite o login (CPF, Email ou Código) do agente para logar: ";
    std::getline(std::cin, login);
    while (!logado && login.compare("SAIR") != 0)
    {
        // pesquisa na lista de agentes
        std::list<AgenteViagem *>::iterator it;
        for (it = agentes.begin(); it != agentes.end(); it++)
        {
            if (std::to_string((*it)->getCpf().getNumero()).compare(login) == 0 || (*it)->getEmail().compare(login) == 0 || (*it)->getCodigo().compare(login) == 0)
            {
                std::cout << "Encontrou agente! Logando..." << std::endl;
                return *it;
            }
            else
            {
                std::cout << "Não encontrou agente com esse login!" << std::endl;
            }
        }

        std::cout << "Digite o login (CPF, Email ou Código): ";
        std::getline(std::cin, login);
    }

    return nullptr;
}

Pessoa *Console::loginPassageiro(std::list<Passageiro *> &passageiros)
{
    std::cout << "----------------------LOGIN----------------------" << std::endl;
    std::string resposta;
    std::cout << "Deseja listar novamente os passageiros? (S/n): ";
    std::getline(std::cin, resposta);
    while (resposta.compare("S") != 0 && resposta.compare("n") != 0)
    {
        std::cout << "Deseja listar novamente os passageiros? (S/n): ";
        std::getline(std::cin, resposta);
    }

    if (resposta.compare("S") == 0)
    {
        Utils::imprimirListaPassageiros(passageiros);
    }

    std::cout << std::endl;

    if (passageiros.empty())
    {
        std::cout << "Nenhum passageiro encontrado!" << std::endl;
        return nullptr;
    }

    std::string login{""}, senha{""};
    bool logado = false;
    std::cout << "Digite o login (CPF ou Email) do passageiro para logar: ";
    std::getline(std::cin, login);
    while (!logado && login.compare("SAIR") != 0)
    {
        // pesquisa na lista de agentes
        std::list<Passageiro *>::iterator it;
        for (it = passageiros.begin(); it != passageiros.end(); it++)
        {
            if (std::to_string((*it)->getCpf().getNumero()).compare(login) == 0 || (*it)->getEmail().compare(login) == 0)
            {
                std::cout << "Encontrou passageiro! Logando..." << std::endl;
                return *it;
            }
            else
            {
                std::cout << "Não encontrou passageiro com esse login!" << std::endl;
            }
        }

        std::cout << "Digite o login (CPF ou Email): ";
        std::getline(std::cin, login);
    }

    return nullptr;
}

void Console::imprimirOpcoesGerenciamentoPassageiros()
{
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

void Console::cadastrarPassageiro(std::list<Passageiro *> &passageiros)
{
    std::string nomePassageiro = Utils::lerStringTratada("Digite o nome do passageiro a ser adicionado");

    CPF *cpfPassageiro = Utils::lerCPFTratado("Digite o CPF (sem pontuação) do passageiro a ser adicionado");
    if (cpfPassageiro == nullptr)
    {
        std::cout << "Falha ao ler CPF!" << std::endl;
        return;
    }
    RG *rgPassageiro = Utils::lerRGTratado("Digite o RG (sem pontuação) do passageiro a ser adicionado");
    if (rgPassageiro == nullptr)
    {
        std::cout << "Falha ao ler RG!" << std::endl;
        return;
    }

    std::string dataDeNascimento;
    try
    {
        dataDeNascimento = Utils::lerDataTratada("Digite a data de nascimento (dd/MM/yyyy) do passageiro a ser adicionado");
    }
    catch (FormatoInvalidoException &fie)
    {
        std::cout << "Formato da data de nascimento é inválida!" << std::endl;
        return;
    }

    unsigned long contato;
    try
    {
        contato = Utils::lerTelefoneTratado("Digite o telefone de contato (apenas números) do passageiro a ser adicionado");
    }
    catch (FormatoInvalidoException &fie)
    {
        std::cout << "Formato do telefone é inválido!" << std::endl;
        return;
    }

    std::string email = Utils::lerStringTratada("Digite o email do passageiro a ser adicionado");

    // verifica se já não existe passageiro com esse CPF, RG ou email
    std::list<Passageiro *>::iterator it;
    for (it = passageiros.begin(); it != passageiros.end(); it++)
    {
        if ((*it)->getCpf() == *cpfPassageiro || (*it)->getRg() == *rgPassageiro || (*it)->getEmail().compare(email) == 0)
        {
            std::cout << std::endl
                      << "\tATENÇÃO! Já existe passageiro com esse CPF, RG ou email! Passageiro não vai ser cadastrado!" << std::endl;
            return;
        }
    }

    Passageiro *novoPas{nullptr};
    try
    {
        novoPas = new Passageiro{nomePassageiro, *cpfPassageiro, *rgPassageiro, dataDeNascimento, contato, email};
    }
    catch (DocumentoInvalidoException &die)
    {
        std::cout << "Falha ao cadastrar passageiro por documento inválido: " << die.what() << std::endl;
        return;
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao cadastrar passageiro: " << e.what() << std::endl;
        return;
    }

    passageiros.push_back(novoPas);

    std::cout << "Passageiro '" << novoPas->getNome() << "' adicionado com sucesso!" << std::endl;
}
bool Console::mensagemConfirmacao(std::string mensagem)
{
    std::string retorno{""};
    std::cout << mensagem << "(S/n): ";
    std::getline(std::cin, retorno);
    while (retorno.compare("SAIR") != 0 && retorno.compare("S") != 0 && retorno.compare("n") != 0)
    {

        std::cout << mensagem << "(S/n): ";
        std::getline(std::cin, retorno);
    }

    if (retorno.compare("S") == 0)
    {
        return true;
    }

    return false;
}

void Console::excluirPassageiro(std::list<Passageiro *> &passageiros)
{
    std::string termoBusca = Utils::lerStringTratada("Digite o Nome completo, CPF, RG ou Email do passageiro a ser excluído");

    try
    {
        std::list<Passageiro *>::iterator it;
        for (it = passageiros.begin(); it != passageiros.end(); it++)
        {
            if ((*it)->getNome() == termoBusca || (*it)->getEmail().compare(termoBusca) == 0 || std::to_string((*it)->getCpf().getNumero()).compare(termoBusca) == 0 || std::to_string((*it)->getRg().getNumero()).compare(termoBusca) == 0)
            {
                std::cout << std::endl
                          << "Encontrou passageiro para excluir: " << std::endl;
                (*it)->imprimirDadosFormatados();

                if (mensagemConfirmacao("Tem certeza que deseja excluir o passageiro acima?"))
                {
                    std::cout << "Excluindo passageiro..." << std::endl;

                    passageiros.erase(it);
                    delete *it;

                    std::cout << std::endl
                              << "Passageiro excluído com sucesso!" << std::endl;
                    break;
                }
                else
                {
                    std::cout << "NÃO vai excluir passageiro..." << std::endl;
                }
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao encontrar Passageiro para excluir! " << std::endl;
    }
}

void Console::editarPassageiro(std::list<Passageiro *> &passageiros)
{
    std::string termoBusca = Utils::lerStringTratada("Digite o Nome completo, CPF, RG ou Email do passageiro a ser editado");

    try
    {
        bool encontrouPassageiro = false;
        std::list<Passageiro *>::iterator it;
        for (it = passageiros.begin(); it != passageiros.end(); it++)
        {
            if ((*it)->getNome() == termoBusca || (*it)->getEmail().compare(termoBusca) == 0 || std::to_string((*it)->getCpf().getNumero()).compare(termoBusca) == 0 || std::to_string((*it)->getRg().getNumero()).compare(termoBusca) == 0)
            {
                std::cout << std::endl
                          << "Encontrou passageiro para editar: " << std::endl;
                encontrouPassageiro = true;
                (*it)->imprimirDadosFormatados();

                if (mensagemConfirmacao("Tem certeza que deseja editar o passageiro acima?"))
                {
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
                    std::cout << "Digite o NÚMERO da opção escolhida: " << std::endl
                              << "> ";
                    std::getline(std::cin, comando);
                    while (comando.compare("SAIR") != 0)
                    {
                        if (comando.compare("1") == 0)
                        {
                            (*it)->setNome(Utils::lerStringTratada("Digite o Nome"));
                            break;
                        }
                        else if (comando.compare("2") == 0)
                        {
                            CPF *novoCpf = Utils::lerCPFTratado("Digite o CPF");
                            // verifica se já não existe passageiro com esse CPF
                            std::list<Passageiro *>::iterator it2;
                            for (it2 = passageiros.begin(); it2 != passageiros.end(); it2++)
                            {
                                if ((*it2)->getCpf() == *novoCpf)
                                {
                                    std::cout << std::endl
                                              << "\tATENÇÃO! Já existe passageiro com esse CPF! Passageiro não vai ser editado!" << std::endl;
                                    return;
                                }
                            }
                            std::cout << "Atualizando CPF..." << std::endl;
                            (*it)->setCpf(*novoCpf);
                            break;
                        }
                        else if (comando.compare("3") == 0)
                        {
                            RG *novoRg = Utils::lerRGTratado("Digite o RG");
                            // verifica se já não existe passageiro com esse RG
                            std::list<Passageiro *>::iterator it2;
                            for (it2 = passageiros.begin(); it2 != passageiros.end(); it2++)
                            {
                                if ((*it2)->getRg() == *novoRg)
                                {
                                    std::cout << std::endl
                                              << "\tATENÇÃO! Já existe passageiro com esse RG! Passageiro não vai ser editado!" << std::endl;
                                    return;
                                }
                            }
                            std::cout << "Atualizando RG..." << std::endl;
                            (*it)->setRg(*novoRg);
                            break;
                        }
                        else if (comando.compare("4") == 0)
                        {
                            (*it)->setEmail(Utils::lerStringTratada("Digite o Email"));
                            break;
                        }
                        else if (comando.compare("5") == 0)
                        {
                            (*it)->setDataDeNascimento(Utils::lerDataTratada("Digite a Data de Nascimento"));
                            break;
                        }
                        else if (comando.compare("6") == 0)
                        {
                            (*it)->setContato(Utils::lerTelefoneTratado("Digite o Telefone"));
                            break;
                        }
                        else if (comando.compare("7") == 0)
                        {
                            break;
                        }
                    }

                    std::cout << std::endl
                              << "Passageiro editado com sucesso!" << std::endl;
                    break;
                }
                else
                {
                    std::cout << "NÃO vai editar passageiro..." << std::endl;
                }
            }
        }

        if (!encontrouPassageiro)
        {
            std::cout << "Não encontrou passageiro com os dados especificados!" << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao encontrar Passageiro para editar! " << std::endl;
    }
}

void Console::gerenciarPassageiros(std::list<Passageiro *> &passageiros)
{
    imprimeStatusLogin();
    imprimirOpcoesGerenciamentoPassageiros();

    std::string comando{""};
    std::cout << "Digite o NÚMERO da opção escolhida: " << std::endl
              << "> ";
    std::getline(std::cin, comando);
    while (comando.compare("SAIR") != 0)
    {
        if (comando.compare("1") == 0)
        {
            if (usuario != nullptr && usuarioEhAgente)
            {
                Utils::imprimirListaPassageiros(passageiros);
            }
            else
            {
                std::cout << "OPÇÃO PERMITIDA APENAS PARA AGENTES LOGADOS!" << std::endl;
            }
        }
        else if (comando.compare("2") == 0)
        {
            try
            {
                cadastrarPassageiro(passageiros);
            }
            catch (std::exception &e)
            {
                std::cout << "Falha ao cadastrar passageiro: " << e.what() << std::endl;
            }
        }
        else if (comando.compare("3") == 0)
        {
            try
            {
                editarPassageiro(passageiros);
            }
            catch (std::exception &e)
            {
                std::cout << "Falha ao excluir passageiro: " << e.what() << std::endl;
            }
        }
        else if (comando.compare("4") == 0)
        {
            try
            {
                excluirPassageiro(passageiros);
            }
            catch (std::exception &e)
            {
                std::cout << "Falha ao excluir passageiro: " << e.what() << std::endl;
            }
        }
        else if (comando.compare("5") == 0)
        {
            break;
        }

        imprimirOpcoesGerenciamentoPassageiros();
        std::cout << "> ";
        std::getline(std::cin, comando);
    }
}

void Console::imprimirOpcoesGerenciamentoReservas()
{
    std::cout << std::endl;
    std::cout << "----------------------GERENCIAMENTO DE RESERVAS-----------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) LISTAR RESERVAS" << std::endl;
    std::cout << "2) CRIAR RESERVA" << std::endl;
    std::cout << "3) EDITAR RESERVA" << std::endl;
    std::cout << "4) EXCLUIR RESERVA" << std::endl;
    std::cout << "5) VOLTAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void Console::cadastrarReserva(std::list<AgenteViagem *> &agentes, std::list<Passageiro *> &passageiros, std::list<Reserva *> &reservas, std::list<Voo *> voos)
{
    bool adicionouPassageiro = false;
    Passageiro *passageiroReserva{nullptr};

    std::cout << "Adicionando passageiro..." << std::endl;
    Utils::imprimirListaPassageiros(passageiros);
    std::string termoBusca = Utils::lerStringTratada("Digite o Nome completo, CPF, RG ou Email do passageiro a ser adicionado na reserva");
    while (!adicionouPassageiro && termoBusca.compare("SAIR") != 0)
    {
        std::list<Passageiro *>::iterator it;
        for (it = passageiros.begin(); it != passageiros.end(); it++)
        {
            if ((*it)->getNome() == termoBusca || (*it)->getEmail().compare(termoBusca) == 0 || std::to_string((*it)->getCpf().getNumero()).compare(termoBusca) == 0 || std::to_string((*it)->getRg().getNumero()).compare(termoBusca) == 0)
            {
                std::cout << std::endl
                          << "Encontrou passageiro para adicionar: " << std::endl;
                (*it)->imprimirDadosFormatados();
                if (mensagemConfirmacao("Tem certeza que deseja adicionar o passageiro acima na reserva?"))
                {
                    passageiroReserva = (*it);
                }
            }
        }

        if (passageiroReserva != nullptr)
        {
            adicionouPassageiro = true;
            break;
        }

        std::cout << "Falha ao encontrar passageiro!" << std::endl;
        termoBusca = Utils::lerStringTratada("Digite o Nome completo, CPF, RG ou Email do passageiro a ser adicionado na reserva");
    }

    if (!adicionouPassageiro)
    {
        std::cout << "Falha ao encontrar passageiro para a reserva... " << std::endl;
        return;
    }

    bool adicionouVoo = false;
    std::cout << "Adicionando voos..." << std::endl;
    Utils::imprimirListaVoos(voos);
    Voo *vooReserva{nullptr};
    termoBusca = Utils::lerStringTratada("Digite o Número do voo a ser adicionado na reserva");
    while (!adicionouVoo && termoBusca.compare("SAIR") != 0)
    {
        std::list<Voo *>::iterator it2;
        for (it2 = voos.begin(); it2 != voos.end(); it2++)
        {
            if ((*it2)->getNumeroDoVoo().compare(termoBusca) == 0)
            {
                std::cout << std::endl
                          << "Encontrou voo para adicionar: " << std::endl;
                (*it2)->imprimirDadosVoo();

                if ((*it2)->getAssentosDisponiveis() == 0)
                {
                    std::cout << "VOO LOTADO! NÃO SERÁ POSSÍVEL ADICIONAR NA RESERVA!" << std::endl;
                    break;
                }

                if (mensagemConfirmacao("Tem certeza que deseja adicionar o voo acima na reserva?"))
                {
                    vooReserva = (*it2);
                    break;
                }
            }
        }

        if (vooReserva != nullptr)
        {
            adicionouVoo = true;
            break;
        }

        std::cout << "Falha ao encontrar voo!" << std::endl;
        termoBusca = Utils::lerStringTratada("Digite o Número do voo a ser adicionado na reserva");
    }

    if (!adicionouVoo)
    {
        std::cout << "Falha ao encontrar voo para a reserva... " << std::endl;
        return;
    }

    std::list<std::string> assentosOcupados;
    if (!vooReserva->getReservas().empty())
    {
        Utils::imprimirListaReservas(vooReserva->getReservas());
        std::list<Reserva *> reservas = vooReserva->getReservas();
        std::list<Reserva *>::iterator it;
        for (it = reservas.begin(); it != reservas.end(); it++)
        {
            std::string numeroAssentoOcupado = (*it)->getNumeroDoAssento();
            std::cout << "ADICIONANDO " << numeroAssentoOcupado << " NA LISTA DE ASSENTOS OCUPADOS..." << std::endl;
            ;
            assentosOcupados.push_back(numeroAssentoOcupado);
        }
    }

    vooReserva->imprimirMapaDeAssentos();
    bool escolheuAssentoValido = false;
    std::string aux{""};
    std::string numeroAssentoReserva = Utils::lerStringTratada("Digite o assento desejado (assentos XXX estão ocupados)");
    std::string letrasAssentos{"ABCD"};
    while (!escolheuAssentoValido && numeroAssentoReserva.compare("SAIR") != 0)
    {

        // verifica se o assento é válido
        for (int i = 1; i <= (int)vooReserva->getCapacidade() / 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                char letra = letrasAssentos.at(j);

                if (i < 10)
                {
                    aux = "0";
                }

                aux = aux + std::to_string(i) + letra;

                if (numeroAssentoReserva.compare(aux) == 0 && !Utils::assentoOcupado(aux, assentosOcupados))
                {
                    escolheuAssentoValido = true;
                    break;
                }

                aux = "";
            }
        }

        if (escolheuAssentoValido)
        {
            break;
        }

        std::cout << "Assento não é válido!" << std::endl;
        numeroAssentoReserva = Utils::lerStringTratada("Digite o assento desejado (assentos XXX estão ocupados)");
    }

    std::string localizador = "LR" + std::to_string(Utils::geradorNumeroAleatorio());
    int cont = 0;
    while (Reserva::buscaReservaLocalizador(localizador, reservas) != nullptr && cont < 400)
    {
        localizador = "LR" + std::to_string(Utils::geradorNumeroAleatorio());
        cont++;
    }

    std::cout << "Criou reserva com localizador: " << localizador << std::endl;

    Reserva *reserva{nullptr};

    try
    {
        reserva = new Reserva{localizador, *passageiroReserva, *vooReserva, numeroAssentoReserva};
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao criar reserva: " << e.what() << std::endl;
        return;
    }

    reservas.push_back(reserva);

    vooReserva->adicionarReserva(reserva);
    vooReserva->setAssentosDisponiveis(vooReserva->getAssentosDisponiveis() - 1);

    std::cout << std::endl
              << std::endl
              << "Resumo Reserva: " << std::endl;
    reserva->imprimirDadosReserva();
}

void Console::gerenciarReservas(std::list<AgenteViagem *> &agentes, std::list<Passageiro *> &passageiros, std::list<Reserva *> &reservas, std::list<Voo *> voos)
{
    imprimeStatusLogin();
    imprimirOpcoesGerenciamentoReservas();

    std::string comando{""};
    std::cout << "Digite o NÚMERO da opção escolhida: " << std::endl
              << "> ";
    std::getline(std::cin, comando);
    while (comando.compare("SAIR") != 0)
    {
        if (comando.compare("1") == 0)
        {
            Utils::imprimirListaReservas(reservas);
        }
        else if (comando.compare("2") == 0)
        {
            try
            {
                cadastrarReserva(agentes, passageiros, reservas, voos);
            }
            catch (std::exception &e)
            {
                std::cout << "Falha ao cadastrar passageiro: " << e.what() << std::endl;
            }
        } /*else if(comando.compare("3") == 0){
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
        } */
        else if (comando.compare("5") == 0)
        {
            break;
        }

        imprimirOpcoesGerenciamentoReservas();
        std::cout << "> ";
        std::getline(std::cin, comando);
    }
}

bool Console::verificaUsuarioEhAgente()
{
    if (usuario != nullptr && usuarioEhAgente)
    {
        return true;
    }
    return false;
}

void Console::imprimirOpcoesGerenciamentoVoos()
{
    std::cout << std::endl;
    std::cout << "-------------------------GERENCIAMENTO DE VOOS------------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) LISTAR VOOS" << std::endl;
    std::cout << "2) CRIAR VOO" << std::endl;
    std::cout << "3) EDITAR VOO" << std::endl;
    std::cout << "4) EXCLUIR VOO" << std::endl;
    std::cout << "5) VOLTAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void Console::cadastrarVoo(std::list<Voo *> &voos)
{
    std::string numeroDoVoo = Utils::lerStringTratada("Digite o número do voo");
    std::string partida = Utils::lerStringTratada("Digite o local de partida do voo");
    std::string chegada = Utils::lerStringTratada("Digite o local de chegada do voo");
    std::string data = Utils::lerDataTratada("Digite a data de partida do voo");
    std::string horarioPartida = Utils::lerHorarioTratado("Digite o horário de partida do voo");
    std::string horarioChegada = Utils::lerHorarioTratado("Digite o horário de chegada do voo");
    int capacidade = stoi(Utils::lerStringTratada("Digite a capacidade do voo (múltiplo de 4 entre 20 e 200)"));

    Voo *voo{nullptr};
    try
    {
        voo = new Voo{numeroDoVoo, partida, chegada, capacidade, data, horarioPartida, horarioChegada};
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao cadastrar voo: " << e.what() << std::endl;
        return;
    }

    voos.push_back(voo);

    std::cout << "Sucesso ao cadastrar voo!" << std::endl;
}

void Console::excluirVoo(std::list<Voo *> &voos)
{
}

void Console::gerenciarVoos(std::list<Voo *> &voos)
{
    imprimeStatusLogin();
    imprimirOpcoesGerenciamentoVoos();

    std::string comando{""};
    std::cout << "Digite o NÚMERO da opção escolhida: " << std::endl
              << "> ";
    std::getline(std::cin, comando);
    while (comando.compare("SAIR") != 0)
    {
        // Lista voos
        if (comando.compare("1") == 0)
        {
            Utils::imprimirListaVoos(voos);
        }
        // Cadastra voos
        else if (comando.compare("2") == 0)
        {
            try
            {
                cadastrarVoo(voos);
            }
            catch (std::exception &e)
            {
                std::cout << "Falha ao cadastrar passageiro: " << e.what() << std::endl;
            }
        }
        // Atualiza algum voo
        else if (comando.compare("3") == 0)
        {
            try
            {
                excluirVoo(voos);
            }
            catch (std::exception &e)
            {
                std::cout << "Falha ao cadastrar passageiro: " << e.what() << std::endl;
            }
        }
        // Exclui algum voo
        else if (comando.compare("4") == 0)
        {
        }
        // else if (comando.compare("3") == 0)
        // {
        //     try
        //     {
        // editarPassageiro(passageiros);
        //     }
        //     catch (std::exception &e)
        //     {
        //         std::cout << "Falha ao excluir passageiro: " << e.what() << std::endl;
        //     }
        // }
        // else if (comando.compare("4") == 0)
        // {
        //     try
        //     {
        //         excluirPassageiro(passageiros);
        //     }
        //     catch (std::exception &e)
        //     {
        //         std::cout << "Falha ao excluir passageiro: " << e.what() << std::endl;
        //     }
        // }
        else if (comando.compare("5") == 0)
        {
            break;
        }

        imprimirOpcoesGerenciamentoVoos();
        std::cout << "> ";
        std::getline(std::cin, comando);
    }
}
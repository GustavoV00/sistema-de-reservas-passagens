#include <iostream>
#include <string>
#include "../../includes/consoles/ConsoleAgente.hpp"
#include "../../includes/utils/Utils.hpp"
#include "../../includes/modelos/Voo.hpp"

ConsoleAgente::ConsoleAgente()
{
}

void ConsoleAgente::imprimirComandosTelaPrincipal()
{
    // imprimeStatusLogin();
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << " 1) FAZER LOGIN COMO PASSAGEIRO" << std::endl;
    std::cout << " 2) FAZER LOGIN COMO OUTRO AGENTE" << std::endl;
    std::cout << " 3) MOSTRAR OPÇÕES DE VOOS" << std::endl;
    std::cout << " 4) MOSTRAR OPÇÕES DE RESERVAS" << std::endl;
    std::cout << "10) SAIR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void ConsoleAgente::imprimirOpcoesGerenciamentoVoos()
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

void ConsoleAgente::imprimirOpcoesDadosEditarVoo()
{
    std::cout << std::endl;
    std::cout << "----------------------------EDIÇÃO DE VOO------------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) PARTIDA" << std::endl;
    std::cout << "2) DESTINO" << std::endl;
    std::cout << "3) DATA" << std::endl;
    std::cout << "4) HORARIO DE PARTIDA" << std::endl;
    std::cout << "5) HORARIO DE CHEGADA" << std::endl;
    std::cout << "6) VOLTAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void ConsoleAgente::atualizarVooInterface(VooControle *vooControle)
{
    std::list<Voo *> voos = vooControle->obterTodosOsVoos();

    std::string termoBusca = Utils::lerStringTratada("Digite o número do voo a ser editado ou 'SAIR'");
    int numeroVooParsed{0};
    bool alterouVoo{false};
    while (termoBusca.compare("SAIR") != 0)
    {
        numeroVooParsed = 0;
        try
        {
            numeroVooParsed = stoi(termoBusca);
        }
        catch (std::exception &e)
        {
            std::cout << "Digite apenas números!" << std::endl;
        }

        if (numeroVooParsed > 0)
        {
            std::list<Voo *>::iterator it;
            for (it = voos.begin(); it != voos.end(); it++)
            {
                if ((*it)->getNumeroDoVoo() == numeroVooParsed)
                {
                    std::cout << "Encontrou voo para editar!" << std::endl;
                    (*it)->imprimirDadosVoo();

                    imprimirOpcoesDadosEditarVoo();
                    std::string campoEditar = Utils::lerStringTratada("Digite o número do CAMPO a ser editado ou 'SAIR'");
                    while (campoEditar.compare("SAIR") != 0)
                    {
                        if (campoEditar.compare("1") == 0)
                        {
                            std::string partida = Utils::lerStringTratada("Digite o novo local de partida do voo ou 'SAIR'");
                            if (partida.compare("SAIR") == 0)
                            {
                                return;
                            }
                            if (Utils::mensagemConfirmacao("Tem certeza que deseja editar o voo acima?"))
                            {
                                (*it)->setPartida(partida);
                                alterouVoo = true;
                                std::cout << "Sucesso ao alterar partida!" << std::endl;
                            }
                            break;
                        }
                        else if (campoEditar.compare("2") == 0)
                        {
                            std::string destino = Utils::lerStringTratada("Digite o novo local de destino do voo ou 'SAIR'");
                            if (destino.compare("SAIR") == 0)
                            {
                                return;
                            }
                            if (Utils::mensagemConfirmacao("Tem certeza que deseja editar o voo acima?"))
                            {
                                (*it)->setDestino(destino);
                                alterouVoo = true;
                                std::cout << "Sucesso ao alterar destino!" << std::endl;
                            }
                            break;
                        }
                        else if (campoEditar.compare("3") == 0)
                        {
                            std::string data = Utils::lerDataTratada("Digite a nova data do voo ou 'SAIR'");
                            if (data.compare("SAIR") == 0)
                            {
                                return;
                            }
                            if (Utils::mensagemConfirmacao("Tem certeza que deseja editar o voo acima?"))
                            {
                                (*it)->setData(data);
                                alterouVoo = true;
                                std::cout << "Sucesso ao alterar data!" << std::endl;
                            }
                            break;
                        }
                        else if (campoEditar.compare("4") == 0)
                        {
                            std::string horarioPartida = Utils::lerHorarioTratado("Digite o novo horário de partida do voo ou 'SAIR'");
                            if (horarioPartida.compare("SAIR") == 0)
                            {
                                return;
                            }
                            if (Utils::mensagemConfirmacao("Tem certeza que deseja editar o voo acima?"))
                            {
                                (*it)->setHorarioPartida(horarioPartida);
                                alterouVoo = true;
                                std::cout << "Sucesso ao alterar horário de partida!" << std::endl;
                            }
                            break;
                        }
                        else if (campoEditar.compare("5") == 0)
                        {
                            std::string horarioChegada = Utils::lerHorarioTratado("Digite o novo horário de chegada do voo ou 'SAIR'");
                            if (horarioChegada.compare("SAIR") == 0)
                            {
                                return;
                            }
                            if (Utils::mensagemConfirmacao("Tem certeza que deseja editar o voo acima?"))
                            {
                                (*it)->setHorarioChegada(horarioChegada);
                                alterouVoo = true;
                                std::cout << "Sucesso ao alterar horário de chegada!" << std::endl;
                            }
                            break;
                        }
                        else if (campoEditar.compare("6") == 0)
                        {
                            return;
                        }

                        campoEditar = Utils::lerStringTratada("Digite o número do CAMPO a ser editado ou 'SAIR'");
                    }

                    if (campoEditar.compare("SAIR") == 0)
                    {
                        return;
                    }
                }
            }

            if (alterouVoo)
            {
                break;
            }
            else
            {
                std::cout << "Não editou voo!" << std::endl;
            }
        }
        else
        {
            std::cout << "Digite um número > 0!" << std::endl;
        }

        termoBusca = Utils::lerStringTratada("Digite o número do voo a ser editado ou 'SAIR'");
    }
}

void ConsoleAgente::excluirVooInterface(VooControle *vooControle)
{
    std::list<Voo *> voos = vooControle->obterTodosOsVoos();

    std::string termoBusca = Utils::lerStringTratada("Digite o número do voo a ser excluído ou 'SAIR'");
    int numeroVooParsed{0};
    bool excluiuVoo{false};
    while (termoBusca.compare("SAIR") != 0)
    {
        numeroVooParsed = 0;
        try
        {
            numeroVooParsed = stoi(termoBusca);
        }
        catch (std::exception &e)
        {
            std::cout << "Digite apenas números!" << std::endl;
        }

        if (numeroVooParsed > 0)
        {
            std::list<Voo *>::iterator it{voos.begin()};
            while (it != voos.end())
            {
                if ((*it)->getNumeroDoVoo() == numeroVooParsed)
                {
                    std::cout << "Encontrou voo para excluir!" << std::endl;
                    (*it)->imprimirDadosVoo();

                    // verifica se tem alguma reserva atrelada nele
                    bool reservaAtrelada{false};
                    std::list<Reserva *> reservasVoo = (*it)->getReservas();
                    std::list<Reserva *>::iterator it2{reservasVoo.begin()};
                    for (; it2 != reservasVoo.end(); ++it2)
                    {
                        if ((*it2)->getVoo()->getNumeroDoVoo() == (*it)->getNumeroDoVoo())
                        {
                            std::cout << "Voo está atrelado na reserva " << (*it2)->getLocalizador() << std::endl;
                            reservaAtrelada = true;
                        }
                    }
                    if (reservaAtrelada)
                    {
                        std::cout << "Não é possível excluir voo com reservas!" << std::endl;
                        return;
                    }

                    if (Utils::mensagemConfirmacao("Tem certeza que deseja excluir o voo acima?"))
                    {
                        std::cout << "Excluindo voo..." << std::endl;

                        if (!vooControle->excluirVooPorId((*it)->getId()))
                        {
                            std::cout << "Falha ao excluir voo!" << std::endl;
                        }
                        else
                        {
                            excluiuVoo = true;

                            std::cout << std::endl;
                            std::cout << "Voo excluído com sucesso!" << std::endl;

                            break;
                        }
                    }
                    else
                    {
                        std::cout << "NÃO vai excluir o voo!" << std::endl;
                        it++;
                    }
                }
                else
                {
                    it++;
                }
            }

            if (excluiuVoo)
            {
                std::cout << "Excluiu voo" << std::endl;
                break;
            }
            else
            {
                std::cout << "Não excluiu voo!" << std::endl;
            }
        }
        else
        {
            std::cout << "Digite um número > 0!" << std::endl;
        }

        termoBusca = Utils::lerStringTratada("Digite o número do voo a ser excluído ou 'SAIR'");
    }
}

void ConsoleAgente::cadastrarVooInterface(VooControle *vooControle)
{
    std::list<Voo *> voos = vooControle->obterTodosOsVoos();
    std::string numeroDoVoo = Utils::lerStringTratada("Digite o número do voo ou 'SAIR'");
    int numeroDoVooParsed{0};

    while (numeroDoVoo.compare("SAIR") != 0)
    {
        if (numeroDoVoo.compare("SAIR") == 0)
        {
            return;
        }
        try
        {
            numeroDoVooParsed = stoi(numeroDoVoo);
            if (numeroDoVooParsed <= 0)
            {
                std::cout << "Número do voo deve ser > 0" << std::endl;
            }
            else
            {
                // verifica se já existe voo com esse número
                if (!Utils::existeVooNumero(voos, numeroDoVooParsed))
                {
                    break;
                }
                std::cout << "Já existe voo com esse número!" << std::endl;
            }
        }
        catch (std::exception &e)
        {
            std::cout << "Digite apenas números!" << std::endl;
        }

        numeroDoVoo = Utils::lerStringTratada("Digite o número do voo ou 'SAIR'");
    }

    if (numeroDoVoo.compare("SAIR") == 0)
    {
        return;
    }
    if (numeroDoVooParsed <= 0)
    {
        std::cout << "Número do voo não pode ser <= 0" << std::endl;
        return;
    }

    std::string partida = Utils::lerStringTratada("Digite o local de partida do voo ou 'SAIR'");
    if (partida.compare("SAIR") == 0)
    {
        return;
    }
    std::string chegada = Utils::lerStringTratada("Digite o local de chegada do voo ou 'SAIR'");
    if (chegada.compare("SAIR") == 0)
    {
        return;
    }
    std::string data = Utils::lerDataTratada("Digite a data de partida do voo ou 'SAIR'");
    if (data.compare("SAIR") == 0)
    {
        return;
    }
    std::string horarioPartida = Utils::lerHorarioTratado("Digite o horário de partida do voo ou 'SAIR'");
    if (horarioPartida.compare("SAIR") == 0)
    {
        return;
    }
    std::string horarioChegada = Utils::lerHorarioTratado("Digite o horário de chegada do voo ou 'SAIR'");
    if (horarioChegada.compare("SAIR") == 0)
    {
        return;
    }

    int capacidade{0};
    try
    {
        std::string stringCapacidade = Utils::lerStringTratada("Digite a capacidade do voo (múltiplo de 4 entre 20 e 200) ou 'SAIR'");
        if (stringCapacidade.compare("SAIR") == 0)
        {
            return;
        }

        capacidade = stoi(stringCapacidade);
    }
    catch (std::exception &e)
    {
        std::cout << "Capacidade deve ser inteiro (múltiplo de 4 entre 20 e 200)!" << std::endl;
        return;
    }

    Voo *voo{nullptr};
    try
    {
        unsigned int novoID = voos.size() + 1;
        voo = new Voo{novoID, numeroDoVooParsed, partida, chegada, capacidade, data, horarioPartida, horarioChegada};
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao cadastrar voo: " << e.what() << std::endl;
        return;
    }

    // voos.push_back(voo);
    if (!vooControle->cadastrarVoo(voo))
    {
        return;
    }
}

// usuário agente tem todas as permissões para gerenciar os voos
void ConsoleAgente::rodarGerenciamentoDeVoo(VooControle *vooControle)
{
    std::string comando{""};
    while (comando.compare("5") != 0)
    {
        imprimirOpcoesGerenciamentoVoos();
        comando = Utils::lerStringTratada("Digite o número da opção escolhida");
        if (comando.compare("1") == 0)
        {
            Utils::imprimirListaVoos(vooControle->obterTodosOsVoos());
        }
        else if (comando.compare("2") == 0)
        {
            cadastrarVooInterface(vooControle);
        }
        else if (comando.compare("3") == 0)
        {
            atualizarVooInterface(vooControle);
        }
        else if (comando.compare("4") == 0)
        {
            excluirVooInterface(vooControle);
        }
        std::cout << std::endl;
    }
}

void ConsoleAgente::imprimirOpcoesGerenciamentoDeReservas()
{
    std::cout << std::endl;
    std::cout << "-------------------------GERENCIAMENTO DE VOOS------------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) LISTAR RESERVAS" << std::endl;
    std::cout << "2) CRIAR  RESERVAS" << std::endl;
    std::cout << "3) EDITAR RESERVAS" << std::endl;
    std::cout << "4) EXCLUIR  RESERVAS" << std::endl;
    std::cout << "5) VOLTAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void ConsoleAgente::rodarGerenciamentoDeReservas()
{
    std::string comando{""};
    while (comando.compare("5") != 0)
    {
        this->imprimirOpcoesGerenciamentoDeReservas();
        comando = Utils::lerStringTratada("Digite o número da opção escolhida");
        // Listar
        if (comando.compare("1") == 0)
        {
            std::cout << "Aqui chama a função de listar reservas, mas deve ser lançado uma exceção!" << std::endl;
        }
        // Cadastrar
        else if (comando.compare("2") == 0)
        {
            std::cout << "Aqui o UsuarioConvidado deve ser redirecionado para uma página de cadastro de passageiro e logo em seguida fazer a reserva" << std::endl;
        }
        else if (comando.compare("3") == 0)
        {
            std::cout << "Aqui chama a função de atualizar reserva, mas deve ser lançado uma exceção!" << std::endl;
        }
        else if (comando.compare("4") == 0)
        {
            std::cout << "Aqui chama a função de excluir reserva, mas deve ser lançado uma exceção!" << std::endl;
        }
        std::cout << std::endl;
    }
}
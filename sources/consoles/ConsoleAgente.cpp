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
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << " 1) FAZER LOGIN COMO PASSAGEIRO" << std::endl;
    std::cout << " 2) FAZER LOGIN COMO OUTRO AGENTE" << std::endl;
    std::cout << " 3) MOSTRAR OPÇÕES DE VOOS" << std::endl;
    std::cout << " 4) MOSTRAR OPÇÕES DE RESERVAS" << std::endl;
    std::cout << " 5) MOSTRAR OPÇÕES DE PASSAGEIROS" << std::endl;
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

void ConsoleAgente::imprimirOpcoesGerenciamentoPassageiros()
{
    std::cout << std::endl;
    std::cout << "---------------------GERENCIAMENTO DE PASSAGEIROS------------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) LISTAR PASSAGEIROS" << std::endl;
    std::cout << "2) CRIAR PASSAGEIRO" << std::endl;
    std::cout << "3) EDITAR PASSAGEIRO" << std::endl;
    std::cout << "4) EXCLUIR PASSAGEIRO" << std::endl;
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

void ConsoleAgente::imprimirOpcoesDadosEditarPassageiro()
{
    std::cout << std::endl;
    std::cout << "-------------------------EDIÇÃO DE PASSAGEIRO------------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) NOME" << std::endl;
    std::cout << "2) CPF" << std::endl;
    std::cout << "3) RG" << std::endl;
    std::cout << "4) EMAIL" << std::endl;
    std::cout << "5) DATA DE NASCIMENTO " << std::endl;
    std::cout << "6) TELEFONE " << std::endl;
    std::cout << "7) VOLTAR " << std::endl;
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
            for (it = voos.begin(); it != voos.end(); ++it)
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
        voo = new Voo{numeroDoVooParsed, partida, chegada, capacidade, data, horarioPartida, horarioChegada};
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
    std::cout << "-------------------------GERENCIAMENTO DE RESERVASS------------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) LISTAR RESERVAS" << std::endl;
    std::cout << "2) CRIAR  RESERVAS" << std::endl;
    std::cout << "3) EDITAR RESERVAS" << std::endl;
    std::cout << "4) EXCLUIR  RESERVAS" << std::endl;
    std::cout << "5) VOLTAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void ConsoleAgente::rodarGerenciamentoDeReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Usuario *usuario)
{
    std::string comando{""};
    std::list<Reserva *> reservas = reservaControle->obterTodosAsReservas();

    // char locL{'L'};
    // char locR{'R'};
    while (comando.compare("5") != 0)
    {
        this->imprimirOpcoesGerenciamentoDeReservas();
        comando = Utils::lerStringTratada("Digite o número da opção escolhida");

        // // Listar
        if (comando.compare("1") == 0)
        {
            Utils::imprimirListaReservas(reservaControle->obterTodosAsReservas());
        }
        // Cadastrar reserva
        else if (comando.compare("2") == 0)
        {
            this->cadastrarReservaInterface(reservaControle, passageiroControle, vooControle);
        }
        else if (comando.compare("3") == 0)
        {
            this->atualizarReservaInterface(reservaControle, passageiroControle, vooControle);
        }
        else if (comando.compare("4") == 0)
        {
            this->removerReservaInterface(reservaControle, passageiroControle, vooControle);
        }

        // std::cout << std::endl;
    }
}

void ConsoleAgente::cadastrarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle)
{
    std::list<Passageiro *> passageiros = passageiroControle->obterTodosOsPassageiros();
    Voo *voo{nullptr};
    Passageiro *passageiro{nullptr};

    std::cout << "Adicionando passageiro..." << std::endl;
    Utils::imprimirListaPassageiros(passageiros);
    std::string termoBusca = Utils::lerStringTratada("Digite o Nome completo, CPF, RG ou Email do passageiro a ser adicionado na reserva ou 'SAIR'");
    bool adicionouPassageiro{false};
    while (!adicionouPassageiro && termoBusca.compare("SAIR") != 0)
    {
        std::list<Passageiro *>::iterator it;
        for (it = passageiros.begin(); it != passageiros.end(); it++)
        {
            if ((*it)->getNome() == termoBusca || (*it)->getEmail().compare(termoBusca) == 0 || std::to_string((*it)->getCpf().getNumero()).compare(termoBusca) == 0 || std::to_string((*it)->getRg().getNumero()).compare(termoBusca) == 0)
            {
                std::cout << std::endl;
                std::cout << "Encontrou passageiro para adicionar: " << std::endl;
                (*it)->imprimirDadosFormatados();
                if (Utils::mensagemConfirmacao("Tem certeza que deseja adicionar o passageiro acima na reserva?"))
                {
                    passageiro = (*it);
                }
            }
        }

        if (passageiro != nullptr)
        {
            adicionouPassageiro = true;
            break;
        }

        std::cout << "Falha ao encontrar passageiro!" << std::endl;
        termoBusca = Utils::lerStringTratada("Digite o Nome completo, CPF, RG ou Email do passageiro a ser adicionado na reserva ou 'SAIR'");
    }

    if (termoBusca.compare("SAIR") == 0)
    {
        return;
    }

    if (!adicionouPassageiro)
    {
        std::cout << "Falha ao encontrar passageiro para a reserva... " << std::endl;
        return;
    }

    std::string comando{""};
    int numeroDoVoo{0};

    std::list<Voo *> voos = vooControle->obterTodosOsVoos();
    Utils::imprimirListaVoos(voos);
    while (voo == nullptr)
    {
        comando = Utils::lerStringTratada("Digite SAIR para sair ou um NUMERO DO VOO para criar a reserva ou 'SAIR'");
        if (comando.compare("SAIR") == 0)
        {
            return;
        }
        else
        {
            if (Utils::eh_numero(comando))
            {
                numeroDoVoo = stoi(comando);
                voo = vooControle->obterVooPorNumeroDoVoo(numeroDoVoo);
                if (voo == nullptr)
                    std::cout << "Numero do VOO inválido" << std::endl;
                else
                {

                    // verifica se o passageiro já está no voo
                    std::list<Reserva *> resevasDoPassageiro = reservaControle->obterReservasDoPassageiro(passageiro);
                    std::list<Reserva *>::iterator it;
                    for (it = resevasDoPassageiro.begin(); it != resevasDoPassageiro.end(); ++it)
                    {
                        if ((*it)->getVoo() == voo)
                        {
                            std::cout << "Não pode fazer a reserva desse PASSAGEIRO nesse mesmo VOO" << std::endl;
                            voo = nullptr;
                        }
                    }
                }
            }
            else
            {
                std::cout << "Numero do VOO inválido" << std::endl;
            }
        }
    }

    std::list<Reserva *> reservas = reservaControle->obterTodosAsReservas();
    std::string localizador = GerarDados::gerarLocalizador(reservaControle);
    std::string numeroDoAssento = GerarDados::gerarNovoNumeroDoAssento(reservaControle);

    Reserva *reserva{nullptr};
    try
    {
        reserva = new Reserva{localizador, passageiro, voo, numeroDoAssento};
        if (reservaControle->cadastrarReserva(reserva))
        {
            // adiciona reserva na lista de reservas do voo
            try
            {
                voo->adicionarReserva(reserva);
            }
            catch (std::exception &e)
            {
                std::cout << "Falha ao adicionar reserva no voo: " << e.what() << "! Reserva não vai ser adicionada!" << std::endl;
                reservaControle->excluirReservaPorLocalizador(localizador);
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao criar reserva!" << std::endl;
    }
}

void ConsoleAgente::atualizarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle)
{
    std::string comando{""};
    char locL{'L'};
    char locR{'R'};
    while (comando.compare("SAIR") != 0)
    {
        comando = Utils::lerStringTratada("Digite o CÓDIGO da reserva que deseja atualizar ou SAIR para sair");
        if (comando.size() == 6 && comando.at(0) == locL && comando.at(1) == locR)
        {

            Reserva *reserva = reservaControle->obterReservaPorLocalizador(comando);
            if (reserva != nullptr)
            {
                // reserva->imprimirDadosReserva();
                std::cout << *reserva << std::endl;
                if (Utils::mensagemConfirmacao("Tem certeza que deseja atualizar a reserva acima?"))
                {
                    comando = Utils::lerStringTratada("Digite VOO para mudar o VOO e ASSENTO para mudar o ASSENTO do VOO atual");
                    if (comando.compare("VOO") == 0 || comando.compare("voo") == 0)
                    {
                        std::list<Voo *> voos = vooControle->obterTodosOsVoos();
                        Utils::imprimirListaVoos(voos);
                        comando = Utils::lerStringTratada("Digite o NUMERO do novo VOO");
                        int numVoo = stoi(comando);
                        Voo *vooAntigo = reserva->getVoo();
                        Voo *voo = vooControle->obterVooPorNumeroDoVoo(numVoo);
                        if (vooAntigo->getNumeroDoVoo() != voo->getNumeroDoVoo())
                        {
                            reserva->setVoo(voo);
                            voo->adicionarReserva(reserva);
                            std::cout << "VOO foi atualizado com sucesso" << std::endl;
                            vooAntigo->removerReserva(reserva);
                        }
                        else
                        {
                            std::cout << "O Voo novo não pode ser igual ao atual" << std::endl;
                        }
                    }
                    else if (comando.compare("ASSENTO") == 0 || comando.compare("assento") == 0)
                    {
                        std::cout << "Foi gerado um novo assento com sucesso!" << std::endl;
                        std::string novoAssento = GerarDados::gerarNovoNumeroDoAssento(reservaControle);
                        reserva->setNumeroDoAssento(novoAssento);
                    }
                }
            }
            else
            {
                std::cout << "Reserva não existe!" << std::endl;
            }
        }
        else
        {
            std::cout << "Entrada incorreta!" << std::endl;
        }
    }
}

void ConsoleAgente::removerReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle)
{

    std::string comando{""};

    comando = Utils::lerStringTratada("Digite o CÓDIGO da reserva para remover e SAIR para sair ");
    if (comando.compare("SAIR") == 0)
        return;

    char locL{'L'};
    char locR{'R'};
    if (comando.size() == 6 && comando.at(0) == locL && comando.at(1) == locR)
    {

        if (Utils::mensagemConfirmacao("Tem certeza que deseja excluir a reserva acima?"))
        {
            reservaControle->excluirReservaPorLocalizador(comando);
        }
    }
    else
    {
        std::cout << "Esse código não existe" << std::endl;
    }
}

void ConsoleAgente::rodarGerenciamentoDePassageiros(PassageiroControle *passageiroControle, Usuario *usuario, ReservaControle *reservaControle)
{
    std::string comando{""};
    while (comando.compare("5") != 0)
    {
        imprimirOpcoesGerenciamentoPassageiros();
        comando = Utils::lerStringTratada("Digite o número da opção escolhida");
        if (comando.compare("1") == 0)
        {
            Utils::imprimirListaPassageiros(passageiroControle->obterTodosOsPassageiros());
        }
        else if (comando.compare("2") == 0)
        {
            cadastrarPassageiroInterface(passageiroControle);
        }
        else if (comando.compare("3") == 0)
        {
            atualizarPassageiroInterface(passageiroControle);
        }
        else if (comando.compare("4") == 0)
        {
            excluirPassageiroInterface(passageiroControle, reservaControle);
        }
        std::cout << std::endl;
    }
}

void ConsoleAgente::atualizarPassageiroInterface(PassageiroControle *passageiroControle)
{
    std::list<Passageiro *> passageiros = passageiroControle->obterTodosOsPassageiros();
    std::string termoBusca = Utils::lerStringTratada("Digite o Nome completo, CPF, RG ou Email do passageiro a ser editado ou 'SAIR'");
    if (termoBusca.compare("SAIR") == 0)
    {
        return;
    }
    bool encontrouPassageiro = false;
    std::list<Passageiro *>::iterator it;
    for (it = passageiros.begin(); it != passageiros.end(); ++it)
    {
        if ((*it)->getNome() == termoBusca || (*it)->getEmail().compare(termoBusca) == 0 ||
            std::to_string((*it)->getCpf().getNumero()).compare(termoBusca) == 0 || std::to_string((*it)->getRg().getNumero()).compare(termoBusca) == 0)
        {
            std::cout << std::endl;
            std::cout << "Encontrou passageiro para editar: " << std::endl;
            (*it)->imprimirDadosPassageiro();

            if (Utils::mensagemConfirmacao("Tem certeza que deseja editar o passageiro acima?"))
            {
                encontrouPassageiro = true;

                imprimirOpcoesDadosEditarPassageiro();
                std::string campoEditar = Utils::lerStringTratada("Digite o número do CAMPO a ser editado ou 'SAIR'");
                while (campoEditar.compare("SAIR") != 0)
                {
                    if (campoEditar.compare("1") == 0)
                    {
                        // nome
                        std::string novoNomePassageiro = Utils::lerStringTratada("Digite o novo nome do passageiro ou 'SAIR'");
                        if (novoNomePassageiro.compare("SAIR") == 0)
                        {
                            return;
                        }

                        (*it)->setNome(novoNomePassageiro);
                        std::cout << "Sucesso ao alterar nome do passageiro!" << std::endl;
                        break;
                    }
                    else if (campoEditar.compare("2") == 0)
                    {
                        // cpf
                        CPF *novoCpf = Utils::lerCPFTratado("Digite o CPF ou 'SAIR'");
                        if (novoCpf == nullptr)
                        {
                            std::cout << "CPF não é válido! Saindo da atualização de passageiro..." << std::endl;
                            return;
                        }
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

                        (*it)->setCpf(*novoCpf);
                        std::cout << "Sucesso ao atualizar CPF!" << std::endl;
                        break;
                    }
                    else if (campoEditar.compare("3") == 0)
                    {
                        // rg
                        RG *novoRg = Utils::lerRGTratado("Digite o RG ou 'SAIR'");
                        if (novoRg == nullptr)
                        {
                            std::cout << "RG não é válido! Saindo da atualização de passageiro..." << std::endl;
                            return;
                        }
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

                        (*it)->setRg(*novoRg);
                        std::cout << "Sucesso ao atualizar RG!" << std::endl;
                        break;
                    }
                    else if (campoEditar.compare("4") == 0)
                    {
                        // email
                        std::string email = Utils::lerStringTratada("Digite o novo email do passageiro ou 'SAIR'");
                        if (email.compare("SAIR") == 0)
                        {
                            return;
                        }

                        (*it)->setEmail(email);
                        std::cout << "Sucesso ao alterar email do passageiro!" << std::endl;
                        break;
                    }
                    else if (campoEditar.compare("5") == 0)
                    {
                        // data de nascimento
                        std::string dataNascimento = Utils::lerDataTratada("Digite a nova data de nascimento do passageiro ou 'SAIR'");
                        if (dataNascimento.compare("SAIR") == 0)
                        {
                            return;
                        }

                        (*it)->setDataDeNascimento(dataNascimento);
                        std::cout << "Sucesso ao alterar data de nascimento do passageiro!" << std::endl;
                        break;
                    }
                    else if (campoEditar.compare("6") == 0)
                    {
                        // telefone
                        unsigned long telefone = Utils::lerTelefoneTratado("Digite o Telefone ou 'SAIR'");
                        if (telefone == 0)
                        {
                            std::cout << "Telefone inválido!" << std::endl;
                        }

                        (*it)->setContato(telefone);
                        std::cout << "Sucesso ao alterar telefone do passageiro!" << std::endl;
                        break;
                    }
                    else if (campoEditar.compare("7") == 0)
                    {
                        return;
                    }

                    campoEditar = Utils::lerStringTratada("Digite o número do CAMPO a ser editado ou 'SAIR'");
                }
            }
            else
            {
                std::cout << "Não vai editar o passageiro!" << std::endl;
            }
        }

        if (encontrouPassageiro)
        {
            break;
        }
    }

    if (!encontrouPassageiro)
    {
        std::cout << "Não encontrou passageiro com os dados especificados!" << std::endl;
    }
}

void ConsoleAgente::excluirPassageiroInterface(PassageiroControle *passageiroControle, ReservaControle *reservaControle)
{
    std::list<Passageiro *> passageiros = passageiroControle->obterTodosOsPassageiros();
    std::string termoBusca = Utils::lerStringTratada("Digite o Nome completo, CPF, RG ou Email do passageiro a ser excluído ou 'SAIR'");
    if (termoBusca.compare("SAIR") == 0)
    {
        return;
    }
    bool encontrouPassageiro = false;
    std::list<Passageiro *>::iterator it;
    for (it = passageiros.begin(); it != passageiros.end(); ++it)
    {
        if ((*it)->getNome() == termoBusca || (*it)->getEmail().compare(termoBusca) == 0 ||
            std::to_string((*it)->getCpf().getNumero()).compare(termoBusca) == 0 || std::to_string((*it)->getRg().getNumero()).compare(termoBusca) == 0)
        {
            std::cout << std::endl;
            std::cout << "Encontrou passageiro para excluir: " << std::endl;
            (*it)->imprimirDadosPassageiro();

            if (Utils::mensagemConfirmacao("Tem certeza que deseja excluir o passageiro acima?"))
            {
                encontrouPassageiro = true;

                // verifica se o passageiro está em alguma reserva
                std::list<Reserva *> reservas = reservaControle->obterReservasDoPassageiro(*it);
                if (reservas.size() > 0)
                {
                    std::cout << "Passageiro possui reservas! Não foi possível excluir passageiro!" << std::endl;
                    return;
                }

                std::cout << "Excluindo passageiro..." << std::endl;

                if (!passageiroControle->excluirPassageiroPorId((*it)->getId()))
                {
                    std::cout << "Falha ao excluir passageiro!" << std::endl;
                }
                else
                {
                    std::cout << std::endl;
                    std::cout << "Passageiro excluído com sucesso!" << std::endl;

                    break;
                }
            }
            else
            {
                std::cout << "Não vai excluir o passageiro!" << std::endl;
            }
        }

        if (encontrouPassageiro)
        {
            break;
        }
    }

    if (!encontrouPassageiro)
    {
        std::cout << "Não encontrou passageiro com os dados especificados!" << std::endl;
    }
}
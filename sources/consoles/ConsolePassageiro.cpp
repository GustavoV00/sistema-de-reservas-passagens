#include <iostream>
#include <string>
#include "../../includes/consoles/ConsolePassageiro.hpp"
#include "../../includes/utils/Utils.hpp"
#include "../../includes/modelos/Voo.hpp"

ConsolePassageiro::ConsolePassageiro()
{
}

void ConsolePassageiro::imprimirComandosTelaPrincipal()
{
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << " 1) FAZER LOGIN COMO OUTRO PASSAGEIRO" << std::endl;
    std::cout << " 2) FAZER LOGIN COMO AGENTE" << std::endl;
    std::cout << " 3) MOSTRAR OPÇÕES DE VOOS" << std::endl;
    std::cout << " 4) MOSTRAR OPÇÕES DE RESERVAS" << std::endl;
    std::cout << "10) SAIR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void ConsolePassageiro::imprimirOpcoesGerenciamentoDeReservas()
{
    std::cout << std::endl;
    std::cout << "-------------------------GERENCIAMENTO DE RESERVAS------------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) LISTAR MINHAS RESERVAS" << std::endl;
    std::cout << "2) LISTAR MINHAS RESERVA POR CÓDIGO" << std::endl;
    std::cout << "3) CRIAR  RESERVAS" << std::endl;
    std::cout << "4) EDITAR RESERVAS" << std::endl;
    std::cout << "5) EXCLUIR  RESERVAS" << std::endl;
    std::cout << "6) VOLTAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void ConsolePassageiro::rodarGerenciamentoDeReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Usuario *usuario)
{
    std::string comando{""};
    std::list<Reserva *> reservas = reservaControle->obterReservasDoPassageiro(usuario);
    std::list<Reserva *>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); ++it)
    {
        std::cout << (*it)->getPassageiro()->getNome() << std::endl;
        std::cout << (*it)->getLocalizador() << std::endl;
    }

    CPF cpfBusca = usuario->getCpf();
    Passageiro *passageiro = passageiroControle->obterPassageiroPorCPF(cpfBusca);
    char locL{'L'};
    char locR{'R'};
    while (comando.compare("6") != 0)
    {
        this->imprimirOpcoesGerenciamentoDeReservas();
        comando = Utils::lerStringTratada("Digite o número da opção escolhida");

        // // Listar
        if (comando.compare("1") == 0)
        {
            Utils::imprimirListaReservas(reservas);
        }
        // buscar apenas uma reserva
        else if (comando.compare("2") == 0)
        {
            if (reservas.empty())
            {
                std::cout << "Você não possui nenhuma reserva!" << std::endl;
                continue;
            }

            std::string comando{""};
            comando = Utils::lerStringTratada("Digite o localizador da reserva");
            if (comando.size() == 6 && comando.at(0) == locL && comando.at(1) == locR)
            {
                Reserva *reserva = reservaControle->obterReservaPorLocalizador(comando);
                // reserva->imprimirDadosReserva();
                std::cout << *reserva << std::endl;
            }
            else
            {
                std::cout << "Número do código está incorreto! " << std::endl;
            }
        }
        // Cadastrar reserva
        else if (comando.compare("3") == 0)
        {
            this->cadastrarReservaInterface(reservaControle, passageiroControle, vooControle, passageiro, reservas);
            reservas = reservaControle->obterReservasDoPassageiro(usuario);
        }
        else if (comando.compare("4") == 0)
        {
            if (reservas.empty())
            {
                std::cout << "Você não possui nenhuma reserva!" << std::endl;
                continue;
            }
            this->atualizarReservaInterface(reservaControle, passageiroControle, vooControle);
        }
        else if (comando.compare("5") == 0)
        {
            if (reservas.empty())
            {
                std::cout << "Você não possui nenhuma reserva!" << std::endl;
                continue;
            }
            this->removerReservaInterface(reservaControle, passageiroControle, vooControle, passageiro);
            reservas = reservaControle->obterReservasDoPassageiro(usuario);
        }
        else if (comando.compare("6") == 0)
        {
            comando = "6";
        }
    }
}

void ConsolePassageiro::cadastrarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Passageiro *passageiro, std::list<Reserva *> resevasDoPassageiro)
{
    Voo *voo{nullptr};
    std::string comando{""};
    int numeroDoVoo{0};

    std::list<Voo *> voos = vooControle->obterTodosOsVoos();
    Utils::imprimirListaVoos(voos);
    while (voo == nullptr)
    {
        comando = Utils::lerStringTratada("Digite SAIR para sair ou um NUMERO DO VOO para criar a reserva");
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

void ConsolePassageiro::removerReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Passageiro *passageiro)
{

    std::string comando{""};

    comando = Utils::lerStringTratada("Digite o CÓDIGO da reserva para remover e SAIR para sair ");
    if (comando.compare("SAIR") == 0)
        return;

    // Reserva *reserva = reservaControle->obterReservaPorLocalizador(comando);
    // reserva->getPassageiro();
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

void ConsolePassageiro::atualizarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle)
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
                            break;
                        }
                    }
                    else if (comando.compare("ASSENTO") == 0 || comando.compare("assento") == 0)
                    {
                        std::cout << "Foi gerado um novo assento com sucesso!" << std::endl;
                        std::string novoAssento = GerarDados::gerarNovoNumeroDoAssento(reservaControle);
                        reserva->setNumeroDoAssento(novoAssento);
                    }
                    else
                    {
                        std::cout << "VOO ou ASSENTO foi digitado incorreto, tente novamente" << std::endl;
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
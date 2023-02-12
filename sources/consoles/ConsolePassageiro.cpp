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
    std::cout << "1) LISTAR RESERVAS" << std::endl;
    std::cout << "2) LISTAR RESERVA POR ID: Entre 1 e 30" << std::endl;
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

        std::cout << "Estou entrando aqui!" << std::endl;
        std::cout << (*it)->getPassageiro()->getNome() << std::endl;
        std::cout << (*it)->getLocalizador() << std::endl;
    }

    // isso aqui vai dar problema quando a lista for fazia
    std::string email = usuario->getEmail();
    Passageiro *passageiro = passageiroControle->obterPassageiroPorEmail(email);
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
            std::string comando{""};
            comando = Utils::lerStringTratada("Digite o localizador da reserva");
            if (comando.size() == 6)
            {
                Reserva *reserva = reservaControle->obterReservaPorLocalizador(comando);
                reserva->imprimirDadosReserva();
            }
            else
            {
                std::cout << "Número do localizador está incorreto! " << std::endl;
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
            this->atualizarReservaInterface(reservaControle, passageiroControle, vooControle);
        }
        else if (comando.compare("5") == 0)
        {
            this->removerReservaInterface(reservaControle, passageiroControle, vooControle, passageiro);
            reservas = reservaControle->obterReservasDoPassageiro(usuario);
        }
        else if (comando.compare("6") == 0)
        {
            comando = "6";
        }
        // std::cout << std::endl;
    }
}

// Verificar se um Passageiro já pertence ao voo e não deixar ele se cadastrar dnv
void ConsolePassageiro::cadastrarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Passageiro *passageiro, std::list<Reserva *> resevasDoPassageiro)
{
    // Passageiro *passageiro = passageiroControle->obterPassageiroPorId(1);
    // std::cout << passageiro->getNome();
    Voo *voo{nullptr};
    std::list<Voo *> voos;
    std::string comando{""};
    int numeroDoVoo{0};

    // std::list<Voo *> voos = vooControle->obterTodosOsVoos();
    while (voo == nullptr)
    {
        comando = Utils::lerStringTratada("Digite SAIR para sair, LISTAR para mostrar os VOOS ou o NUMERO DO VOO para criar a reserva");
        if (comando.compare("LISTAR") == 0)
        {
            voos = vooControle->obterTodosOsVoos();
            Utils::imprimirListaVoos(voos);
        }
        else if (comando.compare("SAIR") == 0)
        {
            return;
        }
        else
        {
            numeroDoVoo = stoi(comando);
            // if (isdigit(numeroDoVoo))
            // {
            voo = vooControle->obterVooPorNumeroDoVoo(numeroDoVoo);
            if (voo == nullptr)
                std::cout << "NUMERO do VOO inválido" << std::endl;

            // std::list<Reserva *>::iterator it;
            // for (it = reservas.begin(); it != reservas.end(); ++it)
            // {
            //     if ((*it)->getVoo() == voo)
            //     {
            //         std::cout << "Não pode fazer a reserva desse PASSAGEIRO nesse mesmo VOO" << std::endl;
            //         voo = nullptr;
            //     }
            // }

            // }
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
    reservaControle->excluirReservaPorLocalizador(comando);
}

void ConsolePassageiro::atualizarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle)
{
    std::string comando{""};
    while (comando.compare("SAIR") != 0)
    {
        comando = Utils::lerStringTratada("Digite o CÓDIGO da reserva que deseja atualizar ou SAIR para sair");
        if (comando.size() == 6)
        {
            Reserva *reserva = reservaControle->obterReservaPorLocalizador(comando);
            if (reserva != nullptr)
            {
                comando = Utils::lerStringTratada("Digite VOO para mudar o VOO e ASSENTO para mudar o ASSENTO do VOO atual");
                if (comando.compare("VOO") == 0)
                {
                    std::list<Voo *> voos = vooControle->obterTodosOsVoos();
                    Utils::imprimirListaVoos(voos);
                    comando = Utils::lerStringTratada("Digite o NUMERO do novo VOO");
                    int numVoo = stoi(comando);
                    Voo *voo = vooControle->obterVooPorNumeroDoVoo(numVoo);
                    reserva->setVoo(voo);
                }
                else if (comando.compare("ASSENTO") == 0)
                {
                    std::cout << "Foi gerado um novo assento com sucesso!" << std::endl;
                    std::string novoAssento = GerarDados::gerarNovoNumeroDoAssento(reservaControle);
                    reserva->setNumeroDoAssento(novoAssento);
                }
            }
            else
            {
                std::cout << "Reserva não existe!" << std::endl;
            }
        }
        else
        {
            std::cout << "Código incorreto!" << std::endl;
        }
    }
}
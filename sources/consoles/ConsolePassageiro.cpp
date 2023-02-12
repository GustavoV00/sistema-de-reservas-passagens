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
    // imprimeStatusLogin();
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << " 1) FAZER LOGIN COMO PASSAGEIRO" << std::endl;
    std::cout << " 2) FAZER LOGIN COMO AGENTE" << std::endl;
    std::cout << " 3) MOSTRAR OPÇÕES DE VOOS" << std::endl;
    std::cout << " 4) MOSTRAR OPÇÕES DE RESERVAS" << std::endl;
    std::cout << "10) SAIR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    // std::cout << "testeeeereee" << std::endl;
}

void ConsolePassageiro::imprimirOpcoesGerenciamentoVoos()
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

void ConsolePassageiro::cadastrarVooInterface(VooControle *vooControle)
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

    std::cout << "Sucesso ao cadastrar voo!" << std::endl;
}

// usuário agente tem todas as permissões para gerenciar os voos
void ConsolePassageiro::rodarGerenciamentoDeVoo(VooControle *vooControle)
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
            std::cout << "Aqui chama a função de cadastrar voo" << std::endl;
            cadastrarVooInterface(vooControle);
        }
        else if (comando.compare("3") == 0)
        {
            std::cout << "Aqui chama a função de atualizar voo" << std::endl;
        }
        else if (comando.compare("4") == 0)
        {
            std::cout << "Aqui chama a função de excluir voo" << std::endl;
        }
        std::cout << std::endl;
    }
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

void ConsolePassageiro::rodarGerenciamentoDeReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle)
{
    std::string comando{""};
    while (comando.compare("5") != 0)
    {
        this->imprimirOpcoesGerenciamentoDeReservas();
        comando = Utils::lerStringTratada("Digite o número da opção escolhida");
        // Listar
        if (comando.compare("1") == 0)
        {
            std::list<Reserva *> reservas = reservaControle->obterTodosAsReservas();
            Utils::imprimirListaReservas(reservas);
        }
        // buscar apenas uma reserva
        else if (comando.compare("2") == 0)
        {
            std::string comando{""};
            comando = Utils::lerStringTratada("Digite o id da reserva");
            int id = stoi(comando);
            Reserva *reserva = reservaControle->obterReservaPorId(id);
            reserva->imprimirDadosReserva();
        }
        // Cadastrar reserva
        else if (comando.compare("3") == 0)
        {
            this->cadastrarReservaInterface(reservaControle, passageiroControle, vooControle);
        }
        else if (comando.compare("4") == 0)
        {
            // this->atualizarReservaInterface(reservaControle, passageiroControle, vooControle);
        }
        else if (comando.compare("5") == 0)
        {
            std::cout << "Aqui chama a função de excluir reserva, mas deve ser lançado uma exceção!" << std::endl;
            this->removerReservaInterface(reservaControle, passageiroControle, vooControle);
        }
        std::cout << std::endl;
    }
}

void ConsolePassageiro::cadastrarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle)
{
    Passageiro *passageiro{nullptr};
    // Passageiro *passageiro = passageiroControle->obterPassageiroPorId(1);
    // std::cout << passageiro->getNome();
    Voo *voo{nullptr};
    std::list<Reserva *> reservas = reservaControle->obterTodosAsReservas();
    std::string comando{""};
    int id{0};

    std::cout << "ESSA RESERVA VAI PERTENCER A QUAL PASSAGEIRO ? " << std::endl;
    while (passageiro == nullptr)
    {
        comando = Utils::lerStringTratada("DESEJA LISTAR TODOS OS PASSAGEIROS ? S/n");
        if (comando.compare("S") == 0)
        {
            std::list<Passageiro *> passageiros = passageiroControle->obterTodosOsPassageiros();
            Utils::imprimirListaPassageiros(passageiros);
        }
        comando = Utils::lerStringTratada("Digite um ID valido!");
        id = stoi(comando);
        passageiro = passageiroControle->obterPassageiroPorId(id);
        if (passageiro == nullptr)
            std::cout << "ID Inválido!" << std::endl;
    }

    std::cout << "ESSA RESERVA PERTENCE A QUAL VOO? " << std::endl;
    while (voo == nullptr)
    {
        comando = Utils::lerStringTratada("DESEJA LISTAR TODOS OS VOOS? S/n");
        if (comando.compare("S") == 0)
        {
            std::list<Voo *> voos = vooControle->obterTodosOsVoos();
            Utils::imprimirListaVoos(voos);
        }
        comando = Utils::lerStringTratada("Digite um ID valido do Voo!");
        id = stoi(comando);
        voo = vooControle->obterVooPorId(id);
        if (voo == nullptr)
            std::cout << "ID Inválido!" << std::endl;
    }

    unsigned int tamReserva = reservas.size() + 1;
    unsigned int novoId{tamReserva};
    std::string localizador = GerarDados::gerarLocalizador(reservaControle);
    unsigned int capacidade = voo->getCapacidade();
    std::string numeroDoAssento = GerarDados::gerarNovoNumeroDoAssento(reservaControle, capacidade);

    Reserva *reserva = new Reserva{novoId, localizador, passageiro, voo, numeroDoAssento};
    reservaControle->cadastrarReserva(reserva);
}

void ConsolePassageiro::removerReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle)
{

    Passageiro *passageiro{nullptr};
    Voo *voo{nullptr};
    std::list<Reserva *> reservas = reservaControle->obterTodosAsReservas();
    Utils::imprimirListaReservas(reservas);
    std::string comando{""};
    int id{0};

    while (comando.compare("SAIR") != 0)
    {
        comando = Utils::lerStringTratada("Digite o ID para remover, LISTAR para ver as reservas e SAIR para sair ");
        if (comando.compare("LISTAR") == 0)
            Utils::imprimirListaReservas(reservas);
        else if (comando.compare("SAIR"))
        {
            id = stoi(comando);
            Reserva *reserva = reservaControle->obterReservaPorId(id);
            passageiro = reserva->getPassageiro();
            passageiro = nullptr;
            reservaControle->excluirReservaPorId(id);
        }
    }
}
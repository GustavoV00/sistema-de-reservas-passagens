#include <vector>
#include "../../includes/modelos/GerarDados.hpp"
#include "../../includes/utils/Utils.hpp"
#include "../../includes/modelos/Voo.hpp"
#include "../../includes/modelos/Passageiro.hpp"

GerarDados::GerarDados()
{
}

void GerarDados::gerarDadosVoos(VooControle *vooControle)
{
    srand((unsigned)time(NULL));
    for (unsigned int i = 0; i < 30; i++)
    {
        unsigned int id{i};
        int numeroDoVoo = Utils::geradorNumeroAleatorio();
        std::string partida = "Partida" + std::to_string(i);
        std::string chegada = "Chegada" + std::to_string(i);
        std::string data = this->gerarNovaData();

        std::string horarioPartida = this->gerarNovoHorario();
        std::string horarioChegada = this->gerarNovoHorario();
        int capacidade = this->gerarCapacidade();

        // std::cout << id << " " << numeroDoVoo << " " << partida << " " << chegada << " " << data << " " << horarioPartida << " " << horarioChegada << " " << capacidade << " " << std::endl;

        Voo *voo = new Voo{id, numeroDoVoo, partida, chegada, capacidade, data, horarioPartida, horarioChegada};
        if (!vooControle->cadastrarVoo(voo))
        {
            std::cout << "FALHA AO CADASTRAR VOO!" << std::endl;
        }
    }
}

void GerarDados::gerarDadosPassageiros(PassageiroControle *passageiroControle)
{
    srand((unsigned)time(NULL));
    for (unsigned int i = 0; i < 50; i++)
    {
        unsigned int id{i};
        std::string nome = "Passageiro" + std::to_string(i);
        CPF cpf{11111111111}; // Criar um gerador de CPF
        RG rg{111111111};     // Criar um gerador de RG
        std::string dataDeNascimento = this->gerarNovaData();
        unsigned long contato = 4199799999;
        std::string email = "email" + std::to_string(i) + "@email" + std::to_string(i) + ".com";

        // std::cout << id << " " << nome << " " << cpf.getNumero() << " " << rg.getNumero() << " " << dataDeNascimento << " " << contato << " " << email << std::endl;

        Passageiro *passageiro = new Passageiro{id, nome, cpf, rg, dataDeNascimento, contato, email};
        passageiroControle->cadastrarPassageiro(passageiro);
    }
}

void GerarDados::gerarDadosReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle)
{
    srand((unsigned)time(NULL));

    // Quantidade de voos existentes
    for (unsigned int i = 0; i < 50; i++)
    {
        unsigned int id{i};
        std::string localizador = this->gerarLocalizador(reservaControle);

        unsigned int vooAleat = (rand() % 29);
        Voo *voo = vooControle->obterVooPorId(vooAleat);
        // std::cout << "VOO: " << voo->getId() << std::endl;

        unsigned int passageiroAleat = (rand() % 49);
        Passageiro *passageiro = passageiroControle->obterPassageiroPorId(passageiroAleat);
        // std::cout << "Passageiro: " << passageiro->getId() << std::endl;

        unsigned int capacidade = voo->getCapacidade();
        std::string numeroDoAssento = this->gerarNovoNumeroDoAssento(reservaControle, capacidade);

        Reserva *reserva = new Reserva{id, localizador, passageiro, voo, numeroDoAssento};
        if (!reservaControle->cadastrarReserva(reserva))
        {
            std::cout << "Falha ao cadastrar reserva!" << std::endl;
        }
        else
        {
            // adiciona reserva na lista de reservas do voo
            try
            {
                voo->adicionarReserva(reserva);
            }
            catch (std::exception &e)
            {
                std::cout << "Falha ao adicionar reserva no voo: " << e.what() << "! Reserva não vai ser adicionada!" << std::endl;
                reservaControle->excluirReservaPorId(id);
            }
        }
    }
    // Tenho que verificar depois, a existência de assentos repetidos/passageiros repetidos ou alguma coisa assim!!!!
}

std::string GerarDados::gerarNovoNumeroDoAssento(ReservaControle *reservaControle, unsigned int capacidade)
{
    std::string letrasAssentos{"ABCD"};
    unsigned int letraAleatoria;
    unsigned int numero;

    std::string numAssento;
    std::list<Reserva *> reservas = reservaControle->obterTodosAsReservas();
    do
    {
        letraAleatoria = rand() % 4;
        numero = (rand() % 20) + 1;
        if (numero < 10)
            numAssento = "0" + std::to_string(numero) + letrasAssentos.at(letraAleatoria);
        else
            numAssento = std::to_string(numero) + letrasAssentos.at(letraAleatoria);
    } while (Reserva::buscaReservaLocalizador(numAssento, reservas) != nullptr);

    // std::cout << numAssento << std::endl;

    return numAssento;

    // std::cout << gerarNumero << " " << charAleatorio[0];
}

std::string GerarDados::gerarLocalizador(ReservaControle *reservaControle)
{
    std::string localizador = "LR" + std::to_string(Utils::geradorNumeroAleatorio());
    int cont = 0;

    std::list<Reserva *> reservas = reservaControle->obterTodosAsReservas();
    while (Reserva::buscaReservaLocalizador(localizador, reservas) != nullptr && cont < 100)
    {
        localizador = "LR" + std::to_string(Utils::geradorNumeroAleatorio());
        cont++;
    }

    // std::cout << "Criou reserva com localizador: " << localizador << std::endl;
    return localizador;
}

std::string GerarDados::gerarNovaData()
{
    unsigned int dia = (rand() % 20) + 10;
    unsigned int mes = (rand() % 10) + 1;
    unsigned int ano = (rand() % 2023);

    ano = ano < 1900 ? 1920 + rand() % 100 : ano;

    std::string data;
    if (mes < 10)
        data = std::to_string(dia) + "/" + "0" + std::to_string(mes) + "/" + std::to_string(ano);
    else
        data = std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(ano);

    // std::cout << data << std::endl;
    if (Utils::formatoData(data))
        return data;
    return "";
}

std::string GerarDados::gerarNovoHorario()
{
    unsigned int hora = (rand() % 24);
    unsigned int min = (rand() % 50) + 10;
    std::string horario;
    if (hora < 10)
        horario = "0" + std::to_string(hora) + ":" + std::to_string(min);
    else
        horario = std::to_string(hora) + ":" + std::to_string(min);

    return horario;
}

int GerarDados::gerarCapacidade()
{
    int capacidade;
    do
    {
        capacidade = (rand() % 200) + 50;
    } while ((capacidade % 4 != 0) || (capacidade <= 0) || (capacidade > 200));
    return capacidade;
}
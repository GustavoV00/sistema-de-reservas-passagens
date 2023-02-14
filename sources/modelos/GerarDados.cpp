/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include <list>
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
    for (unsigned int i = 0; i < 15; i++)
    {
        // unsigned int id{i};
        int numeroDoVoo = Utils::geradorNumeroAleatorio();
        std::string partida = "Partida" + std::to_string(i);
        std::string chegada = "Chegada" + std::to_string(i);
        std::string data = this->gerarNovaData();

        std::string horarioPartida = this->gerarNovoHorario();
        std::string horarioChegada = this->gerarNovoHorario();
        int capacidade = this->gerarCapacidade();

        Voo *voo{nullptr};
        try
        {
            voo = new Voo{numeroDoVoo, partida, chegada, capacidade, data, horarioPartida, horarioChegada};
            vooControle->cadastrarVoo(voo);
        }
        catch (std::exception &e)
        {
            std::cout << "Erro ao criar voo!" << std::endl;
        }
    }
}

void GerarDados::gerarDadosPassageiros(PassageiroControle *passageiroControle)
{
    // array com cpfs válidos aleatórios
    unsigned long arrayCpfsValidos[10] = {
        44778767853,
        27819295309,
        54888646791,
        65716284493,
        60941972089,
        56135928376,
        26113812758,
        43433414106,
        71590307704,
        73615056191};
    // array com rgs válidos aleatórios
    unsigned long arrayRgsValidos[10] = {
        322196462,
        385805147,
        216413606,
        476192821,
        214117364,
        245323594,
        322186547,
        335512434,
        470124623,
        319921414};

    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        std::string nome = "Passageiro" + std::to_string(i);
        CPF cpf{arrayCpfsValidos[i]};
        RG rg{arrayRgsValidos[i]};
        std::string dataDeNascimento = this->gerarNovaData();
        unsigned long contato = 4199799999;
        std::string email = "email" + std::to_string(i) + "@email" + std::to_string(i) + ".com";

        Passageiro *passageiro{nullptr};
        try
        {
            passageiro = new Passageiro{nome, cpf, rg, dataDeNascimento, contato, email};
            passageiroControle->cadastrarPassageiro(passageiro);
        }
        catch (std::exception &e)
        {
            std::cout << "Falha ao cadastrar passageiro!" << std::endl;
        }
    }
}

void GerarDados::gerarDadosReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle)
{
    srand((unsigned)time(NULL));

    // Quantidade de voos existentes
    for (unsigned int i = 0; i < 10; i++)
    {
        std::string localizador = this->gerarLocalizador(reservaControle);

        unsigned int vooAleat = (rand() % 14);
        Voo *voo = vooControle->obterVooPorId(vooAleat);

        unsigned int passageiroAleat = (rand() % 9);
        Passageiro *passageiro = passageiroControle->obterPassageiroPorId(passageiroAleat);

        std::string numeroDoAssento = this->gerarNovoNumeroDoAssento(reservaControle);

        try
        {
            Reserva *reserva = new Reserva{localizador, passageiro, voo, numeroDoAssento};
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
            std::cout << "Erro ao criar reserva!" << std::endl;
        }
    }
}

std::string GerarDados::gerarNovoNumeroDoAssento(ReservaControle *reservaControle)
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

    return numAssento;
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

void GerarDados::gerarListaDeAgentes(std::list<AgenteViagem *> &agentes)
{

    unsigned long arraysCpfValidos[5] = {
        53118958707,
        92893956564,
        34681867624,
        76024460201,
        91882674405};

    unsigned long arrayRgsValidos[5] = {
        149081352,
        363665213,
        320331003,
        430039888,
        317889837};

    for (unsigned int i = 0; i < 5; i++)
    {
        CPF cpfAgente{arraysCpfValidos[i]};
        RG rgAgente{arrayRgsValidos[i]};
        std::string nome = "AgenteViagem" + std::to_string(i);
        std::string data = this->gerarNovaData();
        unsigned long celular = (rand() % 99999999999) + 10000000000;
        std::string email = "email" + std::to_string(i) + "@email" + std::to_string(i) + ".com";
        std::string codigoAgente = "AV" + std::to_string(Utils::geradorNumeroAleatorio());
        agentes.push_back(new AgenteViagem{nome, cpfAgente, rgAgente, data, celular, email, codigoAgente});
    }
}
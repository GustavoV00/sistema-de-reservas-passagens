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
    std::cout << "NÃO PODE ESQUECER DE FAZER A GERAÇÃO DE UMA LISTA DE RESERVAS\n";
    for (unsigned int i = 0; i < 30; i++)
    {
        unsigned int id{i};
        unsigned int numeroDoVoo = Utils::geradorNumeroAleatorio();
        std::string partida = "Partida" + std::to_string(i);
        std::string chegada = "Chegada" + std::to_string(i);
        std::string data = this->gerarNovaData();
        if (data.compare("") == 0)
            std::cout << "Lançar alguma excessão de erro na geração da data" << std::endl;
        // Lançar exceção q deu errado

        std::string horarioPartida = this->gerarNovoHorario();
        std::string horarioChegada = this->gerarNovoHorario();
        unsigned int capacidade = this->gerarCapacidade();

        std::cout << id << " " << numeroDoVoo << " " << partida << " " << chegada << " " << data << " " << horarioPartida << " " << horarioChegada << " " << capacidade << " " << std::endl;

        Voo voo{id, numeroDoVoo, partida, chegada, capacidade, data, horarioPartida, horarioChegada};
        vooControle->cadastrarVoo(&voo);
    }
}

void GerarDados::gerarDadosPassageiros(PassageiroControle *passageiroControle)
{
    // Passageiro(const std::string &nome, const CPF &cpf, const RG &rg,
    //            const std::string &dataDeNascimento, const unsigned long &contato, const std::string &email);
    srand((unsigned)time(NULL));
    for (unsigned int i = 0; i < 30; i++)
    {
        unsigned int id{i};
        std::string nome = "Passageiro" + std::to_string(i);
        CPF cpf{11111111111}; // Criar um gerador de CPF
        RG rg{111111111};     // Criar um gerador de RG
        std::string dataDeNascimento = this->gerarNovaData();
        unsigned long contato = 4199799999;
        std::string email = "email" + std::to_string(i) + "@email" + std::to_string(i) + ".com";

        std::cout << id << " " << nome << " " << cpf.getNumero() << " " << rg.getNumero() << " " << dataDeNascimento << " " << contato << " " << email << std::endl;

        Passageiro passageiro{id, nome, cpf, rg, dataDeNascimento, contato, email};
        passageiroControle->cadastrarPassageiro(&passageiro);

        // Voo voo{id, numeroDoVoo, partida, chegada, capacidade, data, horarioPartida, horarioChegada};
        // vooControle->cadastrarVoo(&voo);
    }
}

void GerarDados::gerarDadosReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle)
{
    // Passageiro(const std::string &nome, const CPF &cpf, const RG &rg,
    //            const std::string &dataDeNascimento, const unsigned long &contato, const std::string &email);
    srand((unsigned)time(NULL));
    for (unsigned int i = 0; i < 30; i++)
    {
        unsigned int id{i};
        unsigned int passageiroAleatorio = (rand() % 30) + 1;
        unsigned int vooAleatorio = (rand() % 30) + 1;
        std::string localizador = this->gerarLocalizador(reservaControle);

        // Verificar se não existe alguma coisa errado com os dados
        // No sentido de um passageiro pertece a mais de uma reserva ou algo assim
        Passageiro *passageiro = passageiroControle->obterPassageiroPorId(passageiroAleatorio);
        Voo *voo = vooControle->obterVooPorId(vooAleatorio);
        unsigned int capacidade = voo->getCapacidade();

        // std::string numeroDoAssento = this->gerarNovoNumeroDoAssento(reservaControle, capacidade);

        // Reserva reserva{id, localizador, passageiro, voo, numeroDoAssento};
        // vooControle->cadastrarVoo(&voo);
    }
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
        // numero = (rand() % capacidade) + 1;
        numero = (rand() % 20) + 1;
        if (numero < 10)
            numAssento = "0" + std::to_string(numero) + letrasAssentos.at(letraAleatoria);
        else
            numAssento = std::to_string(numero) + letrasAssentos.at(letraAleatoria);
    } while (Reserva::buscaReservaLocalizador(numAssento, reservas) != nullptr);

    std::cout << numAssento << std::endl;

    return numAssento;

    // std::cout << gerarNumero << " " << charAleatorio[0];
}

std::string GerarDados::gerarLocalizador(ReservaControle *reservaControle)
{
    std::string localizador = "LR" + std::to_string(Utils::geradorNumeroAleatorio());
    int cont = 0;

    std::list<Reserva *> reservas = reservaControle->getReservaServico().obterTodosAsReservas();
    while (Reserva::buscaReservaLocalizador(localizador, reservas) != nullptr && cont < 100)
    {
        localizador = "LR" + std::to_string(Utils::geradorNumeroAleatorio());
        cont++;
    }

    std::cout << "Criou reserva com localizador: " << localizador << std::endl;
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

unsigned int GerarDados::gerarCapacidade()
{
    unsigned int capacidade;
    do
    {
        capacidade = (rand() % 200) + 50;
    } while (capacidade % 4 != 0);
    return capacidade;
}
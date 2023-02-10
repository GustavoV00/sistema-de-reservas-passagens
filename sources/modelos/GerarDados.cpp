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
        CPF cpf{11111111111};
        RG rg{111111111};
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

// void GerarDados::gerarDadosReservas(ReservaControle *reservaControle)
// {
//     // Passageiro(const std::string &nome, const CPF &cpf, const RG &rg,
//     //            const std::string &dataDeNascimento, const unsigned long &contato, const std::string &email);
//     srand((unsigned)time(NULL));
//     for (unsigned int i = 0; i < 30; i++)
//     {
//         unsigned int id{i};
//         std::string nome = "Passageiro" + std::to_string(i);
//         // CPF cpf{11111111111};
//         // RG rg{111111111};
//         // std::string dataDeNascimento = this->gerarNovaData();
//         // unsigned long contato = 4199799999;
//         // std::string email = "email" + std::to_string(i) + "@email" + std::to_string(i) + ".com";

//         // std::cout << id << " " << nome << " " << cpf.getNumero() << " " << rg.getNumero() << " " << dataDeNascimento << " " << contato << " " << email << std::endl;

//         // Passageiro passageiro{id, nome, cpf, rg, dataDeNascimento, contato, email};
//         // passageiroControle->cadastrarPassageiro(&passageiro);

//         // Voo voo{id, numeroDoVoo, partida, chegada, capacidade, data, horarioPartida, horarioChegada};
//         // vooControle->cadastrarVoo(&voo);
//     }
// }

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
    unsigned int capacidade = (rand() % 200) + 50;
    return capacidade;
}
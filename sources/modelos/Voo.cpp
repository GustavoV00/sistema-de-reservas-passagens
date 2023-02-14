/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include <iostream>
#include <string>

#include "../../includes/modelos/Reserva.hpp"
#include "../../includes/utils/Utils.hpp"
#include "../../includes/modelos/Voo.hpp"
#include "../../includes/exceptions/CapacidadeIncorretaException.hpp"
#include "../../includes/exceptions/FormatoInvalidoException.hpp"
#include "../../includes/exceptions/VooCheioException.hpp"

Voo::Voo(int numeroDoVoo, std::string partida, std::string destino, int capacidade, std::string data, std::string horarioPartida, std::string horarioChegada)
    : numeroDoVoo(numeroDoVoo), partida(partida), destino(destino)
{
    this->setCapacidade(capacidade);
    this->setAssentosDisponiveis(capacidade);
    this->setHorarioPartida(horarioPartida);
    this->setHorarioChegada(horarioChegada);
    this->setData(data);
}

unsigned int Voo::getId() const
{
    return this->id;
}

void Voo::setId(const unsigned int id)
{
    this->id = id;
}

int Voo::getNumeroDoVoo() const
{
    return this->numeroDoVoo;
}

void Voo::setNumeroDoVoo(const int numeroDoVoo)
{
    this->numeroDoVoo = numeroDoVoo;
}

std::string Voo::getPartida() const
{
    return this->partida;
}

void Voo::setPartida(const std::string &partida)
{
    this->partida = partida;
}

std::string Voo::getDestino() const
{
    return this->destino;
}

void Voo::setDestino(const std::string &destino)
{
    this->destino = destino;
}

std::string Voo::getHorarioPartida() const
{
    return this->horarioPartida;
}
void Voo::setHorarioPartida(const std::string &horarioPartida)
{
    if (!Utils::formatoHoraHHMM(horarioPartida))
    {
        throw FormatoInvalidoException{"Horário de partida é inválido!"};
    }
    this->horarioPartida = horarioPartida;
}

std::string Voo::getHorarioChegada() const
{
    return this->horarioChegada;
}
void Voo::setHorarioChegada(const std::string &horarioChegada)
{
    if (!Utils::formatoHoraHHMM(horarioChegada))
    {
        throw FormatoInvalidoException{"Horário de chegada é inválido!"};
    }
    this->horarioChegada = horarioChegada;
}

std::string Voo::getData() const
{
    return this->data;
}

void Voo::setData(const std::string &data)
{
    if (!Utils::formatoData(data))
    {
        throw FormatoInvalidoException{"Data é inválida!"};
    }
    this->data = data;
}

int Voo::getCapacidade() const
{
    return this->capacidade;
}

void Voo::setCapacidade(const int capacidade)
{
    if ((capacidade < 20) || ((capacidade % 4) != 0) || (capacidade > 200))
    {
        throw CapacidadeIncorretaException{"Capacidade inválida!", capacidade};
    }
    this->capacidade = capacidade;
}

int Voo::getAssentosDisponiveis() const
{
    return this->assentosDisponiveis;
}

void Voo::setAssentosDisponiveis(const int &assentosDisponiveis)
{
    this->assentosDisponiveis = assentosDisponiveis;
}

std::list<Reserva *> &Voo::getReservas()
{
    return this->reservas;
}

void Voo::setReservas(std::list<Reserva *> reservas)
{
    this->reservas = reservas;
}

void Voo::imprimirDadosVoo()
{
    std::cout << "=================================================================================" << std::endl;
    std::cout << "Número: " << this->getNumeroDoVoo() << std::endl;
    std::cout << "Partida: " << this->getPartida() << std::endl;
    std::cout << "Destino: " << this->getDestino() << std::endl;
    std::cout << "Data: " << this->getData() << std::endl;
    std::cout << "Horário de Partida: " << this->getHorarioPartida() << std::endl;
    std::cout << "Horário de Chegada: " << this->getHorarioChegada() << std::endl;
    std::cout << "Capacidade: " << this->getCapacidade() << std::endl;
    std::cout << "Assentos Disponíveis: " << this->getAssentosDisponiveis() << std::endl;
    std::cout << "=================================================================================" << std::endl;
}

void Voo::adicionarReserva(Reserva *reserva)
{
    if (this->assentosDisponiveis <= 0)
    {
        throw VooCheioException("Voo já está cheio!");
    }
    this->reservas.push_back(reserva);
    this->assentosDisponiveis = (this->assentosDisponiveis - 1);
}

void Voo::removerReserva(Reserva *reserva)
{
    this->reservas.remove(reserva);
    this->assentosDisponiveis = (this->assentosDisponiveis + 1);
}

std::ostream &operator<<(std::ostream &stream, const Voo &voo)
{
    stream << "=================================================================================" << std::endl;
    stream << "Número: " << voo.getNumeroDoVoo() << std::endl;
    stream << "Partida: " << voo.getPartida() << std::endl;
    stream << "Destino: " << voo.getDestino() << std::endl;
    stream << "Data: " << voo.getData() << std::endl;
    stream << "Horário de Partida: " << voo.getHorarioPartida() << std::endl;
    stream << "Horário de Chegada: " << voo.getHorarioChegada() << std::endl;
    stream << "Capacidade: " << voo.getCapacidade() << std::endl;
    stream << "Assentos Disponíveis: " << voo.getAssentosDisponiveis() << std::endl;
    stream << "=================================================================================" << std::endl;
    return stream;
}
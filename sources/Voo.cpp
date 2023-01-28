/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#include <string>

// #include "./../includes/Reserva.hpp"
// #include "./../includes/Passageiro.hpp"
#include "./../includes/Voo.hpp"

Voo::Voo(std::string numeroDoVoo, std::string partida, std::string destino, int capacidade) : numeroDoVoo(numeroDoVoo), partida(partida), destino(destino), capacidade(capacidade)
{
}

std::string Voo::getNumeroDoVoo() const
{
    return this->numeroDoVoo;
}

std::string Voo::getPartida() const
{
    return this->partida;
}

std::string Voo::getDestino() const
{
    return this->destino;
}

int Voo::getCapacidade() const
{
    return this->capacidade;
}

int Voo::getAssentosDisponiveis() const
{
    return this->assentosDisponiveis;
}

std::list<Reserva *> Voo::getReservas() const
{
    return this->reservas;
}

void Voo::setPartida(std::string partida)
{
    this->partida = partida;
}

void Voo::setDestino(std::string destino)
{
    this->destino = destino;
}

void Voo::setCapacidade(int capacidade)
{
    this->capacidade = capacidade;
}

void Voo::setAssentosDisponiveis(int assentosDisponiveis)
{
    this->assentosDisponiveis = assentosDisponiveis;
}

void Voo::setReservas(std::list<Reserva *> reservas)
{
    this->reservas = reservas;
}

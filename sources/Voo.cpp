/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#include <iostream>
#include <string>

// #include "./../includes/Reserva.hpp"
// #include "./../includes/Passageiro.hpp"
#include "./../includes/Voo.hpp"
#include "./../includes/CapacidadeIncorretaException.hpp"

Voo::Voo(std::string numeroDoVoo, std::string partida, std::string destino, int capacidade) : numeroDoVoo(numeroDoVoo), partida(partida), destino(destino){
    this->setCapacidade(capacidade);
    this->setAssentosDisponiveis(capacidade);
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
    if(capacidade > 0 && capacidade % 4 != 0){
        throw CapacidadeIncorretaException{"Capacidade inválida!", capacidade};
    }
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

void Voo::imprimirDadosVoo(){
    std::cout << "=================================================================================" << std::endl;
    std::cout << "Número: " << this->getNumeroDoVoo() << std::endl;
    std::cout << "Partida: " << this->getPartida() << std::endl;
    std::cout << "Destino: " << this->getDestino() << std::endl;
    std::cout << "Capacidade: " << this->getCapacidade() << std::endl;
    std::cout << "Assentos Disponíveis: " << this->getAssentosDisponiveis() << std::endl;
}

void Voo::imprimirMapaDeAssentos() {
    std::cout << std::endl << "Mapa de assentos: " << std::endl;
    for(int i = 1; i <= (int) this->getCapacidade()/4; i++){
        std::cout << "[" << i << "A]";
        std::cout << "[" << i << "B]";
        std::cout << "  ";
        std::cout << "[" << i << "C]";
        std::cout << "[" << i << "D]";
        std::cout << std::endl;
    }
}
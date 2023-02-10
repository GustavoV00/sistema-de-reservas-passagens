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

Voo::Voo(unsigned int id, unsigned int numeroDoVoo, std::string partida, std::string destino, unsigned int capacidade, std::string data, std::string horarioPartida, std::string horarioChegada)
    : numeroDoVoo(numeroDoVoo), partida(partida), destino(destino)
{
    this->setCapacidade(capacidade);
    this->setAssentosDisponiveis(capacidade);
    this->setHorarioPartida(horarioPartida);
    this->setHorarioChegada(horarioChegada);
    this->setData(data);
}

unsigned int Voo::getId()
{
    return this->id;
}

unsigned int Voo::getNumeroDoVoo() const
{
    return this->numeroDoVoo;
}

void Voo::setNumeroDoVoo(const unsigned int numeroDoVoo)
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

void Voo::setCapacidade(const unsigned int capacidade)
{
    // if (capacidade > 20 && (capacidade % 4) != 0 && capacidade < 400)
    // {
    //     throw CapacidadeIncorretaException{"Capacidade inválida!", capacidade};
    // }
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

std::list<Reserva *> Voo::getReservas() const
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
    std::cout << "Capacidade: " << this->getCapacidade() << std::endl;
    std::cout << "Assentos Disponíveis: " << this->getAssentosDisponiveis() << std::endl;
}

void Voo::imprimirMapaDeAssentos()
{

    std::list<std::string> assentosOcupados;
    std::list<Reserva *>::iterator it;
    for (it = (this->reservas.begin()); it != (this->reservas.end()); it++)
    {
        std::cout << "ADICIONANDO " << (*it)->getNumeroDoAssento() << " NA LISTA DE ASSENTOS OCUPADOS..." << std::endl;
        ;
        assentosOcupados.push_back((*it)->getNumeroDoAssento());
    }

    std::string assento;

    std::cout << std::endl
              << "Mapa de assentos: " << std::endl;
    for (int i = 1; i <= (int)this->getCapacidade() / 4; i++)
    {
        if (i < 10)
        {
            assento = "0" + std::to_string(i) + "A";
            if (Utils::assentoOcupado(assento, assentosOcupados))
            {
                std::cout << "[XXX]";
            }
            else
            {
                std::cout << "[" << assento << "]";
            }

            assento = "0" + std::to_string(i) + "B";
            if (Utils::assentoOcupado(assento, assentosOcupados))
            {
                std::cout << "[XXX]";
            }
            else
            {
                std::cout << "[" << assento << "]";
            }
        }
        else
        {
            assento = std::to_string(i) + "A";
            if (Utils::assentoOcupado(assento, assentosOcupados))
            {
                std::cout << "[XXX]";
            }
            else
            {
                std::cout << "[" << assento << "]";
            }

            assento = std::to_string(i) + "B";
            if (Utils::assentoOcupado(assento, assentosOcupados))
            {
                std::cout << "[XXX]";
            }
            else
            {
                std::cout << "[" << assento << "]";
            }
        }
        std::cout << "  ";
        if (i < 10)
        {
            assento = "0" + std::to_string(i) + "C";
            if (Utils::assentoOcupado(assento, assentosOcupados))
            {
                std::cout << "[XXX]";
            }
            else
            {
                std::cout << "[" << assento << "]";
            }

            assento = "0" + std::to_string(i) + "D";
            if (Utils::assentoOcupado(assento, assentosOcupados))
            {
                std::cout << "[XXX]";
            }
            else
            {
                std::cout << "[" << assento << "]";
            }
        }
        else
        {
            assento = std::to_string(i) + "C";
            if (Utils::assentoOcupado(assento, assentosOcupados))
            {
                std::cout << "[XXX]";
            }
            else
            {
                std::cout << "[" << assento << "]";
            }

            assento = std::to_string(i) + "D";
            if (Utils::assentoOcupado(assento, assentosOcupados))
            {
                std::cout << "[XXX]";
            }
            else
            {
                std::cout << "[" << assento << "]";
            }
        }

        std::cout << std::endl;
    }
}

void Voo::adicionarReserva(Reserva *reserva)
{
    this->reservas.push_back(reserva);
}
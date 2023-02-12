/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include <iostream>
#include "../../includes/modelos/Reserva.hpp"
#include "../../includes/modelos/Passageiro.hpp"
#include "../../includes/modelos/Voo.hpp"

Reserva::Reserva(unsigned int id, std::string &localizador, Passageiro *passageiro, Voo *voo, std::string numeroDoAssento)
    : id{id}, localizador{localizador}, passageiro{passageiro}, voo{voo}, numeroDoAssento{numeroDoAssento}
{
}

unsigned long Reserva::getId()
{
    return this->id;
}

void Reserva::setId(unsigned long id)
{
    this->id = id;
}

std::string Reserva::getLocalizador() const
{
    return this->localizador;
}

void Reserva::setLocalizador(const std::string &localizador)
{
    this->localizador = localizador;
}

Passageiro *Reserva::getPassageiro() const
{
    return this->passageiro;
}
void Reserva::setPassageiro(Passageiro *passageiro)
{
    this->passageiro = passageiro;
}

Voo *Reserva::getVoo()
{
    return this->voo;
}
void Reserva::setVoo(Voo *voo)
{
    this->voo = voo;
}

std::string Reserva::getNumeroDoAssento() const
{
    return this->numeroDoAssento;
}
void Reserva::setNumeroDoAssento(const std::string &numeroDoAssento)
{
    this->numeroDoAssento = numeroDoAssento;
}

void Reserva::imprimirDadosReserva()
{
    std::cout << "=============================================================================================================================" << std::endl;
    std::cout << "Código: " << this->getLocalizador() << std::endl;
    std::cout << "Passageiro: " << this->getPassageiro()->getNome() << " - Email: " << this->getPassageiro()->getEmail()
              << " - CPF: " << this->getPassageiro()->getCpf().getNumero() << std::endl;
    std::cout << "Voo: " << this->getVoo()->getNumeroDoVoo() << " - Partida: " << this->getVoo()->getPartida() << " - Destino: " << this->getVoo()->getDestino() << " - Data: " << this->getVoo()->getData() << " - Horário Partida: " << this->getVoo()->getHorarioPartida() << " - Horário Chegada: " << this->getVoo()->getHorarioChegada() << std::endl;
    std::cout << "Assento: " << this->getNumeroDoAssento() << std::endl;
    // std::cout << "=================================================================================" << std::endl;
}

Reserva *Reserva::verificaSeAssentoExiste(const std::string &numAssento, std::list<Reserva *> reservas)
{
    std::list<Reserva *>::iterator it{reservas.begin()};
    for (; it != reservas.end(); it++)
    {
        if ((*it)->getLocalizador().compare(numAssento) == 0)
        {
            return (*it);
        }
    }
    return nullptr;
}

Reserva *Reserva::buscaReservaLocalizador(const std::string &localizador, std::list<Reserva *> reservas)
{
    std::list<Reserva *>::iterator it{reservas.begin()};
    for (; it != reservas.end(); it++)
    {
        if ((*it)->getLocalizador().compare(localizador) == 0)
        {
            return (*it);
        }
    }
    return nullptr;
}

/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include <string>
#include <iostream>
#include <list>

#include "../../includes/modelos/Reserva.hpp"
#include "../../includes/controles/ReservaControle.hpp"
#include "../../includes/repositorios/ReservaRepositorio.hpp"

ReservaControle::ReservaControle()
{
}

ReservaRepositorio ReservaControle::getReservaRepositorio() const
{
    return this->reservaRepositorio;
}

std::list<Reserva *> &ReservaControle::obterTodosAsReservas()
{
    return this->reservaRepositorio.getReservas();
}

Reserva *ReservaControle::obterReservaPorId(int id)
{
    std::list<Reserva *> reservas = this->reservaRepositorio.getReservas();
    std::list<Reserva *>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); ++it)
    {
        if ((*it)->getId() == id)
            return *it;
    }

    return nullptr;
}

Reserva *ReservaControle::obterReservaPorLocalizador(std::string &localizador)
{
    std::list<Reserva *> reservas = this->reservaRepositorio.getReservas();
    std::list<Reserva *>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); ++it)
    {
        if ((*it)->getLocalizador() == localizador)
            return *it;
    }

    return nullptr;
}

bool ReservaControle::cadastrarReserva(Reserva *reserva)
{
    try
    {
        reserva->setId(this->reservaRepositorio.getNewId());
        this->reservaRepositorio.getReservas().push_back(reserva);
        std::cout << "Sucesso ao cadastrar reserva! ID: [" << reserva->getId() << "]" << std::endl;
        return true;
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao adicionar reserva no bd: " << e.what() << std::endl;
        return false;
    }
}

bool ReservaControle::excluirReservaPorLocalizador(std::string &localizador)
{
    std::list<Reserva *>::iterator it{this->reservaRepositorio.getReservas().begin()};
    while (it != this->reservaRepositorio.getReservas().end())
    {
        if ((*it)->getLocalizador() == localizador)
        {
            std::cout << "Removendo reserva do voo " << std::endl;
            (*it)->getVoo()->removerReserva(*it);
            this->reservaRepositorio.getReservas().erase(it);
            delete *it;
            return true;
        }
        it++;
    }
    return false;
}

std::list<Reserva *> ReservaControle::obterReservasDoPassageiro(Usuario *usuario)
{
    std::list<Reserva *> reservas = this->obterTodosAsReservas();
    std::list<Reserva *> reservasUsuario;
    std::list<Reserva *>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); ++it)
    {
        if ((*it)->getPassageiro() == usuario)
        {
            reservasUsuario.push_back((*it));
        }
    }
    return reservasUsuario;
}

Passageiro *ReservaControle::obterPassageiroDasReservas(std::list<Reserva *> &reservas)
{
    std::list<Reserva *>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); ++it)
    {
        return (*it)->getPassageiro();
    }
    return nullptr;
}
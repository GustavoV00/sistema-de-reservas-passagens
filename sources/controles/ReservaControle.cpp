

#include <string>
#include <iostream>
#include <list>

#include "../../includes/modelos/Reserva.hpp"
#include "../../includes/controles/ReservaControle.hpp"
#include "../../includes/repositorios/ReservaRepositorio.hpp"

ReservaControle::ReservaControle()
{
    ReservaRepositorio *reservaRepositorio = new ReservaRepositorio{};
    this->reservaRepositorio = reservaRepositorio;
}

// ReservaControle::ReservaControle(const ReservaRepositorio reservaRepositorio)
//     : reservaRepositorio{reservaRepositorio}
// {
// }

ReservaRepositorio *ReservaControle::getReservaRepositorio()
{
    return this->reservaRepositorio;
}

// void ReservaControle::setReservaRepositorio(const ReservaRepositorio reservaRepositorio)
// {
//     this->reservaRepositorio = reservaRepositorio;
// }

std::list<Reserva *> &ReservaControle::obterTodosAsReservas()
{
    return this->getReservaRepositorio()->getReservas();
}

Reserva *ReservaControle::obterReservaPorId(const unsigned long id)
{
    std::list<Reserva *> reservas = this->getReservaRepositorio()->getReservas();
    std::list<Reserva *>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); ++it)
    {
        // Testar isso aqui mais tarde!!!
        std::cout << *it << std::endl;
        if ((*it)->getId() == id)
            return *it;
    }

    return nullptr;
}

bool ReservaControle::atualizarReservaPorId(unsigned long id, Reserva reservaNova)
{
    try
    {
        // Reserva *reserva = this->obterReservaPorId(id);
        // reserva = &reservaNova;
        return true;
    }
    catch (std::exception &e)
    {
        std::cout << "Reserva não existe ou o id está errado: " << e.what() << std::endl;
    }
    return false;
}

bool ReservaControle::cadastrarReserva(Reserva *reserva)
{
    try
    {
        this->getReservaRepositorio()->getReservas().push_back(reserva);
        std::cout << "Sucesso ao cadastrar reserva!" << std::endl;
        return true;
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao adicionar reserva no bd: " << e.what() << std::endl;
        return false;
    }
}

bool ReservaControle::excluirReservaPorId(const unsigned int id)
{
    std::list<Reserva *>::iterator it{this->reservaRepositorio->getReservas().begin()};
    while (it != this->reservaRepositorio->getReservas().end())
    {
        // std::cout << (*it)->getNumeroDoVoo() << std::endl;
        if ((*it)->getId() == id)
        {
            // voos.erase(it);
            this->reservaRepositorio->getReservas().erase(it);
            delete *it;
            return true;
        }
        it++;
    }
    return false;
}
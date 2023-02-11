
// #include "../../includes/controles/ReservaControle.hpp"

// ReservaControle::ReservaControle()
// {
//     ReservaControle *reservaControle = new ReservaControle{};
//     this->reservaControle = reservaControle;
// }

// // ReservaControle::ReservaControle(const ReservaControle reservaControle)
// //     : reservaControle{reservaControle}
// // {
// // }

// ReservaControle *ReservaControle::getReservaControle()
// {
//     return this->reservaControle;
// }

// // void ReservaControle::setReservaControle(ReservaControle *ReservaControle)
// // {
// //     this->reservaControle = ReservaControle;
// // }

// std::list<Reserva *> ReservaControle::obterTodosAsReservas()
// {
//     return this->getReservaControle()->obterTodosAsReservas();
// }

// Reserva *ReservaControle::obterReservaPorId(const unsigned long id)
// {
//     return this->getReservaControle()->obterReservaPorId(id);
// }

// bool ReservaControle::atualizarReservaPorId(unsigned long id, Reserva novaReserva)
// {
//     return this->getReservaControle()->atualizarReservaPorId(id, novaReserva);
// }

// bool ReservaControle::cadastrarReserva(Reserva *reserva)
// {
//     return this->getReservaControle()->cadastrarReserva(reserva);
// }

// bool ReservaControle::excluirReservaPorId(const unsigned long id)
// {
//     return this->getReservaControle()->excluirReservaPorId(id);
// }

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

bool ReservaControle::excluirReservaPorId(const unsigned long id)
{
    std::list<Reserva *> reservas = this->getReservaRepositorio()->getReservas();
    std::list<Reserva *>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); ++it)
    {
        // Testar isso aqui mais tarde!!!
        // isso aqui funciona ? Muito suspeito. Preciso testar com cuidado mais tarde
        std::cout << *it << std::endl;
        if ((*it)->getId() == id)
        {
            delete *it;
            reservas.erase(it);
            return true;
        }
    }
    return false;
}

#include <string>
#include <iostream>
#include <list>

#include "../../includes/modelos/Reserva.hpp"
#include "../../includes/servicos/ReservaServico.hpp"
#include "../../includes/repositorios/ReservaRepositorio.hpp"

ReservaServico::ReservaServico()
{
    ReservaRepositorio *reservaRepositorio = new ReservaRepositorio{};
    this->reservaRepositorio = reservaRepositorio;
}

// ReservaServico::ReservaServico(const ReservaRepositorio reservaRepositorio)
//     : reservaRepositorio{reservaRepositorio}
// {
// }

ReservaRepositorio *ReservaServico::getReservaRepositorio()
{
    return this->reservaRepositorio;
}

// void ReservaServico::setReservaRepositorio(const ReservaRepositorio reservaRepositorio)
// {
//     this->reservaRepositorio = reservaRepositorio;
// }

std::list<Reserva *> &ReservaServico::obterTodosAsReservas()
{
    return this->getReservaRepositorio()->getReservas();
}

Reserva *ReservaServico::obterReservaPorId(const unsigned long id)
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

bool ReservaServico::atualizarReservaPorId(unsigned long id, Reserva reservaNova)
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

bool ReservaServico::cadastrarReserva(Reserva *reserva)
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

bool ReservaServico::excluirReservaPorId(const unsigned long id)
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
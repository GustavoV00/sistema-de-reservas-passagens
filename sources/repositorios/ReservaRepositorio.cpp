
#include "../../includes/repositorios/ReservaRepositorio.hpp"

ReservaRepositorio::ReservaRepositorio(const std::list<Reserva *> &reserva)
    : reservas{reserva}
{
}

ReservaRepositorio::~ReservaRepositorio()
{
}

std::list<Reserva *> ReservaRepositorio::getReservas()
{
    return this->reservas;
}

void ReservaRepositorio::setReservas(std::list<Reserva *> reservas)
{
    this->reservas = reservas;
}
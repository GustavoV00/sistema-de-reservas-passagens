
#include "../../includes/repositorios/ReservaRepositorio.hpp"

ReservaRepositorio::ReservaRepositorio()
{
}

ReservaRepositorio::~ReservaRepositorio()
{
}

std::list<Reserva *> &ReservaRepositorio::getReservas()
{
    return this->reservas;
}

unsigned int ReservaRepositorio::getNewId()
{

    this->lastId += 1;
    return this->lastId;
}

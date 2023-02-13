
#include "../../includes/repositorios/ReservaRepositorio.hpp"

ReservaRepositorio::ReservaRepositorio()
{
    this->lastId = -1;
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

/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include "../../includes/repositorios/ReservaRepositorio.hpp"

ReservaRepositorio::ReservaRepositorio()
{
    this->lastId = -1;
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

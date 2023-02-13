#include "../../includes/repositorios/PassageiroRepositorio.hpp"

PassageiroRepositorio::PassageiroRepositorio()
{
    this->lastId = -1;
}

PassageiroRepositorio::~PassageiroRepositorio()
{
}

std::list<Passageiro *> &PassageiroRepositorio::getPassageiros()
{
    return this->passageiros;
}

unsigned int PassageiroRepositorio::getNewId()
{
    this->lastId += 1;
    return this->lastId;
}
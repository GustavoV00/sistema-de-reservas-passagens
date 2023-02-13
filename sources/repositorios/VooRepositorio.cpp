#include <iostream>
#include "../../includes/repositorios/VooRepositorio.hpp"

VooRepositorio::VooRepositorio()
{
    this->lastId = -1;
}

std::list<Voo *> &VooRepositorio::getVoos()
{
    return this->voos;
}

unsigned int VooRepositorio::getNewId()
{
    this->lastId += 1;
    return this->lastId;
}

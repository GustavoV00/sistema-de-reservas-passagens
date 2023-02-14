/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include <iostream>
#include "../../includes/repositorios/VooRepositorio.hpp"

VooRepositorio::VooRepositorio()
{
    this->lastId = -1;
}

VooRepositorio::~VooRepositorio()
{
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

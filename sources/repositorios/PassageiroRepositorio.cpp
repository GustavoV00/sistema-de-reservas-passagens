/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include <iostream>
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
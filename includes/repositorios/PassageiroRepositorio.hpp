#ifndef PASSAGEIROREPOSITORIO_H
#define PASSAGEIROREPOSITORIO_H

#include <string>
#include <list>
#include "../modelos/Passageiro.hpp"

class PassageiroRepositorio
{
public:
    PassageiroRepositorio();
    ~PassageiroRepositorio();

    std::list<Passageiro *> &getPassageiros();

    unsigned int getNewId();

private:
    std::list<Passageiro *> passageiros;
    unsigned int lastId;
};
#endif
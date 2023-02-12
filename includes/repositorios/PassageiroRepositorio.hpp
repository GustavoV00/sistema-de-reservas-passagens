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

private:
    std::list<Passageiro *> passageiros;
};
#endif
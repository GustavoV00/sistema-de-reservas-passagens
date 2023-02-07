#ifndef PASSAGEIROREPOSITORIO_H
#define PASSAGEIROREPOSITORIO_H

#include <string>
#include <list>
#include "../modelos/Passageiro.hpp"

class PassageiroRepositorio
{
public:
    PassageiroRepositorio(const std::list<Passageiro *> &passageiro);
    ~PassageiroRepositorio();

    std::list<Passageiro *> getPassageiros();
    void setPassageiros(std::list<Passageiro *>);

private:
    std::list<Passageiro *> passageiros;
};
#endif
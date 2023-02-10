#include "../../includes/repositorios/PassageiroRepositorio.hpp"

PassageiroRepositorio::PassageiroRepositorio()
{
}

PassageiroRepositorio::PassageiroRepositorio(const std::list<Passageiro *> &passageiro)
    : passageiros{passageiro}
{
}

PassageiroRepositorio::~PassageiroRepositorio()
{
}

std::list<Passageiro *> PassageiroRepositorio::getPassageiros()
{
    return this->passageiros;
}

void PassageiroRepositorio::setPassageiros(std::list<Passageiro *> passageiros)
{
    this->passageiros = passageiros;
}
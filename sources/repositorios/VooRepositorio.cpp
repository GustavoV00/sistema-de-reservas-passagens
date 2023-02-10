#include "../../includes/repositorios/VooRepositorio.hpp"

VooRepositorio::VooRepositorio()
{
}

VooRepositorio::VooRepositorio(const std::list<Voo *> &voo)
    : voos{voo}
{
}

VooRepositorio::~VooRepositorio()
{
}

std::list<Voo *> VooRepositorio::getVoos()
{
    return this->voos;
}

void VooRepositorio::setVoos(std::list<Voo *> voos)
{
    this->voos = voos;
}
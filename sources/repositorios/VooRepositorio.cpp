#include <iostream>
#include "../../includes/repositorios/VooRepositorio.hpp"

VooRepositorio::VooRepositorio()
{
}

// VooRepositorio::VooRepositorio(std::list<Voo *> voos)
//     : voos{voos}
// {
//     std::cout << "Criou lista com tam " << (*voos).size() << std::endl;
//     // volta como tava ?
// }

VooRepositorio::~VooRepositorio()
{
}

std::list<Voo *> &VooRepositorio::getVoos()
{
    return this->voos;
}

void VooRepositorio::setVoos(std::list<Voo *> &voos)
{
    this->voos = voos;
}
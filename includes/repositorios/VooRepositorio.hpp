#ifndef VOOREPOSITORIO_H
#define VOOREPOSITORIO_H

#include <string>
#include "../modelos/Voo.hpp"

class VooRepositorio
{
public:
    VooRepositorio();
    VooRepositorio(const std::list<Voo *> &voo);
    ~VooRepositorio();

    std::list<Voo *> getVoos();
    void setVoos(std::list<Voo *>);

private:
    std::list<Voo *> voos;
};
#endif
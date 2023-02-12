#ifndef VOOREPOSITORIO_H
#define VOOREPOSITORIO_H

#include <string>
#include "../modelos/Voo.hpp"

class VooRepositorio
{
public:
    VooRepositorio();
    ~VooRepositorio() = default;

    std::list<Voo *> &getVoos();

    unsigned int getNewId();

private:
    std::list<Voo *> voos;
    unsigned int lastId;
};
#endif
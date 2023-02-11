#ifndef VOOREPOSITORIO_H
#define VOOREPOSITORIO_H

#include <string>
#include "../modelos/Voo.hpp"

class VooRepositorio
{
public:
    VooRepositorio();
    // VooRepositorio(std::list<Voo *> *voos);
    ~VooRepositorio();

    std::list<Voo *> &getVoos();
    void setVoos(std::list<Voo *> &voos);

private:
    std::list<Voo *> voos;
};
#endif
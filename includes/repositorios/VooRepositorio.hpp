/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef VOO_REPOSITORIO_H
#define VOO_REPOSITORIO_H

#include <string>
#include "../modelos/Voo.hpp"

class VooRepositorio
{
public:
    VooRepositorio();
    ~VooRepositorio();

    std::list<Voo *> &getVoos();

    unsigned int getNewId();

private:
    std::list<Voo *> voos;
    unsigned int lastId;
};
#endif
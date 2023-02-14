/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef RESERVA_REPOSITORIO_H
#define RESERVA_REPOSITORIO_H

#include <string>
#include "../modelos/Voo.hpp"

class ReservaRepositorio
{
public:
    ReservaRepositorio();
    ~ReservaRepositorio() = default;

    std::list<Reserva *> &getReservas();
    unsigned int getNewId();

private:
    std::list<Reserva *> reservas;
    unsigned int lastId;
};
#endif
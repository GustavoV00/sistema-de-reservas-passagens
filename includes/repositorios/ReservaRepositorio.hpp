#ifndef RESERVAREPOSITORIO_H
#define RESERVAREPOSITORIO_H

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
#ifndef RESERVAREPOSITORIO_H
#define RESERVAREPOSITORIO_H

#include <string>
#include "../modelos/Voo.hpp"

class ReservaRepositorio
{
public:
    ReservaRepositorio();
    // ReservaRepositorio(const std::list<Reserva *> &reserva);
    ~ReservaRepositorio();

    std::list<Reserva *> &getReservas();

private:
    std::list<Reserva *> reservas;
};
#endif
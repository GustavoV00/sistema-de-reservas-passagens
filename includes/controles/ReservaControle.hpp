#ifndef RESERVACONTROLE_H
#define RESERVACONTROLE_H

#include "../servicos/ReservaServico.hpp"
#include "../modelos/Reserva.hpp"

#include <string>

class ReservaControle
{

public:
    ReservaControle();
    // ReservaControle(const ReservaServico reservaServico);
    ~ReservaControle() = default;
    // void setReservaServico(ReservaServico *reservaServico);

    ReservaRepositorio *getReservaRepositorio();

    std::list<Reserva *> &obterTodosAsReservas();
    Reserva *obterReservaPorId(const unsigned long id);
    bool atualizarReservaPorId(unsigned long id, Reserva reservaNovo);
    bool cadastrarReserva(Reserva *Reserva);
    bool excluirReservaPorId(const unsigned long id);

private:
    ReservaRepositorio *reservaRepositorio;
};

#endif
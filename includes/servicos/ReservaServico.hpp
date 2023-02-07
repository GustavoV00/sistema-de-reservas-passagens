#ifndef RESERVASERVICO_H
#define RESERVASERVICO_H

#include "../repositorios/ReservaRepositorio.hpp"

class ReservaServico
{

public:
    ReservaServico(const ReservaRepositorio reservaRepositorio);
    virtual ~ReservaServico() = default;

    ReservaRepositorio getReservaRepositorio();
    void setReservaRepositorio(const ReservaRepositorio reservaRepositorio);

    std::list<Reserva *> obterTodosAsReservas();
    Reserva *obterReservaPorId(const unsigned long id);
    bool atualizarReservaPorId(unsigned long id, Reserva reservaNova);
    bool cadastrarReserva(Reserva *reserva);
    bool excluirReservaPorId(const unsigned long id);

private:
    ReservaRepositorio reservaRepositorio;
};

#endif
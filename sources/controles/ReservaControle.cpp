
#include "../../includes/controles/ReservaControle.hpp"

ReservaControle::ReservaControle(const ReservaServico reservaServico)
    : reservaServico{reservaServico}
{
}

ReservaControle::~ReservaControle()
{
}

ReservaServico ReservaControle::getReservaServico()
{
    return this->reservaServico;
}

void ReservaControle::setReservaServico(ReservaServico ReservaServico)
{
    this->reservaServico = ReservaServico;
}

std::list<Reserva *> ReservaControle::obterTodosAsReservas()
{
    return this->getReservaServico().obterTodosAsReservas();
}

Reserva *ReservaControle::obterReservaPorId(const unsigned long id)
{
    return this->getReservaServico().obterReservaPorId(id);
}

bool ReservaControle::atualizarReservaPorId(unsigned long id, Reserva novaReserva)
{
    return this->getReservaServico().atualizarReservaPorId(id, novaReserva);
}

bool ReservaControle::cadastrarReserva(Reserva *reserva)
{
    return this->getReservaServico().cadastrarReserva(reserva);
}

bool ReservaControle::excluirReservaPorId(const unsigned long id)
{
    return this->getReservaServico().excluirReservaPorId(id);
}
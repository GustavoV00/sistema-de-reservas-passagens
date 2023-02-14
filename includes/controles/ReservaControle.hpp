#ifndef RESERVA_CONTROLE_H
#define RESERVA_CONTROLE_H

#include "../repositorios/ReservaRepositorio.hpp"
#include "../modelos/Reserva.hpp"

#include <string>

class ReservaControle
{

public:
    ReservaControle();
    ~ReservaControle() = default;

    ReservaRepositorio getReservaRepositorio() const;

    std::list<Reserva *> &obterTodosAsReservas();
    Reserva *obterReservaPorId(int id);
    Reserva *obterReservaPorLocalizador(std::string &localizador);
    bool cadastrarReserva(Reserva *Reserva);
    bool excluirReservaPorLocalizador(std::string &localizador);
    std::list<Reserva *> obterReservasDoPassageiro(Usuario *usuario);
    Passageiro *obterPassageiroDasReservas(std::list<Reserva *> &reservas);

private:
    ReservaRepositorio reservaRepositorio;
};

#endif
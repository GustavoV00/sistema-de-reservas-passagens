/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
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
    std::list<Reserva *> obterReservasDoPassageiro(Usuario *usuario);
    Passageiro *obterPassageiroDasReservas(std::list<Reserva *> &reservas);
    bool excluirReservaPorLocalizador(std::string &localizador);

private:
    ReservaRepositorio reservaRepositorio;
};

#endif
#ifndef RESERVA_HPP
#define RESERVA_HPP

#include <string>
#include "Voo.hpp"
#include "Passageiro.hpp"

class Reserva
{
private:
    Passageiro passageiro;
    Voo voo;
    int numeroDoAssento;

public:
    // Construtores
    Reserva(Passageiro passageiro, Voo voo, int numeroDoAssento);

    // getters
    Passageiro getPassageiro() const;
    Voo getVoo() const;
    int getNumeroDoAssento() const;

    // setters
    void setPassageiro(Passageiro passageiro);
    void setVoo(Voo voo);
    void setNumeroDoAssento(int numeroDoAssento);
};

#endif
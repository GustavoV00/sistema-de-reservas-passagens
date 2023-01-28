
#include "./../includes/Reserva.hpp"
#include "./../includes/Passageiro.hpp"
#include "./../includes/Voo.hpp"

Reserva::Reserva(Passageiro passageiro, Voo voo, int numeroDoAssento) : passageiro(passageiro), voo(voo), numeroDoAssento(numeroDoAssento)
{
}

Passageiro Reserva::getPassageiro() const
{
    return this->passageiro;
}

Voo Reserva::getVoo() const
{
    return this->voo;
}

int Reserva::getNumeroDoAssento() const
{
    return this->numeroDoAssento;
}

void Reserva::setPassageiro(Passageiro passageiro)
{
    this->passageiro = passageiro;
}

void Reserva::setVoo(Voo voo)
{
    this->voo = voo;
}

void Reserva::setNumeroDoAssento(int numeroDoAssento)
{
    this->numeroDoAssento = numeroDoAssento;
}

#ifndef VOO_H
#define VOO_H

#include <string>
#include <list>

#include "Reserva.hpp"

class Voo
{

public:
    // constructor
    Voo(std::string numeroDoVoo, std::string partida, std::string destino, int capacidade);

    // getters
    std::string getNumeroDoVoo() const;
    std::string getPartida() const;
    std::string getDestino() const;
    int getCapacidade() const;
    int getAssentosDisponiveis() const;
    std::list<Reserva *> getReservas() const;

    // setters
    void setPartida(std::string partida);
    void setDestino(std::string destino);
    void setCapacidade(int capacidade);
    void setAssentosDisponiveis(int assentosDisponiveis);
    void setReservas(std::list<Reserva *> reservas);

private:
    std::string numeroDoVoo;
    std::string partida;
    std::string destino;
    int capacidade;
    int assentosDisponiveis;
    std::list<Reserva *> reservas;
};

#endif
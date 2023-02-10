/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef VOO_H
#define VOO_H

#include <string>
#include <list>

// #include "Reserva.hpp"
class Reserva; // Forward Declaration
class Voo
{
public:
    // constructor
    Voo(unsigned int id, unsigned int numeroDoVoo, std::string partida, std::string chegada, unsigned int capacidade, std::string data, std::string horarioPartida, std::string horarioChegada);

    // getters and setters
    unsigned int getId();

    unsigned int getNumeroDoVoo() const;
    void setNumeroDoVoo(const unsigned int numeroDoVoo);

    std::string getPartida() const;
    void setPartida(const std::string &partida);

    std::string getDestino() const;
    void setDestino(const std::string &destino);

    std::string getHorarioPartida() const;
    void setHorarioPartida(const std::string &horarioPartida);

    std::string getHorarioChegada() const;
    void setHorarioChegada(const std::string &horarioChegada);

    std::string getData() const;
    void setData(const std::string &data);

    int getCapacidade() const;
    void setCapacidade(const unsigned int capacidade);

    int getAssentosDisponiveis() const;
    void setAssentosDisponiveis(const int &assentosDisponiveis);

    std::list<Reserva *> getReservas() const;
    void setReservas(std::list<Reserva *> reservas);

    // setters
    void imprimirDadosVoo();
    void imprimirMapaDeAssentos();

    void adicionarReserva(Reserva *reserva);

private:
    unsigned int id;
    unsigned int numeroDoVoo;
    std::string partida;
    std::string destino;
    std::string data;
    std::string horarioPartida;
    std::string horarioChegada;
    int capacidade;
    int assentosDisponiveis;
    std::list<Reserva *> reservas;
};

#endif
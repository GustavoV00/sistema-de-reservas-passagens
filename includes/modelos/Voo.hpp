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
    Voo(int numeroDoVoo, std::string partida, std::string chegada, int capacidade, std::string data, std::string horarioPartida, std::string horarioChegada);
    ~Voo() = default;

    // getters and setters
    void setId(const unsigned int id);
    unsigned int getId() const;

    int getNumeroDoVoo() const;
    void setNumeroDoVoo(const int numeroDoVoo);

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

    int getCapacidade();
    void setCapacidade(const int capacidade);

    int getAssentosDisponiveis() const;
    void setAssentosDisponiveis(const int &assentosDisponiveis);

    std::list<Reserva *> &getReservas();
    void setReservas(std::list<Reserva *> reservas);

    // setters
    void imprimirDadosVoo();
    void imprimirMapaDeAssentos();

    void adicionarReserva(Reserva *reserva);

private:
    unsigned int id;
    int numeroDoVoo;
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
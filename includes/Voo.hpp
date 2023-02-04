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
class Reserva;  // Forward Declaration
class Voo {
    public:
        // constructor
        Voo(std::string numeroDoVoo, std::string partida, std::string destino, int capacidade, std::string data, std::string horarioPartida, std::string horarioChegada);

        // getters and setters
        std::string getNumeroDoVoo() const;
        void setNumeroDoVoo(const std::string& numeroDoVoo);

        std::string getPartida() const;
        void setPartida(const std::string& partida);

        std::string getDestino() const;
        void setDestino(const std::string& destino);

        std::string getHorarioPartida() const;
        void setHorarioPartida(const std::string& horarioPartida);

        std::string getHorarioChegada() const;
        void setHorarioChegada(const std::string& horarioChegada);

        std::string getData() const;
        void setData(const std::string& data);

        int getCapacidade() const;
        void setCapacidade(const int& capacidade);

        int getAssentosDisponiveis() const;
        void setAssentosDisponiveis(const int& assentosDisponiveis);

        std::list<Reserva *> getReservas() const;
        void setReservas(std::list<Reserva *> reservas);

        
        
        
        
        

        void imprimirDadosVoo();
        void imprimirMapaDeAssentos();

        void adicionarReserva(Reserva *reserva);
        void removerReserva(Reserva *reserva);

        std::string escolherAssentoReserva();

    private:
        std::string numeroDoVoo;
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
/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef RESERVA_HPP
#define RESERVA_HPP

#include <string>
#include "Voo.hpp"
#include "Passageiro.hpp"

class Reserva
{
public:
    // Construtores
    Reserva(std::string &localizador, Passageiro *passageiro, Voo *voo, std::string numeroDoAssento);
    ~Reserva() = default;

    // getters and setters
    int getId() const;
    void setId(int id);

    std::string getLocalizador() const;
    void setLocalizador(const std::string &localizador);

    Passageiro *getPassageiro() const;
    void setPassageiro(Passageiro *passageiro);

    Voo *getVoo();
    void setVoo(Voo *voo);

    std::string getNumeroDoAssento() const;
    void setNumeroDoAssento(const std::string &numeroDoAssento);

    void imprimirDadosReserva();
    static Reserva *buscaReservaLocalizador(const std::string &localizador, std::list<Reserva *> reservas);

    static Reserva *verificaSeAssentoExiste(const std::string &numAssento, std::list<Reserva *> reservas);

private:
    int id;
    std::string localizador;
    Passageiro *passageiro;
    Voo *voo;
    std::string numeroDoAssento;
};

#endif
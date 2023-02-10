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
    Reserva(unsigned int id, const std::string &localizador, const Passageiro &passageiro, const Voo &voo, const std::string numeroDoAssento);

    // getters and setters
    unsigned long getId();
    void setId(unsigned long id);

    std::string getLocalizador() const;
    void setLocalizador(const std::string &localizador);

    Passageiro getPassageiro() const;
    void setPassageiro(const Passageiro &passageiro);

    Voo getVoo() const;
    void setVoo(const Voo &voo);

    std::string getNumeroDoAssento() const;
    void setNumeroDoAssento(const std::string &numeroDoAssento);

    void imprimirDadosReserva();
    static Reserva *buscaReservaLocalizador(const std::string &localizador, std::list<Reserva *> reservas);

private:
    unsigned long id;
    std::string localizador;
    Passageiro passageiro;
    Voo voo;
    std::string numeroDoAssento;
};

#endif
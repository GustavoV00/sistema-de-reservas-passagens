/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "string"

// #include "./../includes/Reserva.hpp"
#include "./../includes/Pessoa.hpp"

class Passageiro : public Pessoa {
    public:
        // constructor
        Passageiro(const std::string& nome, const CPF& cpf, const RG& rg, 
               const std::string& dataDeNascimento, const unsigned long& contato, const std::string& email);

    private:
        //std::list<Reserva *> reservas;
};

#endif
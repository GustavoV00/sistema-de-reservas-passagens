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

#include "Usuario.hpp"

class Passageiro : public Usuario
{
public:
    // constructor
    Passageiro(unsigned int id, const std::string &nome, const CPF &cpf, const RG &rg,
               const std::string &dataDeNascimento, const unsigned long &contato, const std::string &email);

    // destructor
    ~Passageiro() = default;

    unsigned int getId();
    void setId(unsigned int id);

private:
    unsigned int id;
};

#endif
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
    friend std::ostream &operator<<(std::ostream &stream, const Passageiro &passageiro);

public:
    // constructor
    Passageiro(const std::string &nome, const CPF &cpf, const RG &rg,
               const std::string &dataDeNascimento, const unsigned long &contato, const std::string &email);

    // destructor
    virtual ~Passageiro() = default;

    unsigned int getId() const;
    void setId(const unsigned int id);

    void imprimirDadosPassageiro();

private:
    unsigned int id;
};

#endif
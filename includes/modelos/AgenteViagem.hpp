/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef AGENTE_VIAGEM_H
#define AGENTE_VIAGEM_H

#include "string"

#include "../../includes/modelos/Pessoa.hpp"

class AgenteViagem : public Pessoa
{
public:
    // constructor
    AgenteViagem(const std::string &nome, const CPF &cpf, const RG &rg,
                 const std::string &dataDeNascimento, const unsigned long &contato,
                 const std::string &email, const std::string &codigo);

    // destructor
    virtual ~AgenteViagem() = default;

    // getters and setters
    std::string getCodigo() const;
    void setCodigo(const std::string &codigo);

private:
    std::string codigo;
};

#endif
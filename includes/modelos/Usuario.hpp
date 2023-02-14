/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "Pessoa.hpp"

class Usuario : public Pessoa
{
public:
    // construtor padrão
    Usuario();
    Usuario(const std::string &nome, const CPF &cpf, const RG &rg,
            const std::string &dataDeNascimento, const unsigned long &contato, const std::string &email);

    // destrutor
    virtual ~Usuario() = default;

    std::string getSessionID() const;

private:
    std::string sessionID;

    void gerarSessionId();
};

#endif
#ifndef USUARIO_HPP
#define USUARIO_HPP

// #include "../controles/PassageiroControle.hpp"
// #include "../controles/VooControle.hpp"
// #include "../controles/ReservaControle.hpp"
#include "../consoles/ConsoleSistema.hpp"
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

    // void setSessionID(const std::string &sessionID);
    std::string getSessionID() const;

private:
    std::string sessionID;

    void gerarSessionId();
};

#endif
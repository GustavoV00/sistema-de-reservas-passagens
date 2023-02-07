#include "../../includes/modelos/Usuario.hpp"
// #include "../../includes/modelos/Pessoa.hpp"

Usuario::Usuario()
{
    this->gerarSessionId();
}

Usuario::Usuario(ConsoleSistema *consoleSistema)
    : consoleSistema{consoleSistema}
{
}

Usuario::Usuario(const std::string &nome, const CPF &cpf, const RG &rg,
                 const std::string &dataDeNascimento, const unsigned long &contato, const std::string &email)
    : Pessoa{nome, cpf, rg, dataDeNascimento, contato, email}
{
    this->gerarSessionId();
}

// Usuario::~Usuario()
// {
// }

// void Usuario::setSessionID(const std::string &sessionID)
// {
//     this->sessionID();
// }
std::string Usuario::getSessionID() const
{
    return this->sessionID;
}

void Usuario::gerarSessionId()
{
    this->sessionID = "abcd1234";
    // this->setSessionID(função que vai gerar o session id);
}
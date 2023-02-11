#ifndef USUARIOCONVIDADO_HPP
#define USUARIOCONVIDADO_HPP

#include "Usuario.hpp"

class UsuarioConvidado : public Usuario
{
public:
    UsuarioConvidado();
    // UsuarioConvidado(const std::string &nome, const CPF &cpf, const RG &rg,
    //                  const std::string &dataDeNascimento, const unsigned long &contato, const std::string &email);

    // Destructor default
    ~UsuarioConvidado() = default;

private:
};

#endif
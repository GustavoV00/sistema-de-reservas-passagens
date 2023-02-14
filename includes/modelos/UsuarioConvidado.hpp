#ifndef USUARIOCONVIDADO_HPP
#define USUARIOCONVIDADO_HPP

#include "Usuario.hpp"

class UsuarioConvidado : public Usuario
{
public:
    UsuarioConvidado();

    // Destructor default
    virtual ~UsuarioConvidado() = default;

private:
};

#endif
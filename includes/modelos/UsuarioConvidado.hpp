/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
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
/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef FORMATO_INVALIDO_EXCEPTION
#define FORMATO_INVALIDO_EXCEPTION

#include <stdexcept>

class FormatoInvalidoException : public std::runtime_error
{
public:
    const std::string mensagem;

    FormatoInvalidoException(const std::string mensagem);
    virtual ~FormatoInvalidoException() = default;
};
#endif
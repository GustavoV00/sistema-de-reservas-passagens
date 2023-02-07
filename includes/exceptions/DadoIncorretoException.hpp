/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef DADO_INCORRETO_EXCEPTION
#define DADO_INCORRETO_EXCEPTION

#include <stdexcept>

class DadoIncorretoException : public std::runtime_error
{
public:
    const std::string mensagem;

    DadoIncorretoException(const std::string &mensagem);
    virtual ~DadoIncorretoException() = default;
};
#endif
/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef VOO_CHEIO_EXCEPTION
#define VOO_CHEIO_EXCEPTION

#include <stdexcept>

class VooCheioException : public std::runtime_error
{
public:
    const std::string mensagem;

    VooCheioException(const std::string mensagem);
    virtual ~VooCheioException() = default;
};
#endif
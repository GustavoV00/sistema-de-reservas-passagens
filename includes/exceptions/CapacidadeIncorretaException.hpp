/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef CAPACIDADE_INCORRETA_EXCEPTION
#define CAPACIDADE_INCORRETA_EXCEPTION

#include <stdexcept>

class CapacidadeIncorretaException : public std::runtime_error
{
public:
    const std::string mensagem;
    const unsigned int capacidade;

    CapacidadeIncorretaException(const std::string mensagem, unsigned int capacidade);
    virtual ~CapacidadeIncorretaException() = default;
};
#endif
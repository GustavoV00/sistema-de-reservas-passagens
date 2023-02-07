/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include "../../includes/exceptions/FormatoInvalidoException.hpp"

FormatoInvalidoException::FormatoInvalidoException(const std::string mensagem)
    : std::runtime_error{mensagem}
{
}
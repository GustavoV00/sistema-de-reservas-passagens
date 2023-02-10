/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include "../../includes/exceptions/CapacidadeIncorretaException.hpp"

CapacidadeIncorretaException::CapacidadeIncorretaException(const std::string mensagem, unsigned int capacidade)
    : std::runtime_error{mensagem}, capacidade{capacidade}
{
}
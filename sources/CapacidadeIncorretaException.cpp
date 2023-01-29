/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#include "./../includes/CapacidadeIncorretaException.hpp"

CapacidadeIncorretaException::CapacidadeIncorretaException(const std::string mensagem, int capacidade)
    :std::runtime_error{mensagem}, capacidade{capacidade}{
}
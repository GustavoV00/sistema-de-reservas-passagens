/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#include "./../includes/DocumentoInvalidoException.hpp"

DocumentoInvalidoException::DocumentoInvalidoException(const unsigned long documento, const std::string mensagem)
    :std::runtime_error{mensagem}, documento{documento}{
}
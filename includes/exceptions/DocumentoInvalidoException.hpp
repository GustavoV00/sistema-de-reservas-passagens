/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef DOCUMENTO_INVALIDO_EXCEPTION
#define DOCUMENTO_INVALIDO_EXCEPTION

#include <stdexcept>

class DocumentoInvalidoException : public std::runtime_error
{
public:
    const unsigned long documento;
    const std::string mensagem;

    DocumentoInvalidoException(const unsigned long documento, const std::string mensagem);
    virtual ~DocumentoInvalidoException() = default;
};
#endif
/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include <iostream>
#include "../../includes/modelos/RG.hpp"
#include "../../includes/exceptions/DocumentoInvalidoException.hpp"

RG::RG()
{
}

RG::RG(const unsigned long numero)
{
    this->setNumero(numero);
}

unsigned long RG::getNumero() const
{
    return this->numero;
}

void RG::setNumero(const unsigned long numero)
{
    if (!validarRG(numero))
        throw DocumentoInvalidoException{numero, "RG inválido."};
    this->numero = numero;
}

bool RG::validarRG(unsigned long rgTeste) const
{
    if (rgTeste > 99999999)
    {
        return true;
    }
    return false;
}

bool RG::operator==(const RG &outro) const
{
    return this->numero == outro.numero;
}
/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include <iostream>
#include "../../includes/modelos/CPF.hpp"
#include "../../includes/exceptions/DocumentoInvalidoException.hpp"

CPF::CPF()
{
}

CPF::CPF(const unsigned long numero)
{
    this->setNumero(numero);
}

unsigned long CPF::getNumero() const
{
    return this->numero;
}

void CPF::setNumero(const unsigned long numero)
{
    if (!validarCPF(numero))
        throw DocumentoInvalidoException{numero, "CPF inválido."};
    this->numero = numero;
}

bool CPF::validarCPF(unsigned long cpfTeste) const
{
    int ultimo = cpfTeste % 10;
    cpfTeste = cpfTeste / 10;
    int penultimo = cpfTeste % 10;
    cpfTeste = cpfTeste / 10;

    unsigned long copiaCpfTeste = cpfTeste;
    int modulo, somatorioPrimeiroDigito = 0, somatorioSegundoDigito = 0;

    // calculo do primeiro dígito verificador
    for (int i = 2; i < 11; i++)
    {
        modulo = cpfTeste % 10;
        cpfTeste = cpfTeste / 10;
        somatorioPrimeiroDigito += i * modulo;
    }

    somatorioPrimeiroDigito = (somatorioPrimeiroDigito * 10) % 11;
    if (somatorioPrimeiroDigito == 10)
    {
        somatorioPrimeiroDigito = 0;
    }

    // calculo do segundo digito verificador
    for (int i = 3; i <= 11; i++)
    {
        modulo = copiaCpfTeste % 10;
        copiaCpfTeste = copiaCpfTeste / 10;
        somatorioSegundoDigito += i * modulo;
    }

    somatorioSegundoDigito += (2 * somatorioPrimeiroDigito);

    somatorioSegundoDigito = (somatorioSegundoDigito * 10) % 11;
    if (somatorioSegundoDigito == 10)
    {
        somatorioSegundoDigito = 0;
    }

    if ((penultimo != somatorioPrimeiroDigito) || (ultimo != somatorioSegundoDigito))
    {
        return false;
    }

    return true;
}

bool CPF::operator==(const CPF &outro) const
{
    return this->numero == outro.numero;
}
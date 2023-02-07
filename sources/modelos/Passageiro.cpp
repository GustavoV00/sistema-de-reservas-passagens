/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include "../../includes/modelos/Reserva.hpp"
#include "../../includes/modelos/Passageiro.hpp"
#include "../../includes/modelos/Voo.hpp"

Passageiro::Passageiro(const std::string &nome, const CPF &cpf, const RG &rg,
                       const std::string &dataDeNascimento, const unsigned long &contato, const std::string &email)
    : Pessoa(nome, cpf, rg, dataDeNascimento, contato, email)
{
}

unsigned long Passageiro::getId()
{
    return this->id;
}

void Passageiro::setId(unsigned long id)
{
    this->id = id;
}
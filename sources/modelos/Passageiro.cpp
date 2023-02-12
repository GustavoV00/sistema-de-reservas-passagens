/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include <iostream>
#include "../../includes/modelos/Passageiro.hpp"
#include "../../includes/modelos/Reserva.hpp"
#include "../../includes/modelos/Voo.hpp"

Passageiro::Passageiro(unsigned int id, const std::string &nome, const CPF &cpf, const RG &rg,
                       const std::string &dataDeNascimento, const unsigned long &contato, const std::string &email)
    : Usuario(nome, cpf, rg, dataDeNascimento, contato, email)
{
    this->id = id;
}

unsigned int Passageiro::getId()
{
    return this->id;
}

void Passageiro::setId(unsigned int id)
{
    this->id = id;
}

void Passageiro::imprimirDadosPassageiro()

{
    std::cout << "=====================================================================================================" << std::endl;
    std::cout << "Nome: " << this->getNome() << " - CPF: " << this->getCpf().getNumero() << " - RG: " << this->getRg().getNumero() << std::endl;
    std::cout << "Email: " << this->getEmail() << " - Telefone: " << this->getContato() << " - Data de Nascimento: " << this->getDataDeNascimento() << std::endl;
    std::cout << "=====================================================================================================" << std::endl;
}
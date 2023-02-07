/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include <iostream>
#include "../../includes/modelos/Pessoa.hpp"

Pessoa::Pessoa()
{
}

Pessoa::Pessoa(const std::string &nome, const CPF &cpf, const RG &rg,
               const std::string &dataDeNascimento, const unsigned long &contato, const std::string &email)
    : nome{nome}, cpf{cpf}, rg{rg}, dataDeNascimento{dataDeNascimento}, contato{contato}, email{email}
{
}

std::string Pessoa::getNome() const
{
    return this->nome;
}
void Pessoa::setNome(const std::string &nome)
{
    this->nome = nome;
}

const CPF &Pessoa::getCpf() const
{
    return this->cpf;
}
void Pessoa::setCpf(const CPF &cpf)
{
    this->cpf = cpf;
}

const RG &Pessoa::getRg() const
{
    return this->rg;
}
void Pessoa::setRg(const RG &rg)
{
    this->rg = rg;
}

std::string Pessoa::getDataDeNascimento() const
{
    return this->dataDeNascimento;
}
void Pessoa::setDataDeNascimento(const std::string &dataDeNascimento)
{
    this->dataDeNascimento = dataDeNascimento;
}

unsigned long Pessoa::getContato() const
{
    return this->contato;
}
void Pessoa::setContato(const unsigned long &contato)
{
    this->contato = contato;
}

std::string Pessoa::getEmail() const
{
    return this->email;
}
void Pessoa::setEmail(const std::string &email)
{
    this->email = email;
}

void Pessoa::imprimirDadosFormatados()
{
    std::cout << "=================================================================================" << std::endl;
    std::cout << "Nome: " << this->getNome() << " - CPF: " << this->getCpf().getNumero() << " - RG: " << this->getRg().getNumero() << std::endl;
    std::cout << "Email: " << this->getEmail() << " - Telefone: " << this->getContato() << " - Data de Nascimento: " << this->getDataDeNascimento() << std::endl;
    std::cout << "=================================================================================" << std::endl;
}
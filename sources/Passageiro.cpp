
#include "./../includes/Reserva.hpp"
#include "./../includes/Passageiro.hpp"
#include "./../includes/Voo.hpp"

Passageiro::Passageiro(std::string nome, std::string contato, std::string numeroPassaporte, int idade) : nome(nome), contato(contato), numeroPassaporte(numeroPassaporte), idade(idade)
{
}

std::string Passageiro::getNome() const
{
    return this->nome;
}

std::string Passageiro::getContato() const
{
    return this->contato;
}

std::string Passageiro::getNumeroPassaporte() const
{
    return this->numeroPassaporte;
}

int Passageiro::getIdade() const
{
    return this->idade;
}

void Passageiro::setNome(std::string nome)
{
    this->nome = nome;
}

void Passageiro::setContato(std::string contato)
{
    this->contato = contato;
}

void Passageiro::setNumeroPassaporte(std::string numeroPassaporte)
{
    this->numeroPassaporte = numeroPassaporte;
}

void Passageiro::setIdade(int idade)
{
    this->idade = idade;
}

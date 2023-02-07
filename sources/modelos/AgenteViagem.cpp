#include "../../includes/modelos/AgenteViagem.hpp"

AgenteViagem::AgenteViagem(const std::string &nome, const CPF &cpf, const RG &rg,
                           const std::string &dataDeNascimento, const unsigned long &contato, const std::string &email, const std::string &codigo)
    : Pessoa(nome, cpf, rg, dataDeNascimento, contato, email), codigo{codigo}
{
}

std::string AgenteViagem::getCodigo() const
{
    return this->codigo;
}
void AgenteViagem::setCodigo(const std::string &codigo)
{
    this->codigo = codigo;
}
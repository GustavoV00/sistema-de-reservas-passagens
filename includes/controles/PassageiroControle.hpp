#ifndef PASSAGEIRO_CONTROLE_H
#define PASSAGEIRO_CONTROLE_H

#include "../modelos/Passageiro.hpp"
#include "../repositorios/PassageiroRepositorio.hpp"

#include <string>

class PassageiroControle
{

public:
    PassageiroControle();
    ~PassageiroControle() = default;

    PassageiroRepositorio getPassageiroRepositorio() const;

    std::list<Passageiro *> &obterTodosOsPassageiros();
    Passageiro *obterPassageiroPorId(const unsigned int id);
    Passageiro *obterPassageiroPorCPF(CPF &cpf);
    bool atualizarPassageiroPorId(unsigned long id, Passageiro passageiroNovo);
    bool cadastrarPassageiro(Passageiro *passageiro);
    bool excluirPassageiroPorId(const unsigned int id);

private:
    PassageiroRepositorio passageiroRepositorio;
};

#endif
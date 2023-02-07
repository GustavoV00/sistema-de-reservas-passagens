#ifndef PASSAGEIROSERVICO_H
#define PASSAGEIROSERVICO_H

#include "../repositorios/PassageiroRepositorio.hpp"

class PassageiroServico
{

public:
    PassageiroServico(const PassageiroRepositorio passageiroRepositorio);
    virtual ~PassageiroServico() = default;

    PassageiroRepositorio getPassageiroRepositorio();
    void setPassageiroRepositorio(const PassageiroRepositorio PassageiroRepositorio);

    std::list<Passageiro *> obterTodosOsPassageiros();
    Passageiro *obterPassageiroPorId(const unsigned long id);
    bool atualizarPassageiroPorId(unsigned long id, Passageiro passageiroNovo);
    bool cadastrarPassageiro(Passageiro *passageiro);
    bool excluirPassageiroPorId(const unsigned long id);

private:
    PassageiroRepositorio passageiroRepositorio;
};

#endif
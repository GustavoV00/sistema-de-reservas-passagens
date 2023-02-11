#ifndef PASSAGEIRO_CONTROLE_H
#define PASSAGEIRO_CONTROLE_H

#include "../modelos/Passageiro.hpp"
#include "../repositorios/PassageiroRepositorio.hpp"

#include <string>

class PassageiroControle
{

public:
    PassageiroControle();
    // PassageiroControle(const PassageiroRepositorio passageiroRepositorio);
    ~PassageiroControle() = default;

    PassageiroRepositorio *getPassageiroRepositorio();
    void setPassageiroRepositorio(PassageiroRepositorio *passageiroRepositorio);

    std::list<Passageiro *> &obterTodosOsPassageiros();
    Passageiro *obterPassageiroPorId(const unsigned int id);
    bool atualizarPassageiroPorId(unsigned long id, Passageiro passageiroNovo);
    bool cadastrarPassageiro(Passageiro *passageiro);
    bool excluirPassageiroPorId(const unsigned int id);

private:
    /* data */
    PassageiroRepositorio *passageiroRepositorio;
};

#endif
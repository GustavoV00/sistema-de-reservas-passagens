#ifndef PASSAGEIROCONTROLE_H
#define PASSAGEIROCONTROLE_H

#include "../servicos/PassageiroServico.hpp"
#include "../modelos/Passageiro.hpp"

#include <string>

class PassageiroControle
{

public:
    PassageiroControle();
    PassageiroControle(const PassageiroServico passageiroServico);
    ~PassageiroControle() = default;

    PassageiroServico getPassageiroServico();
    void setPassageiroServico(PassageiroServico passageiroServico);

    std::list<Passageiro *> obterTodosOsPassageiros();
    Passageiro *obterPassageiroPorId(const unsigned long id);
    bool atualizarPassageiroPorId(unsigned long id, Passageiro passageiroNovo);
    bool cadastrarPassageiro(Passageiro *passageiro);
    bool excluirPassageiroPorId(const unsigned long id);

private:
    /* data */
    PassageiroServico passageiroServico;
};

#endif

#include "../../includes/controles/PassageiroControle.hpp"

PassageiroControle::PassageiroControle()
{
}

PassageiroControle::PassageiroControle(const PassageiroServico passageiroServico)
    : passageiroServico{passageiroServico}
{
}

PassageiroServico PassageiroControle::getPassageiroServico()
{
    return this->passageiroServico;
}

void PassageiroControle::setPassageiroServico(PassageiroServico PassageiroServico)
{
    this->passageiroServico = passageiroServico;
}

std::list<Passageiro *> PassageiroControle::obterTodosOsPassageiros()
{
    return this->getPassageiroServico().obterTodosOsPassageiros();
}

Passageiro *PassageiroControle::obterPassageiroPorId(const unsigned long id)
{
    return this->getPassageiroServico().obterPassageiroPorId(id);
}

bool PassageiroControle::atualizarPassageiroPorId(unsigned long id, Passageiro novoPassageiro)
{
    return this->getPassageiroServico().atualizarPassageiroPorId(id, novoPassageiro);
}

bool PassageiroControle::cadastrarPassageiro(Passageiro *passageiro)
{
    return this->getPassageiroServico().cadastrarPassageiro(passageiro);
}

bool PassageiroControle::excluirPassageiroPorId(const unsigned long id)
{
    return this->getPassageiroServico().excluirPassageiroPorId(id);
}
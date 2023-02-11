
#include "../../includes/controles/VooControle.hpp"

VooControle::VooControle()
{
    VooServico vooServico{};
    this->setVooServico(vooServico);
}

VooServico VooControle::getVooServico()
{
    return this->vooServico;
}

void VooControle::setVooServico(VooServico VooServico)
{
    this->vooServico = vooServico;
}

std::list<Voo *> VooControle::obterTodosOsVoos()
{
    return this->getVooServico().obterTodosOsVoos();
}

Voo *VooControle::obterVooPorId(const unsigned int id)
{
    return this->getVooServico().obterVooPorId(id);
}

bool VooControle::atualizarVooPorId(unsigned int id, Voo novoVoo)
{
    return this->getVooServico().atualizarVooPorId(id, novoVoo);
}

bool VooControle::cadastrarVoo(Voo *voo)
{
    return this->getVooServico().cadastrarVoo(voo);
}

bool VooControle::excluirVooPorId(const unsigned int id)
{
    return this->getVooServico().excluirVooPorId(id);
}
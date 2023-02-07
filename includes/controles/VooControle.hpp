#ifndef VOOCONTROLE_H
#define VOOCONTROLE_H

#include "../servicos/VooServico.hpp"
#include "../modelos/Voo.hpp"

#include <string>

class VooControle
{

public:
    VooControle(const VooServico vooServico);
    virtual ~VooControle() = default;

    VooServico getVooServico();
    void setVooServico(VooServico vooServico);

    std::list<Voo *> obterTodosOsVoos();
    Voo *obterVooPorId(const unsigned long id);
    bool atualizarVooPorId(unsigned long id, Voo vooNovo);
    bool cadastrarVoo(Voo *voo);
    bool excluirVooPorId(const unsigned long id);

private:
    /* data */
    VooServico vooServico;
};

#endif
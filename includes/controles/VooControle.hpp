#ifndef VOOCONTROLE_H
#define VOOCONTROLE_H

#include "../servicos/VooServico.hpp"
#include "../modelos/Voo.hpp"

#include <string>

class VooControle
{

public:
    VooControle();
    ~VooControle() = default;

    VooServico getVooServico();
    void setVooServico(VooServico vooServico);

    std::list<Voo *> obterTodosOsVoos();
    Voo *obterVooPorId(const unsigned int id);
    bool atualizarVooPorId(unsigned int id, Voo vooNovo);
    bool cadastrarVoo(Voo *voo);
    bool excluirVooPorId(const unsigned int id);

private:
    VooServico vooServico;
};

#endif
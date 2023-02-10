#ifndef VOOSERVICO_H
#define VOOSERVICO_H

#include "../repositorios/VooRepositorio.hpp"

class VooServico
{

public:
    VooServico();
    ~VooServico() = default;

    VooRepositorio getVooRepositorio();
    void setVooRepositorio(const VooRepositorio VooRepositorio);

    std::list<Voo *> obterTodosOsVoos();
    Voo *obterVooPorId(const unsigned long id);
    bool atualizarVooPorId(unsigned long id, Voo vooNovo);
    bool cadastrarVoo(Voo *voo);
    bool excluirVooPorId(const unsigned long id);

private:
    VooRepositorio vooRepositorio;
};

#endif
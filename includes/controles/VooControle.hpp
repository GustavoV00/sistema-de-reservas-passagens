#ifndef VOO_CONTROLE_H
#define VOO_CONTROLE_H

#include "../repositorios/VooRepositorio.hpp"
#include "../modelos/Voo.hpp"

#include <string>

class VooControle
{

public:
    VooControle();
    ~VooControle() = default;

    VooRepositorio getVooRepositorio();

    std::list<Voo *> &obterTodosOsVoos();
    Voo *obterVooPorId(const unsigned int id);
    Voo *obterVooPorNumeroDoVoo(int numeroDoVoo);
    bool atualizarVooPorId(unsigned int id, Voo vooNovo);
    bool cadastrarVoo(Voo *voo);
    bool excluirVooPorId(const unsigned int id);

private:
    VooRepositorio vooRepositorio;
};

#endif
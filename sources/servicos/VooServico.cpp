
#include "../../includes/servicos/VooServico.hpp"

#include <string>
#include <iostream>
#include <list>

VooServico::VooServico()
{
    std::list<Voo *> voos;
    VooRepositorio vooRepositorio{voos};
    this->setVooRepositorio(vooRepositorio);
}

VooRepositorio VooServico::getVooRepositorio()
{
    return this->vooRepositorio;
}

void VooServico::setVooRepositorio(const VooRepositorio vooRepositorio)
{
    this->vooRepositorio = vooRepositorio;
}

std::list<Voo *> VooServico::obterTodosOsVoos()
{
    return this->getVooRepositorio().getVoos();
}

Voo *VooServico::obterVooPorId(const unsigned long id)
{
    std::list<Voo *> voos = this->getVooRepositorio().getVoos();
    std::list<Voo *>::iterator it;
    for (it = voos.begin(); it != voos.end(); ++it)
    {
        // Testar isso aqui mais tarde!!!
        std::cout << *it << std::endl;
        if ((*it)->getId() == id)
            return *it;
    }

    return nullptr;
}

bool VooServico::atualizarVooPorId(unsigned long id, Voo vooNovo)
{
    try
    {
        // Voo *voo = this->obterVooPorId(id);
        // voo = &vooNovo;
        return true;
    }
    catch (std::exception &e)
    {
        std::cout << "Voo não existe ou o id está errado: " << e.what() << std::endl;
    }
    return false;
}

bool VooServico::cadastrarVoo(Voo *voo)
{
    try
    {
        this->getVooRepositorio().getVoos().push_back(voo);
        std::cout << "Sucesso ao cadastrar voo!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao adicionar voo no bd: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool VooServico::excluirVooPorId(const unsigned long id)
{
    std::list<Voo *> voos = this->getVooRepositorio().getVoos();
    std::list<Voo *>::iterator it;
    for (it = voos.begin(); it != voos.end(); ++it)
    {
        // Testar isso aqui mais tarde!!!
        // isso aqui funciona ? Muito suspeito. Preciso testar com cuidado mais tarde
        std::cout << *it << std::endl;
        if ((*it)->getId() == id)
        {
            delete *it;
            voos.erase(it);
            return true;
        }
    }
    return false;
}
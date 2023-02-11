
#include <iostream>
#include "../../includes/controles/VooControle.hpp"

VooControle::VooControle()
{
    VooRepositorio *vooRepositorio = new VooRepositorio{};
    this->vooRepositorio = vooRepositorio;
}

VooRepositorio *VooControle::getVooRepositorio()
{
    return this->vooRepositorio;
}

std::list<Voo *> &VooControle::obterTodosOsVoos()
{
    return this->vooRepositorio->getVoos();
}

Voo *VooControle::obterVooPorId(const unsigned int id)
{
    std::list<Voo *> voos = this->vooRepositorio->getVoos();
    std::list<Voo *>::iterator it;
    for (it = voos.begin(); it != voos.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            std::cout << "retornando o de n " << (*it)->getNumeroDoVoo() << std::endl;
            return (*it);
        }
    }

    return nullptr;
}

bool VooControle::atualizarVooPorId(unsigned int id, Voo vooNovo)
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

bool VooControle::cadastrarVoo(Voo *voo)
{
    try
    {
        this->vooRepositorio->getVoos().push_back(voo);
        std::cout << "Sucesso ao cadastrar voo!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao adicionar voo no bd: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool VooControle::excluirVooPorId(const unsigned int id)
{
    std::list<Voo *> voos = this->vooRepositorio->getVoos();
    std::list<Voo *>::iterator it;
    for (it = voos.begin(); it != voos.end(); ++it)
    {
        // Testar isso aqui mais tarde!!!
        // isso aqui funciona ? Muito suspeito. Preciso testar com cuidado mais tarde
        std::cout << *it << std::endl;
        if ((*it)->getId() == id)
        {
            voos.erase(it);
            delete *it;
            return true;
        }
    }
    return false;
}
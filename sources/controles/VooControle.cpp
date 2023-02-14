
#include <iostream>
#include "../../includes/controles/VooControle.hpp"

VooControle::VooControle()
{
}

VooRepositorio VooControle::getVooRepositorio() const
{
    return this->vooRepositorio;
}

std::list<Voo *> &VooControle::obterTodosOsVoos()
{
    return this->vooRepositorio.getVoos();
}

Voo *VooControle::obterVooPorId(const unsigned int id)
{
    std::list<Voo *> voos = this->vooRepositorio.getVoos();
    std::list<Voo *>::iterator it;
    for (it = voos.begin(); it != voos.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            return (*it);
        }
    }

    return nullptr;
}

Voo *VooControle::obterVooPorNumeroDoVoo(int numeroDoVoo)
{
    std::list<Voo *> voos = this->vooRepositorio.getVoos();
    std::list<Voo *>::iterator it;
    for (it = voos.begin(); it != voos.end(); ++it)
    {
        if ((*it)->getNumeroDoVoo() == numeroDoVoo)
        {
            return (*it);
        }
    }

    return nullptr;
}

bool VooControle::cadastrarVoo(Voo *voo)
{
    try
    {
        voo->setId(this->vooRepositorio.getNewId());
        this->vooRepositorio.getVoos().push_back(voo);
        std::cout << "Sucesso ao cadastrar voo! ID: [" << voo->getId() << "]" << std::endl;
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
    std::list<Voo *>::iterator it{this->vooRepositorio.getVoos().begin()};
    while (it != this->vooRepositorio.getVoos().end())
    {
        if ((*it)->getId() == id)
        {
            this->vooRepositorio.getVoos().erase(it);
            delete *it;
            return true;
        }
        it++;
    }

    return false;
}
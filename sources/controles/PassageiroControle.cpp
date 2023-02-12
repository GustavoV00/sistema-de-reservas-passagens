#include <string>
#include <iostream>
#include <list>
#include "../../includes/controles/PassageiroControle.hpp"

PassageiroControle::PassageiroControle()
{
}

PassageiroRepositorio PassageiroControle::getPassageiroRepositorio()
{
    return this->passageiroRepositorio;
}

std::list<Passageiro *> &PassageiroControle::obterTodosOsPassageiros()
{
    return this->passageiroRepositorio.getPassageiros();
}

Passageiro *PassageiroControle::obterPassageiroPorId(const unsigned int id)
{
    std::list<Passageiro *> passageiros = this->passageiroRepositorio.getPassageiros();
    std::list<Passageiro *>::iterator it;
    for (it = passageiros.begin(); it != passageiros.end(); ++it)
    {
        if ((*it)->getId() == id)
            return *it;
    }

    return nullptr;
}

Passageiro *PassageiroControle::obterPassageiroPorEmail(std::string &email)
{
    std::list<Passageiro *> passageiros = this->passageiroRepositorio.getPassageiros();
    std::list<Passageiro *>::iterator it;
    for (it = passageiros.begin(); it != passageiros.end(); ++it)
    {
        if ((*it)->getEmail() == email)
            return *it;
    }

    return nullptr;
}

bool PassageiroControle::atualizarPassageiroPorId(unsigned long id, Passageiro passageiroNovo)
{
    try
    {
        // Passageiro *passageiro = this->obterPassageiroPorId(id);
        // passageiro = &passageiroNovo;
        return true;
    }
    catch (std::exception &e)
    {
        std::cout << "Passageiro não existe ou o id está errado: " << e.what() << std::endl;
    }
    return false;
}

bool PassageiroControle::cadastrarPassageiro(Passageiro *passageiro)
{
    try
    {
        this->passageiroRepositorio.getPassageiros().push_back(passageiro);
        std::cout << "Sucesso ao cadastrar passageiro!" << std::endl;
        return true;
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao adicionar passageiro no bd: " << e.what() << std::endl;
        return false;
    }
}

bool PassageiroControle::excluirPassageiroPorId(const unsigned int id)
{
    std::list<Passageiro *>::iterator it{this->passageiroRepositorio.getPassageiros().begin()};
    while (it != this->passageiroRepositorio.getPassageiros().end())
    {
        if ((*it)->getId() == id)
        {
            this->passageiroRepositorio.getPassageiros().erase(it);
            delete *it;
            return true;
        }
        it++;
    }

    return false;
}
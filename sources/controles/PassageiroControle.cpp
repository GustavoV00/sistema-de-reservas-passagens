/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#include <string>
#include <iostream>
#include <list>
#include "../../includes/controles/PassageiroControle.hpp"

PassageiroControle::PassageiroControle()
{
}

PassageiroRepositorio PassageiroControle::getPassageiroRepositorio() const
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

Passageiro *PassageiroControle::obterPassageiroPorCPF(CPF &cpf)
{
    std::list<Passageiro *> passageiros = this->passageiroRepositorio.getPassageiros();
    std::list<Passageiro *>::iterator it;
    for (it = passageiros.begin(); it != passageiros.end(); ++it)
    {
        if (std::to_string((*it)->getCpf().getNumero()).compare(std::to_string(cpf.getNumero())) == 0)
        {
            return *it;
        }
    }

    return nullptr;
}

bool PassageiroControle::cadastrarPassageiro(Passageiro *passageiro)
{
    try
    {
        passageiro->setId(this->passageiroRepositorio.getNewId());
        this->passageiroRepositorio.getPassageiros().push_back(passageiro);
        std::cout << "Sucesso ao cadastrar passageiro! ID: [" << passageiro->getId() << "]" << std::endl;
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
            try
            {
                this->passageiroRepositorio.getPassageiros().erase(it);
                delete *it;
                return true;
            }
            catch (std::exception &e)
            {
                std::cout << "Falha ao deletar o passageiro pelo id! " << e.what() << std::endl;
                return false;
            }
        }
        it++;
    }

    return false;
}
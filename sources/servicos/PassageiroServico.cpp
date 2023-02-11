
#include "../../includes/modelos/Passageiro.hpp"
#include "../../includes/servicos/PassageiroServico.hpp"
#include "../../includes/repositorios/PassageiroRepositorio.hpp"

#include <string>
#include <iostream>
#include <list>

PassageiroServico::PassageiroServico()
{
    PassageiroRepositorio *passageiroRepositorio = new PassageiroRepositorio{};
    this->passageiroRepositorio = passageiroRepositorio;
}

// PassageiroServico::PassageiroServico(const PassageiroRepositorio passageiroRepositorio)
//     : passageiroRepositorio{passageiroRepositorio}
// {
// }

PassageiroRepositorio *PassageiroServico::getPassageiroRepositorio()
{
    return this->passageiroRepositorio;
}

void PassageiroServico::setPassageiroRepositorio(PassageiroRepositorio *passageiroRepositorio)
{
    this->passageiroRepositorio = passageiroRepositorio;
}

std::list<Passageiro *> &PassageiroServico::obterTodosOsPassageiros()
{
    return this->getPassageiroRepositorio()->getPassageiros();
}

Passageiro *PassageiroServico::obterPassageiroPorId(const unsigned long id)
{
    std::list<Passageiro *> passageiros = this->passageiroRepositorio->getPassageiros();
    std::list<Passageiro *>::iterator it;
    for (it = passageiros.begin(); it != passageiros.end(); ++it)
    {
        if ((*it)->getId() == id)
            return *it;
    }

    return nullptr;
}

bool PassageiroServico::atualizarPassageiroPorId(unsigned long id, Passageiro passageiroNovo)
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

bool PassageiroServico::cadastrarPassageiro(Passageiro *passageiro)
{
    try
    {
        this->passageiroRepositorio->getPassageiros().push_back(passageiro);
        std::cout << "Sucesso ao cadastrar passageiro!" << std::endl;
        return true;
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao adicionar passageiro no bd: " << e.what() << std::endl;
        return false;
    }
}

bool PassageiroServico::excluirPassageiroPorId(const unsigned long id)
{
    std::list<Passageiro *> passageiros = this->getPassageiroRepositorio()->getPassageiros();
    std::list<Passageiro *>::iterator it;
    for (it = passageiros.begin(); it != passageiros.end(); ++it)
    {
        // Testar isso aqui mais tarde!!!
        // isso aqui funciona ? Muito suspeito. Preciso testar com cuidado mais tarde
        std::cout << *it << std::endl;
        if ((*it)->getId() == id)
        {
            delete *it;
            passageiros.erase(it);
            return true;
        }
    }
    return false;
}
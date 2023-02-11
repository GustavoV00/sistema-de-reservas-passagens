
// #include "../../includes/controles/PassageiroControle.hpp"

// PassageiroControle::PassageiroControle()
// {
//     PassageiroControle *passageiroControle = new PassageiroControle{};
//     this->passageiroControle = passageiroControle;
// }

// // PassageiroControle::PassageiroControle(const PassageiroControle passageiroControle)
// //     : passageiroControle{passageiroControle}
// // {
// // }

// PassageiroControle *PassageiroControle::getPassageiroControle()
// {
//     return this->passageiroControle;
// }

// void PassageiroControle::setPassageiroControle(PassageiroControle *PassageiroControle)
// {
//     this->passageiroControle = passageiroControle;
// }

// std::list<Passageiro *> &PassageiroControle::obterTodosOsPassageiros()
// {
//     return this->getPassageiroControle()->obterTodosOsPassageiros();
// }

// Passageiro *PassageiroControle::obterPassageiroPorId(const unsigned int id)
// {
//     return this->getPassageiroControle()->obterPassageiroPorId(id);
// }

// bool PassageiroControle::atualizarPassageiroPorId(unsigned long id, Passageiro novoPassageiro)
// {
//     return this->getPassageiroControle()->atualizarPassageiroPorId(id, novoPassageiro);
// }

// bool PassageiroControle::cadastrarPassageiro(Passageiro *passageiro)
// {
//     return this->passageiroControle->cadastrarPassageiro(passageiro);
// }

// bool PassageiroControle::excluirPassageiroPorId(const unsigned int id)
// {
//     return this->getPassageiroControle()->excluirPassageiroPorId(id);
// }

#include "../../includes/controles/PassageiroControle.hpp"

#include <string>
#include <iostream>
#include <list>

PassageiroControle::PassageiroControle()
{
    PassageiroRepositorio *passageiroRepositorio = new PassageiroRepositorio{};
    this->passageiroRepositorio = passageiroRepositorio;
}

// PassageiroControle::PassageiroControle(const PassageiroRepositorio passageiroRepositorio)
//     : passageiroRepositorio{passageiroRepositorio}
// {
// }

PassageiroRepositorio *PassageiroControle::getPassageiroRepositorio()
{
    return this->passageiroRepositorio;
}

void PassageiroControle::setPassageiroRepositorio(PassageiroRepositorio *passageiroRepositorio)
{
    this->passageiroRepositorio = passageiroRepositorio;
}

std::list<Passageiro *> &PassageiroControle::obterTodosOsPassageiros()
{
    return this->getPassageiroRepositorio()->getPassageiros();
}

Passageiro *PassageiroControle::obterPassageiroPorId(const unsigned int id)
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

bool PassageiroControle::excluirPassageiroPorId(const unsigned int id)
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
/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef CONSOLE_SISTEMA_HPP
#define CONSOLE_SISTEMA_HPP

#include <list>

#include "../controles/VooControle.hpp"
#include "../controles/ReservaControle.hpp"
#include "../controles/PassageiroControle.hpp"
#include "../modelos/GerarDados.hpp"

class AgenteViagem;

class ConsoleSistema
{
public:
    ConsoleSistema();
    virtual ~ConsoleSistema() = default;

    void imprimirMensagemInicioExecucao();
    virtual void imprimirComandosTelaPrincipal();

    virtual void rodarGerenciamentoDeVoo(VooControle *vooControle);
    virtual void imprimirOpcoesGerenciamentoVoos();

    virtual void rodarGerenciamentoDeReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Usuario *usuario);

    virtual void rodarGerenciamentoDePassageiros(PassageiroControle *passageiroControle, Usuario *usuario, ReservaControle *reservaControle);
    virtual void imprimirOpcoesGerenciamentoPassageiros();
    void cadastrarPassageiroInterface(PassageiroControle *passageiroControle);

    void finalizarSistema();
    void imprimirOpcoesGerenciamentoDeReservas();

    AgenteViagem *loginAgente(std::list<AgenteViagem *> &agentes);
    Passageiro *loginPassageiro(std::list<Passageiro *> &passageiros);

private:
};

#endif
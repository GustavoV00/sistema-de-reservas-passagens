/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef CONSOLE_AGENTE_HPP
#define CONSOLE_AGENTE_HPP

#include "ConsoleSistema.hpp"
#include "../modelos/Voo.hpp"

class ConsoleAgente : public ConsoleSistema
{
public:
    ConsoleAgente();
    virtual ~ConsoleAgente() = default;

    virtual void imprimirComandosTelaPrincipal();

    virtual void rodarGerenciamentoDeVoo(VooControle *vooControle);
    virtual void imprimirOpcoesGerenciamentoVoos();
    void cadastrarVooInterface(VooControle *vooControle);
    void atualizarVooInterface(VooControle *vooControle);
    void excluirVooInterface(VooControle *vooControle);
    void imprimirOpcoesDadosEditarVoo();

    virtual void imprimirOpcoesGerenciamentoDeReservas();
    virtual void rodarGerenciamentoDeReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Usuario *usuario);
    virtual void cadastrarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle);
    virtual void removerReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle);
    virtual void atualizarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle);

    virtual void imprimirOpcoesGerenciamentoPassageiros();
    void rodarGerenciamentoDePassageiros(PassageiroControle *passageiroControle, Usuario *usuario, ReservaControle *reservaControle);
    void atualizarPassageiroInterface(PassageiroControle *passageiroControle);
    void excluirPassageiroInterface(PassageiroControle *passageiroControle, ReservaControle *reservaControle);
    void imprimirOpcoesDadosEditarPassageiro();

private:
};

#endif
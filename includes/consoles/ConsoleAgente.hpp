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
    virtual void rodarGerenciamentoDeReservas();

    void imprimirOpcoesGerenciamentoPassageiros();
    void rodarGerenciamentoDePassageiros(PassageiroControle *passageiroControle, Usuario *usuario, ReservaControle *reservaControle);
    void cadastrarPassageiroInterface(PassageiroControle *passageiroControle);
    void atualizarPassageiroInterface(PassageiroControle *passageiroControle);
    void excluirPassageiroInterface(PassageiroControle *passageiroControle, ReservaControle *reservaControle);
    void imprimirOpcoesDadosEditarPassageiro();

private:
};

#endif
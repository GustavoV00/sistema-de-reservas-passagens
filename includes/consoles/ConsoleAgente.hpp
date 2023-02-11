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

    virtual void imprimirOpcoesGerenciamentoDeReservas();
    virtual void rodarGerenciamentoDeReservas();

    void cadastrarVooInterface(VooControle *vooControle);

private:
};

#endif
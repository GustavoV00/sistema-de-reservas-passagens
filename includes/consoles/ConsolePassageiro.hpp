
#ifndef CONSOLE_PASSAGEIRO_HPP
#define CONSOLE_PASSAGEIRO_HPP

#include "ConsoleSistema.hpp"
#include "../modelos/Voo.hpp"

class ConsolePassageiro : public ConsoleSistema
{
public:
    ConsolePassageiro();
    virtual ~ConsolePassageiro() = default;

    virtual void imprimirComandosTelaPrincipal();
    virtual void rodarGerenciamentoDeVoo(VooControle *vooControle);
    virtual void imprimirOpcoesGerenciamentoVoos();

    virtual void imprimirOpcoesGerenciamentoDeReservas();
    virtual void rodarGerenciamentoDeReservas(ReservaControle *reservaControle);

    void cadastrarVooInterface(VooControle *vooControle);

private:
};

#endif
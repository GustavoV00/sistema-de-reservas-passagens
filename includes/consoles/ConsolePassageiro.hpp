
#ifndef CONSOLE_PASSAGEIRO_HPP
#define CONSOLE_PASSAGEIRO_HPP

#include "ConsoleSistema.hpp"
#include "../modelos/Voo.hpp"
#include "../modelos/GerarDados.hpp"

class ConsolePassageiro : public ConsoleSistema
{
public:
    ConsolePassageiro();
    virtual ~ConsolePassageiro() = default;

    virtual void imprimirComandosTelaPrincipal();
    virtual void rodarGerenciamentoDeVoo(VooControle *vooControle);
    virtual void imprimirOpcoesGerenciamentoVoos();

    virtual void imprimirOpcoesGerenciamentoDeReservas();
    virtual void rodarGerenciamentoDeReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle);

    void cadastrarVooInterface(VooControle *vooControle);
    void cadastrarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle);
    void removerReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle);

private:
};

#endif
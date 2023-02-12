
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

    virtual void imprimirOpcoesGerenciamentoDeReservas();
    virtual void rodarGerenciamentoDeReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Usuario *usuario);

    // void cadastrarVooInterface(VooControle *vooControle);
    void cadastrarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Passageiro *passageiro, std::list<Reserva *> reservas);

    void removerReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Passageiro *passageiro);
    void atualizarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle);

private:
};

#endif

/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef CONSOLE_PASSAGEIRO_HPP
#define CONSOLE_PASSAGEIRO_HPP

#include "ConsoleSistema.hpp"
#include "../modelos/Voo.hpp"
#include "../modelos/GerarDados.hpp"
#include "../exceptions/FormatoInvalidoException.hpp"

class ConsolePassageiro : public ConsoleSistema
{
public:
    ConsolePassageiro();
    virtual ~ConsolePassageiro() = default;

    virtual void imprimirComandosTelaPrincipal();

    virtual void imprimirOpcoesGerenciamentoDeReservas();
    virtual void rodarGerenciamentoDeReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Usuario *usuario);
    virtual void cadastrarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Passageiro *passageiro, std::list<Reserva *> reservas);
    virtual void removerReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Passageiro *passageiro);
    virtual void atualizarReservaInterface(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle);

private:
};

#endif
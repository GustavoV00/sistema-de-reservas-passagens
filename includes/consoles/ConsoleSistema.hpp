#ifndef CONSOLE_SISTEMA_HPP
#define CONSOLE_SISTEMA_HPP

// #include "../modelos/AgenteViagem.hpp"
#include <list>

#include "../controles/VooControle.hpp"
#include "../controles/ReservaControle.hpp"
#include "../controles/PassageiroControle.hpp"

class AgenteViagem;
// class Passageiro;
// class Usuario;

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

    void finalizarSistema();
    void imprimirOpcoesGerenciamentoDeReservas();

    AgenteViagem *loginAgente(std::list<AgenteViagem *> &agentes);
    Passageiro *loginPassageiro(std::list<Passageiro *> &passageiros);

private:
};

#endif
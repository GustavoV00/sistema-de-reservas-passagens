#ifndef CONSOLE_SISTEMA_HPP
#define CONSOLE_SISTEMA_HPP

// #include "../modelos/AgenteViagem.hpp"
#include <list>

#include "../controles/VooControle.hpp"

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

    virtual void rodarGerenciamentoDeReservas();

    // void imprimirMensagemInicioExecucao();

    void finalizarSistema();
    void imprimirOpcoesGerenciamentoDeReservas();

    AgenteViagem *loginAgente(std::list<AgenteViagem *> &agentes);

private:
};

#endif
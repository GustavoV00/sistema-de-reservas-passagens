#ifndef CONSOLE_SISTEMA_HPP
#define CONSOLE_SISTEMA_HPP

// #include "../modelos/AgenteViagem.hpp"
#include <list>

class AgenteViagem;

class ConsoleSistema
{
public:
    ConsoleSistema();
    ~ConsoleSistema() = default;

    void imprimirMensagemInicioExecucao();
    virtual void imprimirComandosTelaPrincipal();
    // void imprimirMensagemInicioExecucao();
    void imprimirOpcoesGerenciamentoVoos();
    void finalizarSistema();
    void imprimirOpcoesGerenciamentoDeReservas();

    AgenteViagem *loginAgente(std::list<AgenteViagem *> &agentes);

private:
};

#endif
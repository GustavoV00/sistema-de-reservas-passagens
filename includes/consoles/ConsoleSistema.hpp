#ifndef CONSOLESISTEMA_H
#define CONSOLESISTEMA_H

class ConsoleSistema
{
public:
    ConsoleSistema();
    ~ConsoleSistema() = default;

    void imprimirMensagemInicioExecucao();
    void imprimirComandosTelaPrincipal();
    void imprimirMensagemInicioExecucaoConvidado();
    void imprimirOpcoesGerenciamentoVoos();
    void finalizarSistema();
    void imprimirOpcoesGerenciamentoDeReservas();

private:
};

#endif
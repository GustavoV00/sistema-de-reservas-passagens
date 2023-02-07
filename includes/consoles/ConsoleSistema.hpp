#ifndef CONSOLESISTEMA_H
#define CONSOLESISTEMA_H

#include "ConsoleConvidado.hpp"
// #include "../modelos/users/UserConvidado.hpp"

class ConsoleSistema
{
public:
    ConsoleSistema();
    ~ConsoleSistema() = default;

    void imprimirMensagemInicioExecucao();
    void imprimirComandosTelaPrincipal();

private:
};

#endif
#ifndef CONSOLE_AGENTE_HPP
#define CONSOLE_AGENTE_HPP

#include "ConsoleSistema.hpp"

class ConsoleAgente : public ConsoleSistema
{
public:
    ConsoleAgente();
    ~ConsoleAgente() = default;

    virtual void imprimirComandosTelaPrincipal();

private:
};

#endif
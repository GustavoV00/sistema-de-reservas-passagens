#ifndef CONSOLECONVIDADO_HPP
#define CONSOLECONVIDADO_HPP

// #include "../modelos/users/UserConvidado.hpp"
#include <string>

// class UserConvidado;
class ConsoleConvidado
{
public:
    ConsoleConvidado();
    virtual ~ConsoleConvidado() = default;

    void imprimirMensagemInicioExecucaoConvidado();
    void imprimirComandosTelaDeConvidado();
    void imprimirOpcoesGerenciamentoVoos();

    // Verificar se o comando utilizado é para deslogar
    void deslogadoComSucesso();
    bool deslogarDeConvidado(std::string comando);

    void gerenciamentoComandosConvidado(std::string comando);

private:
};

#endif
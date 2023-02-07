#include <iostream>
#include <string>
// #include "./includes/Passageiro.hpp"
// #include "./includes/AgenteViagem.hpp"
#include "includes/utils/Utils.hpp"
// #include "./includes/Reserva.hpp"
// #include "./includes/Voo.hpp"
// #include "./includes/Console.hpp"
#include "includes/consoles/ConsoleSistema.hpp"
#include "includes/consoles/ConsoleConvidado.hpp"
#include "includes/modelos/UsuarioConvidado.hpp"
#include "includes/modelos/Usuario.hpp"

int main()
{
    ConsoleSistema *consoleSistema{};
    UsuarioConvidado usuario{consoleSistema};
    // usuario->setConsoleSistema(new ConsoleSistema{...});

    // ConsoleSistema *console = usuario->getConsoleSistema();

    std::string comando{""};

    // cria o usuário como convidado
    // UserConvidado uc = cs.gerarInstanciaDeUserConvidado();

    // cs.imprimirMensagemInicioExecucao();
    // cv.imprimirMensagemInicioExecucaoConvidado();

    // se for 10 encerra a execução
    while (comando.compare("10") != 0)
    {
        // imprime opções do convidado (ou agente/passageiro)
        // cs.imprimirComandosTelaPrincipal();
        comando = Utils::leComando(comando);

        // unsigned long comandoSucesso{0};

        // Condição de saída do convidado
        // while (cv.deslogarDeConvidado(cmdConvidado))
        // {
        //     cv.imprimirComandosTelaDeConvidado();
        //     cmdConvidado = Utils::leComando(cmdConvidado);
        //     uc.rodarComando(cmdConvidado);
        // }

        // std::cout << comando;

        // Significa que é um usuário convidado
        // Cadastrar / logar como passageiro
        // else if (comando.compare("2") != 0)
        // {
        //     std::string cmdComum{""};
        //     unsigned long comandoSucesso{0};
        //     UserComum userComum = cs->gerarInstanciaDeUserComum();
        //     ConsoleConvidado cv = userConvidado.getConsoleConvidado();
        //     // Condição de saída do convidado
        //     while (cv->deslogarDeConvidado(cmdConvidado))
        //     {
        //         cv->imprimirComandosTelaDeConvidado();
        //         cmdConvidado = Utils::LeComando();
        //         cv->gerenciamendoComandosConvidado(cmdConvidado, UserConvidado);
        //     }
        // }
        // else if (comando.compare("3") != 0)
        // {
        //     // Gerar um usuário admin
        // }
    }

    delete consoleSistema;
    return 0;
}

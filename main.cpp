#include <iostream>
#include <string>
// #include "./includes/Passageiro.hpp"
#include "includes/utils/Utils.hpp"
// #include "./includes/Reserva.hpp"
#include "includes/controles/VooControle.hpp"
// #include "./includes/Console.hpp"
#include "includes/consoles/ConsoleSistema.hpp"
#include "includes/modelos/UsuarioConvidado.hpp"
#include "includes/modelos/Usuario.hpp"
#include "includes/modelos/GerarDados.hpp"
#include "includes/modelos/AgenteViagem.hpp"

#include "includes/consoles/ConsoleAgente.hpp"

int main()
{
    GerarDados gerarDados{};
    VooControle vooControle{};
    PassageiroControle passageiroControle{};
    ReservaControle reservaControle{};
    gerarDados.gerarDadosVoos(&vooControle);
    gerarDados.gerarDadosPassageiros(&passageiroControle);
    // gerarDados.gerarDadosReservas(&reservaControle, &passageiroControle, &vooControle);

    // VooControle vooControle{};
    // UsuarioConvidado *usuarioConvidado{};
    // ConsoleSistema console = usuarioConvidado->getConsoleSistema();

    Usuario *usuario = new UsuarioConvidado{};
    ConsoleSistema *console = new ConsoleSistema{};

    // Pode ser logado como passageiro ou como agente
    // bool logado{false};
    std::string comando{""};

    console->imprimirMensagemInicioExecucao();
    // console->imprimirMensagemInicioExecucao();

    // se for 10 encerra a execução
    while (comando.compare("10") != 0)
    {
        // imprime opções do convidado
        // if (!logado)
        // {
        //     console.imprimirComandosTelaPrincipal();
        // } else {

        // }
        // logado ? () : (console->imprimirComandosTelaPrincipal());
        console->imprimirComandosTelaPrincipal();
        comando = Utils::lerStringTratada("Digite o número da opção escolhida");

        if (comando.compare("1") == 0) // login como passageiro
        {
        }
        else if (comando.compare("2") == 0) // login como agente
        {
            std::list<AgenteViagem *> agentes;
            CPF cpfAgente{11111111111};
            RG rgAgente{111111111};
            agentes.push_back(new AgenteViagem{"Bruno", cpfAgente, rgAgente, "25/01/2001", 41998877875, "bruno43ist@gmail.com", "AV12345"});
            usuario = console->loginAgente(agentes);

            // ALERTA DE XUNXO ABAIXO

            console = new ConsoleAgente{};
            // usuario->rodarGerenciamentoDeVoo(&console);
        }
        else if (comando.compare("3") == 0)
        {
            // usuario->rodarGerenciamentoDeVoo(&console);
        }
        else if (comando.compare("4") == 0)
        {
            // usuario->rodarGerenciamentoDeReservas(&console);
        }

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
    console->finalizarSistema();

    delete usuario;
    return 0;
}

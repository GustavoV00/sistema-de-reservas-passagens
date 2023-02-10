#include <iostream>
#include <string>
// #include "./includes/Passageiro.hpp"
// #include "./includes/AgenteViagem.hpp"
#include "includes/utils/Utils.hpp"
// #include "./includes/Reserva.hpp"
#include "includes/controles/VooControle.hpp"
// #include "./includes/Console.hpp"
#include "includes/consoles/ConsoleSistema.hpp"
#include "includes/modelos/UsuarioConvidado.hpp"
#include "includes/modelos/Usuario.hpp"
#include "includes/modelos/GerarDados.hpp"

int main()
{
    GerarDados gerarDados{};
    VooControle vooControle{};
    PassageiroControle passageiroControle{};
    gerarDados.gerarDadosVoos(&vooControle);
    gerarDados.gerarDadosPassageiros(&passageiroControle);
    // VooControle vooControle{};
    // UsuarioConvidado *usuarioConvidado{};
    // ConsoleSistema console = usuarioConvidado->getConsoleSistema();

    // Pode ser logado como passageiro ou como agente
    // bool logado{false};

    // std::string comando{""};

    // cria o usuário como convidado
    // UserConvidado uc = cs.gerarInstanciaDeUserConvidado();

    // console.imprimirMensagemInicioExecucao();
    // console.imprimirMensagemInicioExecucaoConvidado();

    // se for 10 encerra a execução
    // while (comando.compare("10") != 0)
    // {
    //     // imprime opções do convidado (ou agente/passageiro)
    //     if (!logado)
    //     {
    //         console.imprimirComandosTelaPrincipal();
    //     }
    //     comando = Utils::lerStringTratada(comando);

    //     if (comando.compare("3") == 0)
    //     {
    //         usuarioConvidado->rodarGerenciamentoDeVoo(&console);
    //     }
    //     else if (comando.compare("4") == 0)
    //     {
    //         usuarioConvidado->rodarGerenciamentoDeReservas(&console);
    //     }

    //     // unsigned long comandoSucesso{0};

    //     // Condição de saída do convidado
    //     // while (cv.deslogarDeConvidado(cmdConvidado))
    //     // {
    //     //     cv.imprimirComandosTelaDeConvidado();
    //     //     cmdConvidado = Utils::leComando(cmdConvidado);
    //     //     uc.rodarComando(cmdConvidado);
    //     // }

    //     // std::cout << comando;

    //     // Significa que é um usuário convidado
    //     // Cadastrar / logar como passageiro
    //     // else if (comando.compare("2") != 0)
    //     // {
    //     //     std::string cmdComum{""};
    //     //     unsigned long comandoSucesso{0};
    //     //     UserComum userComum = cs->gerarInstanciaDeUserComum();
    //     //     ConsoleConvidado cv = userConvidado.getConsoleConvidado();
    //     //     // Condição de saída do convidado
    //     //     while (cv->deslogarDeConvidado(cmdConvidado))
    //     //     {
    //     //         cv->imprimirComandosTelaDeConvidado();
    //     //         cmdConvidado = Utils::LeComando();
    //     //         cv->gerenciamendoComandosConvidado(cmdConvidado, UserConvidado);
    //     //     }
    //     // }
    //     // else if (comando.compare("3") != 0)
    //     // {
    //     //     // Gerar um usuário admin
    //     // }
    // }
    // console.finalizarSistema();

    // delete usuarioConvidado;
    return 0;
}

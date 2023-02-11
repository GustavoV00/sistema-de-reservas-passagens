#include <iostream>
#include <string>
#include <list>
// #include "./includes/Passageiro.hpp"
#include "includes/utils/Utils.hpp"
// #include "./includes/Reserva.hpp"
#include "includes/controles/VooControle.hpp"
#include "includes/controles/PassageiroControle.hpp"
// #include "./includes/Console.hpp"

#include "includes/modelos/UsuarioConvidado.hpp"
#include "includes/modelos/Usuario.hpp"
#include "includes/modelos/GerarDados.hpp"
#include "includes/modelos/AgenteViagem.hpp"

#include "includes/consoles/ConsoleSistema.hpp"
#include "includes/consoles/ConsoleAgente.hpp"

int main()
{
    // classes de controle dos dados de voos, passageiros e reservas
    VooControle *vooControle = new VooControle{};
    PassageiroControle *passageiroControle = new PassageiroControle{};
    ReservaControle *reservaControle = new ReservaControle{};

    GerarDados gerarDados{};
    gerarDados.gerarDadosVoos(vooControle);

    gerarDados.gerarDadosPassageiros(passageiroControle);
    gerarDados.gerarDadosReservas(reservaControle, passageiroControle, vooControle);

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
        console->imprimirComandosTelaPrincipal();
        comando = Utils::lerStringTratada("Digite o número da opção escolhida");

        // encerra execução
        if (comando.compare("10") == 0)
        {
            break;
        }

        if (comando.compare("1") == 0) // login como passageiro
        {
        }
        else if (comando.compare("2") == 0) // login como agente
        {
            std::list<AgenteViagem *> agentes;
            CPF cpfAgente{11111111111};
            RG rgAgente{111111111};
            agentes.push_back(new AgenteViagem{"Bruno", cpfAgente, rgAgente, "25/01/2001", 41998877875, "bruno43ist@gmail.com", "AV12345"});

            Usuario *novoUsuarioAgente = console->loginAgente(agentes);
            if (novoUsuarioAgente != nullptr)
            {
                delete usuario;
                usuario = novoUsuarioAgente;
                delete console;                // exclui o console atual
                console = new ConsoleAgente{}; // cria um console para agentes
                std::cout << "Mudou console!" << std::endl;
            }
        }
        else if (comando.compare("3") == 0)
        {
            console->rodarGerenciamentoDeVoo(vooControle);
        }
        else if (comando.compare("4") == 0)
        {
            console->rodarGerenciamentoDeReservas();
        }
    }

    // liberar memória

    console->finalizarSistema();

    delete console;
    delete usuario;
    return 0;
}

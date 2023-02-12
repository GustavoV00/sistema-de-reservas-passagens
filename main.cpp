#include <iostream>
#include <string>
#include <list>

#include "includes/utils/Utils.hpp"
#include "includes/controles/VooControle.hpp"
#include "includes/controles/PassageiroControle.hpp"

#include "includes/modelos/UsuarioConvidado.hpp"
#include "includes/modelos/Usuario.hpp"
#include "includes/modelos/GerarDados.hpp"

#include "includes/modelos/Passageiro.hpp"
#include "includes/modelos/AgenteViagem.hpp"

#include "includes/consoles/ConsoleSistema.hpp"
#include "includes/consoles/ConsoleAgente.hpp"
#include "includes/consoles/ConsolePassageiro.hpp"

int main()
{
    // classes de controle dos dados de voos, passageiros e reservas
    VooControle *vooControle{nullptr};
    PassageiroControle *passageiroControle{nullptr};
    ReservaControle *reservaControle{nullptr};
    Usuario *usuario{nullptr};
    ConsoleSistema *console{nullptr};

    try
    {
        vooControle = new VooControle{};
        passageiroControle = new PassageiroControle{};
        reservaControle = new ReservaControle{};
        usuario = new UsuarioConvidado{};
        console = new ConsoleSistema{};
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao alocar memória dinâmicamente!" << std::endl;
        return 1;
    }

    // geração de dados pra preencher o sistema inicialmente
    GerarDados gerarDados{};
    gerarDados.gerarDadosVoos(vooControle);
    gerarDados.gerarDadosPassageiros(passageiroControle);
    gerarDados.gerarDadosReservas(reservaControle, passageiroControle, vooControle);

    // Pode ser logado como passageiro ou como agente
    bool usuarioLogado{false};
    std::string comando{""};

    console->imprimirMensagemInicioExecucao();

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
            // comando = Utils::lerStringTratada("Digite o número da opção escolhida");
            std::list<Passageiro *> passageiros = passageiroControle->obterTodosOsPassageiros();
            Passageiro *passageiroLogado = console->loginPassageiro(passageiros);
            if (passageiroLogado != nullptr)
            {
                try
                {
                    delete usuario;
                    usuario = passageiroLogado;
                    delete console;
                    console = new ConsolePassageiro{};
                    usuarioLogado = true;
                }
                catch (std::exception &e)
                {
                    std::cout << "Erro ao logar como passageiro!" << std::endl;
                }
            }
            else
            {
                std::cout << "Falha ao logar como passsageiro!" << std::endl;
            }
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
                try
                {
                    delete usuario;
                    usuario = novoUsuarioAgente;
                    delete console;                // exclui o console atual
                    console = new ConsoleAgente{}; // cria um console para agentes
                    usuarioLogado = true;
                }
                catch (std::exception &e)
                {
                    std::cout << "Erro ao logar como passageiro!" << std::endl;
                }
            }
            else
            {
                std::cout << "Falha ao logar como agente!" << std::endl;
            }
        }
        else if (comando.compare("3") == 0)
        {
            console->rodarGerenciamentoDeVoo(vooControle);
        }
        else if (comando.compare("4") == 0)
        {
            console->rodarGerenciamentoDeReservas(reservaControle, passageiroControle, vooControle, usuario);
        }
        else if (comando.compare("5") == 0)
        {
            if (!usuarioLogado)
            {
                std::cout << "Precisa estar logado como Agente para realizar essa função!" << std::endl;
            }
            else
            {
                console->rodarGerenciamentoDePassageiros(passageiroControle, usuario, reservaControle);
            }
        }
    }

    // liberar memória

    console->finalizarSistema();

    delete console;
    delete usuario;
    return 0;
}

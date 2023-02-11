#include <iostream>
#include "../../includes/consoles/ConsoleSistema.hpp"
#include "../../includes/utils/Utils.hpp"

#include "../../includes/modelos/AgenteViagem.hpp" //forward declaration

ConsoleSistema::ConsoleSistema()
{
}

void ConsoleSistema::imprimirMensagemInicioExecucao()
{
    std::cout << std::endl
              << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << "Bem-Vindo(a) ao Sistema de Reserva de Passagens Aéreas (SRP)!" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl
              << std::endl;
}

// imprime opções de comando quando o usuário é convidado
void ConsoleSistema::imprimirComandosTelaPrincipal()
{
    // imprimeStatusLogin();
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << " 1) FAZER LOGIN COMO PASSAGEIRO" << std::endl;
    std::cout << " 2) FAZER LOGIN COMO AGENTE" << std::endl;
    std::cout << " 3) MOSTRAR OPÇÕES DE VOOS" << std::endl;
    std::cout << " 4) MOSTRAR OPÇÕES DE RESERVAS" << std::endl;
    std::cout << "10) SAIR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

// mensagens de boa vinda quando o usuário convidado entra no sistema
/*
void ConsoleSistema::imprimirMensagemInicioExecucao()
{
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << "Você acessou o sistema como Convidado!" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl
              << std::endl;
}
*/

void ConsoleSistema::imprimirOpcoesGerenciamentoVoos()
{
    std::cout << std::endl;
    std::cout << "-------------------------GERENCIAMENTO DE VOOS------------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) LISTAR VOOS" << std::endl;
    std::cout << "2) CRIAR VOO" << std::endl;
    std::cout << "3) EDITAR VOO" << std::endl;
    std::cout << "4) EXCLUIR VOO" << std::endl;
    std::cout << "5) VOLTAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void ConsoleSistema::imprimirOpcoesGerenciamentoDeReservas()
{
    std::cout << std::endl;
    std::cout << "-------------------------GERENCIAMENTO DE VOOS------------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) LISTAR RESERVAS" << std::endl;
    std::cout << "2) CRIAR  RESERVAS" << std::endl;
    std::cout << "3) EDITAR RESERVAS" << std::endl;
    std::cout << "4) EXCLUIR  RESERVAS" << std::endl;
    std::cout << "5) VOLTAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void ConsoleSistema::finalizarSistema()
{
    std::cout << std::endl
              << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << "Sistema desligado com Sucesso!" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl
              << std::endl;
}

// bool ConsoleSistema::deslogarDeConvidado(std::string comando)
// {
//     if (comando.compare("10") == 0)
//     {
//         this->deslogadoComSucesso();
//         return false;
//     }
//     return true;
// }

AgenteViagem *ConsoleSistema::loginAgente(std::list<AgenteViagem *> &agentes)
{
    std::cout << "----------------------LOGIN----------------------" << std::endl;
    std::string resposta;
    std::cout << "Deseja listar novamente os agentes? (S/n): ";
    std::getline(std::cin, resposta);
    while (resposta.compare("S") != 0 && resposta.compare("n") != 0)
    {
        std::cout << "Deseja listar novamente os agentes? (S/n): ";
        std::getline(std::cin, resposta);
    }

    if (resposta.compare("S") == 0)
    {
        Utils::imprimirListaAgentes(agentes);
    }

    std::cout << std::endl;

    std::string login{""}, senha{""};
    bool logado = false;
    std::cout << "Digite o login (CPF, Email ou Código) do agente para logar: ";
    std::getline(std::cin, login);
    while (!logado && login.compare("SAIR") != 0)
    {
        // pesquisa na lista de agentes
        std::list<AgenteViagem *>::iterator it;
        for (it = agentes.begin(); it != agentes.end(); it++)
        {
            if (std::to_string((*it)->getCpf().getNumero()).compare(login) == 0 || (*it)->getEmail().compare(login) == 0 || (*it)->getCodigo().compare(login) == 0)
            {
                std::cout << "Encontrou agente! Logando..." << std::endl;
                return *it;
            }
            else
            {
                std::cout << "Não encontrou agente com esse login!" << std::endl;
            }
        }

        std::cout << "Digite o login (CPF, Email ou Código): ";
        std::getline(std::cin, login);
    }

    return nullptr;
}
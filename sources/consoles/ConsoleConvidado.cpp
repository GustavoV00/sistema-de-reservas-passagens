#include <iostream>
#include "../../includes/consoles/ConsoleConvidado.hpp"
#include "../../includes/utils/Utils.hpp"

ConsoleConvidado::ConsoleConvidado()
{
}

// ConsoleConvidado::~ConsoleConvidado()
// {
// }

void ConsoleConvidado::imprimirMensagemInicioExecucaoConvidado()
{
    std::cout << std::endl
              << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << "Você acessou o sistema como Convidado!" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl
              << std::endl;
}

void ConsoleConvidado::imprimirComandosTelaDeConvidado()
{
    std::cout << std::endl;
    std::cout << "----------------------PAINEL DE CONVIDADO--------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) OPÇÕES VOOS" << std::endl;
    std::cout << "2) OPÇÕES DE RESERVAS - N FUNCIONA POR ENQUANTO" << std::endl;
    std::cout << "3) OPÇÕES DE PASSAGEIROS - N FUNCIONA POR ENQUANTO" << std::endl;
    std::cout << "10) DESLOGAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void ConsoleConvidado::imprimirOpcoesGerenciamentoVoos()
{
    std::cout << std::endl;
    std::cout << "-------------------------GERENCIAMENTO DE VOOS------------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) LISTAR VOOS" << std::endl;
    std::cout << "5) VOLTAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void ConsoleConvidado::deslogadoComSucesso()
{
    std::cout << std::endl
              << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << "Usuário deslogado com Sucesso!" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl
              << std::endl;
}

bool ConsoleConvidado::deslogarDeConvidado(std::string comando)
{
    if (comando.compare("10") == 0)
    {
        this->deslogadoComSucesso();
        return false;
    }
    return true;
}

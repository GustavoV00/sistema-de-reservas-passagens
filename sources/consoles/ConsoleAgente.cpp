#include <iostream>
#include "../../includes/consoles/ConsoleAgente.hpp"
#include "../../includes/utils/Utils.hpp"

ConsoleAgente::ConsoleAgente()
{
}

void ConsoleAgente::imprimirComandosTelaPrincipal()
{
    // imprimeStatusLogin();
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << " 1) FAZER LOGIN COMO PASSAGEIRO" << std::endl;
    std::cout << " 2) FAZER LOGIN COMO OUTRO AGENTE" << std::endl;
    std::cout << " 3) MOSTRAR OPÇÕES DE VOOS" << std::endl;
    std::cout << " 4) MOSTRAR OPÇÕES DE RESERVAS" << std::endl;
    std::cout << "10) SAIR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    // std::cout << "testeeeereee" << std::endl;
}

void ConsoleAgente::imprimirOpcoesGerenciamentoVoos()
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

void ConsoleAgente::cadastrarVooInterface()
{
}

// usuário agente tem todas as permissões para gerenciar os voos
void ConsoleAgente::rodarGerenciamentoDeVoo(VooControle *vooControle)
{
    std::string comando{""};
    while (comando.compare("5") != 0)
    {
        imprimirOpcoesGerenciamentoVoos();
        comando = Utils::lerStringTratada("Digite o número da opção escolhida");
        if (comando.compare("1") == 0)
        {
            Utils::imprimirListaVoos(vooControle->obterTodosOsVoos());
        }
        else if (comando.compare("2") == 0)
        {
            std::cout << "Aqui chama a função de cadastrar voo" << std::endl;
            cadastrarVooInterface();
        }
        else if (comando.compare("3") == 0)
        {
            std::cout << "Aqui chama a função de atualizar voo" << std::endl;
        }
        else if (comando.compare("4") == 0)
        {
            std::cout << "Aqui chama a função de excluir voo" << std::endl;
        }
        std::cout << std::endl;
    }
}

void ConsoleAgente::imprimirOpcoesGerenciamentoDeReservas()
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

void ConsoleAgente::rodarGerenciamentoDeReservas()
{
    std::string comando{""};
    while (comando.compare("5") != 0)
    {
        this->imprimirOpcoesGerenciamentoDeReservas();
        comando = Utils::lerStringTratada("Digite o número da opção escolhida");
        // Listar
        if (comando.compare("1") == 0)
        {
            std::cout << "Aqui chama a função de listar reservas, mas deve ser lançado uma exceção!" << std::endl;
        }
        // Cadastrar
        else if (comando.compare("2") == 0)
        {
            std::cout << "Aqui o UsuarioConvidado deve ser redirecionado para uma página de cadastro de passageiro e logo em seguida fazer a reserva" << std::endl;
        }
        else if (comando.compare("3") == 0)
        {
            std::cout << "Aqui chama a função de atualizar reserva, mas deve ser lançado uma exceção!" << std::endl;
        }
        else if (comando.compare("4") == 0)
        {
            std::cout << "Aqui chama a função de excluir reserva, mas deve ser lançado uma exceção!" << std::endl;
        }
        std::cout << std::endl;
    }
}
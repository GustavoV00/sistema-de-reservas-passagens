
#include <iostream>
#include "../../includes/modelos/UsuarioConvidado.hpp"
#include "../../includes/modelos/Usuario.hpp"
#include "../../includes/utils/Utils.hpp"
#include "../../includes/consoles/ConsoleSistema.hpp"

UsuarioConvidado::UsuarioConvidado()
    : Usuario()
{
}

// UsuarioConvidado::~UsuarioConvidado()
// {
// }

void UsuarioConvidado::rodarGerenciamentoDeVoo(ConsoleSistema *console)
{
    std::string comando{""};
    while (comando.compare("5") != 0)
    {

        console->imprimirOpcoesGerenciamentoVoos();
        comando = Utils::lerStringTratada(comando);
        if (comando.compare("1") == 0)
        {
            std::cout << "UsuarioConvidado tem permissão para ver os voos!" << std::endl;
            std::cout << "Aqui chama a função de listar voos" << std::endl;
        }
        else if (comando.compare("2") == 0)
        {
            std::cout << "UsuárioConvidado não tem permissão de fazer isso!" << std::endl;
            std::cout << "Aqui chama a função de cadastrar voo, mas deve ser lançado uma exceção!" << std::endl;
        }
        else if (comando.compare("3") == 0)
        {
            std::cout << "UsuárioConvidado não tem permissão de fazer isso!" << std::endl;
            std::cout << "Aqui chama a função de atualizar voo, mas deve ser lançado uma exceção!" << std::endl;
        }
        else if (comando.compare("4") == 0)
        {
            std::cout << "UsuárioConvidado não tem permissão de fazer isso!" << std::endl;
            std::cout << "Aqui chama a função de excluir voo, mas deve ser lançado uma exceção!" << std::endl;
        }
        std::cout << std::endl;
    }
}
void UsuarioConvidado::rodarGerenciamentoDeReservas(ConsoleSistema *console)
{
    {
        std::string comando{""};
        while (comando.compare("5") != 0)
        {

            console->imprimirOpcoesGerenciamentoDeReservas();
            comando = Utils::lerStringTratada(comando);
            // Listar
            if (comando.compare("1") == 0)
            {
                std::cout << "UsuarioConvidado não permissão para ver as reservas!" << std::endl;
                std::cout << "Aqui chama a função de listar reservas, mas deve ser lançado uma exceção!" << std::endl;
            }
            // Cadastrar
            else if (comando.compare("2") == 0)
            {
                std::cout << "UsuarioConvidado pode se cadastrar como passageiro e fazer uma reserva!" << std::endl;
                std::cout << "Aqui o UsuarioConvidado deve ser redirecionado para uma página de cadastro de passageiro e logo em seguida fazer a reserva" << std::endl;
            }
            else if (comando.compare("3") == 0)
            {
                std::cout << "UsuárioConvidado não tem permissão de fazer isso!" << std::endl;
                std::cout << "Aqui chama a função de atualizar reserva, mas deve ser lançado uma exceção!" << std::endl;
            }
            else if (comando.compare("4") == 0)
            {
                std::cout << "UsuárioConvidado não tem permissão de fazer isso!" << std::endl;
                std::cout << "Aqui chama a função de excluir reserva, mas deve ser lançado uma exceção!" << std::endl;
            }
            std::cout << std::endl;
        }
    }
}
#include "../../includes/modelos/UsuarioConvidado.hpp"
#include <iostream>

// #include "../../../includes/consoles/ConsoleConvidado.hpp"
// #include "../../../includes/utils/Utils.hpp"

// UsuarioConvidado::UsuarioConvidado(const std::string &nome, const CPF &cpf, const RG &rg,
//                                    const std::string &dataDeNascimento, const unsigned long &contato, const std::string &email)
//     : Usuario{nome, cpf, rg, dataDeNascimento, contato, email}
// {
// }

UsuarioConvidado::UsuarioConvidado()
{
}

UsuarioConvidado::UsuarioConvidado(ConsoleSistema *consoleSistema)
    : Usuario{consoleSistema}
{
}

UsuarioConvidado::~UsuarioConvidado()
{
}

// void UserConvidado::setConsoleConvidado(ConsoleConvidado consoleConvidado)
// {
//     this->consoleConvidado = consoleConvidado;
// }

// ConsoleConvidado UserConvidado::getConsoleConvidado()
// {
//     return this->consoleConvidado;
// }

// void UserConvidado::rodarComando(std::string comando)
// {
//     if (comando.compare("1") == 0)
//     {
//         ConsoleConvidado cv = this->getConsoleConvidado();
//         while (comando.compare("5") != 0)
//         {
//             cv.imprimirOpcoesGerenciamentoVoos();
//             comando = Utils::leComando(comando);
//             if (comando.compare("1") == 0)
//             {
//                 std::cout << "Aqui chama a função de listar voos";
//             }
//         }
//     }
// }
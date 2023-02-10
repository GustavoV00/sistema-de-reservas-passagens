#include <iostream>
#include "../../includes/consoles/ConsoleSistema.hpp"
// #include "../../includes/modelos/users/UserConvidado.hpp"

ConsoleSistema::ConsoleSistema()
{
}

// ConsoleSistema::~ConsoleSistema()
// {
// }

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

void ConsoleSistema::imprimirComandosTelaPrincipal()
{
    // imprimeStatusLogin();
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << " 1) FAZER LOGIN COMO PASSAGEIRO" << std::endl;
    std::cout << " 2) FAZER LOGIN COMO AGENTE" << std::endl;
    std::cout << " 3) MOSTRAR OPÇÕES DE VOOS" << std::endl;
    std::cout << " 4) MOSTRAR OPÇÕES DE RESERVAS" << std::endl;
    // if (verificaUsuarioEhAgente())
    // {
    //     std::cout << " 5) GERENCIAR VOOS" << std::endl;
    // }
    std::cout << "10) SAIR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

// UserComum ConsoleSistema::gerarInstanciaDeUserConvidado()
// {
// }

// UserAdmin ConsoleSistema::gerarInstanciaDeUserConvidado()
// {
// }

void ConsoleSistema::imprimirMensagemInicioExecucaoConvidado()
{
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << "Você acessou o sistema como Convidado!" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl
              << std::endl;
}

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
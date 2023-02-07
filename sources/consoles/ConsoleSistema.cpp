#include <iostream>
#include "../../includes/consoles/ConsoleSistema.hpp"
#include "../../includes/consoles/ConsoleConvidado.hpp"
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
    // std::cout << " 3) GERENCIAR PASSAGEIROS" << std::endl;
    // std::cout << " 4) GERENCIAR RESERVAS" << std::endl;
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

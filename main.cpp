#include <iostream>
#include <string>
#include "./includes/Passageiro.hpp"
#include "./includes/AgenteViagem.hpp"
#include "./includes/Utils.hpp"
#include "./includes/Reserva.hpp"
#include "./includes/Voo.hpp"
#include "./includes/Console.hpp"

int main(){
    Utils::imprimirMensagemInicioExecucao();
    Utils::imprimirFuncoesAgentePassageiro();

    std::list<AgenteViagem*> agentes;
    std::list<Passageiro*> passageiros;
    std::list<Reserva*> reservas;
    std::list<Voo*> voos;

    //cria agente 'default'
    CPF cpfAgente{11111111111};
    RG rgAgente{111111111};

    AgenteViagem *agente = new AgenteViagem{"Agente 1", cpfAgente, rgAgente, "01/01/1993", 04133333333, "agente1@gmail.com", "AV1234"};
    agentes.push_back(agente);
    Utils::imprimirListaAgentes(agentes);

    CPF cpfPassageiro1{22222222222};
    RG rgPassageiro1{222222222};

    Passageiro *passageiro1 = new Passageiro{"Passageiro 1", cpfPassageiro1, rgPassageiro1, "02/02/1996", 04166666666, "passageiro1@gmail.com"};
    passageiros.push_back(passageiro1);

    CPF cpfPassageiro2{33333333333};
    RG rgPassageiro2{333333333};

    Passageiro *passageiro2 = new Passageiro{"Passageiro 2", cpfPassageiro2, rgPassageiro2, "02/02/1998", 04177777777, "passageiro2@gmail.com"};
    passageiros.push_back(passageiro2);
    Utils::imprimirListaPassageiros(passageiros);

    Voo *voo = new Voo{"AD1234", "CWB", "POA", 120};
    voos.push_back(voo);
    
    Pessoa *usuario{nullptr};
    bool usuarioEhAgente = false;
    Console console{usuario, usuarioEhAgente};
    console.imprimirComandosTelaPrincipal();

    
    std::string comando{""};
    std::cout << "Digite o NÚMERO da opção escolhida: " << std::endl << "> ";
    std::getline(std::cin, comando);
    while(comando.compare("SAIR") != 0){
        // std::cout << "Comando lido: " << comando << std::endl;
        if(comando.compare("1") == 0){
            usuario = Console::loginAgente(agentes);
            if(usuario != nullptr){
                std::cout << "Encontrou! Logado como" << usuario->getNome() << std::endl;
                usuarioEhAgente = true;
            } else {
                std::cout << "Falha ao encontrar agente!" << std::endl;
            }
        } else if(comando.compare("2") == 0){
            usuario = Console::loginPassageiro(passageiros);
            if(usuario != nullptr){
                std::cout << "Encontrou! Logado como" << usuario->getNome() << std::endl;
            } else {
                std::cout << "Falha ao encontrar passageiro!" << std::endl;
            }
        } else if(comando.compare("3") == 0){
            console.gerenciarPassageiros(passageiros);
        } else if(comando.compare("4") == 0){
            console.gerenciarReservas(agentes, passageiros, reservas, voos);
        } else if(comando.compare("10") == 0){
            break;
        }

        
        console.imprimirComandosTelaPrincipal();
        std::cout << "> ";
        std::getline(std::cin, comando);
    }

    Utils::imprimirMensagemFinalExecucao();
    //Pessoa pessoa{"Bruno Farias", cpfBruno, rgBruno, "25/01/2001", 41998877875, "bruno43ist@yahoo.com.br"};
    // Passageiro passageiro{"Bruno Farias", cpfBruno, rgBruno, "25/01/2001", 41998877875, "bruno43ist@yahoo.com.br"};
    // passageiro.imprimirDadosFormatados();

    // 

    // Reserva reserva{"ABC", passageiro, voo, "13A"};

    // reserva.imprimirDadosReserva();

    while(!agentes.empty()){
        delete agentes.front();
        agentes.pop_front();
    }
    while(!passageiros.empty()){
        delete passageiros.front();
        passageiros.pop_front();
    }

    return 0;
}


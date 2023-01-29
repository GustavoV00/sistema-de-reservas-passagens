/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#include <iostream>
#include <list>
#include "./../includes/Utils.hpp"

Utils::Utils(){

}

void Utils::imprimirMensagemInicioExecucao(){
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << "Bem-Vindo(a) ao Sistema de Reserva de Passagens Aéreas (SRP)!" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << std::endl;
}

void Utils::imprimirMensagemFinalExecucao(){
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << "Muito obrigado por utilizar o nosso sistema! Esperamos te ver em breve! :)" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << std::endl;
}

void Utils::imprimirFuncoesAgentePassageiro(){
    // std::cout << std::endl;
    std::cout << "--------------------------------FUNÇÕES--------------------------------" << std::endl;
    std::cout << "Passageiro: Reservar, acessar e editar suas reservas, Fazer alterações no seu perfil" << std::endl;
    std::cout << "Agente: Todas as funções acima, além de cadastrar, editar e excluir Voos" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void Utils::imprimirListaAgentes(std::list<AgenteViagem*>& agentes){
    std::cout << std::endl << "Agentes: " << std::endl;
    std::list<AgenteViagem*>::iterator it;
    for (it = agentes.begin(); it != agentes.end(); it++){
        std::cout << "=================================================================================" << std::endl;
        std::cout << "Nome: " << (*it)->getNome() << " - CPF: " << (*it)->getCpf().getNumero() 
                  << " - Email: " <<  (*it)->getEmail() << " - Código: " << (*it)->getCodigo() << std::endl;
    }
    std::cout << "=================================================================================" << std::endl;
}

void Utils::imprimirListaPassageiros(std::list<Passageiro*>& passageiros){
    std::cout  << std::endl << "Passageiros: " << std::endl;
    std::list<Passageiro*>::iterator it;
    for (it = passageiros.begin(); it != passageiros.end(); it++){
        std::cout << "=================================================================================" << std::endl;
        std::cout << "Nome: " << (*it)->getNome() << " - CPF: " << (*it)->getCpf().getNumero() 
                  << " - Email: " << (*it)->getEmail() << std::endl;
    }
    std::cout << "=================================================================================" << std::endl;
}

std::string Utils::lerStringTratada(std::string mensagem){
    std::string retorno{""};
    std::cout << mensagem << ": ";
    std::getline(std::cin, retorno);
    while(retorno.compare("SAIR") != 0){
        if(retorno.compare("") != 0){
            break;   
        }
        std::cout << "Campo não pode ser vazio!" << std::endl;
        std::cout << mensagem << ": ";
        std::getline(std::cin, retorno);
    }

    return retorno;
}


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
        std::cout << "=====================================================================================" << std::endl;
        std::cout << "Nome: " << (*it)->getNome() << " - CPF: " << (*it)->getCpf().getNumero() << " - RG: " << (*it)->getRg().getNumero() << std::endl;
        std::cout << "Email: " << (*it)->getEmail() << " - Telefone: " << (*it)->getContato() << " - Data de Nascimento: " << (*it)->getDataDeNascimento() << std::endl;
        std::cout << "Código: " << (*it)->getCodigo() << std::endl;
    }
    std::cout << "=====================================================================================" << std::endl;
}

void Utils::imprimirListaPassageiros(std::list<Passageiro*>& passageiros){
    std::cout  << std::endl << "Passageiros: " << std::endl;
    std::list<Passageiro*>::iterator it;
    for (it = passageiros.begin(); it != passageiros.end(); it++){
        std::cout << "=====================================================================================" << std::endl;
        std::cout << "Nome: " << (*it)->getNome() << " - CPF: " << (*it)->getCpf().getNumero() << " - RG: " << (*it)->getRg().getNumero() << std::endl;
        std::cout << "Email: " << (*it)->getEmail() << " - Telefone: " << (*it)->getContato() << " - Data de Nascimento: " << (*it)->getDataDeNascimento() << std::endl;
    }
    std::cout << "=====================================================================================" << std::endl;
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

CPF* Utils::lerCPFTratado(std::string mensagem) {
    std::string retorno{""};
    std::cout << mensagem << ": ";
    std::getline(std::cin, retorno);
    CPF *cpf;
    while(retorno.compare("SAIR") != 0){
        if(retorno.compare("") != 0){
            try {
                cpf = new CPF{stoul(retorno)};
                return cpf;
            } catch (DocumentoInvalidoException &die) {
                std::cout << "CPF inválido!" << std::endl;
            } catch (std::exception &die) {
                std::cout << "CPF pode ter apenas números!" << std::endl;
            }
        } else {
            std::cout << "Campo não pode ser vazio!" << std::endl;
        }
        
        std::cout << mensagem << ": ";
        std::getline(std::cin, retorno);
    }

    return nullptr;
}
RG* Utils::lerRGTratado(std::string mensagem){
    std::string retorno{""};
    std::cout << mensagem << ": ";
    std::getline(std::cin, retorno);
    RG *rg;
    while(retorno.compare("SAIR") != 0){
        if(retorno.compare("") != 0){
            try {
                rg = new RG{stoul(retorno)};
                return rg;
            } catch (DocumentoInvalidoException &die) {
                std::cout << "RG inválido!" << std::endl;
            } catch (std::exception &die) {
                std::cout << "RG pode ter apenas números!" << std::endl;
            }
        } else {
            std::cout << "Campo não pode ser vazio!" << std::endl;
        }
        
        std::cout << mensagem << ": ";
        std::getline(std::cin, retorno);
    }

    return nullptr;
}

std::string Utils::lerDataNascimentoTratada(std::string mensagem){
    std::string retorno{""};
    std::cout << mensagem << ": ";
    std::getline(std::cin, retorno);
    while(retorno.compare("SAIR") != 0){
        if(retorno.compare("") != 0){
            if(retorno.at(2) == '/' && retorno.at(5) == '/'){
                try {
                    int dia = stoi(retorno.substr(0,2));
                    int mes = stoi(retorno.substr(3,5));
                    int ano = stoi(retorno.substr(6,9));
                    if(dia > 0 && dia <= 31 && mes > 0 && mes <= 12 && ano > 1900 && ano <= 2023){
                        return retorno;
                    } else {
                        std::cout << "Data não está no intervalo aceito!" << std::endl;
                    }
                } catch(std::exception &e) {
                    std::cout << "Falha na leitura da data de nascimento! " << std::endl;
                }
               
            } else {
                std::cout << "Data de nascimento fora do padrão dd/MM/yyyy" << std::endl;
            }
        } else {
            std::cout << "Campo não pode ser vazio!" << std::endl;
        }
       
        std::cout << mensagem << ": ";
        std::getline(std::cin, retorno);
    }

    return retorno;
}

unsigned long Utils::lerTelefoneTratado(std::string mensagem) {
    std::string retorno{""};
    std::cout << mensagem << ": ";
    std::getline(std::cin, retorno);
    while(retorno.compare("SAIR") != 0){
        if(retorno.compare("") != 0){
            try {
                return stoul(retorno);
            } catch(std::exception &e){
                std::cout << "Falha ao ler número de telefone!" << std::endl;
            } 
        } else {
            std::cout << "Campo não pode ser vazio!" << std::endl;
        }
        
        std::cout << mensagem << ": ";
        std::getline(std::cin, retorno);
    }

    return 0;
}


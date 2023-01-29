/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
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

void Utils::imprimirListaReservas(std::list<Reserva*> reservas){
    std::cout  << std::endl << "Reservas: " << std::endl;
    std::list<Reserva*>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); it++){
        std::cout << "=====================================================================================" << std::endl;
        (*it)->imprimirDadosReserva();
    }
    std::cout << "=====================================================================================" << std::endl;

}

void Utils::imprimirListaVoos(std::list<Voo*>& voos){
    std::cout  << std::endl << "Voos: " << std::endl;
    std::list<Voo*>::iterator it;
    for (it = voos.begin(); it != voos.end(); it++){
        std::cout << "=====================================================================================" << std::endl;
        (*it)->imprimirDadosVoo();
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

std::string Utils::lerDataTratada(std::string mensagem){
    std::string retorno{""};
    std::cout << mensagem << ": ";
    std::getline(std::cin, retorno);
    while(retorno.compare("SAIR") != 0){
        if(retorno.compare("") != 0){
            if(formatoData(retorno)){
                return retorno;
            } else {
                std::cout << "Data fora do padrão dd/MM/yyyy" << std::endl;
            }
        } else {
            std::cout << "Campo não pode ser vazio!" << std::endl;
        }
       
        std::cout << mensagem << ": ";
        std::getline(std::cin, retorno);
    }

    throw FormatoInvalidoException{"Data inválida!"};
    // return retorno;
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

//gera um número aleatório entre 1000 e 1999
int Utils::geradorNumeroAleatorio(){
    srand((unsigned) time(NULL));
    return rand() % 9000 + 1000;
}

bool Utils::assentoOcupado(const std::string& assento, std::list<std::string> assentosOcupados){
    std::list<std::string>::iterator it;
    for (it = assentosOcupados.begin(); it != assentosOcupados.end(); it++){
        if((*it).compare(assento) == 0){
            return true;
        }
    }
    return false;
}

bool Utils::formatoData(const std::string& data){
    if(data.at(2) == '/' && data.at(5) == '/'){
        try {
            int dia = stoi(data.substr(0,2));
            int mes = stoi(data.substr(3,5));
            int ano = stoi(data.substr(6,9));
            if(dia > 0 && dia <= 31 && mes > 0 && mes <= 12 && ano > 1900 && ano <= 2024){
                return true;
            } else {
                std::cout << "Data não está no intervalo aceito!" << std::endl;
            }
        } catch(std::exception &e) {
            std::cout << "Falha na leitura da data de nascimento! " << std::endl;
        }
    } else {
        std::cout << "Data de nascimento fora do padrão dd/MM/yyyy" << std::endl;
    }
    return false;
}

bool Utils::formatoHoraHHMM(const std::string& horario){
    if(horario.at(2) == ':'){
        try {
            int hora = stoi(horario.substr(0,2));
            int minuto = stoi(horario.substr(3,5));
            if(hora >= 0 && hora <= 23 && minuto >= 0 && minuto <= 59){
                return true;
            } else {
                std::cout << "Horário fora do range permitido!" << std::endl;
            }
        } catch(std::exception &e) {
            std::cout << "Falha na leitura do horário! " << std::endl;
        }
    } else {
        std::cout << "Horario fora do padrão HH:MM" << std::endl;
    }

    return false;
}

std::string Utils::lerHorarioTratado(std::string mensagem){
    std::string retorno{""};
    std::cout << mensagem << " (HH:MM): ";
    std::getline(std::cin, retorno);
    while(retorno.compare("SAIR") != 0){
        if(retorno.compare("") != 0){
            if(formatoHoraHHMM(retorno)){
                return retorno;
            } else {
                std::cout << "Horário fora do padrão HH:MM" << std::endl;
            }
        } else {
            std::cout << "Campo não pode ser vazio!" << std::endl;
        }
       
        std::cout << mensagem << " (HH:MM): ";
        std::getline(std::cin, retorno);
    }

    throw FormatoInvalidoException{"Data inválida!"};
    // return retorno;
}

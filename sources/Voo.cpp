/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#include <iostream>
#include <string>

#include "./../includes/Reserva.hpp"
#include "./../includes/Utils.hpp"
#include "./../includes/Voo.hpp"
#include "./../includes/CapacidadeIncorretaException.hpp"
#include "./../includes/FormatoInvalidoException.hpp"

Voo::Voo(std::string numeroDoVoo, std::string partida, std::string destino, int capacidade, std::string data, std::string horarioPartida, std::string horarioChegada) 
        : numeroDoVoo(numeroDoVoo), partida(partida), destino(destino){
    this->setCapacidade(capacidade);
    this->setAssentosDisponiveis(capacidade);
    this->setHorarioPartida(horarioPartida);
    this->setHorarioChegada(horarioChegada);
    this->setData(data);
}

std::string Voo::getNumeroDoVoo() const{
    return this->numeroDoVoo;
}

void Voo::setNumeroDoVoo(const std::string& numeroDoVoo){
    this->numeroDoVoo = numeroDoVoo;
}

std::string Voo::getPartida() const{
    return this->partida;
}

void Voo::setPartida(const std::string& partida){
    this->partida = partida;
}

std::string Voo::getDestino() const{
    return this->destino;
}

void Voo::setDestino(const std::string& destino){
    this->destino = destino;
}

std::string Voo::getHorarioPartida() const {
    return this->horarioPartida;
}
void Voo::setHorarioPartida(const std::string& horarioPartida){
    if(!Utils::formatoHoraHHMM(horarioPartida)){
        throw FormatoInvalidoException{"Horário de partida é inválido!"};
    }
    this->horarioPartida = horarioPartida;
}

std::string Voo::getHorarioChegada() const {
    return this->horarioChegada;
}
void Voo::setHorarioChegada(const std::string& horarioChegada){
    if(!Utils::formatoHoraHHMM(horarioChegada)){
        throw FormatoInvalidoException{"Horário de chegada é inválido!"};
    }
    this->horarioChegada = horarioChegada;
}

std::string Voo::getData() const {
    return this->data;
}
void Voo::setData(const std::string& data) {
    if(!Utils::formatoData(data)){
        throw FormatoInvalidoException{"Data é inválida!"};
    }
    this->data = data;
}

int Voo::getCapacidade() const{
    return this->capacidade;
}

void Voo::setCapacidade(const int& capacidade){
    if(capacidade > 20 && (capacidade % 4) != 0 && capacidade < 400){
        throw CapacidadeIncorretaException{"Capacidade inválida!", capacidade};
    }
    this->capacidade = capacidade;
}

int Voo::getAssentosDisponiveis() const{
    return this->assentosDisponiveis;
}

void Voo::setAssentosDisponiveis(const int& assentosDisponiveis){
    this->assentosDisponiveis = assentosDisponiveis;
}

std::list<Reserva *> Voo::getReservas() const {
    return this->reservas;
}

void Voo::setReservas(std::list<Reserva *> reservas){
    this->reservas = reservas;
}

void Voo::imprimirDadosVoo(){
    std::cout << "=================================================================================" << std::endl;
    std::cout << "Número: " << this->getNumeroDoVoo() << std::endl;
    std::cout << "Partida: " << this->getPartida() << std::endl;
    std::cout << "Destino: " << this->getDestino() << std::endl;
    std::cout << "Capacidade: " << this->getCapacidade() << std::endl;
    std::cout << "Assentos Disponíveis: " << this->getAssentosDisponiveis() << std::endl;
    std::cout << "Quantidade de Reservas: " << this->getReservas().size() << std::endl;
}

void Voo::imprimirMapaDeAssentos() {

    std::list<std::string> assentosOcupados;
    std::list<Reserva*>::iterator it;
    for (it = (this->reservas.begin()); it != (this->reservas.end()); it++){
        std::cout << "ADICIONANDO " << (*it)->getNumeroDoAssento() << " NA LISTA DE ASSENTOS OCUPADOS..." << std::endl;;
        assentosOcupados.push_back((*it)->getNumeroDoAssento());
    }

    std::string assento;

    std::cout << std::endl << "Mapa de assentos: " << std::endl;
    for(int i = 1; i <= (int) this->getCapacidade()/4; i++){
        if(i < 10){
            assento = "0" + std::to_string(i) + "A";
            if(Utils::assentoOcupado(assento, assentosOcupados)){
                std::cout << "[XXX]";
            } else {
                std::cout << "[" << assento << "]";
            }
            
            assento = "0" + std::to_string(i) + "B";
            if(Utils::assentoOcupado(assento, assentosOcupados)){
                std::cout << "[XXX]";
            } else {
                std::cout << "[" << assento << "]";
            }
        } else {
            assento = std::to_string(i) + "A";
            if(Utils::assentoOcupado(assento, assentosOcupados)){
                std::cout << "[XXX]";
            } else {
                std::cout << "[" << assento << "]";
            }

            assento = std::to_string(i) + "B";
            if(Utils::assentoOcupado(assento, assentosOcupados)){
                std::cout << "[XXX]";
            } else {
                std::cout << "[" << assento << "]";
            }
        }
        std::cout << "  ";
        if(i < 10){
            assento = "0" + std::to_string(i) + "C";
            if(Utils::assentoOcupado(assento, assentosOcupados)){
                std::cout << "[XXX]";
            } else {
                std::cout << "[" << assento << "]";
            }
            
            assento = "0" + std::to_string(i) + "D";
            if(Utils::assentoOcupado(assento, assentosOcupados)){
                std::cout << "[XXX]";
            } else {
                std::cout << "[" << assento << "]";
            }
        } else {
            assento = std::to_string(i) + "C";
            if(Utils::assentoOcupado(assento, assentosOcupados)){
                std::cout << "[XXX]";
            } else {
                std::cout << "[" << assento << "]";
            }

            assento = std::to_string(i) + "D";
            if(Utils::assentoOcupado(assento, assentosOcupados)){
                std::cout << "[XXX]";
            } else {
                std::cout << "[" << assento << "]";
            }
        }
       
        std::cout << std::endl;
    }
}

void Voo::adicionarReserva(Reserva *reserva){
    this->reservas.push_back(reserva);
}
void Voo::removerReserva(Reserva *reserva){
    this->reservas.remove(reserva);
}

std::string Voo::escolherAssentoReserva(){
    //faz lista de assentos ocupados para verificação se o assento escolhido é válido
    std::list<std::string> assentosOcupados;
    if(!this->getReservas().empty()){
        Utils::imprimirListaReservas(this->getReservas());
        std::list<Reserva*> reservas = this->getReservas();
        std::list<Reserva*>::iterator it{reservas.begin()};
        for ( ; it != reservas.end(); it++){
            std::string numeroAssentoOcupado = (*it)->getNumeroDoAssento();
            std::cout << "ADICIONANDO " << numeroAssentoOcupado << " NA LISTA DE ASSENTOS OCUPADOS..." << std::endl;;
            assentosOcupados.push_back(numeroAssentoOcupado);
        }
    }

    this->imprimirMapaDeAssentos(); //imprime o mapa de assentos formatado

    bool escolheuAssentoValido = false;
    std::string aux{""};
    std::string numeroAssentoReserva = Utils::lerStringTratada("Digite o assento desejado (assentos XXX estão ocupados) ou digite 'SAIR'");
    std::string letrasAssentos{"ABCD"};
    while(!escolheuAssentoValido && numeroAssentoReserva.compare("SAIR") != 0){

        //verifica se o assento é válido
        for(int i = 1; i <= (int) this->getCapacidade()/4; i++){
            for(int j = 0; j < 4; j++){
                char letra = letrasAssentos.at(j);

                if(i < 10){
                    aux = "0";
                }

                aux = aux + std::to_string(i) + letra;

                if(numeroAssentoReserva.compare(aux) == 0 && !Utils::assentoOcupado(aux, assentosOcupados)){
                    escolheuAssentoValido = true;
                    break;
                }

                aux = "";
            }
            
        }

        if(escolheuAssentoValido){
            break;
        }

        std::cout << "Assento não é válido!" << std::endl;
        numeroAssentoReserva = Utils::lerStringTratada("Digite o assento desejado (assentos XXX estão ocupados)");
    }

    return numeroAssentoReserva;
}
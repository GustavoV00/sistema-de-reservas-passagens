/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#include <iostream>
#include "./../includes/Reserva.hpp"
#include "./../includes/Passageiro.hpp"
#include "./../includes/Voo.hpp"

Reserva::Reserva(const std::string& localizador, const Passageiro& passageiro, const Voo& voo, const std::string numeroDoAssento)
    : localizador{localizador}, passageiro{passageiro}, voo{voo}, numeroDoAssento{numeroDoAssento}{
}

std::string Reserva::getLocalizador() const {
    return this->localizador;
}

void Reserva::setLocalizador(const std::string& localizador){
    this->localizador = localizador;
}

Passageiro Reserva::getPassageiro() const{
    return this->passageiro;
}
void Reserva::setPassageiro(const Passageiro& passageiro){
    this->passageiro = passageiro;
}

Voo Reserva::getVoo() const{
    return this->voo;
}
void Reserva::setVoo(const Voo& voo){
    this->voo = voo;
}

std::string Reserva::getNumeroDoAssento() const{
    return this->numeroDoAssento;
}
void Reserva::setNumeroDoAssento(const std::string& numeroDoAssento){
    this->numeroDoAssento = numeroDoAssento;
}

void Reserva::imprimirDadosReserva() {
    std::cout << "=================================================================================" << std::endl;
    std::cout << "Código: " << this->getLocalizador() << std::endl;
    std::cout << "Passageiro: " << this->getPassageiro().getNome() << std::endl;
    std::cout << "Voo: " << this->getVoo().getNumeroDoVoo() << std::endl;
    std::cout << "Assento: " << this->getNumeroDoAssento() << std::endl;
    //std::cout << "=================================================================================" << std::endl;
}

Reserva* Reserva::buscaReservaLocalizador(const std::string& localizador, std::list<Reserva*> reservas){
    std::list<Reserva*>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); it++){
        if((*it)->getLocalizador().compare(localizador) == 0){
            return (*it);
        }
    }
    return nullptr;
}

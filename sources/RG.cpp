/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#include <iostream>
#include "./../includes/RG.hpp"
#include "./../includes/DocumentoInvalidoException.hpp"

RG::RG(const unsigned long numero){
    this->setNumero(numero);
}

unsigned long RG::getNumero() const{
    return this->numero;
}

void RG::setNumero(const unsigned long numero){
    if(!validarRG(numero))
        throw DocumentoInvalidoException{numero, "RG inválido."};
    this->numero = numero;
}

bool RG::validarRG(unsigned long rgTeste) const {
    if(rgTeste > 99999999){
        return true;
    }
    return false;
    // int ultimo = rgTeste%10;
    // rgTeste = rgTeste/10;

    // int modulo = 0, somatorio = 0;

    // for(int i = 9; i >= 2; i--){
    //     modulo = rgTeste%10;
    //     rgTeste = rgTeste/10;
    //     somatorio += (i * modulo);
    //     std::cout << i << " * " << modulo << std::endl;
    // }

    // std::cout << "SOMATORIO: " << somatorio << std::endl;

    // somatorio = 11 - (somatorio%11);
    // if(somatorio == 1){
    //     somatorio = 0;
    // }
    // std::cout << "SOMATORIO: " << somatorio << std::endl;

    // if(ultimo != somatorio){
    //     return false;
    // }

    // return true;
}

bool RG::operator==(const RG& outro) const {
	return this->numero == outro.numero;
}
/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#include "./../includes/Reserva.hpp"
#include "./../includes/Passageiro.hpp"
#include "./../includes/Voo.hpp"

Passageiro::Passageiro(const std::string& nome, const CPF& cpf, const RG& rg, 
               const std::string& dataDeNascimento, const unsigned long& contato, const std::string& email)
        :Pessoa(nome, cpf, rg, dataDeNascimento, contato, email){

}



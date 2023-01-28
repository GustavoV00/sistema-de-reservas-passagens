/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/

#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include "./../includes/CPF.hpp"
#include "./../includes/RG.hpp"

class Pessoa {
    public:
        // constructor
        Pessoa(const std::string& nome, const CPF& cpf, const RG& rg, 
               const std::string& dataDeNascimento, const unsigned long& contato, const std::string& email);

        // destructor
        virtual ~Pessoa() = default;

        //getters and setters
        std::string getNome() const;
        void setNome(const std::string& nome);
        
        const CPF& getCpf() const;
        void setCpf(const CPF& cpf);

        const RG& getRg() const;
        void setRg(const RG& rg);

        std::string getDataDeNascimento() const;
        void setDataDeNascimento(const std::string& dataDeNascimento);

        unsigned long getContato() const;
        void setContato(const unsigned long& contato);
        
        std::string getEmail() const;
        void setEmail(const std::string& email);

        void imprimirDadosFormatados();

    private:
        std::string nome;
        CPF cpf;
        RG rg;
        std::string dataDeNascimento;
        unsigned long contato;
        std::string email;
};

#endif
#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>

class Passageiro
{
public:
    // constructor
    Passageiro(std::string nome, std::string contato, std::string numeroPassaporte, int idade);

    // getters
    std::string getNome() const;
    std::string getContato() const;
    std::string getNumeroPassaporte() const;
    int getIdade() const;

    // setters
    void setNome(std::string nome);
    void setContato(std::string contato);
    void setNumeroPassaporte(std::string numeroPassaporte);
    void setIdade(int idade);

private:
    std::string nome;
    std::string contato;
    std::string numeroPassaporte;
    int idade;
};

#endif
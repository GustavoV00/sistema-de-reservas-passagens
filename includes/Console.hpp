/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#ifndef CONSOLE_H
#define CONSOLE_H

#include "string"
#include <list>
#include <ctype.h>
#include "Pessoa.hpp"
#include "AgenteViagem.hpp"
#include "Passageiro.hpp"
#include "Reserva.hpp"

class Console {
    public:
        // constructor
        Console(Pessoa* usuario, const bool& usuarioEhAgente);

        // destructor
        virtual ~Console() = default;

        //getters and setters
        Pessoa* getUsuario() const;
        void setUsuario(Pessoa* usuario);

        bool getUsuarioEhAgente() const;
        void setUsuarioEhAgente(const bool& usuarioEhAgente);

        static Pessoa* loginAgente(std::list<AgenteViagem*>& agentes);
        static Pessoa* loginPassageiro(std::list<Passageiro*>& passageiros);

        void imprimirOpcoesGerenciamentoPassageiros();
        void cadastrarPassageiro(std::list<Passageiro*>& passageiros);
        void editarPassageiro(std::list<Passageiro*>& passageiros);
        void excluirPassageiro(std::list<Passageiro*>& passageiros);
        void gerenciarPassageiros(std::list<Passageiro*>& passageiros);

        void imprimirOpcoesGerenciamentoReservas();
        void cadastrarReserva(std::list<AgenteViagem*>& agentes, std::list<Passageiro*>& passageiros, std::list<Reserva*>& reservas, std::list<Voo*> voos);
        void excluirReserva(std::list<Reserva*>& reserva);
        void gerenciarReservas(std::list<AgenteViagem*>& agentes, std::list<Passageiro*>& passageiros, std::list<Reserva*>& reservas, std::list<Voo*> voos);
        
        void imprimirOpcoesGerenciamentoVoos();
        void cadastrarVoo(std::list<Voo*>& voos);
        void editarReserva(std::list<Reserva*>& reservas, std::list<Voo*>& voos);
        void gerenciarVoos(std::list<Voo*>& voos);

        void imprimeStatusLogin();
        void imprimirComandosTelaPrincipal();
        static bool mensagemConfirmacao(std::string mensagem);

        bool verificaUsuarioEhAgente();
       
    private:
        Pessoa *usuario;
        bool usuarioEhAgente;
};

#endif
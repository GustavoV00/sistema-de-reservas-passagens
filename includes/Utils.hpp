/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#ifndef UTILS_HPP
#define UTILS_HPP

#include <list>
#include <string>

#include "./../includes/Pessoa.hpp"
#include "./../includes/AgenteViagem.hpp"
#include "./../includes/Passageiro.hpp"

class Utils{
    public:
        Utils();
        virtual ~Utils() = default;

        static void imprimirMensagemInicioExecucao();
        static void imprimirMensagemFinalExecucao();
        static void imprimirFuncoesAgentePassageiro();
        static void imprimirListaAgentes(std::list<AgenteViagem*>& agentes);
        static void imprimirListaPassageiros(std::list<Passageiro*>& passageiros);
        static std::string lerStringTratada(std::string mensagem);
        
    private:
       
};

#endif
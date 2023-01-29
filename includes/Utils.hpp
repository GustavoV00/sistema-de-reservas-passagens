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
#include "./../includes/Reserva.hpp"
#include "./../includes/CPF.hpp"
#include "./../includes/RG.hpp"
#include "./../includes/DocumentoInvalidoException.hpp"
#include "./../includes/FormatoInvalidoException.hpp"

class Utils{
    public:
        Utils();
        virtual ~Utils() = default;

        static void imprimirMensagemInicioExecucao();
        static void imprimirMensagemFinalExecucao();
        static void imprimirFuncoesAgentePassageiro();
        static void imprimirListaAgentes(std::list<AgenteViagem*>& agentes);
        static void imprimirListaPassageiros(std::list<Passageiro*>& passageiros);
        static void imprimirListaReservas(std::list<Reserva*> reservas);
        static void imprimirListaVoos(std::list<Voo*>& voos);
        static std::string lerStringTratada(std::string mensagem);
        static CPF* lerCPFTratado(std::string mensagem);
        static RG* lerRGTratado(std::string mensagem);
        static std::string lerDataTratada(std::string mensagem);
        static std::string lerHorarioTratado(std::string mensagem);
        static unsigned long lerTelefoneTratado(std::string mensagem);
        static int geradorNumeroAleatorio();
        static bool assentoOcupado(const std::string& assento, std::list<std::string> assentosOcupados);

        static bool formatoData(const std::string& data);
        static bool formatoHoraHHMM(const std::string& horario);

        

        
    private:
       
};

#endif
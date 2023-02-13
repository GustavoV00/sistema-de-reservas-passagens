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
#include <iostream>
#include <string>

#include "../modelos/Pessoa.hpp"
#include "../modelos/AgenteViagem.hpp"
// #include "../modelos/Passageiro.hpp"
#include "../modelos/Reserva.hpp"
#include "../modelos/CPF.hpp"
#include "../modelos/RG.hpp"
#include "../exceptions/DocumentoInvalidoException.hpp"
#include "../exceptions/FormatoInvalidoException.hpp"

class Utils
{
public:
    Utils();
    virtual ~Utils() = default;

    static void imprimirMensagemInicioExecucao();
    static void imprimirMensagemFinalExecucao();
    static void imprimirFuncoesAgentePassageiro();
    static void imprimirListaAgentes(std::list<AgenteViagem *> &agentes);
    static void imprimirListaPassageiros(std::list<Passageiro *> &passageiros);
    static void imprimirListaReservas(std::list<Reserva *> reservas);

    static void imprimirListaVoos(std::list<Voo *> &voos);
    static std::string lerStringTratada(std::string mensagem);
    static CPF *lerCPFTratado(std::string mensagem);
    static RG *lerRGTratado(std::string mensagem);
    static std::string lerDataTratada(std::string mensagem);
    static std::string lerHorarioTratado(std::string mensagem);
    static unsigned long lerTelefoneTratado(std::string mensagem);
    static int geradorNumeroAleatorio();
    static bool assentoOcupado(const std::string &assento, std::list<std::string> assentosOcupados);

    static bool formatoData(const std::string &data);
    static bool formatoHoraHHMM(const std::string &horario);

    static bool existeVooNumero(std::list<Voo *> &voos, int numeroDoVoo);

    static bool mensagemConfirmacao(std::string mensagem);
    static bool eh_numero(const std::string &s);

private:
};

#endif
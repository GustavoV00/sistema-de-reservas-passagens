/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef GERARDADOS_HPP
#define GERARDADOS_HPP

#include "../controles/PassageiroControle.hpp"
#include "../controles/VooControle.hpp"
#include "../controles/ReservaControle.hpp"
#include "../modelos/AgenteViagem.hpp"

class GerarDados
{
public:
    GerarDados();
    ~GerarDados() = default;

    void gerarDadosVoos(VooControle *vooControle);
    void gerarDadosPassageiros(PassageiroControle *passageiroControle);
    void gerarDadosReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle);
    static std::string gerarNovoNumeroDoAssento(ReservaControle *reservaControle);
    static std::string gerarLocalizador(ReservaControle *reservaControle);
    std::string gerarNovaData();
    std::string gerarNovoHorario();
    int gerarCapacidade();

    void gerarListaDeAgentes(std::list<AgenteViagem *> &agentes);

private:
    VooControle vooControle;
    PassageiroControle passageiroControle;
    ReservaControle reservaControle;
};

#endif
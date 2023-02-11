#ifndef GERARDADOS_HPP
#define GERARDADOS_HPP

#include "../controles/PassageiroControle.hpp"
#include "../controles/VooControle.hpp"
#include "../controles/ReservaControle.hpp"

class GerarDados
{
public:
    GerarDados();
    ~GerarDados() = default;

    void gerarDadosVoos(VooControle *vooControle);
    void gerarDadosPassageiros(PassageiroControle *passageiroControle);
    void gerarDadosReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle);
    std::string gerarNovoNumeroDoAssento(ReservaControle *reservaControle, unsigned int capacidade);
    std::string gerarLocalizador(ReservaControle *reservaControle);
    std::string gerarNovaData();
    std::string gerarNovoHorario();
    unsigned int gerarCapacidade();

private:
    VooControle vooControle;
    PassageiroControle passageiroControle;
    ReservaControle reservaControle;
};

#endif
#include <iostream>
#include "./includes/Passageiro.hpp"
#include "./includes/Utils.hpp"
#include "./includes/Reserva.hpp"
#include "./includes/Voo.hpp"

int main(){
    Utils::imprimirMensagemInicioExecucao();

    CPF cpfBruno{11111111111};
    RG rgBruno{111111111};
    //Pessoa pessoa{"Bruno Farias", cpfBruno, rgBruno, "25/01/2001", 41998877875, "bruno43ist@yahoo.com.br"};
    Passageiro passageiro{"Bruno Farias", cpfBruno, rgBruno, "25/01/2001", 41998877875, "bruno43ist@yahoo.com.br"};
    passageiro.imprimirDadosFormatados();

    Voo voo{"AD1234", "CWB", "POA", 154};

    Reserva reserva{"ABC", passageiro, voo, "13A"};

    reserva.imprimirDadosReserva();

    return 0;
}
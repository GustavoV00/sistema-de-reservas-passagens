nomePrograma=srp
compilador=g++
parametrosCompilacao=-Wall #-Wshadow


all: $(nomePrograma)

$(nomePrograma): main.o Pessoa.o CPF.o RG.o DocumentoInvalidoException.o Utils.o Reserva.o Passageiro.o Voo.o AgenteViagem.o Console.o DadoIncorretoException.o CapacidadeIncorretaException.o FormatoInvalidoException.o
	$(compilador) -o $(nomePrograma) main.o Pessoa.o CPF.o RG.o DocumentoInvalidoException.o Utils.o Reserva.o Passageiro.o Voo.o AgenteViagem.o Console.o DadoIncorretoException.o CapacidadeIncorretaException.o FormatoInvalidoException.o $(parametrosCompilacao)

main.o: main.cpp
	$(compilador) -c main.cpp $(parametrosCompilacao)

Pessoa.o: includes/Pessoa.hpp sources/Pessoa.cpp
	$(compilador) -c sources/Pessoa.cpp $(parametrosCompilacao)

CPF.o: includes/CPF.hpp sources/CPF.cpp
	$(compilador) -c sources/CPF.cpp $(parametrosCompilacao)

RG.o: includes/RG.hpp sources/RG.cpp
	$(compilador) -c sources/RG.cpp $(parametrosCompilacao)

DocumentoInvalidoException.o: includes/DocumentoInvalidoException.hpp sources/DocumentoInvalidoException.cpp
	$(compilador) -c sources/DocumentoInvalidoException.cpp $(parametrosCompilacao)

Utils.o: includes/Utils.hpp sources/Utils.cpp
	$(compilador) -c sources/Utils.cpp $(parametrosCompilacao)

Reserva.o: includes/Reserva.hpp sources/Reserva.cpp
	$(compilador) -c sources/Reserva.cpp $(parametrosCompilacao)

Passageiro.o: includes/Passageiro.hpp sources/Passageiro.cpp
	$(compilador) -c sources/Passageiro.cpp $(parametrosCompilacao)

Voo.o: includes/Voo.hpp sources/Voo.cpp
	$(compilador) -c sources/Voo.cpp $(parametrosCompilacao)

AgenteViagem.o: includes/AgenteViagem.hpp sources/AgenteViagem.cpp
	$(compilador) -c sources/AgenteViagem.cpp $(parametrosCompilacao)

Console.o: includes/Console.hpp sources/Console.cpp
	$(compilador) -c sources/Console.cpp $(parametrosCompilacao)

DadoIncorretoException.o: includes/DadoIncorretoException.hpp sources/DadoIncorretoException.cpp
	$(compilador) -c sources/DadoIncorretoException.cpp $(parametrosCompilacao)

CapacidadeIncorretaException.o: includes/CapacidadeIncorretaException.hpp sources/CapacidadeIncorretaException.cpp
	$(compilador) -c sources/CapacidadeIncorretaException.cpp $(parametrosCompilacao)

FormatoInvalidoException.o: includes/FormatoInvalidoException.hpp sources/FormatoInvalidoException.cpp
	$(compilador) -c sources/FormatoInvalidoException.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
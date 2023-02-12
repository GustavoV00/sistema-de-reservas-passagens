nomePrograma=srp
compilador=g++
parametrosCompilacao=-Wall -std=c++17 #-Wshadow


all: $(nomePrograma)

# $(nomePrograma): main.o Pessoa.o CPF.o RG.o DocumentoInvalidoException.o Utils.o Reserva.o Passageiro.o Voo.o AgenteViagem.o Console.o DadoIncorretoException.o CapacidadeIncorretaException.o FormatoInvalidoException.o
# 	$(compilador) -o $(nomePrograma) main.o Pessoa.o CPF.o RG.o DocumentoInvalidoException.o Utils.o Reserva.o Passageiro.o Voo.o AgenteViagem.o Console.o DadoIncorretoException.o CapacidadeIncorretaException.o FormatoInvalidoException.o $(parametrosCompilacao)

$(nomePrograma): main.o Pessoa.o CPF.o RG.o DocumentoInvalidoException.o Utils.o Reserva.o Passageiro.o Voo.o AgenteViagem.o UsuarioConvidado.o Usuario.o  ConsoleSistema.o ConsoleAgente.o ConsolePassageiro.o GerarDados.o VooControle.o ReservaControle.o PassageiroControle.o VooRepositorio.o ReservaRepositorio.o PassageiroRepositorio.o DadoIncorretoException.o CapacidadeIncorretaException.o FormatoInvalidoException.o VooCheioException.o
	$(compilador) -o $(nomePrograma) main.o Pessoa.o CPF.o RG.o DocumentoInvalidoException.o Utils.o Reserva.o Passageiro.o Voo.o AgenteViagem.o UsuarioConvidado.o Usuario.o ConsoleSistema.o ConsoleAgente.o ConsolePassageiro.o GerarDados.o VooControle.o ReservaControle.o PassageiroControle.o VooRepositorio.o ReservaRepositorio.o PassageiroRepositorio.o DadoIncorretoException.o CapacidadeIncorretaException.o FormatoInvalidoException.o VooCheioException.o $(parametrosCompilacao)

main.o: main.cpp
	$(compilador) -c main.cpp $(parametrosCompilacao)

Pessoa.o: includes/modelos/Pessoa.hpp sources/modelos/Pessoa.cpp
	$(compilador) -c sources/modelos/Pessoa.cpp $(parametrosCompilacao)

CPF.o: includes/modelos/CPF.hpp sources/modelos/CPF.cpp
	$(compilador) -c sources/modelos/CPF.cpp $(parametrosCompilacao)

RG.o: includes/modelos/RG.hpp sources/modelos/RG.cpp
	$(compilador) -c sources/modelos/RG.cpp $(parametrosCompilacao)

Utils.o: includes/utils/Utils.hpp sources/utils/Utils.cpp
	$(compilador) -c sources/utils/Utils.cpp $(parametrosCompilacao)

Reserva.o: includes/modelos/Reserva.hpp sources/modelos/Reserva.cpp
	$(compilador) -c sources/modelos/Reserva.cpp $(parametrosCompilacao)

ReservaControle.o: includes/controles/ReservaControle.hpp sources/controles/ReservaControle.cpp
	$(compilador) -c sources/controles/ReservaControle.cpp $(parametrosCompilacao)


ReservaRepositorio.o: includes/repositorios/ReservaRepositorio.hpp sources/repositorios/ReservaRepositorio.cpp
	$(compilador) -c sources/repositorios/ReservaRepositorio.cpp $(parametrosCompilacao)

Passageiro.o: includes/modelos/Passageiro.hpp sources/modelos/Passageiro.cpp
	$(compilador) -c sources/modelos/Passageiro.cpp $(parametrosCompilacao)

PassageiroControle.o: includes/controles/PassageiroControle.hpp sources/controles/PassageiroControle.cpp
	$(compilador) -c sources/controles/PassageiroControle.cpp $(parametrosCompilacao)


PassageiroRepositorio.o: includes/repositorios/PassageiroRepositorio.hpp sources/repositorios/PassageiroRepositorio.cpp
	$(compilador) -c sources/repositorios/PassageiroRepositorio.cpp $(parametrosCompilacao)

Voo.o: includes/modelos/Voo.hpp sources/modelos/Voo.cpp
	$(compilador) -c sources/modelos/Voo.cpp $(parametrosCompilacao)

VooControle.o: includes/controles/VooControle.hpp sources/controles/VooControle.cpp
	$(compilador) -c sources/controles/VooControle.cpp $(parametrosCompilacao)


VooRepositorio.o: includes/repositorios/VooRepositorio.hpp sources/repositorios/VooRepositorio.cpp
	$(compilador) -c sources/repositorios/VooRepositorio.cpp $(parametrosCompilacao)

AgenteViagem.o: includes/modelos/AgenteViagem.hpp sources/modelos/AgenteViagem.cpp
	$(compilador) -c sources/modelos/AgenteViagem.cpp $(parametrosCompilacao)

Usuario.o: includes/modelos/Usuario.hpp sources/modelos/Usuario.cpp
	$(compilador) -c sources/modelos/Usuario.cpp $(parametrosCompilacao)

UsuarioConvidado.o: includes/modelos/UsuarioConvidado.hpp sources/modelos/UsuarioConvidado.cpp
	$(compilador) -c sources/modelos/UsuarioConvidado.cpp $(parametrosCompilacao)

GerarDados.o: includes/modelos/GerarDados.hpp sources/modelos/GerarDados.cpp
	$(compilador) -c sources/modelos/GerarDados.cpp $(parametrosCompilacao)

ConsoleSistema.o: includes/consoles/ConsoleSistema.hpp sources/consoles/ConsoleSistema.cpp
	$(compilador) -c sources/consoles/ConsoleSistema.cpp $(parametrosCompilacao)

ConsoleAgente.o: includes/consoles/ConsoleAgente.hpp sources/consoles/ConsoleAgente.cpp
	$(compilador) -c sources/consoles/ConsoleAgente.cpp $(parametrosCompilacao)

ConsolePassageiro.o: includes/consoles/ConsolePassageiro.hpp sources/consoles/ConsolePassageiro.cpp
	$(compilador) -c sources/consoles/ConsolePassageiro.cpp $(parametrosCompilacao)

DocumentoInvalidoException.o: includes/exceptions/DocumentoInvalidoException.hpp sources/exceptions/DocumentoInvalidoException.cpp
	$(compilador) -c sources/exceptions/DocumentoInvalidoException.cpp $(parametrosCompilacao)

DadoIncorretoException.o: includes/exceptions/DadoIncorretoException.hpp sources/exceptions/DadoIncorretoException.cpp
	$(compilador) -c sources/exceptions/DadoIncorretoException.cpp $(parametrosCompilacao)

CapacidadeIncorretaException.o: includes/exceptions/CapacidadeIncorretaException.hpp sources/exceptions/CapacidadeIncorretaException.cpp
	$(compilador) -c sources/exceptions/CapacidadeIncorretaException.cpp $(parametrosCompilacao)

FormatoInvalidoException.o: includes/exceptions/FormatoInvalidoException.hpp sources/exceptions/FormatoInvalidoException.cpp
	$(compilador) -c sources/exceptions/FormatoInvalidoException.cpp $(parametrosCompilacao)

VooCheioException.o: includes/exceptions/VooCheioException.hpp sources/exceptions/VooCheioException.cpp
	$(compilador) -c sources/exceptions/VooCheioException.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
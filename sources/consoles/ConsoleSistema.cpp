#include <iostream>
#include "../../includes/consoles/ConsoleSistema.hpp"
#include "../../includes/utils/Utils.hpp"

#include "../../includes/modelos/AgenteViagem.hpp" //forward declaration
#include "../../includes/modelos/Passageiro.hpp"   //forward declaration

ConsoleSistema::ConsoleSistema()
{
}

void ConsoleSistema::imprimirMensagemInicioExecucao()
{
    std::cout << std::endl
              << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << "Bem-Vindo(a) ao Sistema de Reserva de Passagens Aéreas (SRP)!" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl
              << std::endl;
}

// imprime opções de comando quando o usuário é convidado
void ConsoleSistema::imprimirComandosTelaPrincipal()
{
    // imprimeStatusLogin();
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << " 1) FAZER LOGIN COMO PASSAGEIRO" << std::endl;
    std::cout << " 2) FAZER LOGIN COMO AGENTE" << std::endl;
    std::cout << " 3) MOSTRAR OPÇÕES DE VOOS" << std::endl;
    std::cout << " 5) MOSTRAR OPÇÕES DE PASSAGEIROS" << std::endl;
    std::cout << "10) SAIR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

// usuário convidado só pode listar os voos
void ConsoleSistema::imprimirOpcoesGerenciamentoVoos()
{
    std::cout << std::endl;
    std::cout << "-------------------------GERENCIAMENTO DE VOOS------------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) LISTAR VOOS" << std::endl;
    std::cout << "2) VOLTAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

// usuario convidado só pode criar reservas
void ConsoleSistema::imprimirOpcoesGerenciamentoDeReservas()
{
    std::cout << std::endl;
    std::cout << "-------------------------GERENCIAMENTO DE RESERVAS------------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) CRIAR RESERVAS" << std::endl;
    std::cout << "2) VOLTAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void ConsoleSistema::finalizarSistema()
{
    std::cout << std::endl
              << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << "Sistema desligado com Sucesso!" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl
              << std::endl;
}

Passageiro *ConsoleSistema::loginPassageiro(std::list<Passageiro *> &passageiros)
{
    std::cout << std::endl;
    std::cout << "----------------------LOGIN----------------------" << std::endl;
    std::string resposta;
    std::cout << "Deseja listar novamente os passageiros? (S/n): ";
    std::getline(std::cin, resposta);
    while (resposta.compare("S") != 0 && resposta.compare("n") != 0)
    {
        std::cout << "Deseja listar novamente os passageiros? (S/n): ";
        std::getline(std::cin, resposta);
    }

    if (resposta.compare("S") == 0)
    {
        Utils::imprimirListaPassageiros(passageiros);
    }

    std::cout << std::endl;

    std::string login{""};
    bool logado{false};

    std::cout << "Digite o login (CPF ou Email) do passageiro para logar ou 'SAIR': ";
    std::getline(std::cin, login);
    while (!logado && login.compare("SAIR") != 0)
    {
        // pesquisa na lista de passageiros
        std::list<Passageiro *>::iterator it;
        for (it = passageiros.begin(); it != passageiros.end(); ++it)
        {
            if (std::to_string((*it)->getCpf().getNumero()).compare(login) == 0 || (*it)->getEmail().compare(login) == 0)
            {
                std::cout << std::endl;
                std::cout << "Encontrou passageiro! Logando..." << std::endl;
                return *it;
            }
        }

        std::cout << "Não encontrou passageiro com esse login!" << std::endl;

        std::cout << "Digite o login (CPF ou Email) ou 'SAIR': ";
        std::getline(std::cin, login);
    }

    return nullptr;
}

AgenteViagem *ConsoleSistema::loginAgente(std::list<AgenteViagem *> &agentes)
{
    std::cout << std::endl;
    std::cout << "----------------------LOGIN----------------------" << std::endl;
    std::string resposta;
    std::cout << "Deseja listar novamente os agentes? (S/n): ";
    std::getline(std::cin, resposta);
    while (resposta.compare("S") != 0 && resposta.compare("n") != 0)
    {
        std::cout << "Deseja listar novamente os agentes? (S/n): ";
        std::getline(std::cin, resposta);
    }

    if (resposta.compare("S") == 0)
    {
        Utils::imprimirListaAgentes(agentes);
    }

    std::cout << std::endl;

    std::string login{""};
    bool logado{false};
    std::cout << "Digite o login (CPF, Email ou Código) do agente para logar ou 'SAIR': ";
    std::getline(std::cin, login);
    while (!logado && login.compare("SAIR") != 0)
    {
        // pesquisa na lista de agentes
        std::list<AgenteViagem *>::iterator it;
        for (it = agentes.begin(); it != agentes.end(); ++it)
        {
            if (std::to_string((*it)->getCpf().getNumero()).compare(login) == 0 || (*it)->getEmail().compare(login) == 0 || (*it)->getCodigo().compare(login) == 0)
            {
                std::cout << std::endl;
                std::cout << "Encontrou agente! Logando..." << std::endl;
                return *it;
            }
        }

        std::cout << "Não encontrou agente com esse login!" << std::endl;

        std::cout << "Digite o login (CPF, Email ou Código) ou 'SAIR': ";
        std::getline(std::cin, login);
    }

    return nullptr;
}

// usuário convidado só tem permissão para listar voos
void ConsoleSistema::rodarGerenciamentoDeVoo(VooControle *vooControle)
{
    std::string comando{""};
    while (comando.compare("2") != 0)
    {
        imprimirOpcoesGerenciamentoVoos();
        comando = Utils::lerStringTratada("Digite o número da opção escolhida");
        if (comando.compare("1") == 0)
        {
            Utils::imprimirListaVoos(vooControle->obterTodosOsVoos());
        }
        std::cout << std::endl;
    }
}

void ConsoleSistema::rodarGerenciamentoDeReservas(ReservaControle *reservaControle, PassageiroControle *passageiroControle, VooControle *vooControle, Usuario *usuario)
{
    return;
}

void ConsoleSistema::imprimirOpcoesGerenciamentoPassageiros()
{
    std::cout << std::endl;
    std::cout << "---------------------GERENCIAMENTO DE PASSAGEIROS------------------------" << std::endl;
    std::cout << "--------------------------------OPÇÕES--------------------------------" << std::endl;
    std::cout << "1) LISTAR PASSAGEIROS" << std::endl;
    std::cout << "2) CRIAR PASSAGEIRO" << std::endl;
    std::cout << "5) VOLTAR" << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void ConsoleSistema::rodarGerenciamentoDePassageiros(PassageiroControle *passageiroControle, Usuario *usuario, ReservaControle *reservaControle)
{
    // std::cout << "Função permitida apenas como agente logado!" << std::endl;
    std::string comando{""};
    while (comando.compare("5") != 0)
    {
        imprimirOpcoesGerenciamentoPassageiros();
        comando = Utils::lerStringTratada("Digite o número da opção escolhida");
        if (comando.compare("1") == 0)
        {
            Utils::imprimirListaPassageiros(passageiroControle->obterTodosOsPassageiros());
        }
        else if (comando.compare("2") == 0)
        {
            cadastrarPassageiroInterface(passageiroControle);
        }
        std::cout << std::endl;
    }
}

void ConsoleSistema::cadastrarPassageiroInterface(PassageiroControle *passageiroControle)
{
    std::list<Passageiro *> passageiros = passageiroControle->obterTodosOsPassageiros();
    std::string nomePassageiro = Utils::lerStringTratada("Digite o nome do passageiro a ser adicionado ou 'SAIR'");
    if (nomePassageiro.compare("SAIR") == 0)
    {
        return;
    }

    CPF *cpfPassageiro = Utils::lerCPFTratado("Digite o CPF (sem pontuação) do passageiro a ser adicionado ou 'SAIR'");
    if (cpfPassageiro == nullptr)
    {
        std::cout << "CPF não é válido! Encerrando cadastro de passageiro..." << std::endl;
        return;
    }
    RG *rgPassageiro = Utils::lerRGTratado("Digite o RG (sem pontuação) do passageiro a ser adicionado ou 'SAIR'");
    if (rgPassageiro == nullptr)
    {
        std::cout << "RG não é válido! Encerrando cadastro de passageiro..." << std::endl;
        return;
    }

    std::string dataDeNascimento;
    try
    {
        dataDeNascimento = Utils::lerDataTratada("Digite a data de nascimento (dd/MM/yyyy) do passageiro a ser adicionado ou 'SAIR'");
    }
    catch (FormatoInvalidoException &fie)
    {
        std::cout << "Formato da data de nascimento é inválido! Encerrando cadastro do passageiro..." << std::endl;
        return;
    }

    unsigned long contato;
    try
    {
        contato = Utils::lerTelefoneTratado("Digite o telefone de contato (apenas números) do passageiro a ser adicionado ou 'SAIR'");
    }
    catch (FormatoInvalidoException &fie)
    {
        std::cout << "Formato do telefone é inválido!  Encerrando cadastro do passageiro..." << std::endl;
        return;
    }

    std::string email = Utils::lerStringTratada("Digite o email do passageiro a ser adicionado ou 'SAIR'");

    if (email.compare("SAIR") == 0)
    {
        return;
    }

    // verifica se já não existe passageiro com esse CPF, RG ou email
    std::list<Passageiro *>::iterator it;
    for (it = passageiros.begin(); it != passageiros.end(); ++it)
    {
        if ((*it)->getCpf() == *cpfPassageiro || (*it)->getRg() == *rgPassageiro || (*it)->getEmail().compare(email) == 0)
        {
            std::cout << std::endl
                      << "\tATENÇÃO! Já existe passageiro com esse CPF, RG ou email! Passageiro não vai ser cadastrado!" << std::endl;
            return;
        }
    }

    Passageiro *novoPas{nullptr};
    try
    {
        novoPas = new Passageiro{nomePassageiro, *cpfPassageiro, *rgPassageiro, dataDeNascimento, contato, email};
    }
    catch (DocumentoInvalidoException &die)
    {
        std::cout << "Falha ao cadastrar passageiro por documento inválido: " << die.what() << std::endl;
        return;
    }
    catch (std::exception &e)
    {
        std::cout << "Falha ao cadastrar passageiro: " << e.what() << std::endl;
        return;
    }

    if (!passageiroControle->cadastrarPassageiro(novoPas))
    {
        return;
    }

    std::cout << "Passageiro '" << novoPas->getNome() << "' adicionado com sucesso!" << std::endl;
}
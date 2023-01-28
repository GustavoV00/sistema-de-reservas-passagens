/**
 * 
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 * 
*/
#ifndef CPF_HPP
#define CPF_HPP

class CPF{
    public:
        CPF(const unsigned long numero);
        virtual ~CPF() = default;

        unsigned long getNumero() const;
        void setNumero(const unsigned long numero);

        bool operator==(const CPF& outro) const;
        
    private:
        bool validarCPF(unsigned long cpfTeste) const;
        unsigned long numero;
};

#endif
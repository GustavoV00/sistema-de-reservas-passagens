/**
 *
 * Autores: Bruno Farias e Gustavo Valente
 * 2022/2 - UFPR - PRÁTICA EM DESENVOLVIMENTO DE SOFTWARE
 * PROF. PAULO ALMEIDA
 *
 */
#ifndef RG_HPP
#define RG_HPP

class RG
{
public:
    RG();
    RG(const unsigned long numero);
    virtual ~RG() = default;

    unsigned long getNumero() const;
    void setNumero(const unsigned long numero);

    bool operator==(const RG &outro) const;

private:
    bool validarRG(unsigned long rgTeste) const;
    unsigned long numero;
};

#endif
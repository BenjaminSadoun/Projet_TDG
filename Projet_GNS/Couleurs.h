#ifndef COULEURS_H_INCLUDED
#define COULEURS_H_INCLUDED

#include <string>
#include <cstdint>

class Couleur
{
    public :
        Couleur(uint8_t rouge, uint8_t vert, uint8_t bleu);
        Couleur();
        void afficher() const;
        void saisir();
        void muter(double amplitude);
        void degrader(double portee);
        void setR(int r);
        void setG(int g);
        void setB(int b);

        operator std::string() const;

    private :
        // uint8_t équivalent à unsigned char :
        // unsigned 8 bits (8 bits non signé)
        uint8_t m_rouge, m_vert, m_bleu;
};

#endif // COULEURS_H_INCLUDED

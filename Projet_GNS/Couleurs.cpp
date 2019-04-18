#include "Couleurs.h"
#include "svgfile.h"
#include "util.h"
#include <iostream>

Couleur::Couleur(uint8_t rouge, uint8_t vert, uint8_t bleu)
    : m_rouge{rouge}, m_vert{vert}, m_bleu{bleu}
{ }

void Couleur::setR(int r)
{
    m_rouge = r;
}

void Couleur::setG(int g)
{
    m_vert = g;
}


void Couleur::setB(int b)
{
    m_bleu = b;
}


Couleur::Couleur()
    : Couleur(0, 0, 0) // Délégation de constructeur
{ }


void Couleur::afficher() const
{
    std::cout << "(" << (int)m_rouge << ", " << (int)m_vert << ", " << (int)m_bleu << ")" << std::endl;
}

uint8_t saisirCanal()
{
    int val;
    std::cin >> val;
    while (val<0 || val>255)
    {
        std::cout << "Mauvaise valeur couleur, recommencer : ";
        util::videCin();
        std::cin >> val;
    }

    return (uint8_t)val;
}

void Couleur::saisir()
{
    std::cout << "Veuillez saisir rouge vert et bleu SVP : ";
    m_rouge = saisirCanal();
    m_vert = saisirCanal();
    m_bleu = saisirCanal();
}

uint8_t muterCanal(uint8_t v, double amplitude)
{
    int val=v;

    val += util::alea(-amplitude, amplitude);

    if ( val<0 )
        val = 0;

    if ( val>255 )
        val = 255;

    return (uint8_t)val;
}


void Couleur::muter(double amplitude)
{
    m_rouge = muterCanal(m_rouge, amplitude);
    m_vert = muterCanal(m_vert, amplitude);
    m_bleu = muterCanal(m_bleu, amplitude);
}

Couleur::operator std::string()const
{
    return Svgfile::makeRGB(m_rouge, m_vert, m_bleu);
}

uint8_t degraderCanal(uint8_t v, double portee)
{
    int val=v;

    val += 10;

    if ( val<0 )
        val = 0;

    if ( val>255 )
        val = 255;

    return (uint8_t)val;
}

void Couleur::degrader(double portee)
{
    //m_rouge = degraderCanal(m_rouge, portee);
    //m_vert = degraderCanal(m_vert, portee);
    m_bleu = degraderCanal(m_bleu, portee);
}

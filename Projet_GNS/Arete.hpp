//
//  Arete.hpp
//  Projet_GNSX
//
//  Created by pezi on 15/04/2019.
//  Copyright © 2019 pezi. All rights reserved.
//

#ifndef Arete_hpp
#define Arete_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>

class Arete   {
    
private:
    
    int m_indice;
    int m_sommet1;
    int m_sommet2;
    float m_poids1;
    float m_poids2;
public:
    Arete(int,int,int,float,float);
    Arete(int, int, int);
    void afficherData() const;
    ~Arete();
    int get_indice() const;
    int getSommet1() const;
    int getSommet2() const;
    float getPoids1() const;
    float getPoids2() const;
    friend bool operator < (const Arete &a, const Arete &b);
    friend bool operator > (const Arete &a, const Arete &b);
    
};

#endif /* Arete_hpp */


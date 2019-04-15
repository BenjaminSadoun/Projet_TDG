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

    std::string m_indice;
    std::string m_sommet1;
    std::string m_sommet2;
    float m_poids1;
    float m_poids2;
public:
    Arete(std::string,std::string,std::string,float,float);
    Arete(std::string,std::string,std::string);
    void afficherData() const;
    ~Arete();
};

#endif /* Arete_hpp */

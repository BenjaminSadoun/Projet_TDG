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
#endif /* Arete_hpp */
class Arete   {
    
private:
    
    std::string m_indice;
    std::string m_sommet1;
    std::string m_sommet2;
    std::pair<int,int> m_poids;
public:
    Arete(std::string,std::string,std::string);
    ~Arete();
};

//
//  Arete.cpp
//  Projet_GNSX
//
//  Created by pezi on 15/04/2019.
//  Copyright © 2019 pezi. All rights reserved.
//

#include "Arete.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

Arete::Arete(std::string indice,std::string indiceS1,std::string indiceS2,std::pair<int,int> poids): m_indice(indice),m_sommet1(indiceS1),m_sommet2(indiceS2),m_poids(poids){
    
}
Arete::~Arete(){
    
}

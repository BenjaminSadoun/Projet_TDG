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



Arete::Arete(std::string indice,std::string indiceS1,std::string indiceS2,float poids1,float poids2):  m_indice(indice),m_sommet1(indiceS1),m_sommet2(indiceS2),m_poids1(poids1),m_poids2(poids2)
{

}
Arete::~Arete()
{

}

void Arete::afficherData() const
{
    std::cout<<"    "<<m_indice<<" : "<<"(sommet1,sommet2)=("<<m_sommet1<<","<<m_sommet2<<")"<<std::endl;
}

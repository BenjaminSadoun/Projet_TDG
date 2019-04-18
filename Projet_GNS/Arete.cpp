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



Arete::Arete(int indice,int indiceS1,int indiceS2,float poids1,float poids2):  m_indice(indice),m_sommet1(indiceS1),m_sommet2(indiceS2),m_poids1(poids1),m_poids2(poids2)
{
    
}
Arete::~Arete()
{
    
}

void Arete::afficherData() const
{
    std::cout<<"    "<<m_indice<<" : "<<"(s1,s2,p1,p2)=("<<m_sommet1<<","<<m_sommet2<<","<<m_poids1<<","<<m_poids2<<")"<<std::endl;
}


int Arete::get_indice() const
{
    return m_indice;
}

int Arete::getSommet1() const
{
    return m_sommet1;
}
int Arete::getSommet2() const
{
    return m_sommet2;
}

float Arete::getPoids1() const
{
    return m_poids1;
}

float Arete::getPoids2() const
{
    return m_poids2;
}

bool operator < (const Arete &a,const Arete &b){
    
    return a.m_poids1 < b.m_poids1;
}

bool operator > (const Arete &a,const Arete &b){
    
    return a.m_poids1 > b.m_poids1;
}


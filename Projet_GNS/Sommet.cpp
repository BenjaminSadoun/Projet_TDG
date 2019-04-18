//
//  Sommet.cpp
//  Projet_GNSX
//
//  Created by pezi on 15/04/2019.
//  Copyright © 2019 pezi. All rights reserved.
//

#include "Sommet.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include<unordered_map>
#include<unordered_set>
#include "Couleurs.h"
#include "svgfile.h"

Sommet::Sommet(int id,double x,double y):m_id{id},m_x{x},m_y{y}
{
}
void Sommet::ajouterVoisin(int voisin, float poid)
{
    m_voisins.push_back(std::make_pair(voisin,poid));
}
void Sommet::afficherData() const{
    std::cout<<"    "<<m_id<<" : "<<"(x,y)=("<<m_x<<","<<m_y<<")"<<std::endl;
}

void Sommet::dessSommet(Svgfile &svgout)
{
    svgout.addDisk(m_x, m_y, 10, Couleur(0,0,130));
}


/*
 void Sommet::afficherVoisins() const{
 std::cout<<"  voisins :"<<std::endl;
 for(auto v:m_voisins) {
 v.afficherData();
 }
 }*/
/*
 std::unordered_map<int,int> Sommet::parcoursBFS() const{
 std::unordered_map<int,int> l_pred;
 std::unordered_set<int> l_marque;
 std::queue<Sommet*> file;
 //std::vector<Sommet>::iterator it;
 Sommet* p = new Sommet(*this);
 file.push(p);
 
 while(!file.empty())
 {
 p=file.front();
 file.pop();
 
 for(size_t i= 0; i<p->m_voisins.size(); ++i)
 {
 if(l_marque.find(p->m_voisins[i].sommet->getid())==l_marque.end())
 {
 l_marque.insert(p->m_voisins[i].getid());
 Sommet* suivant = new Sommet(*p->m_voisins[i]);
 file.push(suivant);
 l_pred.insert({suivant->getid(),p->getid()});
 
 }
 }
 }
 for(auto it: l_pred){
 std::cout <<"suivant "<< it.first <<"  precedent  "<<it.second ;
 }
 return l_pred;
 }
 */
std::unordered_map<std::string,std::string> Sommet::parcoursDFS() const{
    std::unordered_map<std::string,std::string> l_pred;
    std::cout<<"DFS a completer"<<std::endl;
    return l_pred;
}
std::unordered_set<std::string> Sommet::rechercherCC() const{
    std::unordered_set<std::string> cc;
    std::cout<<"rechercherCC a coder"<<std::endl;
    return cc;
}

int Sommet::getid() const
{
    return m_id;
}

double Sommet::get_x()
{
    return m_x;
}

double Sommet::get_y()
{
    return m_y;
}

Sommet::~Sommet()
{
    //dtor
}

std::vector<std::pair<int,float>>Sommet::getvoisins(){
    return m_voisins;
}
/*
 void Sommet::affichervoisins(){
 for(auto it: m_voisins)
 std::cout <<"VOISINS :" << it.first->getid()<<"  distance: "<<it<<std::endl;
 
 }
 */


#include <fstream>
#include <iostream>
#include "Graphe.hpp"
#include "Arete.hpp"
#include "Sommet.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
graphe::graphe(std::string FichierSommets,std::string FichierPoids){
    std::ifstream ifs1{FichierSommets};
    std::ifstream ifs2{FichierPoids};
    if (!ifs1)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + FichierSommets );
    int ordre;
    ifs1 >> ordre;
    if ( ifs1.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    std::string id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i){
        ifs1>>id; if(ifs1.fail()) throw std::runtime_error("Probleme lecture donnÈes sommet");
        ifs1>>x; if(ifs1.fail()) throw std::runtime_error("Probleme lecture donnÈes sommet");
        ifs1>>y; if(ifs1.fail()) throw std::runtime_error("Probleme lecture donnÈes sommet");
        m_sommets.insert({id,new Sommet{id,x,y}});
    }
    int nbAretes;
    ifs1 >> nbAretes;
    if ( ifs1.fail() )
        throw std::runtime_error("Probleme lecture Aretes");
    std::string id_ext1;
    std::string id_ext2;
    int pondérations;
    float poids1;
    float poids2;
    //lecture des aretes
    ifs2>>nbAretes; if(ifs2.fail()) throw std::runtime_error("Probleme lecture poid ");
    ifs2>>pondérations; if(ifs2.fail()) throw std::runtime_error("Probleme lecture poid ");
    
    for (int i=0; i<nbAretes; ++i){
        //lecture des ids des deux extrÈmitÈs
        ifs1>>id; if(ifs1.fail()) throw std::runtime_error("Probleme lecture arete ");
        ifs1>>id_ext1; if(ifs1.fail()) throw std::runtime_error("Probleme lecture sommet arete 1");
        ifs1>>id_ext2; if(ifs1.fail()) throw std::runtime_error("Probleme lecture sommet arete 2");
        
        ifs2>>id; if(ifs2.fail()) throw std::runtime_error("Probleme lecture poid ");
        ifs2>>poids1; if(ifs2.fail()) throw std::runtime_error("Probleme lecture poid1 ");
        ifs2>>poids2; if(ifs2.fail()) throw std::runtime_error("Probleme lecture poid2");
        
        m_Aretes.push_back(new Arete{id,id_ext1,id_ext2,poids1,poids2});
        
        //(m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        //(m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orientÈ
    }
}
void graphe::afficher() const{
    std::cout<<"graphe : "<<std::endl;
    std::cout<<"  coder l'affichage ! "<<std::endl;
}

void graphe::parcoursBFS(std::string id) const{
    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<std::string,std::string> l_pred;
    l_pred=s0->parcoursBFS();
}
void graphe::afficherBFS(std::string id) const{
    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<std::string,std::string> l_pred;
    std::cout<<"parcoursBFS a partir de "<<id<<" :"<<std::endl;
    l_pred=s0->parcoursBFS();
    for(auto s:l_pred){
        std::cout<<s.first<<" <--- ";
        std::pair<std::string,std::string> pred=s;
        while(pred.second!=id){
            pred=*l_pred.find(pred.second);
            std::cout<<pred.first<<" <--- ";
        }
        std::cout<<id<<std::endl;
    }
}
void graphe::parcoursDFS(std::string id) const{
    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<std::string,std::string> l_pred;
    l_pred=s0->parcoursDFS();
}
void graphe::afficherDFS(std::string id) const{
    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<std::string,std::string> l_pred;
    std::cout<<"parcoursDFS a partir de "<<id<<" :"<<std::endl;
    l_pred=s0->parcoursDFS();
    for(auto s:l_pred){
        std::cout<<s.first<<" <--- ";
        std::pair<std::string,std::string> pred=s;
        while(pred.second!=id){
            pred=*l_pred.find(pred.second);
            std::cout<<pred.first<<" <--- ";
        }
        std::cout<<id<<std::endl;
    }
}
int graphe::rechercher_afficherToutesCC() const{
    int i=0;
    std::cout<<"composantes connexes :"<<std::endl;
    std::cout<<"recherche et affichage de toutes les composantes connexes a coder"<<std::endl;
    return i;
}
graphe::~graphe()
{
    //dtor
}
/*
std::vector<Arete*> graphe::kruskal(std::vector<Arete*> Aretes) const{
    std::vector<Arete*> Aretes_marques;
    std::vector<std::string> sommets_marques;
    std::sort(*Aretes.begin(),*Aretes.end());
    int compte=0;
    
    for( auto it: Aretes){
        
        for(auto ut: sommets_marques){
            
            if(it->getSommet1()==ut){
                ++compte;
            }
            
            if(it->getSommet2()==ut){
                ++compte;
            }
            
            if(compte<2){
                Aretes_marques.push_back(it);
                sommets_marques.push_back(it->getSommet1());
                sommets_marques.push_back(it->getSommet2());
                compte=0;
            }
        }
    }

        return Aretes_marques;
}
*/

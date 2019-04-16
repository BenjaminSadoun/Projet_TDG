#include <fstream>
#include <iostream>
#include "Graphe.hpp"
#include "Arete.hpp"
#include "Sommet.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

graphe::graphe(std::string FichierSommets,std::string FichierPoids)
{
    std::ifstream ifs1{FichierSommets};
    std::ifstream ifs2{FichierPoids};
    if (!ifs1)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + FichierSommets );
    if (!ifs2)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + FichierPoids );
    int ordre;
    ifs1 >> ordre;
    if ( ifs1.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    std::string id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i)
    {
        ifs1>>id;
        if(ifs1.fail())
            throw std::runtime_error("Probleme lecture donnÈes sommet");
        ifs1>>x;
        if(ifs1.fail())
            throw std::runtime_error("Probleme lecture donnÈes sommet");
        ifs1>>y;
        if(ifs1.fail())
            throw std::runtime_error("Probleme lecture donnÈes sommet");
        m_sommets.insert({id,new Sommet{id,x,y}});
    }
    int nbAretes;
    ifs1 >> nbAretes;
    if ( ifs1.fail() )
        throw std::runtime_error("Probleme lecture Aretes");
    std::string id_ext1;
    std::string id_ext2;
    int ponderations;
    float poids1;
    float poids2;
    //lecture des aretes
    ifs2 >> nbAretes;
    if(ifs2.fail())
        throw std::runtime_error("Probleme lecture poids ");
    ifs2>>ponderations;
    if(ifs2.fail())
        throw std::runtime_error("Probleme lecture poid ");

    for (int i=0; i<nbAretes; ++i)
    {
        //lecture des ids des deux extrÈmitÈs
        ifs1>>id;
        if(ifs1.fail())
            throw std::runtime_error("Probleme lecture arete ");
        ifs1>>id_ext1;
        if(ifs1.fail())
            throw std::runtime_error("Probleme lecture sommet arete 1");
        ifs1>>id_ext2;
        if(ifs1.fail())
            throw std::runtime_error("Probleme lecture sommet arete 2");

        ifs2>>id;
        if(ifs2.fail())
            throw std::runtime_error("Probleme lecture poid ");
        ifs2>>poids1;
        if(ifs2.fail())
            throw std::runtime_error("Probleme lecture poid1 ");
        ifs2>>poids2;
        if(ifs2.fail())
            throw std::runtime_error("Probleme lecture poid2");

        m_aretes.insert({id,new Arete{id,id_ext1,id_ext2,poids1,poids2}});

        //(m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
        //(m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orientÈ
    }
}

/*
std::ifstream ifs1{FichierSommetsAretes};
if (!ifs1)
    throw std::runtime_error( "Impossible d'ouvrir en lecture " + FichierSommetsAretes );
int ordre;
ifs1 >> ordre;
if ( ifs1.fail() )
    throw std::runtime_error("Probleme lecture ordre du graphe");
std::string id_sommet;
double x,y;
//lecture des sommets
for (int i=0; i<ordre; ++i)
{
    ifs1>>id_sommet;
    if(ifs1.fail())
        throw std::runtime_error("Probleme lecture donnees sommet");
    ifs1>>x;
    if(ifs1.fail())
        throw std::runtime_error("Probleme lecture donnees sommet");
    ifs1>>y;
    if(ifs1.fail())
        throw std::runtime_error("Probleme lecture donnees sommet");
    m_sommets.insert({id_sommet,new Sommet{id_sommet,x,y}});
}
int taille;
ifs1 >> taille;
if ( ifs1.fail() )
    throw std::runtime_error("Probleme lecture taille du graphe");
std::string id_arete;
std::string id_sommet1, id_sommet2;
//lecture des aretes
for (int i=0; i<taille; ++i)
{
    //lecture des ids des deux extrÈmitÈs
    ifs1>>id_arete;
    if(ifs1.fail())
        throw std::runtime_error("Probleme lecture id arete");
    ifs1>>id_sommet1;
    if(ifs1.fail())
        throw std::runtime_error("Probleme lecture arete sommet 1");
    ifs1>>id_sommet2;
    if(ifs1.fail())
        throw std::runtime_error("Probleme lecture arete sommet 2");
    m_aretes.insert({id_arete, new Arete{id_arete, id_sommet1, id_sommet2, 0, 0}});
}


//ajouter chaque extrÈmitÈ ‡ la liste des voisins de l'autre (graphe non orientÈ)
//(m_sommets.find(id))->second->ajouterVoisin((m_sommets.find(id_voisin))->second);
//(m_sommets.find(id_voisin))->second->ajouterVoisin((m_sommets.find(id))->second);//remove si graphe orientÈ



std::ifstream ifs2{FichierPoidsAretes};
if (!ifs2)
    throw std::runtime_error( "Impossible d'ouvrir en lecture " + FichierPoidsAretes );
int taille2, ponderation;
ifs2 >> taille2;
if ( ifs2.fail() )
    throw std::runtime_error("Probleme lecture taille du graphe");
ifs2 >> ponderation;
if ( ifs2.fail() )
    throw std::runtime_error("Probleme lecture ponderation du graphe");
//std::string id_sommet;
std::string id_arete2;
float poids1,poids2;
//lecture des sommets
for (int i=0; i<taille2; ++i)
{
    ifs2>>id_arete2;
    if(ifs2.fail())
        throw std::runtime_error("Probleme lecture donnees id arete");
    ifs2>>poids1;
    if(ifs2.fail())
        throw std::runtime_error("Probleme lecture donnees poids 1");
    ifs2>>poids2;
    if(ifs2.fail())
        throw std::runtime_error("Probleme lecture donnees poids 2");
    m_aretes_ponderees.insert({id_sommet,new Arete{id_arete2,id_sommet1,id_sommet2, poids1, poids2}});
}

*/





void graphe::afficher() const
{
    std::cout<<"graphe : "<<std::endl;

    std::cout<<"   ordre : "<<m_sommets.size()<<std::endl;


    //pour chaque sommet:

    for ( auto it1=m_sommets.begin(); it1!=m_sommets.end(); ++it1)
    {
        std::cout<<"   sommet : ";
        std::cout << it1->first;
        it1->second->afficherData();
        std::cout<<std::endl;

    }

    std::cout<<"   taille : "<<m_aretes.size()<<std::endl;


    auto it2 = m_aretes.begin();

    while(it2 != m_aretes.end())
    {
        std::cout<<"   arete : ";
        it2->second->afficherData();
        std::cout<<std::endl;
        it2++;
    }


}

void graphe::parcoursBFS(std::string id) const
{
    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<std::string,std::string> l_pred;
    l_pred=s0->parcoursBFS();
}
void graphe::afficherBFS(std::string id) const
{
    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<std::string,std::string> l_pred;
    std::cout<<"parcoursBFS a partir de "<<id<<" :"<<std::endl;
    l_pred=s0->parcoursBFS();
    for(auto s:l_pred)
    {
        std::cout<<s.first<<" <--- ";
        std::pair<std::string,std::string> pred=s;
        while(pred.second!=id)
        {
            pred=*l_pred.find(pred.second);
            std::cout<<pred.first<<" <--- ";
        }
        std::cout<<id<<std::endl;
    }
}
void graphe::parcoursDFS(std::string id) const
{
    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<std::string,std::string> l_pred;
    l_pred=s0->parcoursDFS();
}
void graphe::afficherDFS(std::string id) const
{
    Sommet*s0=(m_sommets.find(id))->second;
    std::unordered_map<std::string,std::string> l_pred;
    std::cout<<"parcoursDFS a partir de "<<id<<" :"<<std::endl;
    l_pred=s0->parcoursDFS();
    for(auto s:l_pred)
    {
        std::cout<<s.first<<" <--- ";
        std::pair<std::string,std::string> pred=s;
        while(pred.second!=id)
        {
            pred=*l_pred.find(pred.second);
            std::cout<<pred.first<<" <--- ";
        }
        std::cout<<id<<std::endl;
    }
}
int graphe::rechercher_afficherToutesCC() const
{
    int i=0;
    std::cout<<"composantes connexes :"<<std::endl;
    std::cout<<"recherche et affichage de toutes les composantes connexes a coder"<<std::endl;
    return i;
}
graphe::~graphe()
{
    //dtor
}


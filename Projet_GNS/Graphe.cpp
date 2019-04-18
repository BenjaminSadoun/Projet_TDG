#include <fstream>
#include <iostream>
#include "Graphe.hpp"
#include "Arete.hpp"
#include "Sommet.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "Couleurs.h"
#include <algorithm>
#include <queue>
#include <limits>
//CHARGEMENT GRAPHES
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
    int id;
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
        m_sommetsB.push_back(new Sommet{id,x,y});
        // m_sommets.insert({id,new Sommet{id,x,y}});
    }
    int nbAretes;
    ifs1 >> nbAretes;
    if ( ifs1.fail() )
        throw std::runtime_error("Probleme lecture Aretes");
    int id_ext1;
    int id_ext2;
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
        
        m_aretes.push_back(new Arete{id,id_ext1,id_ext2,poids1,poids2});
        
        m_sommetsB[id_ext1]->ajouterVoisin(id_ext2,poids1);
        m_sommetsB[id_ext2]->ajouterVoisin(id_ext1,poids1);
    }
}


//AFFICHAGE GRAPHE
void graphe::afficher() const
{
    std::cout<<"graphe : "<<std::endl;
    
    std::cout<<"   ordre : "<<m_sommetsB.size()<<std::endl;
    //pour chaque sommet:
    /*
     for ( auto it1=m_sommets.begin(); it1!=m_sommets.end(); ++it1)
     {
     std::cout<<"   sommet : ";
     std::cout << it1->first;
     it1->second->afficherData();
     std::cout<<std::endl;
     
     }*/
    
    std::cout<<"   taille : "<<m_aretes.size()<<std::endl;
    
    for (auto it2: m_aretes)
    {
        std::cout<<"   arete : ";
        it2-> afficherData();
        std::cout<<std::endl;
    }
    
    
    
    
    for (auto o: m_sommetsB)
    {
        
        std::cout<<"   sommet : ";
        o->afficherData();
        
        //it1->second->afficherData();
        std::cout<<std::endl;
        
    }
}
//DESSINER SOMMETS
void graphe::dessinerSommets(Svgfile &svgout)
{
    
    for ( auto o : m_sommetsB)
    {
        o->dessSommet(svgout);
        std::cout<<std::endl;
    }
}

//DESSINER ARETES
void graphe::dessinerArete(Svgfile &svgout)
{
    float pdstot1 = 0;
    float pdstot2 = 0;
    for (auto it : m_aretes)
    {
        
        int ind1, ind2;
        ind1 = it -> getSommet1();
        ind2 = it -> getSommet2();
        //std::cout << ind1 << " "<< ind2<<std::endl;
        /* double x1 = m_sommets.find(ind1)->second->get_x();
         double y1 = m_sommets.find(ind1)->second->get_y();
         float pds1 = it->getPoids1();
         double x2 = m_sommets.find(ind2)->second->get_x();
         double y2 = m_sommets.find(ind2)->second->get_y();*/
        double x1 = m_sommetsB[ind1]->get_x();
        double y1 = m_sommetsB[ind1]->get_y();
        float pds1 = it->getPoids1();
        double x2 = m_sommetsB[ind2]->get_x();
        double y2 = m_sommetsB[ind2]->get_y();
        float pds2 = it->getPoids2();
        
        pdstot1 += pds1;
        pdstot2 += pds2;
        
        //std::cout << x1 << " "<< y1 <<"     "<<x2<<" "<<y2 <<std::endl;
        svgout.addLine(x1,y1,x2,y2, Couleur(0,0,0));
        svgout.addText((x1+x2)/2-5, (y1+y2)/2, pds1, Couleur(200,0,0));
        svgout.addText((x1+x2)/2+5, (y1+y2)/2, pds2, Couleur(0,200,0));
    }
    svgout.addText(10, 30, "Poids 1", Couleur(200,0,0));
    svgout.addText(50, 30, pdstot1, Couleur(200,0,0));
    svgout.addText(10, 50, "Poids 2", Couleur(0,200,0));
    svgout.addText(30, 50, pdstot2, Couleur(0,200,0));
}

void graphe::dessinerArete(Svgfile &svgout,std::vector<Arete*> vec)
{
    float pdstot1 = 0;
    float pdstot2 = 0;
    for (auto it : vec)
    {
        int ind1, ind2;
        ind1 = it -> getSommet1();
        ind2 = it -> getSommet2();
        //std::cout << ind1 << " "<< ind2<<std::endl;
        /*double x1 = m_sommets.find(ind1)->second->get_x();
         double y1 = m_sommets.find(ind1)->second->get_y();
         float pds1 = it->getPoids1();
         double x2 = m_sommets.find(ind2)->second->get_x();
         double y2 = m_sommets.find(ind2)->second->get_y();
         float pds2 = it->getPoids2();*/
        double x1 = m_sommetsB[ind1]->get_x();
        double y1 = m_sommetsB[ind1]->get_y();
        float pds1 = it->getPoids1();
        double x2 = m_sommetsB[ind2]->get_x();
        double y2 = m_sommetsB[ind2]->get_y();
        float pds2 = it->getPoids2();
        pdstot1 += pds1;
        pdstot2 += pds2;
        
        //std::cout << x1 << " "<< y1 <<"     "<<x2<<" "<<y2 <<std::endl;
        svgout.addLine(x1,y1,x2,y2, Couleur(0,0,0));
        svgout.addText((x1+x2)/2-5, (y1+y2)/2, pds1, Couleur(200,0,0));
        svgout.addText((x1+x2)/2+5, (y1+y2)/2, pds2, Couleur(0,200,0));
    }
    svgout.addText(10, 30, "Poids 1:", Couleur(200,0,0));
    svgout.addText(65, 30, pdstot1, Couleur(200,0,0));
    svgout.addText(10, 50, "Poids 2:", Couleur(0,200,0));
    svgout.addText(65, 50, pdstot2, Couleur(0,200,0));
    
}

/*
 void graphe::parcoursBFS(int id) const
 {
 Sommet*s0=(m_sommetsB[id]);
 std::unordered_map<int,int> l_pred;
 l_pred= s0->parcoursBFS();
 }
 void graphe::afficherBFS(int id) const
 {
 Sommet*s0=(m_sommetsB[id]);
 std::unordered_map<int,int> l_pred;
 std::cout<<"parcoursBFS a partir de "<<id<<" :"<<std::endl;
 l_pred=s0->parcoursBFS();
 
 for(auto s:l_pred)
 {
 std::cout<< s.first<<" <--- ";
 std::pair<int,int> pred=s;
 
 while(pred.second != id)
 {
 pred=*l_pred.find(pred.second);
 std::cout<<pred.first<<" <--- ";
 }
 std::cout<<id<<std::endl;
 }
 }*/
/*
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
 
 */
//DESTRUCTEUR
graphe::~graphe()
{
    //dtor
}


//KRUKAL
std::vector<Arete*> graphe::kruskal(int choix)
{
    
    std::vector<Arete*> Aretes_marques;
    std::unordered_set<int> sommets_marques;
    std::unordered_map<int,int> cc;
    int id,id1;
    int numerocc=0;
    
    for(auto i: m_sommetsB)
    {
        
        id=i->getid();
        cc.insert({id,numerocc});
        ++numerocc;
        
    }
    
    
    if(choix==1){
        auto fl = [](Arete* a, Arete* b){return a->getPoids1()<b->getPoids1();};
        std::sort(m_aretes.begin(),m_aretes.end(),fl);
        int p(0), p2(0);
        for( auto it: m_aretes)
        {
            int som1=it->getSommet1();
            int som2=it->getSommet2();
            // sommets_marques.insert(som1);
            // sommets_marques.insert(som2);
            
            
            for(auto ut: cc)
            {
                id= ut.first;
                if(id==som1)
                {
                    p=ut.second;
                    
                }
            }
            
            for(auto ut: cc)
            {
                id1= ut.first;
                if(id1==som2)
                {
                    p2=ut.second;
                }
            }
            if(p!=p2)
            {
                for(auto& i: cc )
                {
                    if(i.second==p)
                    {
                        i.second=p2;
                    }
                }
                Aretes_marques.push_back(it);
            }
        }
    }
    else if(choix==2)
    {
        auto fl = [](Arete* a, Arete* b){return a->getPoids2()<b->getPoids2();};
        std::sort(m_aretes.begin(),m_aretes.end(),fl);
        int p(0), p2(0);
        for( auto it: m_aretes)
        {
            int som1=it->getSommet1();
            int som2=it->getSommet2();
            // sommets_marques.insert(som1);
            // sommets_marques.insert(som2);
            for(auto ut: cc)
            {
                id= ut.first;
                if(id==som1)
                {
                    p=ut.second;
                }
            }
            for(auto ut: cc)
            {
                id1= ut.first;
                if(id1==som2)
                {
                    p2=ut.second;
                }
            }
            if(p!=p2)
            {
                for(auto& i: cc )
                {
                    if(i.second==p)
                    {
                        i.second=p2;
                    }
                }
                Aretes_marques.push_back(it);
            }
        }
    }
    return Aretes_marques;
}

//DIJKSRA
std::vector<int> graphe::Dijkstra(int depart){
    
    
    
    
    auto comparer = [](const std::pair<int,float> &a,std::pair<int,float> &b) {return a.second > b.second;};
    std::vector<int> Distances(m_sommetsB.size(), std::numeric_limits<int>::max());
    std::vector<std::vector<std::pair<int, int>>> G(m_sommetsB.size());
    
    for (auto i : m_aretes) {
        int u, v;
        float p1;
        u=i->getSommet1();
        v=i->getSommet2();
        p1=i->getPoids2();
        
        G[u].push_back(std::make_pair(v, p1));
        G[v].push_back(std::make_pair(u, p1));
    }
    Distances[depart] = 0;
    std::vector<int> Parents(m_sommetsB.size(),-1);
    std::priority_queue<std::pair<int,float>, std::vector<std::pair<int, float>>, decltype(comparer) > priority(comparer);
    priority.push(std::make_pair(depart,Distances[depart]));
    
    for(auto it: m_sommetsB){
        std::cout <<std::endl;
        while (!priority.empty())
        {
            std::cout <<std::endl;
            
            int v = priority.top().first;
            int w = priority.top().second;
            std::cout <<std::endl;
            priority.pop();
            if (w <= Distances[v])
            {
                
                for (const auto& i : G[v])
                {
                    
                    auto v2 = i.first;
                    
                    auto w2 = i.second;
                    
                    if (Distances[v] + w2 < Distances[v2] )
                    {
                        
                       
                        
                        Distances[v2] = Distances[v] + w2;
                        
                        Parents[v2] = v;
                        priority.push(std::make_pair( v2,Distances[v2]));
                    }
                }
            }
        }
    }
    
    for (auto i = 0; i != m_sommetsB.size(); ++i)
    {
        std::cout << "\nchemin du sommet numéro: " << depart << " au sommet numéro: " << i << " coute " << Distances[i] << std::endl;
        std::cout << i;
        for (auto p = Parents[i]; p != -1; p = Parents[p])
            std::cout << " <- " << p;
    }
    
    
    
    
    
    
    return Parents;
}



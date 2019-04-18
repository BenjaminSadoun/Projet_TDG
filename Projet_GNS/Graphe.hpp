//
//  Graphe.hpp
//  Projet_GNSX
//
//  Created by pezi on 15/04/2019.
//  Copyright © 2019 pezi. All rights reserved.
//

#ifndef Graphe_hpp
#define Graphe_hpp
#include <string>
#include <unordered_map>
#include <map>
#include "Sommet.hpp"
#include "Arete.hpp"
#include "svgfile.h"

class graphe
{
public:
    ///constructeur qui charge le graphe en mÈmoire
    //format du fichier ordre/liste des sommets/taille/liste des arÍtes
    graphe(std::string,std::string);
    ~graphe();
    void afficher() const;
    ///lance un parcours en largeur ‡ partir du sommet d'identifiant id
    // void parcoursBFS(int) const;
    ///lance et affiche le parcours en largeur ‡ partir du sommet d'identifiant id
    // void afficherBFS(int) const;
    ///lance un parcours en profondeur ‡ partir du sommet d'identifiant id
    //  void parcoursDFS(std::string) const;
    ///lance et affiche le parcours en profondeur ‡ partir du sommet d'identifiant id
    // void afficherDFS(std::string) const;
    ///recherche et affiche les composantes connexes
    ///retourne le nombre de composantes connexes
    int rechercher_afficherToutesCC() const;
    void dessinerSommets(Svgfile &svgout);
    void dessinerArete(Svgfile &svgout);
    std::vector<Arete*> kruskal(int);
    void dessinerArete(Svgfile &svgout,std::vector<Arete*>);
    std::vector<int> Dijkstra(int);
    
protected:
    
private:
    /// Le rÈseau est constituÈ d'une collection de sommets
    ///std::map<std::string,Sommet*> m_sommets;
    std::vector<Sommet*> m_sommetsB;
    std::vector<Arete*> m_aretes;
    
};


#endif // Graphe_hpp


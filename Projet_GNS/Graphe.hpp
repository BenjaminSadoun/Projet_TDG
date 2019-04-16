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
#include "Sommet.hpp"
#include "Arete.hpp"
#include <string>
#include <vector>
class graphe
{
public:
    ///constructeur qui charge le graphe en mÈmoire
    //format du fichier ordre/liste des sommets/taille/liste des arÍtes
    graphe(std::string,std::string);
    ~graphe();
    void afficher() const;
    ///lance un parcours en largeur ‡ partir du sommet d'identifiant id
    void parcoursBFS(std::string) const;
    ///lance et affiche le parcours en largeur ‡ partir du sommet d'identifiant id
    void afficherBFS(std::string) const;
    ///lance un parcours en profondeur ‡ partir du sommet d'identifiant id
    void parcoursDFS(std::string) const;
    ///lance et affiche le parcours en profondeur ‡ partir du sommet d'identifiant id
    void afficherDFS(std::string) const;
    ///recherche et affiche les composantes connexes
    ///retourne le nombre de composantes connexes
    int rechercher_afficherToutesCC() const;
    std::vector<Arete*> kruskal(std::vector<Arete*>) const;
    
protected:
    
private:
    /// Le rÈseau est constituÈ d'une collection de sommets
    std::unordered_map<std::string,Sommet*> m_sommets;//stockÈe dans une map (clÈ=id du sommet, valeur= pointeur sur le sommet)
    std::vector<Arete*> m_Aretes;
    
};


#endif // Graphe_hpp

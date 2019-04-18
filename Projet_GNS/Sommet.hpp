#ifndef SOMMET_Hpp
#define SOMMET_Hpp
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "svgfile.h"


class Sommet
{
public:
    ///constructeur qui reÁoit en params les donnÈes du sommet
    Sommet(int,double,double);
    void ajouterVoisin(int,float);
    void afficherData() const;
    void afficherVoisins() const;
    ///mÈthode de parcours en largeur du graphe ‡ partir du sommet
    ///renvoie les prÈdÈcesseurs sous forme d'une map (clÈ=id du sommet,valeur=id de son prÈdÈcesseur)
    //std::unordered_map<int,int> parcoursBFS() const;
    ///mÈthode de parcours en profondeur du graphe ‡ partir du sommet
    std::unordered_map<std::string,std::string> parcoursDFS() const;
    ///mÈthode qui recherche la composante connexe du sommet
    ///renvoie la liste des ids des sommets de la composante
    std::unordered_set<std::string> rechercherCC() const;
    void dessSommet(Svgfile& svgout);
    int getid() const;
    
    double get_x();
    double get_y();
    void affichervoisins();
    std::vector<std::pair<int,float>> getvoisins();
    ~Sommet();
    
protected:
    
private:
    /// Voisinage : liste d'adjacence
    std::vector<std::pair< int,float>> m_voisins;
    
    /// DonnÈes spÈcifiques du sommet
    int m_id; // Identifiant
    double m_x, m_y; // Position
    
};

#endif // SOMMET_H



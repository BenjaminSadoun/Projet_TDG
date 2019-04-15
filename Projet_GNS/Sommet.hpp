#ifndef SOMMET_Hpp
#define SOMMET_Hpp
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Sommet
{
public:
    ///constructeur qui reÁoit en params les donnÈes du sommet
    Sommet(std::string,double,double);
    void ajouterVoisin(const Sommet*);
    void afficherData() const;
    void afficherVoisins() const;
    ///mÈthode de parcours en largeur du graphe ‡ partir du sommet
    ///renvoie les prÈdÈcesseurs sous forme d'une map (clÈ=id du sommet,valeur=id de son prÈdÈcesseur)
    std::unordered_map<std::string,std::string> parcoursBFS() const;
    ///mÈthode de parcours en profondeur du graphe ‡ partir du sommet
    std::unordered_map<std::string,std::string> parcoursDFS() const;
    ///mÈthode qui recherche la composante connexe du sommet
    ///renvoie la liste des ids des sommets de la composante
    std::unordered_set<std::string> rechercherCC() const;
    ~Sommet();

protected:

private:
    /// Voisinage : liste d'adjacence
    std::vector<const Sommet*> m_voisins;

    /// DonnÈes spÈcifiques du sommet
    std::string m_id; // Identifiant
    double m_x, m_y; // Position

};

#endif // SOMMET_H


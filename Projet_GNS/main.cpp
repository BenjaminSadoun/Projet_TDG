#include <iostream>
#include "Graphe.hpp"
#include "Arete.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "svgfile.h"


int main()
{
    Svgfile svgout;
    svgout.addGrid();
    graphe test{"triville.txt", "triville_weights_0.txt"};
    std::vector<Arete*> ccp1;
    
    
    test.afficher();
    ccp1=test.kruskal(1);
    test.dessinerArete(svgout,ccp1);
    test.dessinerSommets(svgout);
    test.Dijkstra(0);
    
    return 0;
}


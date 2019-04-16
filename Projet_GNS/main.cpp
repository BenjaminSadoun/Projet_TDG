#include <iostream>
#include "Graphe.hpp"
#include "Arete.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>


int main()
{
    graphe test{"broadway.txt", "broadway_weights_0.txt"};

    test.afficher();

    return 0;
}

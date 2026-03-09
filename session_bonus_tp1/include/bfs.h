#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include <vector>
#include <string>

// Résultat d'un parcours BFS
struct BFSResult {
    std::vector<int> distance;   // distance[v] = nb d'arêtes depuis la source (-1 si inaccessible)
    std::vector<int> parent;     // parent[v] = prédécesseur sur le plus court chemin (-1 si aucun)
    std::vector<int> order;      // ordre de visite BFS
};

// --- ÉTAPE 3 : BFS ---
// Parcours en largeur depuis une source
BFSResult bfs(const Graph& g, int source);

// --- ÉTAPE 4 : Applications BFS ---
// Reconstruire le chemin de la source vers target
std::string getPath(const BFSResult& result, int target, const Graph& g);

// Trouver toutes les composantes connexes
std::vector<std::vector<int>> connectedComponents(const Graph& g);

// Afficher les composantes
void printComponents(const std::vector<std::vector<int>>& comps, const Graph& g);

// Degré de séparation entre deux sommets
int degreeSeparation(const Graph& g, int u, int v);

#endif // BFS_H

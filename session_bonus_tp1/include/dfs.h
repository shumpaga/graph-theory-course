#ifndef DFS_H
#define DFS_H

#include "graph.h"
#include <vector>

// Résultat d'un parcours DFS
struct DFSResult {
    std::vector<int> discovery;  // discovery[v] = temps de découverte
    std::vector<int> finish;     // finish[v] = temps de fin de traitement
    std::vector<int> parent;     // parent[v] = prédécesseur (-1 si racine)
    std::vector<int> order;      // ordre de visite DFS
};

// --- ÉTAPE 5 : DFS ---
// Visite récursive DFS depuis le sommet u
void dfsVisit(const Graph& g, int u, std::vector<bool>& visited,
              DFSResult& result, int& timer);

// Parcours DFS depuis une source (visite uniquement les sommets accessibles)
DFSResult dfs(const Graph& g, int source);

// DFS complet : visite TOUS les sommets (relance depuis chaque non visité)
DFSResult dfsComplete(const Graph& g);

// --- ÉTAPE 6 : Applications DFS ---
// Tri topologique (graphe orienté acyclique uniquement)
std::vector<int> topologicalSort(const Graph& g);

// Détection de cycle dans un graphe orienté (3 couleurs)
bool dfsCycleVisit(const Graph& g, int u, std::vector<int>& color);
bool hasCycle(const Graph& g);

#endif // DFS_H

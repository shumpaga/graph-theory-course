// NOM : _______________  PRÉNOM : _______________
// TP1 — RéseauVAK : Représentations de graphes, BFS & DFS
// Fichier : bfs.cpp — Implémentation du parcours BFS et applications

#include "bfs.h"
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// ═══════════════════════════════════════════════════════════
// ÉTAPE 3 : BFS — PARCOURS EN LARGEUR
// ═══════════════════════════════════════════════════════════

// FONCTION 3.1 : bfs
// Objectif : parcourir le graphe en largeur depuis la source
// Remplir distance[], parent[] et order[]
BFSResult bfs(const Graph& g, int source) {
    int V = g.getV();
    BFSResult result;
    result.distance.assign(V, -1);    // -1 = non visité
    result.parent.assign(V, -1);      // -1 = pas de parent

    // TODO 1 : Initialiser la source
    //   result.distance[source] = 0
    //   Créer une queue<int> q et y ajouter source
    //   Ajouter source à result.order

    // TODO 2 : Boucle BFS
    //   Tant que la queue n'est pas vide :
    //     int u = q.front(); q.pop();
    //     Pour chaque voisin v de u (g.neighbors(u)) :
    //       Si result.distance[v] == -1 :   (non visité)
    //         result.distance[v] = result.distance[u] + 1
    //         result.parent[v] = u
    //         q.push(v)
    //         result.order.push_back(v)

    return result;
}

// ═══════════════════════════════════════════════════════════
// ÉTAPE 4 : APPLICATIONS BFS
// ═══════════════════════════════════════════════════════════

// FONCTION 4.1 : getPath
// Objectif : reconstruire le chemin source → target en remontant parent[]
string getPath(const BFSResult& result, int target, const Graph& g) {
    // TODO 1 : Si distance[target] == -1, retourner "Aucun chemin"

    // TODO 2 : Remonter parent[] depuis target jusqu'à la source
    //          vector<int> path;
    //          int current = target;
    //          Tant que current != -1 :
    //              path.push_back(current)
    //              current = result.parent[current]

    // TODO 3 : Inverser le chemin (reverse)

    // TODO 4 : Construire la string "Dossou -> Adjovi -> Mensah"
    //          en utilisant g.getName()

    return ""; // placeholder
}

// FONCTION 4.2 : connectedComponents
// Objectif : trouver toutes les composantes connexes du graphe
vector<vector<int>> connectedComponents(const Graph& g) {
    int V = g.getV();
    vector<bool> visited(V, false);
    vector<vector<int>> components;

    // TODO : Pour chaque sommet u de 0 à V-1 :
    //   Si !visited[u] :
    //     Lancer BFS depuis u : BFSResult r = bfs(g, u)
    //     Marquer tous les sommets de r.order comme visited
    //     Ajouter r.order comme nouvelle composante dans components

    return components;
}

// FONCTION 4.3 : printComponents
// Objectif : afficher les composantes joliment
void printComponents(const vector<vector<int>>& comps, const Graph& g) {
    // TODO : Pour chaque composante i :
    //   Afficher "Composante i+1 (N sommets) : nom1, nom2, ..."
    //   Utiliser g.getName() pour les noms
}

// FONCTION 4.4 : degreeSeparation
// Objectif : nombre minimum d'arêtes entre u et v (-1 si déconnectés)
int degreeSeparation(const Graph& g, int u, int v) {
    // TODO : Lancer BFS depuis u, retourner result.distance[v]

    return -1; // placeholder
}

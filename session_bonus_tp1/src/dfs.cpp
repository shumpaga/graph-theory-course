// NOM : _______________  PRÉNOM : _______________
// TP1 — RéseauVAK : Représentations de graphes, BFS & DFS
// Fichier : dfs.cpp — Implémentation du parcours DFS et applications

#include "dfs.h"
#include <iostream>
#include <algorithm>

using namespace std;

// ═══════════════════════════════════════════════════════════
// ÉTAPE 5 : DFS — PARCOURS EN PROFONDEUR
// ═══════════════════════════════════════════════════════════

// FONCTION 5.1 : dfsVisit (récursif)
// Objectif : explorer récursivement depuis u, mettre à jour discovery/finish
void dfsVisit(const Graph& g, int u, vector<bool>& visited,
              DFSResult& result, int& timer) {
    // TODO 1 : Marquer u comme visité : visited[u] = true
    // TODO 2 : Enregistrer le temps de découverte : result.discovery[u] = timer++
    // TODO 3 : Ajouter u à result.order

    // TODO 4 : Pour chaque voisin v de u (g.neighbors(u)) :
    //            Si !visited[v] :
    //              result.parent[v] = u
    //              Appel récursif : dfsVisit(g, v, visited, result, timer)

    // TODO 5 : Enregistrer le temps de fin : result.finish[u] = timer++
}

// FONCTION 5.2 : dfs (depuis une source)
// Objectif : lancer DFS depuis source, ne visite que les sommets accessibles
DFSResult dfs(const Graph& g, int source) {
    int V = g.getV();
    DFSResult result;
    result.discovery.assign(V, -1);
    result.finish.assign(V, -1);
    result.parent.assign(V, -1);
    vector<bool> visited(V, false);
    int timer = 0;

    // TODO : Appeler dfsVisit(g, source, visited, result, timer)

    return result;
}

// FONCTION 5.3 : dfsComplete (visite TOUS les sommets)
// Objectif : relancer DFS depuis chaque sommet non visité
// Utile pour le tri topologique (graphe orienté peut avoir plusieurs sources)
DFSResult dfsComplete(const Graph& g) {
    int V = g.getV();
    DFSResult result;
    result.discovery.assign(V, -1);
    result.finish.assign(V, -1);
    result.parent.assign(V, -1);
    vector<bool> visited(V, false);
    int timer = 0;

    // TODO : Pour chaque sommet u de 0 à V-1 :
    //          Si !visited[u] :
    //            dfsVisit(g, u, visited, result, timer)

    return result;
}

// ═══════════════════════════════════════════════════════════
// ÉTAPE 6 : APPLICATIONS DFS — TRI TOPOLOGIQUE & CYCLES
// ═══════════════════════════════════════════════════════════

// FONCTION 6.1 : topologicalSort
// Objectif : retourner les sommets dans un ordre respectant les prérequis
// Méthode : trier par finish[] DÉCROISSANT après un DFS complet
vector<int> topologicalSort(const Graph& g) {
    // TODO 1 : Lancer dfsComplete(g) pour obtenir finish[] de tous les sommets

    // TODO 2 : Créer un vecteur d'indices {0, 1, 2, ..., V-1}

    // TODO 3 : Trier ce vecteur par finish[] DÉCROISSANT :
    //          sort(indices.begin(), indices.end(),
    //               [&result](int a, int b) {
    //                   return result.finish[a] > result.finish[b];
    //               });

    // TODO 4 : Retourner le vecteur trié

    return {}; // placeholder
}

// FONCTION 6.2 : dfsCycleVisit (3 couleurs)
// Objectif : détecter un cycle en utilisant blanc(0)/gris(1)/noir(2)
// Retourne true si un cycle est trouvé depuis u
bool dfsCycleVisit(const Graph& g, int u, vector<int>& color) {
    // TODO 1 : color[u] = 1  (gris = en cours d'exploration)

    // TODO 2 : Pour chaque voisin v de u :
    //   Si color[v] == 1 :
    //       → On retombe sur un sommet gris = CYCLE !
    //       Retourner true
    //   Si color[v] == 0 :
    //       → Sommet blanc, pas encore visité
    //       Si dfsCycleVisit(g, v, color) retourne true :
    //           Retourner true (cycle trouvé plus profond)

    // TODO 3 : color[u] = 2  (noir = terminé, tous les descendants explorés)

    // TODO 4 : Retourner false (pas de cycle depuis u)

    return false; // placeholder
}

// FONCTION 6.3 : hasCycle
// Objectif : vérifier si le graphe orienté contient un cycle
bool hasCycle(const Graph& g) {
    int V = g.getV();
    // 0 = blanc (non visité), 1 = gris (en cours), 2 = noir (terminé)
    vector<int> color(V, 0);

    // TODO : Pour chaque sommet u de 0 à V-1 :
    //   Si color[u] == 0 :
    //     Si dfsCycleVisit(g, u, color) retourne true :
    //       Retourner true (cycle détecté !)

    // Si on arrive ici, aucun cycle
    return false;
}

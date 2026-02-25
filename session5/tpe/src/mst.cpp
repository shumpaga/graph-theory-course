/**
 * @file mst.cpp
 * @brief Implémentation de l'algorithme de Kruskal
 *
 * TPE5 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * NOM    :
 * PRENOM :
 *
 * 4 fonctions à implémenter :
 *   - getEdges()  : extraction des arêtes (étape 5)
 *   - kruskal()   : algorithme de Kruskal (étape 5)
 *   - mstWeight() : poids total du MST (étape 6)
 *   - printMST()  : affichage du MST (étape 6)
 */

#include "mst.h"
#include "union_find.h"
#include <algorithm>
#include <iostream>

using namespace std;

// ============================================================
// ÉTAPE 5 : EXTRACTION DES ARÊTES (étape 5, partie de 7 pts)
// ============================================================

vector<Edge> getEdges(const Graph& g) {
    // TODO: Extraire toutes les arêtes du graphe SANS DOUBLONS
    //
    // Attention : le graphe est non orienté, donc chaque arête (u,v,w)
    // apparaît deux fois dans la liste d'adjacence :
    //   - une fois dans adj[u] comme (v, w)
    //   - une fois dans adj[v] comme (u, w)
    //
    // Astuce : ne garder que les arêtes où u < v
    //
    // Algorithme :
    //   edges = []
    //   pour chaque sommet u de 0 à V-1 :
    //       pour chaque voisin (v, poids) de u :
    //           si u < v :
    //               edges.ajouter({u, v, poids})
    //   retourner edges

    (void)g;
    return {}; // placeholder — à remplacer
}

// ============================================================
// ÉTAPE 5 : ALGORITHME DE KRUSKAL (étape 5, partie de 7 pts)
// ============================================================

vector<Edge> kruskal(const Graph& g) {
    // TODO: Implémenter l'algorithme de Kruskal
    //
    // Algorithme :
    //   1. edges = getEdges(g)
    //   2. Trier edges par poids croissant
    //      Indice : std::sort(edges.begin(), edges.end(),
    //               [](const Edge& a, const Edge& b) {
    //                   return a.weight < b.weight;
    //               });
    //   3. Créer un UnionFind(V)
    //   4. mst = []
    //   5. Pour chaque arête (u, v, w) dans edges triées :
    //          si !uf.connected(u, v) :
    //              mst.ajouter({u, v, w})
    //              uf.unite(u, v)
    //   6. Retourner mst

    (void)g;
    return {}; // placeholder — à remplacer
}

// ============================================================
// ÉTAPE 6 : POIDS TOTAL DU MST (étape 6, partie de 2 pts)
// ============================================================

int mstWeight(const vector<Edge>& mst) {
    // TODO: Calculer la somme des poids de toutes les arêtes du MST
    //
    // Algorithme :
    //   total = 0
    //   pour chaque arête e dans mst :
    //       total += e.weight
    //   retourner total

    (void)mst;
    return 0; // placeholder — à remplacer
}

// ============================================================
// ÉTAPE 6 : AFFICHAGE DU MST (étape 6, partie de 2 pts)
// ============================================================

void printMST(const vector<Edge>& mst, const Graph& g) {
    // TODO: Afficher chaque arête du MST avec noms de sommets
    //
    // Format attendu :
    //   Arbre Couvrant Minimal (6 arêtes) :
    //     A — C  (poids: 3)
    //     A — D  (poids: 5)
    //     ...
    //   Poids total : 35
    //
    // Utiliser g.getVertexName(sommet) pour afficher les noms

    (void)mst; (void)g;
}

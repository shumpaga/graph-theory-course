/**
 * @file mst.h
 * @brief Algorithme de Kruskal pour l'Arbre Couvrant Minimal (MST)
 *
 * TPE5 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * Fonctions :
 *   - getEdges(g)     : extraire les arêtes sans doublons
 *   - kruskal(g)      : algorithme de Kruskal → arêtes du MST
 *   - mstWeight(mst)  : poids total du MST
 *   - printMST(mst,g) : affichage du MST avec noms de sommets
 */

#ifndef MST_H
#define MST_H

#include "graph.h"
#include <vector>

// Structure représentant une arête pondérée
struct Edge {
    int src, dest, weight;
};

// Extraire les arêtes du graphe (sans doublons pour graphe non orienté)
std::vector<Edge> getEdges(const Graph& g);

// Algorithme de Kruskal : retourne les arêtes du MST triées par poids
std::vector<Edge> kruskal(const Graph& g);

// Calculer le poids total d'un ensemble d'arêtes
int mstWeight(const std::vector<Edge>& mst);

// Afficher les arêtes du MST avec les noms de sommets
void printMST(const std::vector<Edge>& mst, const Graph& g);

#endif // MST_H

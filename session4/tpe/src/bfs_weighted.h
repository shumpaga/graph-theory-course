/**
 * @file bfs_weighted.h
 * @brief BFS sur graphe pondéré (ignore les poids)
 *
 * TPE4 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * Ce module est FOURNI COMPLET aux étudiants.
 * Il sert à démontrer que BFS ne fonctionne pas pour
 * trouver le plus court chemin pondéré (Étape 0).
 */

#ifndef BFS_WEIGHTED_H
#define BFS_WEIGHTED_H

#include "graph.h"
#include <vector>
#include <utility>

/**
 * @brief BFS classique : trouve le chemin avec le MOINS D'ARÊTES (ignore les poids)
 *
 * @param g Graphe pondéré
 * @param source Sommet de départ
 * @param dest Sommet d'arrivée
 * @return {nombre_aretes, chemin} depuis source vers dest
 *         Si dest inaccessible, retourne {-1, {}}
 *
 * Complexité : O(V + E)
 */
std::pair<int, std::vector<int>> bfs_shortest_path(Graph& g, int source, int dest);

/**
 * @brief Calcule le coût réel d'un chemin (somme des poids des arêtes)
 *
 * @param g Graphe pondéré
 * @param path Chemin sous forme de liste de sommets
 * @return Coût total du chemin, ou -1 si le chemin est vide ou invalide
 *
 * Complexité : O(|path| * degré_max)
 */
int compute_path_cost(Graph& g, const std::vector<int>& path);

#endif // BFS_WEIGHTED_H

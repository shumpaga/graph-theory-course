/**
 * @file dijkstra.h
 * @brief Déclarations des fonctions Dijkstra et approches intermédiaires
 *
 * TPE4 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * 7 fonctions à implémenter dans dijkstra.cpp :
 * - ÉTAPE 0 (2 pts)  : test_bfs_fails
 * - ÉTAPE 1 (3 pts)  : greedy_path
 * - ÉTAPE 2 (4 pts)  : relax_all_edges
 * - ÉTAPE 3 (6 pts)  : dijkstra_base
 * - ÉTAPE 4 (6 pts)  : dijkstra_heap
 * - ÉTAPE 5 (4 pts)  : reconstruct_path, dijkstra_between_two
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include <vector>
#include <utility>

// ═══════════════════════════════════════════════
// ÉTAPE 0 : Constater que BFS se trompe (2 pts)
// ═══════════════════════════════════════════════

/**
 * @brief Affiche la comparaison BFS vs chemin optimal
 *
 * Utilise bfs_shortest_path() et compute_path_cost() (fournis dans bfs_weighted.h)
 * pour montrer que BFS minimise les arêtes, PAS le coût.
 *
 * @param g Graphe pondéré
 * @param source Sommet de départ
 * @param dest Sommet d'arrivée
 */
void test_bfs_fails(Graph& g, int source, int dest);

// ═══════════════════════════════════════════════
// ÉTAPE 1 : Approche gloutonne naïve (3 pts)
// ═══════════════════════════════════════════════

/**
 * @brief Chemin glouton : à chaque sommet, prendre le voisin le moins cher
 *
 * @param g Graphe pondéré
 * @param source Sommet de départ
 * @param dest Sommet d'arrivée
 * @return {coût_total, chemin}
 *         Si bloqué (aucun voisin non visité), retourne {-1, {}}
 *
 * Complexité : O(V * degré_max)
 */
std::pair<int, std::vector<int>> greedy_path(Graph& g, int source, int dest);

// ═══════════════════════════════════════════════
// ÉTAPE 2 : Relaxation brute (4 pts)
// ═══════════════════════════════════════════════

/**
 * @brief Relaxe TOUTES les arêtes V-1 fois (Bellman-Ford simplifié)
 *
 * @param g Graphe pondéré
 * @param source Sommet de départ
 * @return Tableau des distances depuis source
 *         distance[v] = INT_MAX si v inaccessible
 *
 * Complexité : O(V * E)
 */
std::vector<int> relax_all_edges(Graph& g, int source);

// ═══════════════════════════════════════════════
// ÉTAPE 3 : Dijkstra base — O(V²) (6 pts)
// ═══════════════════════════════════════════════

/**
 * @brief Relaxation + visite du sommet le plus proche (recherche linéaire)
 *
 * @param g Graphe pondéré
 * @param source Sommet de départ
 * @return Tableau des distances depuis source
 *
 * Complexité : O(V²)
 */
std::vector<int> dijkstra_base(Graph& g, int source);

// ═══════════════════════════════════════════════
// ÉTAPE 4 : Dijkstra heap — O((V+E) log V) (6 pts)
// ═══════════════════════════════════════════════

/**
 * @brief Dijkstra optimisé avec priority_queue (min-heap)
 *
 * @param g Graphe pondéré
 * @param source Sommet de départ
 * @return Tableau des distances depuis source
 *
 * Complexité : O((V+E) log V)
 */
std::vector<int> dijkstra_heap(Graph& g, int source);

// ═══════════════════════════════════════════════
// ÉTAPE 5 : Reconstruction + entre 2 sommets (4 pts)
// ═══════════════════════════════════════════════

/**
 * @brief Reconstruit le chemin source→dest en remontant parent[]
 *
 * @param parent Tableau des parents (parent[v] = prédécesseur de v)
 * @param source Sommet de départ
 * @param dest Sommet d'arrivée
 * @return Chemin [source, ..., dest] ou {} si dest inaccessible
 */
std::vector<int> reconstruct_path(std::vector<int>& parent, int source, int dest);

/**
 * @brief Distance + chemin entre 2 sommets (Dijkstra avec arrêt anticipé)
 *
 * @param g Graphe pondéré
 * @param source Sommet de départ
 * @param dest Sommet d'arrivée
 * @return {distance, chemin} ou {-1, {}} si dest inaccessible
 *
 * Complexité : O((V+E) log V) au pire, souvent moins grâce à l'arrêt anticipé
 */
std::pair<int, std::vector<int>> dijkstra_between_two(Graph& g, int source, int dest);

#endif // DIJKSTRA_H

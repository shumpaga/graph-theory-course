/**
 * @file dfs.h
 * @brief Fonctions de parcours en profondeur (DFS) et applications
 *
 * TPE3 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * 6 fonctions à implémenter dans dfs.cpp :
 * - NIVEAU BASE (10 pts) : dfs_recursive, dfs_iterative, dfs_timestamps
 * - NIVEAU STANDARD (12 pts) : has_cycle, topological_sort
 * - NIVEAU BONUS (3 pts) : find_path_dfs
 */

#ifndef DFS_H
#define DFS_H

#include "graph.h"
#include <vector>

// ============================================================
// NIVEAU BASE (10 points)
// ============================================================

/**
 * @brief Parcours en profondeur récursif depuis un sommet source
 * @param g Graphe à parcourir
 * @param source Sommet de départ
 * Points : 3
 */
void dfs_recursive(Graph& g, int source);

/**
 * @brief Parcours en profondeur itératif avec pile explicite
 * @param g Graphe à parcourir
 * @param source Sommet de départ
 * Points : 3
 * IMPORTANT : Utiliser la classe Stack de stack.h (pas std::stack)
 */
void dfs_iterative(Graph& g, int source);

/**
 * @brief Calcule les temps de découverte et de fin pour chaque sommet
 * @param g Graphe à parcourir
 * @param discovery Tableau des temps de découverte (à remplir)
 * @param finish Tableau des temps de fin (à remplir)
 * Points : 4
 * Note : Initialiser discovery et finish à -1 avant l'appel
 */
void dfs_timestamps(Graph& g, int discovery[], int finish[]);

// ============================================================
// NIVEAU STANDARD (12 points)
// ============================================================

/**
 * @brief Détecte la présence d'un cycle dans le graphe
 * @param g Graphe à analyser
 * @return true si le graphe contient un cycle, false sinon
 * Points : 6
 * Note : Algorithme différent pour graphe orienté vs non-orienté
 */
bool has_cycle(Graph& g);

/**
 * @brief Calcule un tri topologique du graphe (DAG requis)
 * @param g Graphe orienté acyclique (DAG)
 * @return Tableau d'entiers représentant l'ordre topologique, ou NULL si cycle détecté
 * Points : 6
 * Note : Vérifier l'absence de cycle AVANT de faire le tri
 */
int* topological_sort(Graph& g);

// ============================================================
// NIVEAU BONUS (3 points)
// ============================================================

/**
 * @brief Trouve un chemin entre deux sommets avec DFS
 * @param g Graphe à parcourir
 * @param src Sommet source
 * @param dest Sommet destination
 * @param path Vecteur pour stocker le chemin (à remplir)
 * @return true si un chemin existe, false sinon
 * Points : 3
 */
bool find_path_dfs(Graph& g, int src, int dest, std::vector<int>& path);

#endif // DFS_H

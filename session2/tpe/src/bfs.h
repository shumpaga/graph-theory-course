/**
 * @file bfs.h
 * @brief Algorithmes de parcours en largeur (BFS) et applications
 *
 * ESGC VERECHAGUINE A.K. - 2025-2026
 * Enseignant : M. Alexandre GBAGUIDI AISSE
 * Niveau : Licence 2 - Génie Informatique
 *
 * TPE2 - Séance 2 : Breadth-First Search
 *
 * BARÈME :
 * - NIVEAU BASE (10 pts) : Fonctions 1-3
 * - NIVEAU STANDARD (10 pts) : Fonctions 4-6
 * - NIVEAU BONUS (5 pts) : Fonction 7
 * - BONUS CODE (+2 pts) : Code très bien commenté
 */

#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include <vector>
using namespace std;

// ╔══════════════════════════════════════════════════════════╗
// ║               NIVEAU BASE (10 points)                    ║
// ╚══════════════════════════════════════════════════════════╝

/**
 * @brief Fonction 1 : Parcours BFS simple (3 pts)
 *
 * Effectue un parcours en largeur depuis un sommet source
 * et affiche l'ordre de visite des sommets.
 *
 * Algorithme :
 * 1. Créer une Queue Q et un vector<bool> visited
 * 2. Marquer source comme visité et l'enfiler
 * 3. Tant que Q n'est pas vide :
 *    a. Défiler u = Q.pop()
 *    b. Afficher u
 *    c. Pour chaque voisin v de u :
 *       - Si v non visité : marquer v visité, enfiler v
 *
 * @param g Le graphe
 * @param source Le sommet de départ
 *
 * Complexité : O(V + E)
 *
 * Exemple d'affichage :
 *   BFS depuis 0 : 0 1 2 3 4
 */
void bfs(Graph& g, int source);

/**
 * @brief Fonction 2 : Calcul des distances minimales (3 pts)
 *
 * Calcule la distance minimale de source à tous les autres sommets.
 *
 * @param g Le graphe
 * @param source Le sommet de départ
 * @return Vector où distance[v] = distance minimale de source à v
 *         distance[v] = -1 si v n'est pas atteignable depuis source
 *
 * Complexité : O(V + E)
 *
 * Exemple :
 *   Graphe : 0-1-2-3
 *   bfs_distances(g, 0) = [0, 1, 2, 3]
 */
vector<int> bfs_distances(Graph& g, int source);

/**
 * @brief Fonction 3 : Affichage de l'arbre BFS (4 pts)
 *
 * Construit et affiche l'arbre de parcours BFS.
 * Format : "parent → enfant1, enfant2, ..."
 *
 * Algorithme :
 * 1. Faire un BFS en gardant parent[v] pour chaque sommet
 * 2. Créer une structure parent → liste d'enfants
 * 3. Afficher chaque parent avec ses enfants
 *
 * @param g Le graphe
 * @param source La racine de l'arbre BFS
 *
 * Complexité : O(V + E)
 *
 * Exemple d'affichage :
 *   Arbre BFS depuis 0 :
 *   0 → 1, 2
 *   1 → 3
 *   2 → 4
 */
void print_bfs_tree(Graph& g, int source);

// ╔══════════════════════════════════════════════════════════╗
// ║             NIVEAU STANDARD (10 points)                  ║
// ╚══════════════════════════════════════════════════════════╝

/**
 * @brief Fonction 4 : Plus court chemin (3 pts)
 *
 * Reconstruit le plus court chemin de source à destination.
 *
 * Algorithme :
 * 1. Faire BFS avec parent[v] pour chaque sommet
 * 2. Si dest est atteignable :
 *    a. Reconstruire le chemin en remontant de dest à source
 *    b. Inverser le chemin
 * 3. Sinon retourner un vecteur vide
 *
 * @param g Le graphe
 * @param source Le sommet de départ
 * @param dest Le sommet d'arrivée
 * @return Vector contenant le chemin [source, ..., dest]
 *         Vecteur vide si aucun chemin n'existe
 *
 * Complexité : O(V + E)
 *
 * Exemple :
 *   Graphe : 0-1-2-3
 *   shortest_path(g, 0, 3) = [0, 1, 2, 3]
 */
vector<int> shortest_path(Graph& g, int source, int dest);

/**
 * @brief Fonction 5 : Test de connexité (3 pts)
 *
 * Détermine si le graphe est connexe (pour graphe non-orienté).
 * Un graphe est connexe si tous les sommets sont atteignables depuis n'importe quel sommet.
 *
 * Algorithme :
 * 1. Faire BFS depuis le sommet 0
 * 2. Compter le nombre de sommets visités
 * 3. Retourner (nombre_visités == V)
 *
 * @param g Le graphe (doit être non-orienté)
 * @return true si le graphe est connexe, false sinon
 *
 * Complexité : O(V + E)
 *
 * Note : Pour un graphe orienté, utiliser la notion de connexité forte
 */
bool is_connected(Graph& g);

/**
 * @brief Fonction 6 : Comptage des composantes connexes (4 pts)
 *
 * Compte le nombre de composantes connexes du graphe.
 *
 * Algorithme :
 * 1. Initialiser visited(V, false), count = 0
 * 2. Pour chaque sommet v :
 *    a. Si v non visité :
 *       - Faire BFS depuis v (marque tous les sommets de la composante)
 *       - Incrémenter count
 * 3. Retourner count
 *
 * @param g Le graphe
 * @return Nombre de composantes connexes
 *
 * Complexité : O(V + E)
 *
 * Exemple :
 *   Graphe : 0-1  2-3  4
 *   count_components(g) = 3
 */
int count_components(Graph& g);

// ╔══════════════════════════════════════════════════════════╗
// ║               NIVEAU BONUS (5 points)                    ║
// ╚══════════════════════════════════════════════════════════╝

/**
 * @brief Fonction 7 : Test de graphe biparti (5 pts)
 *
 * Détermine si le graphe est biparti (2-colorable).
 * Un graphe est biparti si on peut colorier ses sommets avec 2 couleurs
 * telles que deux sommets adjacents aient des couleurs différentes.
 *
 * Algorithme :
 * 1. Créer color(V, -1) (-1 = non colorié)
 * 2. Pour chaque composante :
 *    a. Faire BFS en coloriant alternativement 0 et 1
 *    b. Si on trouve une arête (u,v) avec color[u] == color[v] :
 *       - Retourner false (graphe non biparti)
 * 3. Retourner true (graphe biparti)
 *
 * @param g Le graphe
 * @return true si le graphe est biparti, false sinon
 *
 * Complexité : O(V + E)
 *
 * Propriété : Un graphe est biparti ssi il ne contient pas de cycle de longueur impaire
 *
 * Exemple :
 *   Graphe : 0-1-2-3-0 (cycle de longueur 4)
 *   is_bipartite(g) = true
 *
 *   Graphe : 0-1-2-0 (triangle)
 *   is_bipartite(g) = false
 */
bool is_bipartite(Graph& g);

#endif

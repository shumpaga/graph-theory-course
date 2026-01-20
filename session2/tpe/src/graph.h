/**
 * @file graph.h
 * @brief Classe Graph - Représentation par liste d'adjacence
 *
 * ESGC VERECHAGUINE A.K. - 2025-2026
 * Enseignant : M. Alexandre GBAGUIDI AISSE
 * Niveau : Licence 2 - Génie Informatique
 *
 * Cours : Théorie des Graphes - Séance 2 : BFS
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <string>

using namespace std;

/**
 * @class Graph
 * @brief Représente un graphe orienté ou non-orienté par liste d'adjacence
 */
class Graph {
private:
    int V;                          // Nombre de sommets
    vector<list<int>> adj;          // Liste d'adjacence
    bool directed;                  // Orienté ou non

public:
    // ==================== CONSTRUCTEURS ====================

    /**
     * @brief Construit un graphe avec V sommets
     * @param vertices Nombre de sommets (0 à V-1)
     * @param isDirected true si orienté, false si non-orienté
     */
    Graph(int vertices, bool isDirected = false);

    // ==================== MÉTHODES PRINCIPALES ====================

    /**
     * @brief Ajoute une arête entre u et v
     * @param u Premier sommet
     * @param v Second sommet
     */
    void addEdge(int u, int v);

    /**
     * @brief Retourne la liste des voisins d'un sommet
     * @param vertex Le sommet
     * @return Vector contenant les identifiants des voisins
     */
    vector<int> getNeighbors(int vertex) const;

    /**
     * @brief Retourne le nombre de sommets
     * @return Nombre de sommets V
     */
    int getVertexCount() const;

    /**
     * @brief Indique si le graphe est orienté
     * @return true si orienté, false sinon
     */
    bool isDirected() const;

    // ==================== AFFICHAGE ====================

    /**
     * @brief Affiche le graphe sous forme de liste d'adjacence
     */
    void printGraph() const;

    // ==================== CHARGEMENT DEPUIS FICHIER ====================

    /**
     * @brief Charge un graphe depuis un fichier texte
     *
     * Format du fichier :
     *   V E directed
     *   u1 v1
     *   u2 v2
     *   ...
     *
     * Exemple :
     *   5 6 0
     *   0 1
     *   0 2
     *   1 3
     *   2 3
     *   2 4
     *   3 4
     *
     * @param filename Chemin du fichier
     * @return Le graphe chargé
     */
    static Graph loadFromFile(const string& filename);
};

#endif

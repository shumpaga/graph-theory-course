/**
 * @file graph.h
 * @brief Classe Graph pour représenter un graphe orienté ou non-orienté
 *
 * TPE3 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
private:
    int n_vertices;                        // Nombre de sommets
    int n_edges;                           // Nombre d'arêtes
    bool directed;                         // Graphe orienté ou non
    std::vector<std::vector<int>> adj;     // Liste d'adjacence

public:
    // Constructeur
    Graph(int vertices, bool is_directed);

    // Accesseurs
    int getNumVertices() const;
    int getNumEdges() const;
    bool isDirected() const;
    std::vector<int> getNeighbors(int vertex) const;

    // Modification
    void addEdge(int src, int dest);

    // Affichage
    void print() const;

    // Chargement depuis fichier
    static Graph loadFromFile(const std::string& filename);
};

#endif // GRAPH_H

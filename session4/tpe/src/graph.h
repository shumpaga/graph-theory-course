/**
 * @file graph.h
 * @brief Classe Graph pour représenter un graphe PONDÉRÉ orienté ou non-orienté
 *
 * TPE4 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * Adaptation du graphe des sessions 2-3 avec support des poids sur les arêtes.
 * getNeighbors() retourne vector<pair<int,int>> : {voisin, poids}
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <utility>

class Graph {
private:
    int V;                                              // Nombre de sommets
    int E;                                              // Nombre d'arêtes
    std::vector<std::vector<std::pair<int,int>>> adj;   // {voisin, poids}
    std::vector<std::string> vertexNames;               // Noms des sommets (optionnel)

public:
    // Constructeur
    Graph(int vertices);

    // Ajout d'arêtes
    void addEdge(int u, int v, int weight);             // Non orienté
    void addDirectedEdge(int u, int v, int weight);     // Orienté

    // Accesseurs
    std::vector<std::pair<int,int>> getNeighbors(int u) const;  // {voisin, poids}
    int getVertexCount() const;
    int getEdgeCount() const;

    // Noms de sommets
    void setVertexName(int v, const std::string& name);
    std::string getVertexName(int v) const;
    bool hasVertexNames() const;

    // Affichage
    void printGraph() const;

    // Chargement depuis fichier
    // Format : 1ère ligne "V E", puis "u v poids" par ligne
    // Les lignes commençant par "//" sont ignorées (commentaires)
    static Graph loadFromFile(const std::string& filename);
};

#endif // GRAPH_H

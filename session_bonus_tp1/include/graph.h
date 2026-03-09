#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
private:
    int V;                              // nombre de sommets
    bool directed;                      // orienté ou non ?
    std::vector<std::vector<int>> adjList;  // liste d'adjacence
    std::vector<std::string> names;     // noms des sommets

public:
    // Constructeur : crée un graphe vide à V sommets
    Graph(int V, bool directed = false);

    // Ajouter une arête (et dans les deux sens si non orienté)
    void addEdge(int u, int v);

    // Charger depuis un fichier texte
    void loadFromFile(const std::string& filename);

    // Accesseurs
    int getV() const;
    bool isDirected() const;
    const std::vector<int>& neighbors(int u) const;
    const std::string& getName(int u) const;

    // Représentations
    std::vector<std::vector<int>> getAdjMatrix() const;
    void printAdjList() const;
    void printAdjMatrix() const;
};

#endif // GRAPH_H

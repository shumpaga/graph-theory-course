/**
 * @file graph.cpp
 * @brief Implémentation de la classe Graph
 *
 * TPE3 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 */

#include "graph.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

Graph::Graph(int vertices, bool is_directed)
    : n_vertices(vertices), n_edges(0), directed(is_directed) {
    adj.resize(vertices);
}

int Graph::getNumVertices() const {
    return n_vertices;
}

int Graph::getNumEdges() const {
    return n_edges;
}

bool Graph::isDirected() const {
    return directed;
}

vector<int> Graph::getNeighbors(int vertex) const {
    if (vertex < 0 || vertex >= n_vertices) {
        throw out_of_range("Sommet invalide");
    }
    return adj[vertex];
}

void Graph::addEdge(int src, int dest) {
    if (src < 0 || src >= n_vertices || dest < 0 || dest >= n_vertices) {
        throw out_of_range("Sommets invalides");
    }

    adj[src].push_back(dest);

    if (!directed) {
        adj[dest].push_back(src);
    }

    n_edges++;
}

void Graph::print() const {
    cout << "Graphe " << (directed ? "orienté" : "non-orienté")
         << " : " << n_vertices << " sommets, " << n_edges << " arêtes\n";

    for (int i = 0; i < n_vertices; i++) {
        cout << i << " → ";
        for (size_t j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j];
            if (j < adj[i].size() - 1) cout << ", ";
        }
        cout << "\n";
    }
}

Graph Graph::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier: " + filename);
    }

    int vertices, edges, is_directed;
    file >> vertices >> edges >> is_directed;

    Graph g(vertices, is_directed == 1);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        file >> src >> dest;
        g.addEdge(src, dest);
    }

    file.close();
    return g;
}

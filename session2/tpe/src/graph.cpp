/**
 * @file graph.cpp
 * @brief Implémentation de la classe Graph
 *
 * ESGC VERECHAGUINE A.K. - 2025-2026
 */

#include "graph.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

// ==================== CONSTRUCTEURS ====================

Graph::Graph(int vertices, bool isDirected)
    : V(vertices), adj(vertices), directed(isDirected) {
    if (vertices < 0) {
        throw invalid_argument("Le nombre de sommets doit être positif");
    }
}

// ==================== MÉTHODES PRINCIPALES ====================

void Graph::addEdge(int u, int v) {
    // Vérification des bornes
    if (u < 0 || u >= V || v < 0 || v >= V) {
        cerr << "Erreur: Sommet invalide (" << u << ", " << v << ")" << endl;
        return;
    }

    // Ajouter l'arête u → v
    adj[u].push_back(v);

    // Si non-orienté, ajouter aussi v → u
    if (!directed && u != v) {  // Éviter les doublons pour boucles
        adj[v].push_back(u);
    }
}

vector<int> Graph::getNeighbors(int vertex) const {
    // Vérification des bornes
    if (vertex < 0 || vertex >= V) {
        cerr << "Erreur: Sommet " << vertex << " invalide" << endl;
        return vector<int>();
    }

    // Convertir list en vector
    vector<int> neighbors;
    for (int neighbor : adj[vertex]) {
        neighbors.push_back(neighbor);
    }
    return neighbors;
}

int Graph::getVertexCount() const {
    return V;
}

bool Graph::isDirected() const {
    return directed;
}

// ==================== AFFICHAGE ====================

void Graph::printGraph() const {
    cout << "Graphe (" << (directed ? "orienté" : "non-orienté")
         << ", " << V << " sommets)" << endl;

    for (int u = 0; u < V; u++) {
        cout << u << " → ";

        bool first = true;
        for (int v : adj[u]) {
            if (!first) cout << ", ";
            cout << v;
            first = false;
        }

        if (adj[u].empty()) {
            cout << "(isolé)";
        }

        cout << endl;
    }
}

// ==================== CHARGEMENT DEPUIS FICHIER ====================

Graph Graph::loadFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier : " + filename);
    }

    int V, E, dir;
    file >> V >> E >> dir;

    if (V <= 0 || E < 0) {
        throw runtime_error("Format de fichier invalide");
    }

    Graph g(V, dir == 1);

    // Lire les arêtes
    for (int i = 0; i < E; i++) {
        int u, v;
        if (!(file >> u >> v)) {
            throw runtime_error("Erreur de lecture des arêtes");
        }
        g.addEdge(u, v);
    }

    file.close();
    return g;
}

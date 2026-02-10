/**
 * @file graph.cpp
 * @brief Implémentation de la classe Graph pondéré
 *
 * TPE4 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 */

#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

Graph::Graph(int vertices) : V(vertices), E(0) {
    adj.resize(vertices);
}

void Graph::addEdge(int u, int v, int weight) {
    if (u < 0 || u >= V || v < 0 || v >= V) {
        throw out_of_range("Sommets invalides");
    }

    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
    E++;
}

void Graph::addDirectedEdge(int u, int v, int weight) {
    if (u < 0 || u >= V || v < 0 || v >= V) {
        throw out_of_range("Sommets invalides");
    }

    adj[u].push_back({v, weight});
    E++;
}

vector<pair<int,int>> Graph::getNeighbors(int u) const {
    if (u < 0 || u >= V) {
        throw out_of_range("Sommet invalide");
    }
    return adj[u];
}

int Graph::getVertexCount() const {
    return V;
}

int Graph::getEdgeCount() const {
    return E;
}

void Graph::setVertexName(int v, const string& name) {
    if (v >= 0 && v < V) {
        if ((int)vertexNames.size() < V)
            vertexNames.resize(V);
        vertexNames[v] = name;
    }
}

string Graph::getVertexName(int v) const {
    if (v >= 0 && v < (int)vertexNames.size() && !vertexNames[v].empty())
        return vertexNames[v];
    return to_string(v);
}

bool Graph::hasVertexNames() const {
    return !vertexNames.empty();
}

void Graph::printGraph() const {
    cout << "Graphe pondéré : " << V << " sommets, " << E << " arêtes\n";

    for (int i = 0; i < V; i++) {
        cout << getVertexName(i) << " (" << i << ") -> ";
        for (size_t j = 0; j < adj[i].size(); j++) {
            cout << getVertexName(adj[i][j].first) << " (poids: " << adj[i][j].second << ")";
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

    string line;
    int vertices = 0, edges = 0;

    // Lire la première ligne non-commentaire : V E
    while (getline(file, line)) {
        // Ignorer les lignes vides ou commençant par "//"
        if (line.empty()) continue;
        // Supprimer les espaces en début de ligne
        size_t start = line.find_first_not_of(" \t");
        if (start == string::npos) continue;
        if (line.size() >= start + 2 && line[start] == '/' && line[start + 1] == '/') continue;

        istringstream iss(line);
        iss >> vertices >> edges;
        break;
    }

    Graph g(vertices);

    int count = 0;
    while (count < edges && getline(file, line)) {
        // Ignorer les lignes vides ou commençant par "//"
        if (line.empty()) continue;
        size_t start = line.find_first_not_of(" \t");
        if (start == string::npos) continue;
        if (line.size() >= start + 2 && line[start] == '/' && line[start + 1] == '/') continue;

        istringstream iss(line);
        int u, v, weight;
        iss >> u >> v >> weight;
        g.addEdge(u, v, weight);
        count++;
    }

    file.close();

    // Parser les noms de sommets depuis les commentaires (format: // 0=Ganhi 1=Dantokpa ...)
    ifstream file2(filename);
    string line2;
    while (getline(file2, line2)) {
        size_t start = line2.find_first_not_of(" \t");
        if (start == string::npos) continue;
        if (line2.size() < start + 2 || line2[start] != '/' || line2[start + 1] != '/') continue;
        if (line2.find('=') == string::npos) continue;

        // Ligne commentaire contenant '=' : parser les tokens N=Nom
        string content = line2.substr(start + 2);
        istringstream iss(content);
        string token;
        while (iss >> token) {
            size_t eq = token.find('=');
            if (eq != string::npos && eq > 0 && eq < token.size() - 1) {
                try {
                    int idx = stoi(token.substr(0, eq));
                    string name = token.substr(eq + 1);
                    g.setVertexName(idx, name);
                } catch (...) {
                    // Token invalide, ignorer
                }
            }
        }
    }
    file2.close();

    return g;
}

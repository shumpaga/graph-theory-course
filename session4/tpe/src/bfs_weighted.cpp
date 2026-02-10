/**
 * @file bfs_weighted.cpp
 * @brief Implémentation du BFS sur graphe pondéré
 *
 * TPE4 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * FOURNI COMPLET - Ne pas modifier.
 */

#include "bfs_weighted.h"
#include <queue>
#include <algorithm>

using namespace std;

pair<int, vector<int>> bfs_shortest_path(Graph& g, int source, int dest) {
    int V = g.getVertexCount();

    // Cas spécial : source == dest
    if (source == dest) {
        return {0, {source}};
    }

    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    queue<int> Q;

    visited[source] = true;
    Q.push(source);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        // Parcourir les voisins (on ignore le poids)
        for (auto& [v, poids] : g.getNeighbors(u)) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                Q.push(v);

                // Si on a trouvé la destination
                if (v == dest) {
                    // Reconstruire le chemin
                    vector<int> path;
                    int current = dest;
                    while (current != -1) {
                        path.push_back(current);
                        current = parent[current];
                    }
                    reverse(path.begin(), path.end());

                    int nb_aretes = (int)path.size() - 1;
                    return {nb_aretes, path};
                }
            }
        }
    }

    // Destination inaccessible
    return {-1, {}};
}

int compute_path_cost(Graph& g, const vector<int>& path) {
    if (path.size() <= 1) {
        return (path.empty()) ? -1 : 0;
    }

    int total = 0;

    for (size_t i = 0; i < path.size() - 1; i++) {
        int u = path[i];
        int v = path[i + 1];

        // Chercher le poids de l'arête u → v
        bool found = false;
        for (auto& [voisin, poids] : g.getNeighbors(u)) {
            if (voisin == v) {
                total += poids;
                found = true;
                break;
            }
        }

        if (!found) {
            return -1;  // Arête inexistante dans le chemin
        }
    }

    return total;
}

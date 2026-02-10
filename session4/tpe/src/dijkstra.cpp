/**
 * @file dijkstra.cpp
 * @brief Implémentation progressive de l'algorithme de Dijkstra
 *
 * TPE4 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * NOM : ____________________
 * PRÉNOM : _________________
 * GROUPE : _________________
 *
 * *** À COMPLÉTER PAR L'ÉTUDIANT ***
 *
 * Instructions :
 * - Remplacez chaque bloc "TODO" par votre implémentation
 * - Testez après chaque étape avec make test
 * - Commentez votre code pour le bonus +2 pts
 * - Le code compile même sans implémentation (retours par défaut)
 */

#include "dijkstra.h"
#include "bfs_weighted.h"
#include <climits>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// ═══════════════════════════════════════════════════════════════
// ÉTAPE 0 : BFS SE TROMPE ! (2 pts)
// ═══════════════════════════════════════════════════════════════

void test_bfs_fails(Graph& g, int source, int dest) {
    (void)g; (void)source; (void)dest;

    // TODO 1 : Appeler bfs_shortest_path(g, source, dest)
    //   auto [nb_aretes, chemin_bfs] = bfs_shortest_path(g, source, dest);
    //   Afficher le chemin BFS et son nombre d'arêtes

    // TODO 2 : Calculer le coût réel du chemin BFS
    //   int cout_bfs = compute_path_cost(g, chemin_bfs);
    //   Afficher : "Chemin BFS : X→Y→Z, coût = N"

    // TODO 3 : Afficher une conclusion
    //   Comparer avec le chemin optimal connu
    //   (ex: sur graph_test.txt, BFS 0→2 coûte 10, mais 0→1→2 coûte 5)
    //   Afficher : "BFS minimise les arêtes, pas le coût !"

    cout << "TODO: Implémenter test_bfs_fails() - Étape 0 (2 pts)" << endl;
}

// ═══════════════════════════════════════════════════════════════
// ÉTAPE 1 : APPROCHE GLOUTONNE NAÏVE (3 pts)
// ═══════════════════════════════════════════════════════════════

pair<int, vector<int>> greedy_path(Graph& g, int source, int dest) {
    int V = g.getVertexCount();
    (void)V; (void)source; (void)dest;

    // TODO 1 : Initialisation
    //   vector<bool> visited(V, false);
    //   vector<int> path;
    //   int current = source, total_cost = 0;
    //   Ajouter source au chemin : path.push_back(source);

    // TODO 2 : Boucle tant que current != dest
    //   while (current != dest) {
    //     Marquer current comme visité : visited[current] = true;
    //
    //     Chercher le voisin NON VISITÉ avec le poids le plus FAIBLE :
    //       int best_v = -1, best_w = INT_MAX;
    //       for (auto& [v, poids] : g.getNeighbors(current)) {
    //         if (!visited[v] && poids < best_w) {
    //           best_v = v;
    //           best_w = poids;
    //         }
    //       }
    //
    //     Si aucun voisin non visité (best_v == -1) :
    //       return {-1, {}};  // Bloqué !
    //
    //     Avancer :
    //       current = best_v;
    //       total_cost += best_w;
    //       path.push_back(current);
    //   }

    // TODO 3 : Retourner {total_cost, path}

    cout << "TODO: Implémenter greedy_path() - Étape 1 (3 pts)" << endl;
    return {-1, {}};
}

// ═══════════════════════════════════════════════════════════════
// ÉTAPE 2 : LA RELAXATION (4 pts)
// ═══════════════════════════════════════════════════════════════

vector<int> relax_all_edges(Graph& g, int source) {
    int V = g.getVertexCount();
    (void)source;

    // TODO 1 : Initialisation
    //   vector<int> distance(V, INT_MAX);
    //   distance[source] = 0;

    // TODO 2 : Répéter V-1 fois :
    //   for (int iter = 0; iter < V - 1; iter++) {
    //     Pour chaque sommet u de 0 à V-1 :
    //       if (distance[u] == INT_MAX) continue;  // Pas encore atteint
    //       Pour chaque voisin {v, poids} de u :
    //         if (distance[u] + poids < distance[v]) {
    //           distance[v] = distance[u] + poids;  // RELAXATION !
    //         }
    //   }

    // TODO 3 : Retourner distance[]

    cout << "TODO: Implémenter relax_all_edges() - Étape 2 (4 pts)" << endl;
    return vector<int>(V, INT_MAX);
}

// ═══════════════════════════════════════════════════════════════
// ÉTAPE 3 : DIJKSTRA BASE — O(V²) (6 pts)
// ═══════════════════════════════════════════════════════════════

vector<int> dijkstra_base(Graph& g, int source) {
    int V = g.getVertexCount();
    (void)source;

    // TODO 1 : Initialisation
    //   vector<int> distance(V, INT_MAX);
    //   vector<bool> visited(V, false);
    //   distance[source] = 0;

    // TODO 2 : Boucle principale (V itérations)
    //   for (int i = 0; i < V; i++) {

    //     TODO 3 : Trouver u = sommet NON VISITÉ avec distance MINIMALE
    //       int u = -1, min_dist = INT_MAX;
    //       for (int j = 0; j < V; j++) {
    //         if (!visited[j] && distance[j] < min_dist) {
    //           u = j;
    //           min_dist = distance[j];
    //         }
    //       }

    //     TODO 4 : Vérifier si on a trouvé un sommet
    //       if (u == -1) break;  // Plus rien à visiter

    //     TODO 5 : Marquer u comme visité
    //       visited[u] = true;

    //     TODO 6 : Relaxation des voisins de u
    //       for (auto& [v, poids] : g.getNeighbors(u)) {
    //         if (!visited[v] && distance[u] + poids < distance[v]) {
    //           distance[v] = distance[u] + poids;
    //         }
    //       }
    //   }

    // TODO 7 : Retourner distance[]

    cout << "TODO: Implémenter dijkstra_base() - Étape 3 (6 pts)" << endl;
    return vector<int>(V, INT_MAX);
}

// ═══════════════════════════════════════════════════════════════
// ÉTAPE 4 : DIJKSTRA HEAP — O((V+E) log V) (6 pts)
// ═══════════════════════════════════════════════════════════════

vector<int> dijkstra_heap(Graph& g, int source) {
    int V = g.getVertexCount();
    (void)source;

    // TODO 1 : Initialisation (comme dijkstra_base)
    //   vector<int> distance(V, INT_MAX);
    //   vector<bool> visited(V, false);
    //   distance[source] = 0;

    // TODO 2 : Créer la file de priorité MIN-HEAP
    //   priority_queue<pair<int,int>, vector<pair<int,int>>,
    //                  greater<pair<int,int>>> Q;
    //   ATTENTION : greater<> pour MIN-Heap (pas max-heap par défaut !)

    // TODO 3 : Ajouter le point de départ
    //   Q.push({0, source});   // {distance, sommet}

    // TODO 4 : Boucle while (!Q.empty())
    //   while (!Q.empty()) {
    //     auto [d, u] = Q.top(); Q.pop();
    //     if (visited[u]) continue;  // Déjà traité !
    //     visited[u] = true;

    //     TODO 5 : Relaxation + ajout dans Q
    //       for (auto& [v, poids] : g.getNeighbors(u)) {
    //         if (!visited[v] && distance[u] + poids < distance[v]) {
    //           distance[v] = distance[u] + poids;
    //           Q.push({distance[v], v});
    //         }
    //       }
    //   }

    // TODO 6 : Retourner distance[]

    cout << "TODO: Implémenter dijkstra_heap() - Étape 4 (6 pts)" << endl;
    return vector<int>(V, INT_MAX);
}

// ═══════════════════════════════════════════════════════════════
// ÉTAPE 5 : RECONSTRUCTION DU CHEMIN (4 pts)
// ═══════════════════════════════════════════════════════════════

vector<int> reconstruct_path(vector<int>& parent, int source, int dest) {
    (void)parent; (void)source; (void)dest;

    // TODO 1 : Si dest inaccessible
    //   if (parent[dest] == -1 && dest != source) return {};

    // TODO 2 : Cas spécial source == dest
    //   if (source == dest) return {source};

    // TODO 3 : Remonter parent[] de dest vers source
    //   vector<int> path;
    //   int current = dest;
    //   while (current != source) {
    //     path.push_back(current);
    //     current = parent[current];
    //   }
    //   path.push_back(source);

    // TODO 4 : Inverser le chemin (dest→...→source  devient  source→...→dest)
    //   reverse(path.begin(), path.end());
    //   return path;

    cout << "TODO: Implémenter reconstruct_path() - Étape 5 (2 pts)" << endl;
    return {};
}

pair<int, vector<int>> dijkstra_between_two(Graph& g, int source, int dest) {
    int V = g.getVertexCount();
    (void)V; (void)source; (void)dest;

    // TODO 1 : Initialisation (comme dijkstra_heap)
    //   vector<int> distance(V, INT_MAX);
    //   vector<bool> visited(V, false);
    //   vector<int> parent(V, -1);        // ← NOUVEAU !
    //   distance[source] = 0;

    // TODO 2 : priority_queue + push({0, source})

    // TODO 3 : Boucle while (!Q.empty())
    //   auto [d, u] = Q.top(); Q.pop();
    //   if (visited[u]) continue;
    //   visited[u] = true;
    //   if (u == dest) break;              // ← ARRET ANTICIPE !

    //   TODO 4 : Relaxation + parent
    //     Pour chaque {v, poids} voisin de u :
    //       Si !visited[v] et distance[u] + poids < distance[v]
    //         distance[v] = distance[u] + poids
    //         parent[v] = u;               // ← MEMORISER LE PARENT !
    //         Q.push({distance[v], v});

    // TODO 5 : Si distance[dest] == INT_MAX → return {-1, {}}
    // TODO 6 : return {distance[dest], reconstruct_path(parent, source, dest)}

    cout << "TODO: Implémenter dijkstra_between_two() - Étape 5 (2 pts)" << endl;
    return {-1, {}};
}

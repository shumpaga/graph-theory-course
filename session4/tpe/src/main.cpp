/**
 * @file main.cpp
 * @brief Programme interactif pour tester les algorithmes Dijkstra
 *
 * TPE4 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * Utilisation : ./main
 *   Puis charger un graphe depuis le menu (option 1)
 */

#include "graph.h"
#include "bfs_weighted.h"
#include "dijkstra.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <climits>
#include <iomanip>
#include <algorithm>

using namespace std;

void print_menu() {
    cout << "\n═══════════════════════════════════════════════\n";
    cout << "  TPE4 : ET SI VOUS INVENTIEZ DIJKSTRA ?\n";
    cout << "═══════════════════════════════════════════════\n";
    cout << "\n--- Étape 0 : Le problème ---\n";
    cout << "  1. Charger un graphe depuis un fichier\n";
    cout << "  2. Afficher le graphe\n";
    cout << "  3. Tester BFS (pourquoi ça échoue)\n";
    cout << "\n--- Étape 1 : Approche gloutonne ---\n";
    cout << "  4. Chemin glouton entre 2 sommets\n";
    cout << "\n--- Étape 2 : Relaxation ---\n";
    cout << "  5. Relaxation brute (toutes les arêtes)\n";
    cout << "\n--- Étape 3-4 : Dijkstra ---\n";
    cout << "  6. Dijkstra base (recherche linéaire)\n";
    cout << "  7. Dijkstra heap (priority_queue)\n";
    cout << "\n--- Étape 5 : Application ---\n";
    cout << "  8. Plus court chemin entre 2 sommets\n";
    cout << "  9. Comparer TOUTES les approches\n";
    cout << "\n  0. Quitter\n";
    cout << "───────────────────────────────────────────────\n";
    cout << "Choix : ";
}

void print_distances(Graph& g, const vector<int>& dist, int source) {
    cout << "Distances depuis " << g.getVertexName(source) << " :\n";
    for (size_t i = 0; i < dist.size(); i++) {
        cout << "  " << left << setw(15) << g.getVertexName(i);
        if (dist[i] == INT_MAX)
            cout << "→ inf (inaccessible)";
        else
            cout << "→ " << right << setw(3) << dist[i] << " min";
        cout << "\n";
    }
}

void print_path(Graph& g, const vector<int>& path) {
    for (size_t i = 0; i < path.size(); i++) {
        cout << g.getVertexName(path[i]);
        if (i < path.size() - 1) cout << " → ";
    }
}

int main() {
    bool graph_loaded = false;
    Graph g(1);  // Placeholder

    int choice;
    do {
        print_menu();
        cin >> choice;

        if (choice != 1 && choice != 0 && !graph_loaded) {
            cout << "⚠ Veuillez d'abord charger un graphe (option 1)\n";
            continue;
        }

        switch (choice) {
            case 1: {
                string filename;
                cout << "Fichier graphe (ex: data/graph_test.txt) : ";
                cin >> filename;
                try {
                    g = Graph::loadFromFile(filename);
                    graph_loaded = true;
                    cout << "✓ Graphe chargé depuis " << filename << "\n";
                    g.printGraph();
                } catch (const exception& e) {
                    cout << "✗ Erreur : " << e.what() << "\n";
                }
                break;
            }

            case 2: {
                g.printGraph();
                break;
            }

            case 3: {
                int source, dest;
                cout << "Sommet source : ";
                cin >> source;
                cout << "Sommet destination : ";
                cin >> dest;
                cout << "\n--- BFS sur graphe pondéré ---\n";
                test_bfs_fails(g, source, dest);
                break;
            }

            case 4: {
                int source, dest;
                cout << "Sommet source : ";
                cin >> source;
                cout << "Sommet destination : ";
                cin >> dest;
                cout << "\n--- Chemin glouton ---\n";
                auto [cost, path] = greedy_path(g, source, dest);
                if (cost == -1) {
                    cout << "Bloqué ! Aucun chemin glouton trouvé.\n";
                } else {
                    cout << "Chemin : ";
                    print_path(g, path);
                    cout << " (" << cost << " min)\n";
                }
                break;
            }

            case 5: {
                int source;
                cout << "Sommet source : ";
                cin >> source;
                cout << "\n--- Relaxation brute (Bellman-Ford simplifié) ---\n";
                auto dist = relax_all_edges(g, source);
                print_distances(g, dist, source);
                break;
            }

            case 6: {
                int source;
                cout << "Sommet source : ";
                cin >> source;
                cout << "\n--- Dijkstra base O(V²) ---\n";
                auto dist = dijkstra_base(g, source);
                print_distances(g, dist, source);
                break;
            }

            case 7: {
                int source;
                cout << "Sommet source : ";
                cin >> source;
                cout << "\n--- Dijkstra heap O((V+E) log V) ---\n";
                auto dist = dijkstra_heap(g, source);
                print_distances(g, dist, source);
                break;
            }

            case 8: {
                int source, dest;
                cout << "Sommet source : ";
                cin >> source;
                cout << "Sommet destination : ";
                cin >> dest;
                cout << "\n--- Plus court chemin (Dijkstra) ---\n";
                auto [cost, path] = dijkstra_between_two(g, source, dest);
                if (cost == -1) {
                    cout << "Pas de chemin entre " << g.getVertexName(source)
                         << " et " << g.getVertexName(dest) << "\n";
                } else {
                    cout << "Chemin : ";
                    print_path(g, path);
                    cout << " (" << cost << " min)\n";
                }
                break;
            }

            case 9: {
                int source, dest;
                cout << "Sommet source : ";
                cin >> source;
                cout << "Sommet destination : ";
                cin >> dest;

                string src_name = g.getVertexName(source);
                string dst_name = g.getVertexName(dest);

                cout << "\n=== COMPARAISON : " << src_name << " → " << dst_name << " ===\n\n";

                // --- Exécuter toutes les approches avec chrono ---

                // 1) BFS
                auto t1 = chrono::high_resolution_clock::now();
                auto [nb_aretes, chemin_bfs] = bfs_shortest_path(g, source, dest);
                int cout_bfs = (nb_aretes != -1) ? compute_path_cost(g, chemin_bfs) : -1;
                auto t2 = chrono::high_resolution_clock::now();
                double ms_bfs = chrono::duration<double, milli>(t2 - t1).count();

                // 2) Glouton
                t1 = chrono::high_resolution_clock::now();
                auto [cout_greedy, chemin_greedy] = greedy_path(g, source, dest);
                t2 = chrono::high_resolution_clock::now();
                double ms_greedy = chrono::duration<double, milli>(t2 - t1).count();

                // 3) Relaxation
                t1 = chrono::high_resolution_clock::now();
                auto dist_relax = relax_all_edges(g, source);
                t2 = chrono::high_resolution_clock::now();
                double ms_relax = chrono::duration<double, milli>(t2 - t1).count();
                int cout_relax = dist_relax[dest];

                // 4) Dijkstra base
                t1 = chrono::high_resolution_clock::now();
                auto dist_base = dijkstra_base(g, source);
                t2 = chrono::high_resolution_clock::now();
                double ms_base = chrono::duration<double, milli>(t2 - t1).count();
                int cout_base = dist_base[dest];

                // 5) Dijkstra heap
                t1 = chrono::high_resolution_clock::now();
                auto dist_heap = dijkstra_heap(g, source);
                t2 = chrono::high_resolution_clock::now();
                double ms_heap = chrono::duration<double, milli>(t2 - t1).count();
                int cout_heap = dist_heap[dest];

                // Trouver le coût optimal (min des résultats valides)
                int optimal = INT_MAX;
                if (cout_bfs > 0) optimal = min(optimal, cout_bfs);
                if (cout_greedy > 0) optimal = min(optimal, cout_greedy);
                if (cout_relax != INT_MAX && cout_relax >= 0) optimal = min(optimal, cout_relax);
                if (cout_base != INT_MAX && cout_base >= 0) optimal = min(optimal, cout_base);
                if (cout_heap != INT_MAX && cout_heap >= 0) optimal = min(optimal, cout_heap);

                // Tableau comparatif
                cout << "  " << left << setw(19) << "Methode" << "| "
                     << right << setw(5) << "Cout" << " | Optimal ? | Temps\n";
                cout << "  " << string(19, '-') << "+" << string(7, '-')
                     << "+" << string(11, '-') << "+" << string(10, '-') << "\n";

                // Lambda pour afficher une ligne
                auto print_row = [&](const string& name, int cost, bool blocked, double ms) {
                    cout << "  " << left << setw(19) << name << "| ";
                    if (blocked) {
                        cout << right << setw(5) << "BLOQ" << " |           | ";
                    } else if (cost == INT_MAX) {
                        cout << right << setw(5) << "inf" << " |           | ";
                    } else {
                        cout << right << setw(5) << cost << " | ";
                        if (optimal != INT_MAX && cost == optimal)
                            cout << "    ✓     | ";
                        else
                            cout << "    ✗     | ";
                    }
                    cout << fixed << setprecision(3) << ms << " ms\n";
                };

                print_row("BFS", cout_bfs, (nb_aretes == -1), ms_bfs);
                print_row("Glouton", cout_greedy, (cout_greedy == -1), ms_greedy);
                print_row("Relaxation", cout_relax, false, ms_relax);
                print_row("Dijkstra base", cout_base, false, ms_base);
                print_row("Dijkstra heap", cout_heap, false, ms_heap);

                cout << "  " << string(47, '-') << "\n";
                break;
            }

            case 0:
                cout << "Au revoir !\n";
                break;

            default:
                cout << "Choix invalide\n";
        }
    } while (choice != 0);

    return 0;
}

/**
 * @file main.cpp
 * @brief Programme interactif pour tester les algorithmes DFS
 *
 * TPE3 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * Utilisation : ./main data/graph_simple.txt
 */

#include "graph.h"
#include "dfs.h"
#include <iostream>
#include <vector>

using namespace std;

void print_menu() {
    cout << "\n═══════════════════════════════════════\n";
    cout << "  TPE3 - Tests Algorithmes DFS\n";
    cout << "═══════════════════════════════════════\n";
    cout << "1. DFS Récursif\n";
    cout << "2. DFS Itératif\n";
    cout << "3. DFS avec Timestamps\n";
    cout << "4. Détection de Cycle\n";
    cout << "5. Tri Topologique\n";
    cout << "6. Recherche de Chemin (DFS)\n";
    cout << "7. Afficher le Graphe\n";
    cout << "0. Quitter\n";
    cout << "───────────────────────────────────────\n";
    cout << "Choix : ";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <fichier_graphe>\n";
        cerr << "Exemple: " << argv[0] << " data/graph_simple.txt\n";
        return 1;
    }

    try {
        Graph g = Graph::loadFromFile(argv[1]);
        cout << "✓ Graphe chargé depuis " << argv[1] << "\n";
        g.print();

        int choice;
        do {
            print_menu();
            cin >> choice;

            switch (choice) {
                case 1: {
                    int source;
                    cout << "Sommet source : ";
                    cin >> source;
                    cout << "DFS récursif depuis " << source << " : ";
                    dfs_recursive(g, source);
                    cout << "\n";
                    break;
                }

                case 2: {
                    int source;
                    cout << "Sommet source : ";
                    cin >> source;
                    cout << "DFS itératif depuis " << source << " : ";
                    dfs_iterative(g, source);
                    cout << "\n";
                    break;
                }

                case 3: {
                    int V = g.getNumVertices();
                    int* discovery = new int[V];
                    int* finish = new int[V];

                    for (int i = 0; i < V; i++) {
                        discovery[i] = finish[i] = -1;
                    }

                    dfs_timestamps(g, discovery, finish);

                    cout << "\nTimestamps:\n";
                    for (int i = 0; i < V; i++) {
                        cout << "Sommet " << i << " : découverte=" << discovery[i]
                             << ", fin=" << finish[i] << "\n";
                    }

                    delete[] discovery;
                    delete[] finish;
                    break;
                }

                case 4: {
                    bool cycle = has_cycle(g);
                    if (cycle) {
                        cout << "✓ Cycle détecté dans le graphe\n";
                    } else {
                        cout << "✓ Pas de cycle dans le graphe\n";
                    }
                    break;
                }

                case 5: {
                    int* order = topological_sort(g);
                    if (order == nullptr) {
                        cout << "✗ Tri topologique impossible (graphe contient un cycle ou n'est pas orienté)\n";
                    } else {
                        cout << "Ordre topologique : ";
                        for (int i = 0; i < g.getNumVertices(); i++) {
                            cout << order[i] << " ";
                        }
                        cout << "\n";
                        delete[] order;
                    }
                    break;
                }

                case 6: {
                    int src, dest;
                    cout << "Sommet source : ";
                    cin >> src;
                    cout << "Sommet destination : ";
                    cin >> dest;

                    vector<int> path;
                    bool found = find_path_dfs(g, src, dest, path);

                    if (found) {
                        cout << "Chemin trouvé : ";
                        for (size_t i = 0; i < path.size(); i++) {
                            cout << path[i];
                            if (i < path.size() - 1) cout << " → ";
                        }
                        cout << "\n";
                    } else {
                        cout << "✗ Pas de chemin entre " << src << " et " << dest << "\n";
                    }
                    break;
                }

                case 7:
                    g.print();
                    break;

                case 0:
                    cout << "Au revoir !\n";
                    break;

                default:
                    cout << "Choix invalide\n";
            }
        } while (choice != 0);

    } catch (const exception& e) {
        cerr << "Erreur : " << e.what() << endl;
        return 1;
    }

    return 0;
}

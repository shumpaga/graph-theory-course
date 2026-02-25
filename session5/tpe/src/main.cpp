/**
 * @file main.cpp
 * @brief Programme interactif pour tester Kruskal et Union-Find
 *
 * TPE5 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * FOURNI COMPLET — Ne pas modifier ce fichier.
 *
 * Utilisation : ./main
 *   Puis charger un graphe depuis le menu (option 1)
 */

#include "graph.h"
#include "union_find.h"
#include "mst.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void print_menu() {
    cout << "\n═══════════════════════════════════════════════\n";
    cout << "  TPE5 : ARBRE COUVRANT MINIMAL — KRUSKAL\n";
    cout << "═══════════════════════════════════════════════\n";
    cout << "\n--- Graphe ---\n";
    cout << "  1. Charger un graphe depuis un fichier\n";
    cout << "  2. Afficher le graphe\n";
    cout << "  3. Lister toutes les arêtes\n";
    cout << "\n--- Union-Find (démonstration) ---\n";
    cout << "  4. Tester Union-Find sur un petit exemple\n";
    cout << "\n--- Kruskal ---\n";
    cout << "  5. Exécuter Kruskal (arbre couvrant minimal)\n";
    cout << "\n  0. Quitter\n";
    cout << "───────────────────────────────────────────────\n";
    cout << "Choix : ";
}

void demo_union_find() {
    cout << "\n--- Démonstration Union-Find ---\n";
    cout << "Création de 6 éléments : {0} {1} {2} {3} {4} {5}\n\n";

    UnionFind uf(6);

    // État initial
    cout << "État initial :\n";
    for (int i = 0; i < 6; i++) {
        cout << "  find(" << i << ") = " << uf.find(i) << "\n";
    }

    // Quelques unions
    cout << "\nOpérations :\n";
    cout << "  unite(0, 1)\n";
    uf.unite(0, 1);
    cout << "  unite(2, 3)\n";
    uf.unite(2, 3);
    cout << "  unite(0, 2)\n";
    uf.unite(0, 2);

    // Vérifications
    cout << "\nRésultats :\n";
    cout << "  connected(0, 3) = " << (uf.connected(0, 3) ? "true" : "false")
         << " (attendu: true)\n";
    cout << "  connected(1, 2) = " << (uf.connected(1, 2) ? "true" : "false")
         << " (attendu: true)\n";
    cout << "  connected(0, 5) = " << (uf.connected(0, 5) ? "true" : "false")
         << " (attendu: false)\n";

    // Find après compression
    cout << "\nFind après compression :\n";
    for (int i = 0; i < 6; i++) {
        cout << "  find(" << i << ") = " << uf.find(i)
             << "  (parent = " << uf.getParent(i) << ")\n";
    }
}

int main() {
    bool graph_loaded = false;
    Graph g(1);  // Placeholder

    int choice;
    do {
        print_menu();
        cin >> choice;

        if (choice != 1 && choice != 4 && choice != 0 && !graph_loaded) {
            cout << "Veuillez d'abord charger un graphe (option 1)\n";
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
                    cout << "Graphe chargé depuis " << filename << "\n";
                    g.printGraph();
                } catch (const exception& e) {
                    cout << "Erreur : " << e.what() << "\n";
                }
                break;
            }

            case 2: {
                g.printGraph();
                break;
            }

            case 3: {
                auto edges = getEdges(g);
                if (edges.empty()) {
                    cout << "Aucune arête extraite (getEdges non implémenté ?)\n";
                } else {
                    cout << "\nArêtes du graphe (" << edges.size() << " arêtes) :\n";
                    for (const auto& e : edges) {
                        cout << "  " << g.getVertexName(e.src) << " — "
                             << g.getVertexName(e.dest)
                             << " (poids: " << e.weight << ")\n";
                    }
                }
                break;
            }

            case 4: {
                demo_union_find();
                break;
            }

            case 5: {
                cout << "\n--- Algorithme de Kruskal ---\n";
                auto mst = kruskal(g);
                if (mst.empty()) {
                    cout << "MST vide (kruskal non implémenté ?)\n";
                } else {
                    printMST(mst, g);
                    cout << "Poids total : " << mstWeight(mst) << "\n";
                    cout << "Nombre d'arêtes : " << mst.size()
                         << " (attendu : " << g.getVertexCount() - 1 << ")\n";
                }
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

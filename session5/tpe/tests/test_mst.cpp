/**
 * @file test_mst.cpp
 * @brief Tests automatiques pour le TPE5 - Kruskal & Union-Find
 *
 * TPE5 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * 16 tests organisés par étape (1 à 5)
 *
 * Valeurs attendues calculées à la main :
 *   graph_test.txt    : MST poids = 35, arêtes = {(0,2,3),(0,3,5),(2,4,5),(3,5,6),(0,1,7),(4,6,9)}
 *   graph_commune.txt : MST poids = 44, arêtes = 9
 */

#include "graph.h"
#include "union_find.h"
#include "mst.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Couleurs pour l'affichage
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

int tests_passed = 0;
int tests_total = 0;

void test_result(const string& name, bool passed) {
    tests_total++;
    if (passed) {
        cout << "  " GREEN "✅" RESET " Test " << tests_total << " : " << name << "\n";
        tests_passed++;
    } else {
        cout << "  " RED "❌" RESET " Test " << tests_total << " : " << name << "\n";
    }
}

// ============================================================
// ÉTAPE 1 : UNION-FIND — CONSTRUCTEUR & FIND (3 tests)
// ============================================================

void test_etape_1() {
    cout << "\n" YELLOW "=== ÉTAPE 1 : UNION-FIND — CONSTRUCTEUR & FIND ===" RESET "\n";

    // Test 1 : Constructeur initialise parent[i] = i
    {
        UnionFind uf(5);
        bool ok = true;
        for (int i = 0; i < 5; i++) {
            if (uf.getParent(i) != i) ok = false;
        }
        test_result("Constructeur : parent[i] == i pour 5 éléments", ok);
    }

    // Test 2 : find(i) == i pour tout i initialement
    {
        UnionFind uf(5);
        bool ok = true;
        for (int i = 0; i < 5; i++) {
            if (uf.find(i) != i) ok = false;
        }
        test_result("find(i) == i initialement pour tout i", ok);
    }

    // Test 3 : Éléments distincts non connectés initialement
    {
        UnionFind uf(5);
        bool ok = (!uf.connected(0, 4) && !uf.connected(1, 3) && !uf.connected(2, 4));
        test_result("Éléments distincts non connectés initialement", ok);
    }
}

// ============================================================
// ÉTAPE 2 : UNION-FIND — UNITE & CONNECTED (4 tests)
// ============================================================

void test_etape_2() {
    cout << "\n" YELLOW "=== ÉTAPE 2 : UNION-FIND — UNITE & CONNECTED ===" RESET "\n";

    // Test 4 : unite(0,1) → connected(0,1) == true
    {
        UnionFind uf(5);
        uf.unite(0, 1);
        bool ok = uf.connected(0, 1);
        test_result("unite(0,1) → connected(0,1) == true", ok);
    }

    // Test 5 : Transitivité : unite(0,1), unite(1,2) → connected(0,2)
    {
        UnionFind uf(5);
        uf.unite(0, 1);
        uf.unite(1, 2);
        bool ok = uf.connected(0, 2);
        test_result("Transitivité : unite(0,1), unite(1,2) → connected(0,2)", ok);
    }

    // Test 6 : Multiple unions : unite(0,1), unite(2,3), unite(0,2) → connected(1,3)
    {
        UnionFind uf(5);
        uf.unite(0, 1);
        uf.unite(2, 3);
        uf.unite(0, 2);
        bool ok = uf.connected(1, 3);
        test_result("Chaîne d'unions : connected(1,3) après unite(0,1)(2,3)(0,2)", ok);
    }

    // Test 7 : Compression de chemin — après find, parent pointe vers racine
    {
        UnionFind uf(5);
        uf.unite(0, 1);
        uf.unite(1, 2);
        uf.unite(2, 3);
        uf.unite(3, 4);
        // Après find(4), la compression devrait aplatir le chemin
        int root = uf.find(4);
        bool ok = (uf.find(0) == root && uf.find(1) == root &&
                   uf.find(2) == root && uf.find(3) == root &&
                   uf.find(4) == root);
        test_result("Compression : tous les éléments pointent vers la même racine", ok);
    }
}

// ============================================================
// ÉTAPE 3 : EXTRACTION DES ARÊTES (2 tests)
// ============================================================

void test_etape_3() {
    cout << "\n" YELLOW "=== ÉTAPE 3 : EXTRACTION DES ARÊTES ===" RESET "\n";

    Graph g = Graph::loadFromFile("data/graph_test.txt");

    // Test 8 : getEdges retourne 11 arêtes
    {
        auto edges = getEdges(g);
        bool ok = (edges.size() == 11);
        test_result("getEdges(graph_test) retourne 11 arêtes", ok);
    }

    // Test 9 : Pas de doublons — chaque paire (u,v) apparaît une seule fois
    {
        auto edges = getEdges(g);
        bool no_dup = true;
        for (size_t i = 0; i < edges.size() && no_dup; i++) {
            for (size_t j = i + 1; j < edges.size() && no_dup; j++) {
                int a_min = min(edges[i].src, edges[i].dest);
                int a_max = max(edges[i].src, edges[i].dest);
                int b_min = min(edges[j].src, edges[j].dest);
                int b_max = max(edges[j].src, edges[j].dest);
                if (a_min == b_min && a_max == b_max) no_dup = false;
            }
        }
        bool ok = (no_dup && !edges.empty());
        test_result("Pas de doublons : chaque arête apparaît une seule fois", ok);
    }
}

// ============================================================
// ÉTAPE 4 : ALGORITHME DE KRUSKAL (4 tests)
// ============================================================

void test_etape_4() {
    cout << "\n" YELLOW "=== ÉTAPE 4 : ALGORITHME DE KRUSKAL ===" RESET "\n";

    // Test 10 : Kruskal graph_test → exactement V-1 = 6 arêtes
    {
        Graph g = Graph::loadFromFile("data/graph_test.txt");
        auto mst = kruskal(g);
        bool ok = ((int)mst.size() == g.getVertexCount() - 1);
        test_result("Kruskal graph_test : exactement V-1 = 6 arêtes", ok);
    }

    // Test 11 : Kruskal graph_test → poids total = 35
    {
        Graph g = Graph::loadFromFile("data/graph_test.txt");
        auto mst = kruskal(g);
        int w = mstWeight(mst);
        bool ok = (w == 35);
        test_result("Kruskal graph_test : poids total = 35", ok);
    }

    // Test 12 : Kruskal graph_commune → exactement V-1 = 9 arêtes
    {
        Graph gc = Graph::loadFromFile("data/graph_commune.txt");
        auto mst = kruskal(gc);
        bool ok = ((int)mst.size() == gc.getVertexCount() - 1);
        test_result("Kruskal graph_commune : exactement V-1 = 9 arêtes", ok);
    }

    // Test 13 : Kruskal graph_commune → poids total = 44
    {
        Graph gc = Graph::loadFromFile("data/graph_commune.txt");
        auto mst = kruskal(gc);
        int w = mstWeight(mst);
        bool ok = (w == 44);
        test_result("Kruskal graph_commune : poids total = 44", ok);
    }
}

// ============================================================
// ÉTAPE 5 : UTILITAIRES ET CAS LIMITES (3 tests)
// ============================================================

void test_etape_5() {
    cout << "\n" YELLOW "=== ÉTAPE 5 : UTILITAIRES ET CAS LIMITES ===" RESET "\n";

    // Test 14 : mstWeight sur un MST connu = 15
    {
        vector<Edge> edges = {{0, 1, 3}, {1, 2, 5}, {2, 3, 7}};
        int w = mstWeight(edges);
        bool ok = (w == 15);
        test_result("mstWeight({3,5,7}) = 15", ok);
    }

    // Test 15 : Graphe complet K3 → MST = 2 arêtes, poids = 3
    {
        Graph k3(3);
        k3.addEdge(0, 1, 1);
        k3.addEdge(0, 2, 3);
        k3.addEdge(1, 2, 2);
        auto mst = kruskal(k3);
        bool ok = ((int)mst.size() == 2 && mstWeight(mst) == 3);
        test_result("K3 : MST = 2 arêtes, poids = 3", ok);
    }

    // Test 16 : Graphe déconnecté → forêt couvrante (< V-1 arêtes)
    {
        Graph disc(4);
        disc.addEdge(0, 1, 5);
        disc.addEdge(2, 3, 7);
        // 2 composantes : {0,1} et {2,3}
        auto mst = kruskal(disc);
        bool ok = ((int)mst.size() == 2 && mstWeight(mst) == 12);
        test_result("Graphe déconnecté : forêt = 2 arêtes, poids = 12", ok);
    }
}

// ============================================================
// MAIN
// ============================================================

int main() {
    cout << BLUE "═══════════════════════════════════════════════\n";
    cout << "  TESTS TPE5 - KRUSKAL & UNION-FIND\n";
    cout << "═══════════════════════════════════════════════" RESET "\n";

    test_etape_1();
    int etape1 = tests_passed;

    test_etape_2();
    int etape2 = tests_passed - etape1;

    test_etape_3();
    int etape3 = tests_passed - etape1 - etape2;

    test_etape_4();
    int etape4 = tests_passed - etape1 - etape2 - etape3;

    test_etape_5();
    int etape5 = tests_passed - etape1 - etape2 - etape3 - etape4;

    // Résumé final
    cout << "\n" BLUE "═══════════════════════════════════════════════" RESET "\n";
    cout << "  RÉSUMÉ PAR ÉTAPE :\n";
    cout << "    Étape 1 (UF constructeur)  : " << etape1 << "/3\n";
    cout << "    Étape 2 (UF opérations)    : " << etape2 << "/4\n";
    cout << "    Étape 3 (Extraction arêtes): " << etape3 << "/2\n";
    cout << "    Étape 4 (Kruskal)          : " << etape4 << "/4\n";
    cout << "    Étape 5 (Utilitaires)      : " << etape5 << "/3\n";
    cout << "\n  TOTAL : " << tests_passed << "/" << tests_total << " tests passés\n";

    // Estimation note
    int score = 0;
    score += (etape1 * 4) / 3;     // 4 pts max
    score += (etape2 * 4) / 4;     // 4 pts max
    score += (etape3 * 4) / 2;     // 4 pts max
    score += (etape4 * 8) / 4;     // 8 pts max
    score += (etape5 * 3) / 3;     // 3 pts max

    cout << "  NOTE ESTIMÉE : " << score << "/25 pts (+ qualité code : +2 pts)\n";
    cout << BLUE "═══════════════════════════════════════════════" RESET "\n";

    return (tests_passed == tests_total) ? 0 : 1;
}

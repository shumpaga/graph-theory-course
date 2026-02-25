/**
 * @file test_mst.cpp
 * @brief Tests automatiques pour le TPE5 - Kruskal & Union-Find
 *
 * TPE5 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * 20 tests organisés par étape (1 à 6)
 *
 * Valeurs attendues :
 *   graph_test.txt    : MST poids = 35, arêtes = 6
 *   graph_commune.txt : MST poids = 44, arêtes = 9
 */

#include "graph.h"
#include "union_find.h"
#include "mst.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Couleurs
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
        cout << "  " GREEN "[PASS]" RESET " " << name << "\n";
        tests_passed++;
    } else {
        cout << "  " RED "[FAIL]" RESET " " << name << "\n";
    }
}

// ============================================================
// ÉTAPE 1 : Union-Find naïf (5 tests)
// ============================================================

void test_etape_1() {
    cout << "\n" YELLOW "--- Étape 1 : Union-Find naïf ---" RESET "\n";

    // Test 1
    {
        UnionFind uf(7);
        bool ok = true;
        for (int i = 0; i < 7; i++) {
            if (uf.find(i) != i) ok = false;
        }
        test_result("test_uf_create_find_self", ok);
    }

    // Test 2
    {
        UnionFind uf(7);
        bool ok = !uf.connected(0, 1);
        test_result("test_uf_create_not_connected", ok);
    }

    // Test 3
    {
        UnionFind uf(7);
        bool ok = (uf.find(3) == 3);
        test_result("test_uf_find_singleton", ok);
    }

    // Test 4
    {
        UnionFind uf(7);
        uf.unite(0, 1);
        bool ok = uf.connected(0, 1);
        test_result("test_uf_unite_basic", ok);
    }

    // Test 5
    {
        UnionFind uf(7);
        uf.unite(0, 1);
        uf.unite(1, 2);
        bool ok = uf.connected(0, 2);
        test_result("test_uf_unite_transitive", ok);
    }
}

// ============================================================
// ÉTAPE 2 : Mesurer le problème (2 tests)
// ============================================================

void test_etape_2() {
    cout << "\n" YELLOW "--- Étape 2 : Mesurer le problème ---" RESET "\n";

    // Test 6 : count_operations(0) == 0 sur singleton
    {
        UnionFind uf(5);
        bool ok = (uf.count_operations(0) == 0);
        test_result("test_count_ops_singleton", ok);
    }

    // Test 7 : Chaîne de 10 éléments — adaptatif (naïf OU rang)
    //   Avec naïf : chaîne se forme, ops = 9 → (9 >= 8) passe
    //   Avec rang  : arbre plat, ops ≈ 1  → (1 <= 2) passe
    {
        UnionFind uf(10);
        for (int i = 8; i >= 0; i--)
            uf.unite(i, i + 1);
        // Prérequis : tous doivent être connectés
        bool chain_ok = uf.connected(0, 9);
        int ops = uf.count_operations(9);
        bool ok = chain_ok && ((ops >= 8) || (ops <= 2));
        test_result("test_count_ops_chain", ok);
    }
}

// ============================================================
// ÉTAPE 3 : Compression de chemin (3 tests)
// ============================================================

void test_etape_3() {
    cout << "\n" YELLOW "--- Étape 3 : Compression de chemin ---" RESET "\n";

    // Test 8 : Après find(9), count_operations(9) <= 1
    {
        UnionFind uf(10);
        for (int i = 8; i >= 0; i--)
            uf.unite(i, i + 1);
        bool chain_ok = uf.connected(0, 9);
        uf.find(9); // déclenche la compression
        int ops = uf.count_operations(9);
        bool ok = chain_ok && (ops <= 1);
        test_result("test_compression_effective", ok);
    }

    // Test 9 : Après find(9), getParent(9) pointe vers la racine
    {
        UnionFind uf(10);
        for (int i = 8; i >= 0; i--)
            uf.unite(i, i + 1);
        bool chain_ok = uf.connected(0, 9);
        int root = uf.find(9);
        bool ok = chain_ok && (uf.getParent(9) == root);
        test_result("test_compression_flattens_all", ok);
    }

    // Test 10 : Après unite(0,1), find(0) == find(1)
    {
        UnionFind uf(5);
        uf.unite(0, 1);
        bool ok = (uf.find(0) == uf.find(1));
        test_result("test_find_same_root_after_unite", ok);
    }
}

// ============================================================
// ÉTAPE 4 : Union par rang (2 tests)
// ============================================================

void test_etape_4() {
    cout << "\n" YELLOW "--- Étape 4 : Union par rang ---" RESET "\n";

    // Test 11 : 8 éléments, unions par paires → hauteur <= 3
    {
        UnionFind uf(8);
        uf.unite(0, 1);
        uf.unite(2, 3);
        uf.unite(4, 5);
        uf.unite(6, 7);
        uf.unite(0, 2);
        uf.unite(4, 6);
        uf.unite(0, 4);

        bool all_ok = uf.connected(0, 7);
        bool ok = all_ok && (uf.count_operations(7) <= 3);
        test_result("test_rank_balanced_tree", ok);
    }

    // Test 12 : unite quand déjà connectés ne corrompt pas
    {
        UnionFind uf(5);
        uf.unite(0, 1);
        uf.unite(1, 2);
        bool before = uf.connected(0, 2);
        int root_before = uf.find(0);
        uf.unite(0, 2); // déjà connectés !
        int root_after = uf.find(0);
        bool ok = before && (root_before == root_after) && uf.connected(0, 1);
        test_result("test_unite_same_noop", ok);
    }
}

// ============================================================
// ÉTAPE 5 : Algorithme de Kruskal (5 tests)
// ============================================================

void test_etape_5() {
    cout << "\n" YELLOW "--- Étape 5 : Algorithme de Kruskal ---" RESET "\n";

    // Test 13
    {
        Graph g = Graph::loadFromFile("data/graph_test.txt");
        auto mst = kruskal(g);
        bool ok = (mstWeight(mst) == 35);
        test_result("test_kruskal_weight", ok);
    }

    // Test 14
    {
        Graph g = Graph::loadFromFile("data/graph_test.txt");
        auto mst = kruskal(g);
        bool ok = ((int)mst.size() == g.getVertexCount() - 1);
        test_result("test_kruskal_edge_count", ok);
    }

    // Test 15
    {
        Graph g(2);
        g.addEdge(0, 1, 5);
        auto mst = kruskal(g);
        bool ok = ((int)mst.size() == 1 && mstWeight(mst) == 5);
        test_result("test_kruskal_trivial", ok);
    }

    // Test 16
    {
        Graph gc = Graph::loadFromFile("data/graph_commune.txt");
        auto mst = kruskal(gc);
        bool ok = (mstWeight(mst) == 44);
        test_result("test_kruskal_commune", ok);
    }

    // Test 17
    {
        Graph g = Graph::loadFromFile("data/graph_test.txt");
        auto edges = getEdges(g);
        bool ok = ((int)edges.size() == 11);
        test_result("test_getEdges_no_duplicates", ok);
    }
}

// ============================================================
// ÉTAPE 6 : Utilitaires (3 tests)
// ============================================================

void test_etape_6() {
    cout << "\n" YELLOW "--- Étape 6 : Utilitaires ---" RESET "\n";

    // Test 18
    {
        vector<Edge> empty;
        bool ok = (mstWeight(empty) == 0);
        test_result("test_mstWeight_empty", ok);
    }

    // Test 19
    {
        Graph g = Graph::loadFromFile("data/graph_test.txt");
        auto mst = kruskal(g);
        printMST(mst, g);
        test_result("test_printMST_no_crash", true);
    }

    // Test 20
    {
        Graph g(3);
        vector<Edge> empty;
        printMST(empty, g);
        test_result("test_printMST_empty_no_crash", true);
    }
}

// ============================================================
// MAIN
// ============================================================

int main() {
    cout << BLUE "=== TPE5 : Tests MST (Kruskal & Union-Find) ===" RESET "\n";

    test_etape_1();
    int e1 = tests_passed;

    test_etape_2();
    int e2 = tests_passed - e1;

    test_etape_3();
    int e3 = tests_passed - e1 - e2;

    test_etape_4();
    int e4 = tests_passed - e1 - e2 - e3;

    test_etape_5();
    int e5 = tests_passed - e1 - e2 - e3 - e4;

    test_etape_6();
    int e6 = tests_passed - e1 - e2 - e3 - e4 - e5;

    // Résumé
    cout << "\n" BLUE "===============================================" RESET "\n";
    cout << "  Étape 1 (UF naïf)          : " << e1 << "/5\n";
    cout << "  Étape 2 (count_operations)  : " << e2 << "/2\n";
    cout << "  Étape 3 (Compression)       : " << e3 << "/3\n";
    cout << "  Étape 4 (Union par rang)    : " << e4 << "/2\n";
    cout << "  Étape 5 (Kruskal)           : " << e5 << "/5\n";
    cout << "  Étape 6 (Utilitaires)       : " << e6 << "/3\n";

    cout << "\n" BLUE "=== Résultat : " << tests_passed << "/20 tests réussis ===" RESET "\n";

    return (tests_passed == tests_total) ? 0 : 1;
}

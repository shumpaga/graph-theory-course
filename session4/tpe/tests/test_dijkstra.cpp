/**
 * @file test_dijkstra.cpp
 * @brief Tests automatiques pour le TPE4 - Dijkstra
 *
 * TPE4 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * 18 tests organisés par étape (0 à 5)
 *
 * Valeurs attendues calculées à la main :
 *   graph_test.txt      : distances depuis 0 = [0, 2, 5, 6, 11]
 *   graph_greedy_fail.txt : distances depuis 0 = [0, 1, 5, 7, 8]
 *   graph_cotonou.txt   : distances depuis 0 = [0, 5, 13, 12, 8, 14, 22, 17]
 */

#include "../src/graph.h"
#include "../src/bfs_weighted.h"
#include "../src/dijkstra.h"
#include <iostream>
#include <vector>
#include <climits>

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

bool vectors_equal(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// ============================================================
// ÉTAPE 0 : BFS SE TROMPE (2 tests)
// ============================================================

void test_etape_0() {
    cout << "\n" YELLOW "=== ÉTAPE 0 : BFS SE TROMPE ===" RESET "\n";

    Graph g = Graph::loadFromFile("data/graph_test.txt");

    // Test 1 : BFS depuis 0 vers 2 donne chemin sous-optimal
    {
        auto [nb_aretes, chemin] = bfs_shortest_path(g, 0, 2);
        int cout_bfs = compute_path_cost(g, chemin);
        // BFS trouve 0→2 direct (coût 10), optimal est 0→1→2 (coût 5)
        bool passed = (cout_bfs > 5);  // Le coût BFS (10) est supérieur à l'optimal (5)
        test_result("BFS donne chemin sous-optimal (coût BFS > coût optimal)", passed);
    }

    // Test 2 : BFS trouve le bon nombre d'arêtes (1) mais le mauvais coût
    {
        auto [nb_aretes, chemin] = bfs_shortest_path(g, 0, 2);
        int cout_bfs = compute_path_cost(g, chemin);
        // BFS minimise les arêtes : 1 arête (0→2), mais coût = 10
        bool passed = (nb_aretes == 1 && cout_bfs == 10);
        test_result("BFS : 1 arête mais coût = 10 (pas 5)", passed);
    }
}

// ============================================================
// ÉTAPE 1 : GLOUTON (2 tests)
// ============================================================

void test_etape_1() {
    cout << "\n" YELLOW "=== ÉTAPE 1 : GLOUTON ===" RESET "\n";

    // Test 3 : Glouton fonctionne sur graph_test (0→4)
    {
        Graph g = Graph::loadFromFile("data/graph_test.txt");
        auto [cost, path] = greedy_path(g, 0, 4);
        // Glouton : 0→1(2) → 1→2(3) → 2→3(1) → 3→4(5) = 11 (optimal ici !)
        vector<int> expected_path = {0, 1, 2, 3, 4};
        bool passed = (cost == 11 && vectors_equal(path, expected_path));
        test_result("Glouton 0→4 sur graph_test = 11 (optimal ici)", passed);
    }

    // Test 4 : Glouton échoue sur graph_greedy_fail (0→4)
    {
        Graph g_fail = Graph::loadFromFile("data/graph_greedy_fail.txt");
        auto [cost_greedy, path_greedy] = greedy_path(g_fail, 0, 4);
        // Glouton : 0→1(1) → 1→3(10) → 3→4(1) = 12
        // Dijkstra : 0→2(5) → 2→3(2) → 3→4(1) = 8
        vector<int> expected_greedy = {0, 1, 3, 4};
        bool passed = (cost_greedy == 12 && vectors_equal(path_greedy, expected_greedy));
        test_result("Glouton échoue : 0→1→3→4 coût=12 (optimal=8)", passed);
    }
}

// ============================================================
// ÉTAPE 2 : RELAXATION (3 tests)
// ============================================================

void test_etape_2() {
    cout << "\n" YELLOW "=== ÉTAPE 2 : RELAXATION ===" RESET "\n";

    Graph g = Graph::loadFromFile("data/graph_test.txt");

    // Test 5 : Distances depuis 0 sur graph_test
    {
        auto dist = relax_all_edges(g, 0);
        vector<int> expected = {0, 2, 5, 6, 11};
        bool passed = vectors_equal(dist, expected);
        test_result("relax_all_edges depuis 0 = [0, 2, 5, 6, 11]", passed);
    }

    // Test 6 : Distance source vers elle-même = 0
    {
        auto dist = relax_all_edges(g, 3);
        bool passed = (dist[3] == 0);
        test_result("Distance source vers elle-même = 0", passed);
    }

    // Test 7 : Vérification exhaustive sur graph_greedy_fail
    {
        Graph g2 = Graph::loadFromFile("data/graph_greedy_fail.txt");
        auto dist = relax_all_edges(g2, 0);
        vector<int> expected = {0, 1, 5, 7, 8};
        bool passed = vectors_equal(dist, expected);
        test_result("relax_all_edges sur graph_greedy_fail = [0, 1, 5, 7, 8]", passed);
    }
}

// ============================================================
// ÉTAPE 3 : DIJKSTRA BASE (4 tests)
// ============================================================

void test_etape_3() {
    cout << "\n" YELLOW "=== ÉTAPE 3 : DIJKSTRA BASE ===" RESET "\n";

    Graph g = Graph::loadFromFile("data/graph_test.txt");

    // Test 8 : Distances depuis 0 sur graph_test
    {
        auto dist = dijkstra_base(g, 0);
        vector<int> expected = {0, 2, 5, 6, 11};
        bool passed = vectors_equal(dist, expected);
        test_result("dijkstra_base depuis 0 = [0, 2, 5, 6, 11]", passed);
    }

    // Test 9 : Cohérence avec relax_all_edges
    {
        auto dist_dijk = dijkstra_base(g, 0);
        auto dist_relax = relax_all_edges(g, 0);
        // Vérifier que les résultats sont valides (pas tous INT_MAX) ET cohérents
        bool passed = (dist_dijk[0] == 0 && dist_relax[0] == 0 &&
                       vectors_equal(dist_dijk, dist_relax));
        test_result("dijkstra_base == relax_all_edges (cohérence)", passed);
    }

    // Test 10 : Distance source = 0
    {
        auto dist = dijkstra_base(g, 2);
        bool passed = (dist[2] == 0);
        test_result("Distance source = 0", passed);
    }

    // Test 11 : Distances sur graph_cotonou
    {
        Graph gc = Graph::loadFromFile("data/graph_cotonou.txt");
        auto dist = dijkstra_base(gc, 0);
        vector<int> expected = {0, 5, 13, 12, 8, 14, 22, 17};
        bool passed = vectors_equal(dist, expected);
        test_result("dijkstra_base sur graph_cotonou = [0,5,13,12,8,14,22,17]", passed);
    }
}

// ============================================================
// ÉTAPE 4 : DIJKSTRA HEAP (4 tests)
// ============================================================

void test_etape_4() {
    cout << "\n" YELLOW "=== ÉTAPE 4 : DIJKSTRA HEAP ===" RESET "\n";

    Graph g = Graph::loadFromFile("data/graph_test.txt");

    // Test 12 : Cohérence avec dijkstra_base
    {
        auto dist_heap = dijkstra_heap(g, 0);
        auto dist_base = dijkstra_base(g, 0);
        // Vérifier que les résultats sont valides (pas tous INT_MAX) ET cohérents
        bool passed = (dist_heap[0] == 0 && dist_base[0] == 0 &&
                       vectors_equal(dist_heap, dist_base));
        test_result("dijkstra_heap == dijkstra_base (cohérence)", passed);
    }

    // Test 13 : Distances depuis 0 sur graph_test
    {
        auto dist = dijkstra_heap(g, 0);
        vector<int> expected = {0, 2, 5, 6, 11};
        bool passed = vectors_equal(dist, expected);
        test_result("dijkstra_heap depuis 0 = [0, 2, 5, 6, 11]", passed);
    }

    // Test 14 : Distance source = 0
    {
        auto dist = dijkstra_heap(g, 4);
        bool passed = (dist[4] == 0);
        test_result("Distance source = 0", passed);
    }

    // Test 15 : Distances sur graph_cotonou
    {
        Graph gc = Graph::loadFromFile("data/graph_cotonou.txt");
        auto dist = dijkstra_heap(gc, 0);
        vector<int> expected = {0, 5, 13, 12, 8, 14, 22, 17};
        bool passed = vectors_equal(dist, expected);
        test_result("dijkstra_heap sur graph_cotonou = [0,5,13,12,8,14,22,17]", passed);
    }
}

// ============================================================
// ÉTAPE 5 : RECONSTRUCTION + ENTRE 2 SOMMETS (3 tests)
// ============================================================

void test_etape_5() {
    cout << "\n" YELLOW "=== ÉTAPE 5 : RECONSTRUCTION + ENTRE 2 SOMMETS ===" RESET "\n";

    // Test 16 : Chemin 0→4 sur graph_test
    {
        Graph g = Graph::loadFromFile("data/graph_test.txt");
        auto [cost, path] = dijkstra_between_two(g, 0, 4);
        vector<int> expected_path = {0, 1, 2, 3, 4};
        bool passed = (cost == 11 && vectors_equal(path, expected_path));
        test_result("dijkstra_between_two 0→4 = {11, [0,1,2,3,4]}", passed);
    }

    // Test 17 : Source == dest
    {
        Graph g = Graph::loadFromFile("data/graph_test.txt");
        auto [cost, path] = dijkstra_between_two(g, 2, 2);
        bool passed = (cost == 0 && path.size() == 1 && path[0] == 2);
        test_result("Source == dest → {0, [2]}", passed);
    }

    // Test 18 : Dest inaccessible (graphe déconnecté)
    {
        Graph g(4);
        g.addEdge(0, 1, 5);
        // Sommets 2 et 3 sont isolés
        auto [cost, path] = dijkstra_between_two(g, 0, 3);
        bool passed = (cost == -1 && path.empty());
        test_result("Dest inaccessible → {-1, []}", passed);
    }
}

// ============================================================
// MAIN
// ============================================================

int main() {
    cout << BLUE "═══════════════════════════════════════════════\n";
    cout << "  TESTS TPE4 - ET SI VOUS INVENTIEZ DIJKSTRA ?\n";
    cout << "═══════════════════════════════════════════════" RESET "\n";

    test_etape_0();
    int etape0 = tests_passed;

    test_etape_1();
    int etape1 = tests_passed - etape0;

    test_etape_2();
    int etape2 = tests_passed - etape0 - etape1;

    test_etape_3();
    int etape3 = tests_passed - etape0 - etape1 - etape2;

    test_etape_4();
    int etape4 = tests_passed - etape0 - etape1 - etape2 - etape3;

    test_etape_5();
    int etape5 = tests_passed - etape0 - etape1 - etape2 - etape3 - etape4;

    // Résumé final
    cout << "\n" BLUE "═══════════════════════════════════════════════" RESET "\n";
    cout << "  RÉSUMÉ PAR ÉTAPE :\n";
    cout << "    Étape 0 (BFS échoue)     : " << etape0 << "/2\n";
    cout << "    Étape 1 (Glouton)        : " << etape1 << "/2\n";
    cout << "    Étape 2 (Relaxation)     : " << etape2 << "/3\n";
    cout << "    Étape 3 (Dijkstra base)  : " << etape3 << "/4\n";
    cout << "    Étape 4 (Dijkstra heap)  : " << etape4 << "/4\n";
    cout << "    Étape 5 (Reconstruction) : " << etape5 << "/3\n";
    cout << "\n  TOTAL : " << tests_passed << "/" << tests_total << " tests passés\n";

    // Estimation note
    int score = 0;
    score += (etape0 * 2) / 2;     // 2 pts max
    score += (etape1 * 3) / 2;     // 3 pts max
    score += (etape2 * 4) / 3;     // 4 pts max
    score += (etape3 * 6) / 4;     // 6 pts max
    score += (etape4 * 6) / 4;     // 6 pts max
    score += (etape5 * 4) / 3;     // 4 pts max

    cout << "  NOTE ESTIMÉE : " << score << "/25 pts (+ qualité code : +2 pts)\n";
    cout << BLUE "═══════════════════════════════════════════════" RESET "\n";

    return (tests_passed == tests_total) ? 0 : 1;
}

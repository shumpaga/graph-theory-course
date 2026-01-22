/**
 * @file test_dfs.cpp
 * @brief Tests automatiques pour le TPE3 - DFS
 *
 * TPE3 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * 26 tests : 10 BASE + 12 STANDARD + 4 BONUS
 */

#include "../src/graph.h"
#include "../src/dfs.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <sstream>

using namespace std;

// Couleurs pour l'affichage
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

int tests_passed = 0;
int tests_total = 0;

void test_header(const string& level, const string& name) {
    (void)level; // Unused parameter
    cout << "  Test " << name << "... ";
    tests_total++;
}

void test_result(bool passed) {
    if (passed) {
        cout << GREEN "✓ PASS" RESET << endl;
        tests_passed++;
    } else {
        cout << RED "✗ FAIL" RESET << endl;
    }
}

// ============================================================
// TESTS NIVEAU BASE (10 tests)
// ============================================================

void test_dfs_recursive_simple() {
    test_header("BASE", "3.1");
    // Graphe simple non-orienté
    Graph g(5, false);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // Capture stdout
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    dfs_recursive(g, 0);
    cout.rdbuf(old);

    string output = buffer.str();
    // Vérifier que tous les sommets sont visités (ordre peut varier)
    bool passed = (output.find("0") != string::npos &&
                   output.find("1") != string::npos &&
                   output.find("2") != string::npos &&
                   output.find("3") != string::npos &&
                   output.find("4") != string::npos);
    test_result(passed);
}

void test_dfs_recursive_disconnected() {
    test_header("BASE", "3.2");
    Graph g(4, false);
    g.addEdge(0, 1);
    // 2 et 3 isolés

    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    dfs_recursive(g, 0);
    cout.rdbuf(old);

    string output = buffer.str();
    bool passed = (output.find("0") != string::npos &&
                   output.find("1") != string::npos);
    test_result(passed);
}

void test_dfs_iterative_simple() {
    test_header("BASE", "3.3");
    Graph g(4, false);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    dfs_iterative(g, 0);
    cout.rdbuf(old);

    string output = buffer.str();
    bool passed = (output.find("0") != string::npos &&
                   output.find("1") != string::npos &&
                   output.find("2") != string::npos &&
                   output.find("3") != string::npos);
    test_result(passed);
}

void test_dfs_iterative_directed() {
    test_header("BASE", "3.4");
    Graph g(3, true);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    dfs_iterative(g, 0);
    cout.rdbuf(old);

    string output = buffer.str();
    bool passed = (output.find("0") != string::npos &&
                   output.find("1") != string::npos &&
                   output.find("2") != string::npos);
    test_result(passed);
}

void test_timestamps_simple() {
    test_header("BASE", "3.5");
    Graph g(3, true);
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    int discovery[3], finish[3];
    for (int i = 0; i < 3; i++) {
        discovery[i] = finish[i] = -1;
    }

    dfs_timestamps(g, discovery, finish);

    bool passed = true;
    for (int i = 0; i < 3; i++) {
        if (discovery[i] == -1 || finish[i] == -1) {
            passed = false;
        }
        if (discovery[i] >= finish[i]) {
            passed = false;
        }
    }
    test_result(passed);
}

void test_timestamps_order() {
    test_header("BASE", "3.6");
    Graph g(4, true);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    int discovery[4], finish[4];
    for (int i = 0; i < 4; i++) {
        discovery[i] = finish[i] = -1;
    }

    dfs_timestamps(g, discovery, finish);

    bool passed = (discovery[0] < finish[0] &&
                   discovery[1] < finish[1] &&
                   discovery[2] < finish[2] &&
                   discovery[3] < finish[3]);
    test_result(passed);
}

void test_dfs_recursive_dag() {
    test_header("BASE", "3.7");
    Graph g = Graph::loadFromFile("data/graph_dag.txt");

    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    dfs_recursive(g, 0);
    cout.rdbuf(old);

    test_result(true); // Si pas d'exception, OK
}

void test_dfs_iterative_dag() {
    test_header("BASE", "3.8");
    Graph g = Graph::loadFromFile("data/graph_dag.txt");

    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    dfs_iterative(g, 0);
    cout.rdbuf(old);

    test_result(true);
}

void test_timestamps_dag() {
    test_header("BASE", "3.9");
    Graph g = Graph::loadFromFile("data/graph_dag.txt");
    int V = g.getNumVertices();

    int* discovery = new int[V];
    int* finish = new int[V];
    for (int i = 0; i < V; i++) {
        discovery[i] = finish[i] = -1;
    }

    dfs_timestamps(g, discovery, finish);

    bool passed = true;
    for (int i = 0; i < V; i++) {
        if (discovery[i] == -1 || finish[i] == -1) {
            passed = false;
        }
    }

    delete[] discovery;
    delete[] finish;
    test_result(passed);
}

void test_timestamps_complex() {
    test_header("BASE", "3.10");
    Graph g = Graph::loadFromFile("data/graph_simple.txt");
    int V = g.getNumVertices();

    int* discovery = new int[V];
    int* finish = new int[V];
    for (int i = 0; i < V; i++) {
        discovery[i] = finish[i] = -1;
    }

    dfs_timestamps(g, discovery, finish);

    bool passed = true;
    for (int i = 0; i < V; i++) {
        if (discovery[i] >= finish[i]) {
            passed = false;
        }
    }

    delete[] discovery;
    delete[] finish;
    test_result(passed);
}

// ============================================================
// TESTS NIVEAU STANDARD (12 tests)
// ============================================================

void test_cycle_directed_true() {
    test_header("STANDARD", "3.11");
    Graph g(3, true);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0); // Cycle

    bool result = has_cycle(g);
    test_result(result == true);
}

void test_cycle_directed_false() {
    test_header("STANDARD", "3.12");
    Graph g = Graph::loadFromFile("data/graph_dag.txt");
    bool result = has_cycle(g);
    test_result(result == false);
}

void test_cycle_undirected_true() {
    test_header("STANDARD", "3.13");
    Graph g(4, false);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0); // Cycle

    bool result = has_cycle(g);
    test_result(result == true);
}

void test_cycle_undirected_false() {
    test_header("STANDARD", "3.14");
    Graph g(4, false);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3); // Arbre

    bool result = has_cycle(g);
    test_result(result == false);
}

void test_topological_sort_dag() {
    test_header("STANDARD", "3.15");
    Graph g = Graph::loadFromFile("data/graph_dag.txt");

    int* order = topological_sort(g);
    bool passed = (order != nullptr);

    if (order) {
        delete[] order;
    }
    test_result(passed);
}

void test_topological_sort_cycle() {
    test_header("STANDARD", "3.16");
    Graph g = Graph::loadFromFile("data/graph_cycle.txt");

    int* order = topological_sort(g);
    bool passed = (order == nullptr); // Doit retourner NULL

    test_result(passed);
}

void test_topological_sort_simple() {
    test_header("STANDARD", "3.17");
    Graph g(4, true);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    int* order = topological_sort(g);
    bool passed = (order != nullptr);

    if (order) {
        // Vérifier ordre valide (0 avant 1 et 2, 1 et 2 avant 3)
        int pos[4];
        for (int i = 0; i < 4; i++) {
            pos[order[i]] = i;
        }
        passed = (pos[0] < pos[1] && pos[0] < pos[2] &&
                  pos[1] < pos[3] && pos[2] < pos[3]);
        delete[] order;
    }
    test_result(passed);
}

void test_topological_sort_undirected() {
    test_header("STANDARD", "3.18");
    Graph g(3, false); // Non-orienté
    g.addEdge(0, 1);
    g.addEdge(1, 2);

    int* order = topological_sort(g);
    bool passed = (order == nullptr); // Tri topo sur non-orienté = NULL

    test_result(passed);
}

void test_cycle_self_loop() {
    test_header("STANDARD", "3.19");
    Graph g(3, true);
    g.addEdge(0, 0); // Boucle sur soi-même

    bool result = has_cycle(g);
    test_result(result == true);
}

void test_cycle_file() {
    test_header("STANDARD", "3.20");
    Graph g = Graph::loadFromFile("data/graph_cycle.txt");
    bool result = has_cycle(g);
    test_result(result == true);
}

void test_topological_courses() {
    test_header("STANDARD", "3.21");
    Graph g = Graph::loadFromFile("data/graph_courses.txt");

    int* order = topological_sort(g);
    bool passed = (order != nullptr);

    if (order) {
        delete[] order;
    }
    test_result(passed);
}

void test_cycle_large() {
    test_header("STANDARD", "3.22");
    Graph g = Graph::loadFromFile("data/graph_simple.txt");
    has_cycle(g); // Juste vérifier qu'il ne crash pas
    test_result(true);
}

// ============================================================
// TESTS NIVEAU BONUS (4 tests)
// ============================================================

void test_find_path_exists() {
    test_header("BONUS", "3.23");
    Graph g(5, false);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    vector<int> path;
    bool found = find_path_dfs(g, 0, 4, path);

    bool passed = (found && path.size() == 5 &&
                   path[0] == 0 && path[4] == 4);
    test_result(passed);
}

void test_find_path_not_exists() {
    test_header("BONUS", "3.24");
    Graph g(5, false);
    g.addEdge(0, 1);
    g.addEdge(2, 3); // Deux composantes

    vector<int> path;
    bool found = find_path_dfs(g, 0, 3, path);

    test_result(found == false);
}

void test_find_path_directed() {
    test_header("BONUS", "3.25");
    Graph g(4, true);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    vector<int> path;
    bool found = find_path_dfs(g, 0, 3, path);

    bool passed = (found && path.size() == 4);
    test_result(passed);
}

void test_find_path_self() {
    test_header("BONUS", "3.26");
    Graph g(3, false);
    g.addEdge(0, 1);

    vector<int> path;
    bool found = find_path_dfs(g, 1, 1, path);

    test_result(found && path.size() == 1 && path[0] == 1);
}

// ============================================================
// MAIN
// ============================================================

int main() {
    cout << BLUE "═══════════════════════════════════════\n";
    cout << "  TESTS TPE3 - DFS\n";
    cout << "═══════════════════════════════════════" RESET "\n\n";

    cout << YELLOW "--- NIVEAU 1 : BASE ---" RESET "\n";
    test_dfs_recursive_simple();
    test_dfs_recursive_disconnected();
    test_dfs_iterative_simple();
    test_dfs_iterative_directed();
    test_timestamps_simple();
    test_timestamps_order();
    test_dfs_recursive_dag();
    test_dfs_iterative_dag();
    test_timestamps_dag();
    test_timestamps_complex();

    int base_passed = tests_passed;
    cout << GREEN ">>> NIVEAU 1 : " << base_passed << "/10 tests passés <<<\n" RESET "\n";

    cout << YELLOW "--- NIVEAU 2 : STANDARD ---" RESET "\n";
    test_cycle_directed_true();
    test_cycle_directed_false();
    test_cycle_undirected_true();
    test_cycle_undirected_false();
    test_topological_sort_dag();
    test_topological_sort_cycle();
    test_topological_sort_simple();
    test_topological_sort_undirected();
    test_cycle_self_loop();
    test_cycle_file();
    test_topological_courses();
    test_cycle_large();

    int standard_passed = tests_passed - base_passed;
    cout << GREEN ">>> NIVEAU 2 : " << standard_passed << "/12 tests passés <<<\n" RESET "\n";

    cout << YELLOW "--- NIVEAU 3 : BONUS ---" RESET "\n";
    test_find_path_exists();
    test_find_path_not_exists();
    test_find_path_directed();
    test_find_path_self();

    int bonus_passed = tests_passed - (base_passed + standard_passed);
    cout << GREEN ">>> NIVEAU 3 : " << bonus_passed << "/4 tests passés <<<\n" RESET "\n";

    // Résumé final
    cout << BLUE "═══════════════════════════════════════\n";
    cout << "RÉSUMÉ : " << tests_passed << "/" << tests_total << " tests passés\n";

    int score = 0;
    if (base_passed >= 10) score += 10;
    else score += (base_passed * 10) / 10;

    if (standard_passed >= 12) score += 12;
    else score += (standard_passed * 12) / 12;

    if (bonus_passed >= 4) score += 3;
    else score += (bonus_passed * 3) / 4;

    cout << "NOTE ESTIMÉE : " << score << "/25 pts\n";
    cout << "═══════════════════════════════════════" RESET "\n";

    return (tests_passed == tests_total) ? 0 : 1;
}

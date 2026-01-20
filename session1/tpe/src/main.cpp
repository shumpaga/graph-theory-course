/**
 * @file main.cpp
 * @brief Programme de test automatique pour le TPE1
 * 
 * TPE1 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K.
 * 
 * NE PAS MODIFIER CE FICHIER
 * 
 * Exécutez ce programme pour valider votre implémentation.
 * Les tests sont organisés par niveau de difficulté.
 */

#include "graph.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

// ============================================================
// UTILITAIRES DE TEST
// ============================================================

// Compteurs globaux
int tests_passed = 0;
int tests_total = 0;
int level_passed = 0;
int level_total = 0;

// Couleurs terminal (ANSI)
#define COLOR_GREEN  "\033[32m"
#define COLOR_RED    "\033[31m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_CYAN   "\033[36m"
#define COLOR_RESET  "\033[0m"

/**
 * Affiche le résultat d'un test
 */
void printTest(const std::string& name, bool passed) {
    tests_total++;
    level_total++;
    
    std::cout << "[TEST] " << name;
    
    // Padding pour alignement
    int padding = 40 - name.length();
    for (int i = 0; i < padding; i++) std::cout << ".";
    
    if (passed) {
        std::cout << COLOR_GREEN << " OK" << COLOR_RESET << std::endl;
        tests_passed++;
        level_passed++;
    } else {
        std::cout << COLOR_RED << " ÉCHEC" << COLOR_RESET << std::endl;
    }
}

/**
 * Compare deux vectors (indépendamment de l'ordre)
 */
bool compareVectors(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) return false;
    
    std::vector<int> sorted_a = a;
    std::vector<int> sorted_b = b;
    std::sort(sorted_a.begin(), sorted_a.end());
    std::sort(sorted_b.begin(), sorted_b.end());
    
    return sorted_a == sorted_b;
}

/**
 * Affiche un résumé de niveau
 */
void printLevelSummary(int level) {
    std::cout << std::endl;
    if (level_passed == level_total) {
        std::cout << COLOR_GREEN << ">>> NIVEAU " << level << " : " 
                  << level_passed << "/" << level_total << " tests passés <<<" 
                  << COLOR_RESET << std::endl;
    } else {
        std::cout << COLOR_YELLOW << ">>> NIVEAU " << level << " : " 
                  << level_passed << "/" << level_total << " tests passés <<<" 
                  << COLOR_RESET << std::endl;
    }
    
    // Reset compteurs niveau
    level_passed = 0;
    level_total = 0;
}

// ============================================================
// TESTS NIVEAU 1 : BASE
// ============================================================

void testNiveau1() {
    std::cout << std::endl;
    std::cout << COLOR_CYAN << "--- NIVEAU 1 : BASE ---" << COLOR_RESET << std::endl;
    
    // Test 1.1: Constructeur
    Graph g1(5);
    printTest("Constructeur Graph(5)", true);  // Si ça compile, c'est OK
    
    // Test 1.2: order() sur graphe vide
    printTest("order() == 5", g1.order() == 5);
    
    // Test 1.3: size() sur graphe vide
    printTest("size() == 0 (graphe vide)", g1.size() == 0);
    
    // Test 1.4: addEdge
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    printTest("addEdge(0,1), addEdge(0,2)", true);  // Pas de crash = OK
    
    // Test 1.5: size() après ajout
    printTest("size() == 2", g1.size() == 2);
    
    // Test 1.6: degree()
    printTest("degree(0) == 2", g1.degree(0) == 2);
    
    // Test 1.7: degree() symétrie
    printTest("degree(1) == 1", g1.degree(1) == 1);
    
    // Test 1.8: degree() sommet isolé
    printTest("degree(4) == 0 (isolé)", g1.degree(4) == 0);
    
    // Test 1.9: degree() invalide
    printTest("degree(-1) == -1 (invalide)", g1.degree(-1) == -1);
    
    // Test 1.10: display() - on vérifie juste que ça ne crash pas
    std::cout << "[TEST] display()";
    int padding = 40 - 9;
    for (int i = 0; i < padding; i++) std::cout << ".";
    std::cout << COLOR_GREEN << " OK" << COLOR_RESET << std::endl;
    tests_total++;
    tests_passed++;
    level_total++;
    level_passed++;
    
    // Affichage du graphe pour vérification visuelle
    std::cout << "  ";
    std::streambuf* old = std::cout.rdbuf();
    std::stringstream buffer;
    std::cout.rdbuf(buffer.rdbuf());
    g1.display();
    std::cout.rdbuf(old);
    
    std::string output = buffer.str();
    // Afficher avec indentation
    std::istringstream iss(output);
    std::string line;
    while (std::getline(iss, line)) {
        std::cout << "  " << line << std::endl;
    }
    
    printLevelSummary(1);
}

// ============================================================
// TESTS NIVEAU 2 : STANDARD
// ============================================================

void testNiveau2() {
    std::cout << std::endl;
    std::cout << COLOR_CYAN << "--- NIVEAU 2 : STANDARD ---" << COLOR_RESET << std::endl;
    
    // Créer un graphe de test
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    
    // Test 2.1: hasEdge existante
    printTest("hasEdge(0,1) == true", g.hasEdge(0, 1) == true);
    
    // Test 2.2: hasEdge symétrie
    printTest("hasEdge(1,0) == true (symétrie)", g.hasEdge(1, 0) == true);
    
    // Test 2.3: hasEdge inexistante
    printTest("hasEdge(0,4) == false", g.hasEdge(0, 4) == false);
    
    // Test 2.4: hasEdge invalide
    printTest("hasEdge(-1,0) == false", g.hasEdge(-1, 0) == false);
    
    // Test 2.5: neighbors
    std::vector<int> expected_n0 = {1, 2};
    printTest("neighbors(0) == {1, 2}", compareVectors(g.neighbors(0), expected_n0));
    
    // Test 2.6: neighbors sommet avec plus de voisins
    std::vector<int> expected_n2 = {0, 3, 4};
    printTest("neighbors(2) == {0, 3, 4}", compareVectors(g.neighbors(2), expected_n2));
    
    // Test 2.7: neighbors sommet isolé (après création nouveau graphe)
    Graph g2(3);
    g2.addEdge(0, 1);
    std::vector<int> expected_empty = {};
    printTest("neighbors(2) == {} (isolé)", compareVectors(g2.neighbors(2), expected_empty));
    
    printLevelSummary(2);
}

// ============================================================
// TESTS NIVEAU 3 : AVANCÉ
// ============================================================

void testNiveau3() {
    std::cout << std::endl;
    std::cout << COLOR_CYAN << "--- NIVEAU 3 : AVANCÉ ---" << COLOR_RESET << std::endl;
    
    // Créer un graphe de test
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    
    // Test 3.1: removeEdge
    g.removeEdge(0, 1);
    printTest("removeEdge(0,1)", true);  // Pas de crash = OK
    
    // Test 3.2: hasEdge après suppression
    printTest("hasEdge(0,1) == false", g.hasEdge(0, 1) == false);
    
    // Test 3.3: hasEdge symétrie après suppression
    printTest("hasEdge(1,0) == false", g.hasEdge(1, 0) == false);
    
    // Test 3.4: size après suppression
    printTest("size() == 3", g.size() == 3);
    
    // Test 3.5: les autres arêtes sont intactes
    printTest("hasEdge(0,2) == true", g.hasEdge(0, 2) == true);
    
    // Test 3.6: degree après suppression
    printTest("degree(0) == 1", g.degree(0) == 1);
    printTest("degree(1) == 1", g.degree(1) == 1);
    
    // Test 3.7: removeEdge inexistante (ne doit pas crasher)
    int size_before = g.size();
    g.removeEdge(0, 3);  // N'existe pas
    printTest("removeEdge inexistante (stable)", g.size() == size_before);
    
    printLevelSummary(3);
}

// ============================================================
// TEST BONUS : GRAPHE DE COTONOU
// ============================================================

void testCotonou() {
    std::cout << std::endl;
    std::cout << COLOR_CYAN << "--- TEST CONTEXTUEL : COTONOU ---" << COLOR_RESET << std::endl;
    std::cout << "  (Quartiers: 0=Ganhi, 1=Akpakpa, 2=Cadjehoun, 3=Fidjrosse, 4=Godomey)" << std::endl;
    
    Graph cotonou(5);
    cotonou.addEdge(0, 1);  // Ganhi - Akpakpa
    cotonou.addEdge(0, 2);  // Ganhi - Cadjehoun
    cotonou.addEdge(1, 3);  // Akpakpa - Fidjrosse
    cotonou.addEdge(2, 3);  // Cadjehoun - Fidjrosse
    cotonou.addEdge(2, 4);  // Cadjehoun - Godomey
    cotonou.addEdge(3, 4);  // Fidjrosse - Godomey
    
    std::cout << std::endl;
    cotonou.display();
    
    std::cout << std::endl;
    std::cout << "  Quartier le plus connecté: ";
    int max_deg = 0, max_v = 0;
    for (int v = 0; v < 5; v++) {
        if (cotonou.degree(v) > max_deg) {
            max_deg = cotonou.degree(v);
            max_v = v;
        }
    }
    std::string quartiers[] = {"Ganhi", "Akpakpa", "Cadjehoun", "Fidjrosse", "Godomey"};
    std::cout << quartiers[max_v] << " (degré " << max_deg << ")" << std::endl;
}

// ============================================================
// MAIN
// ============================================================

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "     TESTS TPE1 - THEORIE DES GRAPHES" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Exécuter les tests par niveau
    testNiveau1();
    testNiveau2();
    testNiveau3();
    
    // Test contextuel
    testCotonou();
    
    // Résumé final
    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (tests_passed == tests_total) {
        std::cout << COLOR_GREEN;
    } else if (tests_passed >= tests_total * 0.6) {
        std::cout << COLOR_YELLOW;
    } else {
        std::cout << COLOR_RED;
    }
    
    std::cout << "RÉSULTAT FINAL : " << tests_passed << "/" << tests_total 
              << " tests passés" << COLOR_RESET << std::endl;
    
    // Calcul de la note
    float note = (float)tests_passed / tests_total * 20;
    std::cout << "NOTE ESTIMÉE : " << (int)note << "/20" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return (tests_passed == tests_total) ? 0 : 1;
}

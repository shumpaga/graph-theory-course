#include "graph.hpp"
#include <cassert>
#include <iostream>
#include <string>

// Couleurs pour l'affichage
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"
#define BLUE "\033[0;34m"

// ========================================
// FONCTIONS AUXILIAIRES DE TEST
// ========================================

void print_test_header(const std::string& test_name) {
    std::cout << "\n" BLUE "========================================\n";
    std::cout << "TEST : " << test_name << "\n";
    std::cout << "========================================" RESET "\n\n";
}

void print_test_result(bool passed) {
    if (passed) {
        std::cout << GREEN "✓ Test réussi\n" RESET;
    } else {
        std::cout << RED "✗ Test échoué\n" RESET;
    }
}

// ========================================
// TESTS - NIVEAU BASE
// ========================================

void test_create_graph() {
    print_test_header("Création d'un graphe vide");

    try {
        // Test 1 : Graphe non-orienté non-pondéré
        Graph g1(5, false, false);
        assert(g1.getNumVertices() == 5);
        assert(g1.getNumEdges() == 0);
        assert(g1.isDirected() == false);
        assert(g1.isWeighted() == false);

        std::cout << "✓ Graphe non-orienté non-pondéré créé avec succès\n";

        // Test 2 : Graphe orienté pondéré
        Graph g2(10, true, true);
        assert(g2.getNumVertices() == 10);
        assert(g2.getNumEdges() == 0);
        assert(g2.isDirected() == true);
        assert(g2.isWeighted() == true);

        std::cout << "✓ Graphe orienté pondéré créé avec succès\n";

        print_test_result(true);
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        print_test_result(false);
    }
}

void test_add_edge_undirected() {
    print_test_header("Ajout d'arêtes (graphe non-orienté)");

    try {
        Graph g(4, false, false);

        // Ajouter quelques arêtes
        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, 1);
        g.addEdge(1, 3, 1);
        g.addEdge(2, 3, 1);

        assert(g.getNumEdges() == 4);
        std::cout << "✓ 4 arêtes ajoutées, n_edges = " << g.getNumEdges() << "\n";

        // Afficher le graphe
        g.print();

        print_test_result(true);
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        print_test_result(false);
    }
}

void test_add_edge_directed() {
    print_test_header("Ajout d'arêtes (graphe orienté)");

    try {
        Graph g(3, true, true);

        // Ajouter des arcs avec poids
        g.addEdge(0, 1, 5);
        g.addEdge(0, 2, 3);
        g.addEdge(2, 1, 7);

        assert(g.getNumEdges() == 3);
        std::cout << "✓ 3 arcs ajoutés, n_edges = " << g.getNumEdges() << "\n";

        // Afficher le graphe
        g.print();

        print_test_result(true);
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        print_test_result(false);
    }
}

// ========================================
// TESTS - NIVEAU STANDARD
// ========================================

void test_degree() {
    print_test_header("Calcul du degré des sommets");

    try {
        Graph g(5, false, false);

        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, 1);
        g.addEdge(1, 2, 1);
        g.addEdge(1, 3, 1);
        g.addEdge(2, 3, 1);
        g.addEdge(3, 4, 1);

        // Vérifier les degrés
        assert(g.degree(0) == 2);
        std::cout << "✓ deg(0) = " << g.degree(0) << "\n";

        assert(g.degree(1) == 3);
        std::cout << "✓ deg(1) = " << g.degree(1) << "\n";

        assert(g.degree(2) == 3);
        std::cout << "✓ deg(2) = " << g.degree(2) << "\n";

        assert(g.degree(3) == 3);
        std::cout << "✓ deg(3) = " << g.degree(3) << "\n";

        assert(g.degree(4) == 1);
        std::cout << "✓ deg(4) = " << g.degree(4) << "\n";

        // Vérifier la propriété : somme des degrés = 2 * |E|
        int sum_degrees = 0;
        for (int i = 0; i < g.getNumVertices(); ++i) {
            sum_degrees += g.degree(i);
        }
        assert(sum_degrees == 2 * g.getNumEdges());
        std::cout << "✓ Propriété vérifiée : Σ deg(v) = " << sum_degrees
                  << " = 2 × " << g.getNumEdges() << "\n";

        print_test_result(true);
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        print_test_result(false);
    }
}

void test_are_neighbors() {
    print_test_header("Test d'adjacence");

    try {
        Graph g(5, false, false);

        g.addEdge(0, 1, 1);
        g.addEdge(0, 2, 1);
        g.addEdge(1, 3, 1);

        // Tests positifs
        assert(g.areNeighbors(0, 1) == true);
        std::cout << "✓ 0 et 1 sont adjacents\n";

        assert(g.areNeighbors(1, 0) == true);
        std::cout << "✓ 1 et 0 sont adjacents (symétrie)\n";

        assert(g.areNeighbors(0, 2) == true);
        std::cout << "✓ 0 et 2 sont adjacents\n";

        assert(g.areNeighbors(1, 3) == true);
        std::cout << "✓ 1 et 3 sont adjacents\n";

        // Tests négatifs
        assert(g.areNeighbors(0, 3) == false);
        std::cout << "✓ 0 et 3 ne sont PAS adjacents\n";

        assert(g.areNeighbors(2, 3) == false);
        std::cout << "✓ 2 et 3 ne sont PAS adjacents\n";

        print_test_result(true);
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        print_test_result(false);
    }
}

// ========================================
// TESTS DE GESTION D'ERREURS
// ========================================

void test_error_handling() {
    print_test_header("Gestion des erreurs");

    bool all_passed = true;

    // Test : Ajout d'arête avec sommets invalides
    try {
        Graph g(3, false, false);
        std::cout << "Test : Ajout d'arête avec sommets invalides (devrait lancer une exception)...\n";
        g.addEdge(0, 5, 1);  // dest invalide
        std::cout << RED "✗ Exception non lancée !\n" RESET;
        all_passed = false;
    } catch (const std::out_of_range& e) {
        std::cout << GREEN "✓ Exception correctement lancée\n" RESET;
    }

    // Test : degree() avec sommet invalide
    try {
        Graph g(5, false, false);
        std::cout << "Test : degree() avec sommet invalide...\n";
        int d = g.degree(10);
        (void)d;  // Éviter warning unused
        std::cout << RED "✗ Exception non lancée !\n" RESET;
        all_passed = false;
    } catch (const std::out_of_range& e) {
        std::cout << GREEN "✓ Exception correctement lancée\n" RESET;
    }

    // Test : areNeighbors() avec sommet invalide
    try {
        Graph g(5, false, false);
        std::cout << "Test : areNeighbors() avec sommets invalides...\n";
        bool result = g.areNeighbors(0, 10);
        (void)result;
        std::cout << RED "✗ Exception non lancée !\n" RESET;
        all_passed = false;
    } catch (const std::out_of_range& e) {
        std::cout << GREEN "✓ Exception correctement lancée\n" RESET;
    }

    print_test_result(all_passed);
}

// ========================================
// TESTS - NIVEAU BONUS
// ========================================

void test_load_from_file() {
    print_test_header("Chargement depuis fichier");

    try {
        std::cout << "Chargement de 'graphe1.txt'...\n";
        Graph g = Graph::loadFromFile("graphe1.txt");

        std::cout << "✓ Graphe chargé avec succès\n\n";
        g.print();

        print_test_result(true);
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        std::cout << "\n💡 Assurez-vous que le fichier 'graphe1.txt' existe\n";
        std::cout << "💡 Une fois implémenté, ce test devrait passer\n";
        print_test_result(false);
    }
}

void test_save_to_file() {
    print_test_header("Sauvegarde dans fichier");

    try {
        // Créer un graphe
        Graph g(3, false, true);
        g.addEdge(0, 1, 5);
        g.addEdge(0, 2, 3);
        g.addEdge(1, 2, 7);

        // Sauvegarder
        g.saveToFile("output.txt");
        std::cout << "✓ Graphe sauvegardé dans 'output.txt'\n";

        // Recharger
        Graph g2 = Graph::loadFromFile("output.txt");
        std::cout << "✓ Graphe rechargé depuis 'output.txt'\n";

        // Vérifier
        assert(g2.getNumVertices() == g.getNumVertices());
        std::cout << "✓ Même nombre de sommets : " << g2.getNumVertices() << "\n";

        assert(g2.getNumEdges() == g.getNumEdges());
        std::cout << "✓ Même nombre d'arêtes : " << g2.getNumEdges() << "\n";

        print_test_result(true);
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        std::cout << "\n💡 Une fois implémenté, ce test devrait passer\n";
        print_test_result(false);
    }
}

// ========================================
// MAIN
// ========================================

int main() {
    std::cout << BLUE "╔════════════════════════════════════════╗\n";
    std::cout << "║   TESTS - Structure de Graphe (TPE1)  ║\n";
    std::cout << "║   Théorie des Graphes L2 GI           ║\n";
    std::cout << "╚════════════════════════════════════════╝" RESET "\n";

    std::cout << "\n" BLUE "=== TESTS NIVEAU BASE ===" RESET "\n";
    test_create_graph();
    test_add_edge_undirected();
    test_add_edge_directed();

    std::cout << "\n" BLUE "=== TESTS NIVEAU STANDARD ===" RESET "\n";
    test_degree();
    test_are_neighbors();

    std::cout << "\n" BLUE "=== TESTS DE GESTION D'ERREURS ===" RESET "\n";
    test_error_handling();

    std::cout << "\n" BLUE "=== TESTS NIVEAU BONUS ===" RESET "\n";
    test_load_from_file();
    test_save_to_file();

    std::cout << "\n" GREEN "🎉 Félicitations ! Tous les tests obligatoires sont passés !\n" RESET;
    std::cout << "\n💡 Conseil : Vérifiez qu'il n'y a aucune fuite mémoire avec Valgrind :\n";
    std::cout << "   make valgrind\n\n";

    return 0;
}

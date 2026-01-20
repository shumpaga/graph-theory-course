/**
 * @file main.cpp
 * @brief Programme principal interactif - Tests des algorithmes BFS
 *
 * ESGC VERECHAGUINE A.K. - 2025-2026
 * Enseignant : M. Alexandre GBAGUIDI AISSE
 * Niveau : Licence 2 - Génie Informatique
 *
 * TPE2 - Séance 2 : Breadth-First Search
 *
 * Ce programme permet de tester interactivement toutes les fonctions BFS
 * implémentées dans bfs.cpp
 */

#include "graph.h"
#include "bfs.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==================== AFFICHAGE DU MENU ====================

void afficherMenu() {
    cout << "\n";
    cout << "╔═══════════════════════════════════════════════════════════════╗\n";
    cout << "║           TPE2 - PARCOURS EN LARGEUR (BFS)                    ║\n";
    cout << "║           ESGC VERECHAGUINE A.K. - 2025-2026                  ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════╝\n";
    cout << "\n";
    cout << "  [NIVEAU BASE - 10 points]\n";
    cout << "  1. Parcours BFS simple (3 pts)\n";
    cout << "  2. Calcul des distances minimales (3 pts)\n";
    cout << "  3. Affichage de l'arbre BFS (4 pts)\n";
    cout << "\n";
    cout << "  [NIVEAU STANDARD - 10 points]\n";
    cout << "  4. Plus court chemin entre deux sommets (3 pts)\n";
    cout << "  5. Test de connexité du graphe (3 pts)\n";
    cout << "  6. Comptage des composantes connexes (4 pts)\n";
    cout << "\n";
    cout << "  [NIVEAU BONUS - 5 points]\n";
    cout << "  7. Test de graphe biparti (5 pts)\n";
    cout << "\n";
    cout << "  [AUTRES OPTIONS]\n";
    cout << "  8. Afficher le graphe\n";
    cout << "  9. Charger un autre graphe\n";
    cout << "  0. Quitter\n";
    cout << "\n";
    cout << "═══════════════════════════════════════════════════════════════\n";
}

// ==================== FONCTIONS UTILITAIRES ====================

/**
 * @brief Affiche un vecteur d'entiers
 */
void afficherVector(const vector<int>& v) {
    if (v.empty()) {
        cout << "(vide)";
        return;
    }
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]";
}

/**
 * @brief Demande un sommet valide à l'utilisateur
 */
int demanderSommet(Graph& g, const string& message) {
    int sommet;
    while (true) {
        cout << message << " (0 à " << g.getVertexCount() - 1 << ") : ";
        cin >> sommet;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Erreur : Veuillez entrer un nombre entier.\n";
            continue;
        }

        if (sommet >= 0 && sommet < g.getVertexCount()) {
            return sommet;
        }

        cout << "Erreur : Le sommet doit être entre 0 et " << g.getVertexCount() - 1 << ".\n";
    }
}

// ==================== TESTS DES FONCTIONS BFS ====================

/**
 * @brief Test de la fonction 1 : Parcours BFS simple
 */
void testBFS(Graph& g) {
    cout << "\n╔═══════════════════════════════════════════════════════════════╗\n";
    cout << "║  FONCTION 1 : PARCOURS BFS SIMPLE (3 pts)                    ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════╝\n";
    cout << "\nCette fonction effectue un parcours en largeur depuis un sommet source\n";
    cout << "et affiche l'ordre de visite des sommets.\n\n";

    int source = demanderSommet(g, "Entrez le sommet source");

    cout << "\nRésultat :\n";
    cout << "BFS depuis " << source << " : ";
    bfs(g, source);
    cout << "\n";
}

/**
 * @brief Test de la fonction 2 : Calcul des distances minimales
 */
void testDistances(Graph& g) {
    cout << "\n╔═══════════════════════════════════════════════════════════════╗\n";
    cout << "║  FONCTION 2 : DISTANCES MINIMALES (3 pts)                    ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════╝\n";
    cout << "\nCette fonction calcule la distance minimale du sommet source\n";
    cout << "à tous les autres sommets du graphe.\n\n";

    int source = demanderSommet(g, "Entrez le sommet source");

    vector<int> distances = bfs_distances(g, source);

    cout << "\nRésultat :\n";
    cout << "Distances depuis le sommet " << source << " :\n";
    for (int i = 0; i < g.getVertexCount(); i++) {
        cout << "  d(" << source << " → " << i << ") = ";
        if (distances[i] == -1) {
            cout << "∞ (non atteignable)\n";
        } else {
            cout << distances[i] << "\n";
        }
    }
    cout << "\n";
}

/**
 * @brief Test de la fonction 3 : Affichage de l'arbre BFS
 */
void testArbreBFS(Graph& g) {
    cout << "\n╔═══════════════════════════════════════════════════════════════╗\n";
    cout << "║  FONCTION 3 : ARBRE BFS (4 pts)                              ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════╝\n";
    cout << "\nCette fonction construit et affiche l'arbre de parcours BFS\n";
    cout << "avec la relation parent → enfants.\n\n";

    int source = demanderSommet(g, "Entrez le sommet racine");

    cout << "\nRésultat :\n";
    print_bfs_tree(g, source);
    cout << "\n";
}

/**
 * @brief Test de la fonction 4 : Plus court chemin
 */
void testPlusCourtChemin(Graph& g) {
    cout << "\n╔═══════════════════════════════════════════════════════════════╗\n";
    cout << "║  FONCTION 4 : PLUS COURT CHEMIN (3 pts)                      ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════╝\n";
    cout << "\nCette fonction trouve le plus court chemin entre deux sommets.\n\n";

    int source = demanderSommet(g, "Entrez le sommet source");
    int dest = demanderSommet(g, "Entrez le sommet destination");

    vector<int> chemin = shortest_path(g, source, dest);

    cout << "\nRésultat :\n";
    if (chemin.empty()) {
        cout << "Aucun chemin n'existe de " << source << " à " << dest << ".\n";
    } else {
        cout << "Plus court chemin de " << source << " à " << dest << " : ";
        afficherVector(chemin);
        cout << "\nLongueur du chemin : " << (chemin.size() - 1) << " arête(s)\n";
    }
    cout << "\n";
}

/**
 * @brief Test de la fonction 5 : Test de connexité
 */
void testConnexite(Graph& g) {
    cout << "\n╔═══════════════════════════════════════════════════════════════╗\n";
    cout << "║  FONCTION 5 : TEST DE CONNEXITÉ (3 pts)                      ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════╝\n";
    cout << "\nCette fonction détermine si le graphe est connexe,\n";
    cout << "c'est-à-dire si tous les sommets sont atteignables depuis n'importe quel sommet.\n\n";

    bool connexe = is_connected(g);

    cout << "Résultat :\n";
    if (connexe) {
        cout << "✓ Le graphe est CONNEXE\n";
        cout << "  → Tous les sommets sont atteignables depuis n'importe quel sommet.\n";
    } else {
        cout << "✗ Le graphe est NON CONNEXE\n";
        cout << "  → Il existe au moins deux sommets qui ne sont pas reliés.\n";
    }
    cout << "\n";
}

/**
 * @brief Test de la fonction 6 : Comptage des composantes connexes
 */
void testComposantes(Graph& g) {
    cout << "\n╔═══════════════════════════════════════════════════════════════╗\n";
    cout << "║  FONCTION 6 : COMPOSANTES CONNEXES (4 pts)                   ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════╝\n";
    cout << "\nCette fonction compte le nombre de composantes connexes du graphe.\n";
    cout << "Une composante connexe est un sous-ensemble maximal de sommets\n";
    cout << "où tous les sommets sont reliés entre eux.\n\n";

    int nb = count_components(g);

    cout << "Résultat :\n";
    cout << "Nombre de composantes connexes : " << nb << "\n";

    if (nb == 1) {
        cout << "→ Le graphe est connexe (une seule composante).\n";
    } else {
        cout << "→ Le graphe est déconnecté (" << nb << " composantes distinctes).\n";
    }
    cout << "\n";
}

/**
 * @brief Test de la fonction 7 : Test de graphe biparti
 */
void testBiparti(Graph& g) {
    cout << "\n╔═══════════════════════════════════════════════════════════════╗\n";
    cout << "║  FONCTION 7 : TEST BIPARTI (5 pts BONUS)                     ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════╝\n";
    cout << "\nCette fonction détermine si le graphe est biparti (2-colorable).\n";
    cout << "Un graphe est biparti si on peut partitionner ses sommets en deux ensembles\n";
    cout << "tels qu'aucune arête ne relie deux sommets du même ensemble.\n";
    cout << "\nPropriété : Un graphe est biparti ssi il ne contient pas de cycle impair.\n\n";

    bool biparti = is_bipartite(g);

    cout << "Résultat :\n";
    if (biparti) {
        cout << "✓ Le graphe est BIPARTI\n";
        cout << "  → On peut colorier les sommets avec 2 couleurs.\n";
        cout << "  → Le graphe ne contient aucun cycle de longueur impaire.\n";
    } else {
        cout << "✗ Le graphe est NON BIPARTI\n";
        cout << "  → Il est impossible de colorier les sommets avec seulement 2 couleurs.\n";
        cout << "  → Le graphe contient au moins un cycle de longueur impaire.\n";
    }
    cout << "\n";
}

/**
 * @brief Affiche le graphe
 */
void afficherGraphe(Graph& g) {
    cout << "\n╔═══════════════════════════════════════════════════════════════╗\n";
    cout << "║  AFFICHAGE DU GRAPHE                                          ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════╝\n";
    cout << "\n";
    cout << "Nombre de sommets : " << g.getVertexCount() << "\n";
    cout << "Type : " << (g.isDirected() ? "Orienté" : "Non orienté") << "\n";
    cout << "\nListe d'adjacence :\n";
    g.printGraph();
    cout << "\n";
}

// ==================== FONCTION PRINCIPALE ====================

int main(int argc, char* argv[]) {
    // Vérification des arguments
    if (argc < 2) {
        cout << "Usage : " << argv[0] << " <fichier_graphe>\n";
        cout << "\nExemples :\n";
        cout << "  " << argv[0] << " data/graph_simple.txt\n";
        cout << "  " << argv[0] << " data/graph_disconnected.txt\n";
        cout << "  " << argv[0] << " data/graph_bipartite.txt\n";
        cout << "  " << argv[0] << " data/graph_cotonou.txt\n";
        return 1;
    }

    // Chargement du graphe
    string filename = argv[1];
    Graph g = Graph::loadFromFile(filename);

    cout << "\n╔═══════════════════════════════════════════════════════════════╗\n";
    cout << "║  TPE2 - PARCOURS EN LARGEUR (BFS)                            ║\n";
    cout << "║  ESGC VERECHAGUINE A.K. - 2025-2026                          ║\n";
    cout << "╚═══════════════════════════════════════════════════════════════╝\n";
    cout << "\nGraphe chargé : " << filename << "\n";
    cout << "Nombre de sommets : " << g.getVertexCount() << "\n";
    cout << "Type : " << (g.isDirected() ? "Orienté" : "Non orienté") << "\n";

    // Boucle principale
    int choix;
    do {
        afficherMenu();
        cout << "Votre choix : ";
        cin >> choix;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nErreur : Veuillez entrer un nombre.\n";
            continue;
        }

        switch (choix) {
            case 1:
                testBFS(g);
                break;
            case 2:
                testDistances(g);
                break;
            case 3:
                testArbreBFS(g);
                break;
            case 4:
                testPlusCourtChemin(g);
                break;
            case 5:
                testConnexite(g);
                break;
            case 6:
                testComposantes(g);
                break;
            case 7:
                testBiparti(g);
                break;
            case 8:
                afficherGraphe(g);
                break;
            case 9:
                cout << "\nEntrez le nouveau fichier graphe : ";
                cin >> filename;
                try {
                    g = Graph::loadFromFile(filename);
                    cout << "✓ Graphe chargé avec succès !\n";
                    cout << "Nombre de sommets : " << g.getVertexCount() << "\n";
                } catch (const exception& e) {
                    cout << "Erreur lors du chargement : " << e.what() << "\n";
                }
                break;
            case 0:
                cout << "\nMerci d'avoir utilisé ce programme !\n";
                cout << "Bon courage pour votre TPE !\n\n";
                break;
            default:
                cout << "\nChoix invalide. Veuillez choisir une option entre 0 et 9.\n";
        }

    } while (choix != 0);

    return 0;
}

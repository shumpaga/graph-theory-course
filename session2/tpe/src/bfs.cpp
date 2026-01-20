/**
 * @file bfs.cpp
 * @brief Implémentation des algorithmes BFS - À COMPLÉTER
 *
 * ESGC VERECHAGUINE A.K. - 2025-2026
 * Enseignant : M. Alexandre GBAGUIDI AISSE
 *
 * NOM : ___________________________
 * PRÉNOM : ________________________
 * GROUPE : ________________________
 *
 * ⚠️ INSTRUCTIONS :
 * - Remplacez chaque bloc "TODO" par votre implémentation
 * - Testez après chaque fonction avec make test_bfs
 * - Commentez votre code pour le bonus +2 pts
 * - Respectez les signatures des fonctions (ne pas modifier bfs.h)
 */

#include "bfs.h"
#include "queue.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// ╔══════════════════════════════════════════════════════════╗
// ║               NIVEAU BASE (10 points)                    ║
// ╚══════════════════════════════════════════════════════════╝

/**
 * Fonction 1 : Parcours BFS simple (3 pts)
 * Complexité attendue : O(V + E)
 */
void bfs(Graph& g, int source) {
    // TODO 1 : Implémenter le parcours BFS
    //
    // Étapes :
    // 1. Créer une Queue Q
    // 2. Créer un vector<bool> visited(V, false) où V = g.getVertexCount()
    // 3. Marquer source comme visité : visited[source] = true
    // 4. Enfiler source : Q.push(source)
    // 5. Tant que Q n'est pas vide :
    //    a. Défiler u = Q.pop()
    //    b. Afficher u (avec cout << u << " ")
    //    c. Pour chaque voisin v de u (utiliser g.getNeighbors(u)) :
    //       - Si v non visité : visited[v] = true, Q.push(v)
    // 6. Afficher un retour à la ligne final (cout << endl)
    //
    // CONSEIL : Commencez par cette fonction, c'est la base de tout !

    (void)g; (void)source;  // Évite les warnings de paramètres non utilisés
    cout << "TODO: Implémenter bfs() - Fonction 1 (3 pts)" << endl;
    cout << "Voir les instructions dans bfs.cpp" << endl;
}

/**
 * Fonction 2 : Calcul des distances minimales (3 pts)
 * Complexité attendue : O(V + E)
 */
vector<int> bfs_distances(Graph& g, int source) {
    // TODO 2 : Implémenter le calcul des distances
    //
    // Étapes :
    // 1. Créer distance(V, -1) pour marquer "non atteignable"
    // 2. Créer visited(V, false)
    // 3. Initialiser : distance[source] = 0, visited[source] = true
    // 4. Créer une Queue Q et enfiler source
    // 5. BFS classique, mais en mettant à jour les distances :
    //    - Quand on visite v depuis u : distance[v] = distance[u] + 1
    // 6. Retourner le vecteur distance
    //
    // CONSEIL : Similaire à bfs(), mais on stocke les distances

    (void)source;  // Évite le warning
    cout << "TODO: Implémenter bfs_distances() - Fonction 2 (3 pts)" << endl;

    int V = g.getVertexCount();
    return vector<int>(V, -1);  // Temporaire, à modifier
}

/**
 * Fonction 3 : Affichage de l'arbre BFS (4 pts)
 * Complexité attendue : O(V + E)
 */
void print_bfs_tree(Graph& g, int source) {
    // TODO 3 : Implémenter l'affichage de l'arbre BFS
    //
    // Étapes :
    // 1. Faire un BFS en gardant parent[v] pour chaque sommet
    //    - Créer parent(V, -1)
    //    - Quand on découvre v depuis u : parent[v] = u
    // 2. Créer une map<int, vector<int>> pour stocker parent → enfants
    //    - Parcourir parent[] : si parent[v] != -1, ajouter v aux enfants de parent[v]
    // 3. Afficher chaque parent avec ses enfants :
    //    - Format : "parent → enfant1, enfant2, ..."
    //
    // CONSEIL : Utilisez la map pour regrouper les enfants par parent

    (void)g;  // Évite le warning
    cout << "TODO: Implémenter print_bfs_tree() - Fonction 3 (4 pts)" << endl;
    cout << "Arbre BFS depuis " << source << " :" << endl;
}

// ╔══════════════════════════════════════════════════════════╗
// ║             NIVEAU STANDARD (10 points)                  ║
// ╚══════════════════════════════════════════════════════════╝

/**
 * Fonction 4 : Plus court chemin (3 pts)
 * Complexité attendue : O(V + E)
 */
vector<int> shortest_path(Graph& g, int source, int dest) {
    // TODO 4 : Implémenter la reconstruction du plus court chemin
    //
    // Étapes :
    // 1. Faire BFS avec parent[] (comme dans print_bfs_tree)
    // 2. Si dest n'est pas atteignable (parent[dest] == -1 et dest != source) :
    //    - Retourner un vecteur vide
    // 3. Sinon, reconstruire le chemin en remontant de dest à source :
    //    - Créer path vide
    //    - current = dest
    //    - Tant que current != -1 :
    //      - Ajouter current au début de path
    //      - current = parent[current]
    // 4. Retourner path
    //
    // CONSEIL : Vous pouvez construire le chemin à l'envers puis l'inverser

    (void)g; (void)source; (void)dest;  // Évite les warnings
    cout << "TODO: Implémenter shortest_path() - Fonction 4 (3 pts)" << endl;

    return vector<int>();  // Temporaire, à modifier
}

/**
 * Fonction 5 : Test de connexité (3 pts)
 * Complexité attendue : O(V + E)
 */
bool is_connected(Graph& g) {
    // TODO 5 : Implémenter le test de connexité
    //
    // Étapes :
    // 1. Si le graphe est vide (V == 0), retourner true
    // 2. Faire BFS depuis le sommet 0
    // 3. Compter le nombre de sommets visités
    // 4. Retourner (nombre_visités == V)
    //
    // CONSEIL : Un graphe est connexe si tous les sommets sont atteignables depuis 0

    (void)g;  // Évite le warning
    cout << "TODO: Implémenter is_connected() - Fonction 5 (3 pts)" << endl;

    return false;  // Temporaire, à modifier
}

/**
 * Fonction 6 : Comptage des composantes connexes (4 pts)
 * Complexité attendue : O(V + E)
 */
int count_components(Graph& g) {
    // TODO 6 : Implémenter le comptage des composantes connexes
    //
    // Étapes :
    // 1. Créer visited(V, false)
    // 2. Initialiser count = 0
    // 3. Pour chaque sommet v de 0 à V-1 :
    //    a. Si v non visité :
    //       - Faire BFS depuis v (marque toute sa composante comme visitée)
    //       - Incrémenter count
    // 4. Retourner count
    //
    // CONSEIL : Chaque BFS explore une nouvelle composante connexe

    (void)g;  // Évite le warning
    cout << "TODO: Implémenter count_components() - Fonction 6 (4 pts)" << endl;

    return 0;  // Temporaire, à modifier
}

// ╔══════════════════════════════════════════════════════════╗
// ║               NIVEAU BONUS (5 points)                    ║
// ╚══════════════════════════════════════════════════════════╝

/**
 * Fonction 7 : Test de graphe biparti (5 pts)
 * Complexité attendue : O(V + E)
 */
bool is_bipartite(Graph& g) {
    // TODO 7 : Implémenter le test de graphe biparti
    //
    // Étapes :
    // 1. Créer color(V, -1) où -1 = non colorié
    // 2. Pour chaque sommet s de 0 à V-1 :
    //    a. Si color[s] == -1 (nouvelle composante) :
    //       - Faire BFS depuis s avec coloration alternée :
    //         * color[s] = 0
    //         * Queue Q, Q.push(s)
    //         * Tant que Q non vide :
    //           - u = Q.pop()
    //           - Pour chaque voisin v de u :
    //             * Si color[v] == -1 :
    //               - color[v] = 1 - color[u]  (couleur opposée)
    //               - Q.push(v)
    //             * Si color[v] == color[u] :
    //               - Retourner false (conflit de couleur)
    // 3. Retourner true (graphe biparti)
    //
    // CONSEIL : Un graphe est biparti ssi il ne contient pas de cycle impair

    (void)g;  // Évite le warning
    cout << "TODO: Implémenter is_bipartite() - Fonction 7 (5 pts BONUS)" << endl;

    return false;  // Temporaire, à modifier
}

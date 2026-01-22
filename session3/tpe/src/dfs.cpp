/**
 * @file dfs.cpp
 * @brief Implémentation des algorithmes DFS
 *
 * TPE3 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * NOM : ____________________
 * PRÉNOM : _________________
 * GROUPE : _________________
 */

#include "dfs.h"
#include "stack.h"
#include <iostream>
#include <vector>

using namespace std;

// ============================================================
// FONCTION AUXILIAIRE POUR DFS RÉCURSIF
// ============================================================

void dfs_visit(Graph& g, int u, vector<bool>& visited) {
    (void)g; (void)u; (void)visited;
    // TODO : Implémenter la fonction auxiliaire récursive
    // 1. Marquer u comme visité : visited[u] = true
    // 2. Afficher u : cout << u << " "
    // 3. Pour chaque voisin v de u :
    //    - Si v n'est pas visité, appeler récursivement dfs_visit(g, v, visited)
    cout << "TODO: Implémenter dfs_visit()" << endl;
}

// ============================================================
// NIVEAU BASE (10 points)
// ============================================================

void dfs_recursive(Graph& g, int source) {
    (void)g; (void)source;
    // TODO : Implémenter DFS récursif (3 points)
    // 1. Créer un vector<bool> visited de taille V, initialisé à false
    // 2. Appeler dfs_visit(g, source, visited)
    cout << "TODO: Implémenter dfs_recursive() - Fonction 1 (3 pts)" << endl;
}

void dfs_iterative(Graph& g, int source) {
    (void)g; (void)source;
    // TODO : Implémenter DFS itératif (3 points)
    // 1. Créer Stack s et vector<bool> visited(V, false)
    // 2. Empiler source : s.push(source)
    // 3. Tant que pile non vide :
    //    - Dépiler u = s.pop()
    //    - Si u déjà visité, continue
    //    - Marquer visited[u] = true, afficher u
    //    - Pour chaque voisin v de u (en ordre inverse pour cohérence) :
    //      * Si v non visité, empiler v
    // IMPORTANT : Utiliser Stack de stack.h (pas std::stack)
    cout << "TODO: Implémenter dfs_iterative() - Fonction 2 (3 pts)" << endl;
}

void dfs_timestamps(Graph& g, int discovery[], int finish[]) {
    (void)g; (void)discovery; (void)finish;
    // TODO : Implémenter calcul des timestamps (4 points)
    // 1. Créer vector<bool> visited(V, false) et int time = 0
    // 2. Initialiser discovery et finish à -1 (déjà fait par appelant normalement)
    // 3. Pour chaque sommet u de 0 à V-1 :
    //    - Si u non visité, lancer DFS avec timestamps depuis u
    // 4. Dans la visite récursive :
    //    - À la découverte de u : discovery[u] = time++
    //    - À la fin de u : finish[u] = time++
    cout << "TODO: Implémenter dfs_timestamps() - Fonction 3 (4 pts)" << endl;
}

// ============================================================
// NIVEAU STANDARD (12 points)
// ============================================================

bool has_cycle(Graph& g) {
    (void)g;
    // TODO : Implémenter détection de cycle (6 points)
    // Pour graphe ORIENTÉ :
    //   - Utiliser vector<bool> visited et vector<bool> in_stack
    //   - in_stack[u] = true quand u est dans la pile de récursion
    //   - Cycle détecté si on atteint un sommet déjà in_stack
    // Pour graphe NON-ORIENTÉ :
    //   - Utiliser vector<bool> visited et vector<int> parent
    //   - Cycle détecté si on atteint un sommet visité qui n'est pas le parent
    cout << "TODO: Implémenter has_cycle() - Fonction 4 (6 pts)" << endl;
    return false;
}

int* topological_sort(Graph& g) {
    (void)g;
    // TODO : Implémenter tri topologique (6 points)
    // 1. VÉRIFIER que le graphe est orienté (sinon retourner NULL)
    // 2. VÉRIFIER l'absence de cycle avec has_cycle() (sinon retourner NULL)
    // 3. Créer vector<int> finish_times et vector<int> vertices
    // 4. Faire DFS avec timestamps pour obtenir finish[]
    // 5. Trier les sommets par ordre DÉCROISSANT de finish[]
    // 6. Allouer int* result = new int[V] et copier l'ordre
    // 7. Retourner result
    cout << "TODO: Implémenter topological_sort() - Fonction 5 (6 pts)" << endl;
    return nullptr;
}

// ============================================================
// NIVEAU BONUS (3 points)
// ============================================================

bool find_path_dfs(Graph& g, int src, int dest, vector<int>& path) {
    (void)g; (void)src; (void)dest; (void)path;
    // TODO : Implémenter recherche de chemin avec DFS (3 points)
    // 1. Créer vector<bool> visited(V, false) et vector<int> parent(V, -1)
    // 2. Faire DFS récursif depuis src en mémorisant parent[]
    // 3. Si dest atteint, reconstruire le chemin depuis dest vers src avec parent[]
    // 4. Inverser le chemin et le stocker dans path
    // 5. Retourner true si chemin trouvé, false sinon
    cout << "TODO: Implémenter find_path_dfs() - Fonction 6 (3 pts)" << endl;
    return false;
}

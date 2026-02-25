/**
 * @file union_find.cpp
 * @brief Implémentation de la structure Union-Find
 *
 * TPE5 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * NOM    :
 * PRENOM :
 *
 * 3 fonctions à implémenter :
 *   - find()      : recherche avec compression de chemin
 *   - unite()     : fusion par rang
 *   - connected() : test de connexité
 */

#include "union_find.h"

// ============================================================
// CONSTRUCTEUR (fourni)
// ============================================================

UnionFind::UnionFind(int n) : parent(n), rank_(n, 0) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// ============================================================
// ÉTAPE 1 : FIND AVEC COMPRESSION DE CHEMIN (2 pts)
// ============================================================

int UnionFind::find(int x) {
    // TODO: Implémenter find avec compression de chemin
    //
    // Algorithme :
    //   si parent[x] != x :
    //       parent[x] = find(parent[x])   // COMPRESSION
    //   retourner parent[x]
    //
    // La compression fait pointer chaque noeud directement vers la racine,
    // ce qui accélère les futurs appels à find().

    return x; // À remplacer
}

// ============================================================
// ÉTAPE 2 : UNION PAR RANG (2.5 pts)
// ============================================================

void UnionFind::unite(int x, int y) {
    // TODO: Implémenter l'union par rang
    //
    // Algorithme :
    //   rx = find(x)
    //   ry = find(y)
    //   si rx == ry : ne rien faire (déjà dans le même ensemble)
    //
    //   si rank_[rx] < rank_[ry] :
    //       parent[rx] = ry
    //   sinon si rank_[rx] > rank_[ry] :
    //       parent[ry] = rx
    //   sinon :
    //       parent[ry] = rx
    //       rank_[rx]++

    (void)x; (void)y; // Supprimez cette ligne
}

// ============================================================
// ÉTAPE 2 : CONNECTED (1.5 pts)
// ============================================================

bool UnionFind::connected(int x, int y) {
    // TODO: Vérifier si x et y sont dans le même ensemble
    //
    // Indice : utiliser find() !

    (void)x; (void)y; // Supprimez cette ligne
    return false; // À remplacer
}

// ============================================================
// ACCESSEUR (fourni)
// ============================================================

int UnionFind::getParent(int x) const {
    return parent[x];
}

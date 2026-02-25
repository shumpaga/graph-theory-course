#include "union_find.h"

// NOM    :
// PRENOM :
// TPE5 - Union-Find (progression en 6 étapes)

// ============================================================
// ÉTAPE 1 : UNION-FIND NAÏF (4 points)
// Objectif : version simple qui MARCHE, sans optimisation
// ============================================================

UnionFind::UnionFind(int n) : parent(n), rank_(n, 0) {
    // TODO : Initialiser parent[i] = i pour tout i de 0 à n-1
    //        (chaque élément est son propre chef)
}

int UnionFind::find(int x) {
    // ----------------------------------------------------------
    // ÉTAPE 1 (NAÏF) : boucle while simple
    // TODO : Tant que parent[x] != x, faire x = parent[x]
    // TODO : Retourner x
    // ----------------------------------------------------------
    // ÉTAPE 3 (COMPRESSION) : REMPLACER le while ci-dessus par :
    // TODO : Si parent[x] == x, retourner x
    // TODO : parent[x] = find(parent[x])   <- LA ligne magique
    // TODO : Retourner parent[x]
    // ----------------------------------------------------------

    return x; // placeholder
}

void UnionFind::unite(int x, int y) {
    // ----------------------------------------------------------
    // ÉTAPE 1 (NAÏF) : rattachement arbitraire
    // TODO : rx = find(x), ry = find(y)
    // TODO : Si rx == ry, return (déjà dans le même groupe)
    // TODO : parent[ry] = rx  (choix arbitraire)
    // ----------------------------------------------------------
    // ÉTAPE 4 (RANG) : REMPLACER parent[ry]=rx par :
    // TODO : Si rank_[rx] < rank_[ry] : parent[rx] = ry
    // TODO : Sinon si rank_[rx] > rank_[ry] : parent[ry] = rx
    // TODO : Sinon : parent[ry] = rx ET rank_[rx]++
    // ----------------------------------------------------------

    (void)x; (void)y; // placeholder — supprimez cette ligne
}

bool UnionFind::connected(int x, int y) {
    // TODO : Retourner find(x) == find(y)

    (void)x; (void)y; // placeholder — supprimez cette ligne
    return false; // placeholder
}

// ============================================================
// ÉTAPE 2 : MESURER LE PROBLÈME (2 points)
// ============================================================

int UnionFind::count_operations(int x) {
    // TODO : Comme find() naïf, mais COMPTER le nombre de
    //        remontées (x = parent[x]) et retourner le compteur
    // ATTENTION : NE PAS modifier parent[] ici !

    (void)x; // placeholder — supprimez cette ligne
    return 0; // placeholder
}

// ============================================================
// ACCESSEUR (fourni — ne pas modifier)
// ============================================================

int UnionFind::getParent(int x) const {
    return parent[x];
}

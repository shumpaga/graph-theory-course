/**
 * @file union_find.h
 * @brief Structure Union-Find (Disjoint Set Union) avec compression et rang
 *
 * TPE5 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * Opérations :
 *   - find(x)        : trouve le représentant de l'ensemble contenant x
 *   - unite(x, y)    : fusionne les ensembles contenant x et y
 *   - connected(x, y): vérifie si x et y sont dans le même ensemble
 */

#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank_;

public:
    // Constructeur : crée n ensembles disjoints {0}, {1}, ..., {n-1}
    UnionFind(int n);

    // Trouve le représentant (racine) de l'ensemble contenant x
    // Avec compression de chemin
    int find(int x);

    // Fusionne les ensembles contenant x et y
    // Union par rang
    void unite(int x, int y);

    // Vérifie si x et y sont dans le même ensemble
    bool connected(int x, int y);

    // Accesseur pour les tests (lecture seule)
    int getParent(int x) const;
};

#endif // UNION_FIND_H

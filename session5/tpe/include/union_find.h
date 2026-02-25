/**
 * @file union_find.h
 * @brief Structure Union-Find (Disjoint Set Union)
 *
 * TPE5 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * Progression en 6 étapes :
 *   Étape 1 : Version naïve (find, unite, connected)
 *   Étape 2 : Mesurer le problème (count_operations)
 *   Étape 3 : Compression de chemin (modifier find)
 *   Étape 4 : Union par rang (modifier unite)
 */

#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>

class UnionFind {
private:
    std::vector<int> parent;    // parent[i] = chef de i
    std::vector<int> rank_;     // rank_[i] = hauteur estimée (étape 4)

public:
    // Constructeur : crée n ensembles disjoints {0}, {1}, ..., {n-1}
    UnionFind(int n);

    // Trouve le représentant (racine) de l'ensemble contenant x
    // Étape 1 : version naïve (boucle while)
    // Étape 3 : version avec compression de chemin
    int find(int x);

    // Fusionne les ensembles contenant x et y
    // Étape 1 : version naïve (parent[ry] = rx)
    // Étape 4 : version avec union par rang
    void unite(int x, int y);

    // Vérifie si x et y sont dans le même ensemble
    bool connected(int x, int y);

    // Étape 2 : compter le nombre de remontées de find(x)
    // (sans modifier parent[] — juste compter)
    int count_operations(int x);

    // Accesseur pour les tests (lecture seule)
    int getParent(int x) const;
};

#endif // UNION_FIND_H

// NOM : _______________  PRÉNOM : _______________
// TP1 — RéseauVAK : Représentations de graphes, BFS & DFS
// Fichier : graph.cpp — Implémentation de la classe Graph

#include "graph.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// ═══════════════════════════════════════════════════════════
// ÉTAPE 1 : FONDATION — Classe Graph
// ═══════════════════════════════════════════════════════════

// FONCTION 1.1 : Constructeur
// Objectif : initialiser un graphe vide à V sommets
Graph::Graph(int V, bool directed) : V(V), directed(directed), adjList(V), names(V) {
    // TODO : Initialiser names[i] = to_string(i) pour tout i de 0 à V-1
    //        (noms par défaut : "0", "1", "2", ...)
}

// FONCTION 1.2 : addEdge
// Objectif : ajouter une arête entre u et v
void Graph::addEdge(int u, int v) {
    // TODO 1 : Ajouter v dans adjList[u]
    // TODO 2 : Si le graphe est NON orienté (!directed),
    //          ajouter aussi u dans adjList[v]
}

// FONCTION 1.3 : loadFromFile
// Objectif : charger un graphe depuis un fichier texte
// Format du fichier :
//   Ligne 1 : V E              (nombre de sommets, nombre d'arêtes)
//   Ligne 2 : nom0 nom1 ...   (noms séparés par des espaces)
//   Lignes suivantes : u v     (une arête par ligne)
void Graph::loadFromFile(const string& filename) {
    // TODO 1 : Ouvrir le fichier avec ifstream
    //          Si échec, afficher une erreur et retourner

    // TODO 2 : Lire V et E

    // TODO 3 : Redimensionner adjList et names
    //          adjList.assign(V, {});
    //          names.resize(V);

    // TODO 4 : Lire les V noms

    // TODO 5 : Lire les E arêtes et appeler addEdge(u, v) pour chacune
}

// FONCTION 1.4 : Accesseurs
int Graph::getV() const {
    // TODO : Retourner V
    return 0;
}

bool Graph::isDirected() const {
    // TODO : Retourner directed
    return false;
}

const vector<int>& Graph::neighbors(int u) const {
    // TODO : Retourner adjList[u]
    static const vector<int> empty;
    return empty; // placeholder — remplacer par : return adjList[u];
}

const string& Graph::getName(int u) const {
    // TODO : Retourner names[u]
    static const string empty;
    return empty; // placeholder — remplacer par : return names[u];
}

// ═══════════════════════════════════════════════════════════
// ÉTAPE 2 : REPRÉSENTATIONS — Matrice & Affichage
// ═══════════════════════════════════════════════════════════

// FONCTION 2.1 : getAdjMatrix
// Objectif : construire la matrice d'adjacence à partir de la liste
vector<vector<int>> Graph::getAdjMatrix() const {
    // TODO 1 : Créer une matrice V×V initialisée à 0
    //          vector<vector<int>> matrix(V, vector<int>(V, 0));

    // TODO 2 : Pour chaque sommet u de 0 à V-1 :
    //            Pour chaque voisin v dans adjList[u] :
    //              matrix[u][v] = 1

    // TODO 3 : Retourner matrix

    return {}; // placeholder
}

// FONCTION 2.2 : printAdjList
// Objectif : afficher la liste d'adjacence
// Format : "Dossou (0) : Agbangla Hounénou Adjovi"
void Graph::printAdjList() const {
    // TODO : Pour chaque sommet u de 0 à V-1 :
    //   Afficher : names[u] + " (" + to_string(u) + ") : "
    //   Puis pour chaque voisin v : afficher names[v] + " "
    //   Terminer par un saut de ligne
}

// FONCTION 2.3 : printAdjMatrix
// Objectif : afficher la matrice d'adjacence avec noms en en-tête
// Format :
//       Dos Agb Hou ...
//  Dos   0   1   1  ...
//  Agb   1   0   1  ...
void Graph::printAdjMatrix() const {
    // TODO 1 : Récupérer la matrice via getAdjMatrix()

    // TODO 2 : Afficher la ligne d'en-tête
    //          (utiliser les 3 premiers caractères de chaque nom : names[i].substr(0, 3))

    // TODO 3 : Pour chaque ligne, afficher le nom (3 car.) puis les valeurs
    //          Utiliser setw(4) de <iomanip> pour aligner
}

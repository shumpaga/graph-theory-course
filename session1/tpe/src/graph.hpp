#ifndef GRAPH_HPP
#define GRAPH_HPP

/**
 * @file Graph.hpp
 * @brief Classe Graph - Représentation par liste d'adjacence
 * 
 * TPE1 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 * 
 * ⚠️ NE PAS MODIFIER CE FICHIER
 */

#include <vector>
#include <list>
#include <string>
#include <iostream>

class Graph {
private:
    int n_vertices;                        // Nombre de sommets
    int n_edges;                           // Nombre d'arêtes
    std::vector<std::list<int>> adj;       // Liste d'adjacence

public:
    // ============================================================
    // NIVEAU 1 : BASE (12 points)
    // ============================================================
    
    /**
     * @brief Constructeur - Crée un graphe avec n sommets (numérotés 0 à n-1)
     * @param n Nombre de sommets
     */
    Graph(int n);
    
    /**
     * @brief Ajoute une arête non-orientée entre u et v
     * 
     * RAPPEL: Graphe NON-ORIENTÉ = ajouter dans les DEUX sens !
     * 
     * @param u Premier sommet
     * @param v Second sommet
     */
    void addEdge(int u, int v);
    
    /**
     * @brief Affiche le graphe (liste d'adjacence)
     * 
     * Format: "v -> [voisin1, voisin2, ...]"
     */
    void display() const;
    
    /**
     * @brief Retourne l'ordre du graphe (nombre de sommets)
     * @return Nombre de sommets
     */
    int order() const;
    
    /**
     * @brief Retourne la taille du graphe (nombre d'arêtes)
     * @return Nombre d'arêtes
     */
    int size() const;
    
    /**
     * @brief Retourne le degré d'un sommet (nombre de voisins)
     * @param v Le sommet
     * @return Degré du sommet, ou -1 si sommet invalide
     */
    int degree(int v) const;
    
    // ============================================================
    // NIVEAU 2 : STANDARD (5 points)
    // ============================================================
    
    /**
     * @brief Vérifie si une arête existe entre u et v
     * @param u Premier sommet
     * @param v Second sommet
     * @return true si l'arête existe, false sinon
     */
    bool hasEdge(int u, int v) const;
    
    /**
     * @brief Retourne la liste des voisins d'un sommet
     * @param v Le sommet
     * @return Vector contenant les identifiants des voisins
     */
    std::vector<int> neighbors(int v) const;
    
    // ============================================================
    // NIVEAU 3 : AVANCÉ (3 points + BONUS)
    // ============================================================
    
    /**
     * @brief Supprime une arête entre u et v (3 points)
     * 
     * RAPPEL: Supprimer dans les DEUX sens !
     * 
     * @param u Premier sommet
     * @param v Second sommet
     */
    void removeEdge(int u, int v);
    
    /**
     * @brief BONUS (+2 points) - Charge un graphe depuis un fichier
     * @param filename Chemin du fichier
     * @return true si chargement réussi, false sinon
     * 
     * Format du fichier (voir graphe_test.txt):
     * - Ligne 1: nombre de sommets n
     * - Lignes suivantes: "u v" pour chaque arête
     */
    bool loadFromFile(const std::string& filename);
};

#endif // GRAPH_HPP

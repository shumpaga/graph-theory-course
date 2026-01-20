/**
 * @file Graph.cpp
 * @brief Implémentation de la classe Graph
 * 
 * TPE1 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 * 
 * ╔════════════════════════════════════════════════════════════════╗
 * ║  FICHIER À COMPLÉTER                                          ║
 * ║  Remplissez les zones marquées TODO (12 au total)             ║
 * ╚════════════════════════════════════════════════════════════════╝
 * 
 * VOTRE NOM : _______________________
 * VOTRE PRÉNOM : ____________________
 */

#include "graph.hpp"
#include <algorithm>  // pour std::find
#include <fstream>    // pour fichiers (Niveau 3)

// ════════════════════════════════════════════════════════════════════
// NIVEAU 1 : BASE (12 points)
// ════════════════════════════════════════════════════════════════════

/**
 * Constructeur : crée un graphe avec n sommets (0 à n-1)
 * Chaque sommet commence avec une liste de voisins vide.
 * 
 * ✅ DÉJÀ IMPLÉMENTÉ - Ne pas modifier
 */
Graph::Graph(int n) : n_vertices(n), n_edges(0), adj(n) {
    // n_vertices = n        → nombre de sommets
    // n_edges = 0           → pas encore d'arêtes
    // adj(n)                → crée n listes vides
}

/**
 * Ajoute une arête non-orientée entre les sommets u et v.
 * 
 * ╔═══════════════════════════════════════════════════════════════╗
 * ║  ⚠️ PIÈGE #1 : N'oubliez pas les DEUX directions !           ║
 * ║  ⚠️ PIÈGE #2 : Incrémentez n_edges UNE SEULE fois !          ║
 * ╚═══════════════════════════════════════════════════════════════╝
 */
void Graph::addEdge(int u, int v) {
    // Vérification des bornes (déjà fait pour vous)
    if (u < 0 || u >= n_vertices || v < 0 || v >= n_vertices) {
        std::cerr << "Erreur: sommet invalide (" << u << ", " << v << ")" << std::endl;
        return;
    }
    
    // ┌─────────────────────────────────────────────────────────────┐
    // │ TODO 1: Ajouter v à la liste des voisins de u              │
    // │ Indice: adj[u].push_back(v);                               │
    // └─────────────────────────────────────────────────────────────┘
    
    
    // ┌─────────────────────────────────────────────────────────────┐
    // │ TODO 2: Ajouter u à la liste des voisins de v              │
    // │ ⚠️ CRUCIAL: Graphe NON-ORIENTÉ = arête dans les DEUX sens! │
    // └─────────────────────────────────────────────────────────────┘
    
    
    // ┌─────────────────────────────────────────────────────────────┐
    // │ TODO 3: Incrémenter le compteur d'arêtes                   │
    // │ ⚠️ ATTENTION: UNE SEULE FOIS (pas deux !)                  │
    // └─────────────────────────────────────────────────────────────┘
    
}

/**
 * Affiche le graphe sous forme de liste d'adjacence.
 * Format attendu: "v -> [voisin1, voisin2]"
 * 
 * ╔═══════════════════════════════════════════════════════════════╗
 * ║  ⚠️ PIÈGE #3 : Pas de virgule après le dernier voisin !      ║
 * ║  Bon:  "0 -> [1, 2]"                                         ║
 * ║  Faux: "0 -> [1, 2, ]"                                       ║
 * ╚═══════════════════════════════════════════════════════════════╝
 */
void Graph::display() const {
    std::cout << "Graphe: " << order() << " sommets, " 
              << size() << " aretes" << std::endl;
    
    for (int v = 0; v < n_vertices; v++) {
        std::cout << v << " -> [";
        
        // ┌─────────────────────────────────────────────────────────────┐
        // │ TODO 4: Afficher les voisins de v, séparés par ", "        │
        // │                                                             │
        // │ ASTUCE pour éviter la virgule finale:                       │
        // │   bool first = true;                                        │
        // │   for (int voisin : adj[v]) {                               │
        // │       if (!first) std::cout << ", ";                        │
        // │       std::cout << voisin;                                  │
        // │       first = false;                                        │
        // │   }                                                         │
        // └─────────────────────────────────────────────────────────────┘
        
        
        std::cout << "]" << std::endl;
    }
}

/**
 * Retourne l'ordre du graphe (nombre de sommets).
 */
int Graph::order() const {
    // ┌─────────────────────────────────────────────────────────────┐
    // │ TODO 5: Retourner le nombre de sommets                     │
    // │ Indice: c'est stocké dans n_vertices                       │
    // └─────────────────────────────────────────────────────────────┘
    
    return 0;  // ← À MODIFIER
}

/**
 * Retourne la taille du graphe (nombre d'arêtes).
 */
int Graph::size() const {
    // ┌─────────────────────────────────────────────────────────────┐
    // │ TODO 6: Retourner le nombre d'arêtes                       │
    // │ Indice: c'est stocké dans n_edges                          │
    // └─────────────────────────────────────────────────────────────┘
    
    return 0;  // ← À MODIFIER
}

/**
 * Retourne le degré d'un sommet (nombre de voisins).
 * 
 * ╔═══════════════════════════════════════════════════════════════╗
 * ║  ⚠️ PIÈGE #4 : La vérification des bornes est DÉJÀ FAITE !   ║
 * ╚═══════════════════════════════════════════════════════════════╝
 */
int Graph::degree(int v) const {
    // Vérification des bornes (déjà fait)
    if (v < 0 || v >= n_vertices) {
        return -1;  // Sommet invalide
    }
    
    // ┌─────────────────────────────────────────────────────────────┐
    // │ TODO 7: Retourner le nombre de voisins de v                │
    // │ Indice: c'est la taille de la liste adj[v]                 │
    // │ Utilisez: adj[v].size()                                    │
    // └─────────────────────────────────────────────────────────────┘
    
    return 0;  // ← À MODIFIER
}

// ════════════════════════════════════════════════════════════════════
// NIVEAU 2 : STANDARD (5 points)
// ════════════════════════════════════════════════════════════════════

/**
 * Vérifie si une arête existe entre u et v.
 * 
 * Dans un graphe non-orienté, il suffit de vérifier
 * si v est dans la liste des voisins de u.
 */
bool Graph::hasEdge(int u, int v) const {
    // Vérification des bornes
    if (u < 0 || u >= n_vertices || v < 0 || v >= n_vertices) {
        return false;
    }
    
    // ┌─────────────────────────────────────────────────────────────┐
    // │ TODO 8: Vérifier si v est dans la liste adj[u]             │
    // │                                                             │
    // │ Méthode 1 (avec std::find):                                │
    // │   return std::find(adj[u].begin(), adj[u].end(), v)        │
    // │          != adj[u].end();                                  │
    // │                                                             │
    // │ Méthode 2 (avec boucle):                                   │
    // │   for (int voisin : adj[u]) {                              │
    // │       if (voisin == v) return true;                        │
    // │   }                                                         │
    // │   return false;                                             │
    // └─────────────────────────────────────────────────────────────┘
    
    return false;  // ← À MODIFIER
}

/**
 * Retourne un vector contenant tous les voisins d'un sommet.
 */
std::vector<int> Graph::neighbors(int v) const {
    std::vector<int> result;
    
    // Vérification des bornes
    if (v < 0 || v >= n_vertices) {
        return result;  // Vector vide
    }
    
    // ┌─────────────────────────────────────────────────────────────┐
    // │ TODO 9: Copier les voisins de v dans result                │
    // │                                                             │
    // │ Indice:                                                     │
    // │   for (int voisin : adj[v]) {                              │
    // │       result.push_back(voisin);                            │
    // │   }                                                         │
    // └─────────────────────────────────────────────────────────────┘
    
    
    return result;
}

// ════════════════════════════════════════════════════════════════════
// NIVEAU 3 : AVANCÉ (3 points + BONUS)
// ════════════════════════════════════════════════════════════════════

/**
 * Supprime l'arête entre u et v. (3 points)
 * 
 * RAPPEL: Dans un graphe non-orienté, il faut supprimer
 * v de la liste de u ET u de la liste de v.
 */
void Graph::removeEdge(int u, int v) {
    // Vérifier que l'arête existe
    if (!hasEdge(u, v)) {
        return;  // Rien à supprimer
    }
    
    // ┌─────────────────────────────────────────────────────────────┐
    // │ TODO 10: Retirer v de la liste adj[u]                      │
    // │ Indice: adj[u].remove(v);                                  │
    // └─────────────────────────────────────────────────────────────┘
    
    
    // ┌─────────────────────────────────────────────────────────────┐
    // │ TODO 11: Retirer u de la liste adj[v]                      │
    // │ (N'oubliez pas : graphe non-orienté !)                     │
    // └─────────────────────────────────────────────────────────────┘
    
    
    // Décrémenter le compteur d'arêtes
    // n_edges--;  // ← À décommenter quand TODO 10 et 11 sont faits
}

/**
 * BONUS (+2 points) : Charge un graphe depuis un fichier texte.
 * 
 * Format du fichier (voir graphe_test.txt):
 *   5          ← nombre de sommets
 *   0 1        ← arête entre 0 et 1
 *   0 2        ← arête entre 0 et 2
 *   1 3        ← etc.
 */
bool Graph::loadFromFile(const std::string& filename) {
    // ┌─────────────────────────────────────────────────────────────┐
    // │ TODO 12 (BONUS): Implémenter le chargement depuis fichier  │
    // │                                                             │
    // │ Étapes:                                                     │
    // │ 1. Ouvrir le fichier:                                       │
    // │    std::ifstream file(filename);                           │
    // │    if (!file.is_open()) return false;                      │
    // │                                                             │
    // │ 2. Lire le nombre de sommets:                               │
    // │    int n;                                                   │
    // │    file >> n;                                               │
    // │                                                             │
    // │ 3. Réinitialiser le graphe:                                │
    // │    n_vertices = n;                                          │
    // │    n_edges = 0;                                             │
    // │    adj.clear();                                             │
    // │    adj.resize(n);                                           │
    // │                                                             │
    // │ 4. Lire les arêtes en boucle:                              │
    // │    int u, v;                                                │
    // │    while (file >> u >> v) {                                │
    // │        addEdge(u, v);                                       │
    // │    }                                                        │
    // │                                                             │
    // │ 5. Fermer et retourner true                                │
    // │    file.close();                                            │
    // │    return true;                                             │
    // └─────────────────────────────────────────────────────────────┘
    
    return false;  // ← À MODIFIER
}

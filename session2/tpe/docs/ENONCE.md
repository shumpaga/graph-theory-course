# TPE2 - Parcours en Largeur (BFS)

## ESGC VERECHAGUINE A.K. - Année 2025-2026
**Enseignant :** M. Alexandre GBAGUIDI AISSE
**Niveau :** Licence 2 - Génie Informatique
**Cours :** Théorie des Graphes - Séance 2

---

## 📋 Informations Générales

**Date de distribution :** Séance 2
**Date de rendu :** [À définir par l'enseignant]
**Durée estimée :** 6-8 heures de travail
**Mode :** Individuel
**Barème :** 25 points + 2 points bonus

---

## 🎯 Objectifs Pédagogiques

À l'issue de ce TPE, vous serez capable de :

1. **Comprendre** l'algorithme de parcours en largeur (BFS)
2. **Implémenter** le BFS et ses applications classiques
3. **Analyser** la complexité temporelle et spatiale
4. **Appliquer** le BFS à des problèmes concrets
5. **Utiliser** des structures de données appropriées (Queue, vecteurs)

---

## 📖 Contexte

Le parcours en largeur (Breadth-First Search - BFS) est l'un des algorithmes fondamentaux en théorie des graphes. Contrairement au DFS qui explore en profondeur, le BFS explore le graphe niveau par niveau, ce qui en fait l'algorithme idéal pour :

- Trouver le **plus court chemin** dans un graphe non pondéré
- Calculer les **distances minimales** depuis une source
- Tester la **connexité** d'un graphe
- Détecter les **graphes bipartis**

### Applications Pratiques

- **Réseaux sociaux** : Trouver le degré de séparation entre deux personnes
- **GPS et navigation** : Plus court chemin dans un réseau routier
- **Réseaux informatiques** : Routage de paquets
- **Jeux** : Résolution de puzzles (Rubik's cube, 8-puzzle)

---

## 📦 Structure du Projet

```
TPE2_BFS/
├── src/
│   ├── graph.h          # Classe Graph (FOURNI - NE PAS MODIFIER)
│   ├── graph.cpp        # Implémentation Graph (FOURNI)
│   ├── queue.h          # Classe Queue (FOURNI - NE PAS MODIFIER)
│   ├── queue.cpp        # Implémentation Queue (FOURNI)
│   ├── bfs.h            # En-têtes des fonctions BFS (FOURNI - NE PAS MODIFIER)
│   ├── bfs.cpp          # À COMPLÉTER : Vos implémentations
│   └── main.cpp         # Programme principal de test
├── tests/
│   └── test_bfs.cpp     # Tests automatiques
├── data/
│   ├── graph_simple.txt        # Graphe connexe simple (5 sommets)
│   ├── graph_disconnected.txt  # Graphe déconnecté (10 sommets, 3 composantes)
│   ├── graph_bipartite.txt     # Graphe biparti (6 sommets)
│   └── graph_cotonou.txt       # Graphe plus complexe (15 sommets)
├── docs/
│   ├── ENONCE.md        # Ce fichier
│   └── BAREME.md        # Détails du barème
├── Makefile             # Compilation automatique
├── .gitignore
└── README.md
```

---

## 🛠️ Outils Fournis

### 1. Classe Graph

La classe `Graph` représente un graphe par **liste d'adjacence**. Elle fournit :

- `Graph(int vertices, bool isDirected)` : Constructeur
- `void addEdge(int u, int v)` : Ajouter une arête
- `vector<int> getNeighbors(int vertex)` : Obtenir les voisins d'un sommet
- `int getVertexCount()` : Nombre de sommets
- `bool isDirected()` : Type de graphe
- `static Graph loadFromFile(const string& filename)` : Charger depuis un fichier

**Format des fichiers graphes :**
```
V E directed
u1 v1
u2 v2
...
```

Exemple (`graph_simple.txt`) :
```
5 6 0
0 1
0 2
1 3
2 3
2 4
3 4
```

### 2. Classe Queue

Une file FIFO (First In, First Out) implémentée avec un `vector` :

- `void push(int x)` : Enfiler un élément - O(1)
- `int pop()` : Défiler et retourner le premier élément - O(1)
- `int front()` : Voir le premier élément - O(1)
- `bool empty()` : Tester si vide - O(1)

**⚠️ IMPORTANT :** Vous devez utiliser cette classe `Queue`, **PAS** `std::queue` de la STL.

---

## 📝 Travail à Réaliser

Vous devez compléter le fichier `src/bfs.cpp` en implémentant **7 fonctions** réparties en 3 niveaux de difficulté.

### ✅ NIVEAU BASE (10 points)

#### Fonction 1 : Parcours BFS Simple (3 points)

```cpp
void bfs(Graph& g, int source);
```

**Objectif :** Effectuer un parcours en largeur depuis `source` et afficher l'ordre de visite.

**Algorithme :**
1. Créer une Queue Q et un vector<bool> visited(V, false)
2. Marquer source comme visité et l'enfiler
3. Tant que Q n'est pas vide :
   - Défiler u
   - Afficher u
   - Pour chaque voisin v de u non visité :
     - Marquer v visité et l'enfiler

**Exemple :**
```
Graphe : 0-1-2-3, 0-2, 2-4, 3-4
BFS depuis 0 : 0 1 2 3 4
```

**Complexité attendue :** O(V + E)

---

#### Fonction 2 : Calcul des Distances Minimales (3 points)

```cpp
vector<int> bfs_distances(Graph& g, int source);
```

**Objectif :** Calculer la distance minimale de `source` à tous les autres sommets.

**Algorithme :**
1. Créer distance(V, -1) et visited(V, false)
2. Initialiser distance[source] = 0
3. BFS en mettant à jour : distance[v] = distance[u] + 1

**Exemple :**
```
Graphe : 0-1-2-3
bfs_distances(g, 0) = [0, 1, 2, 3]
```

**Complexité attendue :** O(V + E)

---

#### Fonction 3 : Affichage de l'Arbre BFS (4 points)

```cpp
void print_bfs_tree(Graph& g, int source);
```

**Objectif :** Construire et afficher l'arbre de parcours BFS.

**Algorithme :**
1. BFS en gardant parent[v] pour chaque sommet
2. Regrouper les enfants par parent (map<int, vector<int>>)
3. Afficher chaque parent avec ses enfants

**Format d'affichage :**
```
Arbre BFS depuis 0 :
0 → 1, 2
1 → 3
2 → 4
```

**Complexité attendue :** O(V + E)

---

### ✅ NIVEAU STANDARD (10 points)

#### Fonction 4 : Plus Court Chemin (3 points)

```cpp
vector<int> shortest_path(Graph& g, int source, int dest);
```

**Objectif :** Reconstruire le plus court chemin de `source` à `dest`.

**Algorithme :**
1. BFS avec parent[v]
2. Si dest atteignable : remonter de dest à source
3. Inverser le chemin
4. Sinon : retourner vecteur vide

**Exemple :**
```
Graphe : 0-1-2-3
shortest_path(g, 0, 3) = [0, 1, 2, 3]
```

**Complexité attendue :** O(V + E)

---

#### Fonction 5 : Test de Connexité (3 points)

```cpp
bool is_connected(Graph& g);
```

**Objectif :** Déterminer si le graphe est connexe.

**Algorithme :**
1. BFS depuis le sommet 0
2. Compter le nombre de sommets visités
3. Retourner (nombre_visités == V)

**Définition :** Un graphe est connexe si tous les sommets sont atteignables depuis n'importe quel sommet.

**Complexité attendue :** O(V + E)

---

#### Fonction 6 : Comptage des Composantes Connexes (4 points)

```cpp
int count_components(Graph& g);
```

**Objectif :** Compter le nombre de composantes connexes.

**Algorithme :**
1. Créer visited(V, false), count = 0
2. Pour chaque sommet v :
   - Si v non visité :
     - BFS depuis v
     - Incrémenter count
3. Retourner count

**Exemple :**
```
Graphe : 0-1  2-3  4
count_components(g) = 3
```

**Complexité attendue :** O(V + E)

---

### ✅ NIVEAU BONUS (5 points)

#### Fonction 7 : Test de Graphe Biparti (5 points)

```cpp
bool is_bipartite(Graph& g);
```

**Objectif :** Déterminer si le graphe est biparti (2-colorable).

**Algorithme :**
1. Créer color(V, -1)
2. Pour chaque composante :
   - BFS avec coloration alternée (0 et 1)
   - Si deux voisins ont la même couleur : retourner false
3. Retourner true

**Propriété Théorique :** Un graphe est biparti ⟺ il ne contient pas de cycle de longueur impaire.

**Exemples :**
```
Cycle de longueur 4 : 0-1-2-3-0 → biparti
Triangle : 0-1-2-0 → NON biparti
```

**Complexité attendue :** O(V + E)

---

## 🚀 Compilation et Exécution

### Compilation

```bash
# Compiler le programme principal
make

# Compiler les tests
make test_bfs
```

### Exécution

```bash
# Programme interactif avec menu
./main data/graph_simple.txt

# Tests automatiques
./test_bfs
```

### Nettoyage

```bash
make clean
```

---

## 📊 Graphes de Test

### 1. graph_simple.txt (5 sommets, 6 arêtes)

Graphe connexe simple pour tester les fonctions de base.

```
    0 ─── 1
    │     │
    │     3
    │   ╱ │
    2 ─── 4
```

### 2. graph_disconnected.txt (10 sommets, 8 arêtes)

Graphe avec 3 composantes connexes pour tester la connexité.

```
Composante 1: 0-1-2
Composante 2: 3-4-5-6
Composante 3: 7-8-9
```

### 3. graph_bipartite.txt (6 sommets, 7 arêtes)

Graphe biparti pour tester la fonction bonus.

```
Ensemble A: {0, 2, 5}
Ensemble B: {1, 3, 4}
```

### 4. graph_cotonou.txt (15 sommets, 18 arêtes)

Graphe plus complexe représentant un réseau (inspiré du réseau routier).

---

## 📋 Livrables

### Fichiers à Rendre

1. **src/bfs.cpp** : Votre implémentation complète
2. **README_ETUDIANT.md** (optionnel) : Vos remarques, difficultés rencontrées

### Format de Rendu

- **Archive :** `NOM_Prenom_TPE2_BFS.zip`
- Contenu : Tout le dossier `TPE2_BFS/` avec vos modifications

### ⚠️ Règles Importantes

1. **NE PAS MODIFIER** les fichiers `.h` (graph.h, queue.h, bfs.h)
2. **NE PAS MODIFIER** graph.cpp et queue.cpp
3. **Respecter** les signatures des fonctions dans bfs.h
4. **Utiliser** la classe Queue fournie (pas std::queue)
5. **Commenter** votre code pour le bonus +2 pts

---

## 🎯 Critères d'Évaluation

Voir le fichier `docs/BAREME.md` pour les détails complets.

### Répartition des Points

| Niveau | Fonction | Points |
|--------|----------|--------|
| BASE | 1. BFS simple | 3 pts |
| BASE | 2. Distances minimales | 3 pts |
| BASE | 3. Arbre BFS | 4 pts |
| STANDARD | 4. Plus court chemin | 3 pts |
| STANDARD | 5. Test connexité | 3 pts |
| STANDARD | 6. Composantes connexes | 4 pts |
| BONUS | 7. Test biparti | 5 pts |
| BONUS | Code commenté | +2 pts |
| **TOTAL** | | **25 + 2 pts** |

---

## 💡 Conseils Méthodologiques

### Stratégie de Travail

1. **Commencez par la fonction 1 (BFS simple)**
   - C'est la base de toutes les autres fonctions
   - Testez-la immédiatement avec `./main data/graph_simple.txt`

2. **Progressez dans l'ordre**
   - Chaque fonction réutilise les concepts de la précédente
   - Ne passez pas à la suivante sans avoir testé

3. **Utilisez les tests automatiques**
   - `make test` après chaque fonction
   - Les tests vous indiquent exactement ce qui ne fonctionne pas

4. **Testez avec tous les graphes**
   - graph_simple.txt : cas de base
   - graph_disconnected.txt : cas avec composantes
   - graph_bipartite.txt : cas biparti
   - graph_cotonou.txt : cas complexe

### Débogage

1. **Affichage intermédiaire**
   ```cpp
   cout << "DEBUG: Visite du sommet " << u << endl;
   ```

2. **Vérification de la Queue**
   ```cpp
   cout << "Queue size: " << Q.size() << endl;
   ```

3. **Validation des tableaux**
   ```cpp
   for (int i = 0; i < V; i++) {
       cout << "visited[" << i << "] = " << visited[i] << endl;
   }
   ```

### Pièges à Éviter

1. ❌ **Oublier de marquer un sommet visité avant de l'enfiler**
   → Risque de boucle infinie

2. ❌ **Utiliser std::queue au lieu de la classe Queue fournie**
   → Pénalité sur la note

3. ❌ **Ne pas initialiser les vecteurs correctement**
   ```cpp
   vector<int> distance(V, -1);  // ✓ Correct
   vector<int> distance(V);      // ✗ Non initialisé
   ```

4. ❌ **Ne pas gérer les sommets inatteignables**
   → Vérifier distance[v] == -1 ou parent[v] == -1

5. ❌ **Oublier le cas où source == dest**
   → Le chemin le plus court de v à v est [v]

---

## 📚 Ressources

### Cours et Support

- Slides du cours (Séance 2 : BFS)
- Notes de cours (Théorie des Graphes)
- Corrections des exercices (Séance 1 : DFS)

### Algorithme BFS - Pseudocode

```
BFS(G, source):
    créer Queue Q
    créer visited[V] initialisé à false

    visited[source] = true
    Q.push(source)

    tant que Q non vide:
        u = Q.pop()
        traiter u

        pour chaque voisin v de u:
            si non visited[v]:
                visited[v] = true
                Q.push(v)
```

### Complexité

- **Temporelle :** O(V + E)
  - Chaque sommet est enfilé/défilé une fois : O(V)
  - Chaque arête est explorée une fois : O(E)

- **Spatiale :** O(V)
  - Queue : au pire O(V)
  - Tableaux visited, distance, parent : O(V)

---

## ❓ FAQ

### Questions Fréquentes

**Q1 : Puis-je utiliser std::queue de la STL ?**
R : Non, vous devez utiliser la classe Queue fournie. C'est une contrainte du TPE.

**Q2 : Que faire si le graphe est vide (V = 0) ?**
R : Cas particuliers à gérer :
- is_connected : retourner true (par convention)
- count_components : retourner 0

**Q3 : Pour is_bipartite, comment gérer un graphe déconnecté ?**
R : Tester chaque composante séparément. Le graphe est biparti si toutes les composantes sont bipartis.

**Q4 : Comment afficher l'arbre BFS si le graphe est déconnecté ?**
R : Afficher uniquement les sommets de la composante contenant source.

**Q5 : Puis-je créer des fonctions auxiliaires ?**
R : Oui ! C'est même recommandé pour éviter la duplication de code.

**Q6 : Mon BFS affiche les sommets dans un ordre différent des solutions ?**
R : C'est normal ! L'ordre exact dépend de l'implémentation. Ce qui compte :
- Tous les sommets de distance d sont visités avant ceux de distance d+1
- Pas de doublons

---

## 📞 Contact

Pour toute question sur le TPE :

- **Enseignant :** M. Alexandre GBAGUIDI AISSE
- **Email :** [Email de l'enseignant]
- **Heures de permanence :** [À définir]

---

## 📅 Planning Suggéré

Pour un rendu dans 2 semaines :

| Semaine | Travail |
|---------|---------|
| **Semaine 1** | Fonctions 1-3 (Niveau BASE) |
| | Jour 1-2 : Fonction 1 (BFS simple) |
| | Jour 3-4 : Fonction 2 (Distances) |
| | Jour 5-7 : Fonction 3 (Arbre BFS) |
| **Semaine 2** | Fonctions 4-7 (STANDARD + BONUS) |
| | Jour 1-2 : Fonction 4 (Plus court chemin) |
| | Jour 3-4 : Fonctions 5-6 (Connexité) |
| | Jour 5-6 : Fonction 7 (Biparti - BONUS) |
| | Jour 7 : Tests finaux et documentation |

---

## 🎓 Compétences Visées

Ce TPE vous permet de développer :

### Compétences Techniques
- Implémentation d'algorithmes de graphes
- Manipulation de structures de données (Queue, vecteurs)
- Gestion de la complexité algorithmique
- Debugging et tests

### Compétences Transversales
- Rigueur et méthodologie
- Autonomie dans la résolution de problèmes
- Documentation de code
- Respect des spécifications

---

**Bon courage pour votre TPE ! 🚀**

---

*ESGC VERECHAGUINE A.K. - Théorie des Graphes - L2 GI - 2025-2026*

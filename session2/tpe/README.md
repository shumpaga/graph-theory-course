# TPE2 - Parcours en Largeur (BFS)

## Théorie des Graphes - L2 Génie Informatique

**Institution** : ESGC VERECHAGUINE A.K. (Cotonou, Bénin)
**Enseignant** : M. Alexandre GBAGUIDI AISSE
**Année académique** : 2025-2026
**Durée** : 1h20 en séance + temps libre

---

## 🎯 Objectifs

Implémenter l'algorithme de **parcours en largeur (Breadth-First Search - BFS)** et ses applications principales :
- Parcours de graphe
- Calcul de distances minimales
- Plus courts chemins
- Test de connexité
- Comptage de composantes connexes
- Test de graphe biparti

---

## 📊 Barème

| Niveau | Points | Fonctions |
|--------|--------|-----------|
| **BASE** | 10 pts | bfs(), bfs_distances(), print_bfs_tree() |
| **STANDARD** | 10 pts | shortest_path(), is_connected(), count_components() |
| **BONUS** | 5 pts | is_bipartite() |
| **BONUS CODE** | +2 pts | Code très bien commenté et structuré |
| **TOTAL** | **27 pts** | (Note ramenée sur 25) |

---

## 🚀 Démarrage rapide

### Prérequis

- Compilateur C++17 (g++, clang++)
- Make
- Terminal

### Compilation

```bash
# Compiler le programme
make

# Compiler et lancer les tests
make test

# Nettoyer
make clean

# Aide
make help
```

### Exécution

```bash
# Avec le graphe simple
./main data/graph_simple.txt

# Avec le graphe de Cotonou (Gozem)
./main data/graph_cotonou.txt
```

---

## 📁 Structure du projet

```
TPE2_BFS/
├── README.md                    ← Ce fichier
├── Makefile                     ← Compilation
├── .gitignore
│
├── src/
│   ├── graph.h / graph.cpp      ← Classe Graph (fournie)
│   ├── queue.h / queue.cpp      ← Classe Queue (fournie)
│   ├── bfs.h / bfs.cpp          ← BFS (à compléter - TODO)
│   └── main.cpp                 ← Programme principal
│
├── tests/
│   └── test_bfs.cpp             ← Tests automatiques
│
├── data/
│   ├── graph_simple.txt         ← Graphe simple (5 sommets)
│   ├── graph_disconnected.txt   ← Graphe avec 3 composantes
│   ├── graph_bipartite.txt      ← Graphe biparti
│   └── graph_cotonou.txt        ← Réseau Gozem Cotonou (15 stations)
│
└── docs/
    ├── ENONCE.md                ← Énoncé détaillé
    └── BAREME.md                ← Détails du barème
```

---

## ✏️ Travail à effectuer

### Fichiers fournis (ne pas modifier)

- ✅ `graph.h / graph.cpp` - Classe Graph complète
- ✅ `queue.h / queue.cpp` - File FIFO complète
- ✅ `bfs.h` - Signatures des fonctions BFS

### Fichiers à compléter (votre travail)

- ❌ **`src/bfs.cpp`** - Implémenter les 7 fonctions BFS

Ouvrez `src/bfs.cpp` et complétez les TODO :

#### NIVEAU BASE (10 pts)

1. **`void bfs(Graph& g, int source)`** (3 pts)
   - Parcours en largeur simple
   - Affiche l'ordre de visite

2. **`vector<int> bfs_distances(Graph& g, int source)`** (3 pts)
   - Calcule les distances minimales depuis source
   - Retourne un vecteur de distances

3. **`void print_bfs_tree(Graph& g, int source)`** (4 pts)
   - Construit et affiche l'arbre BFS
   - Format : "parent → enfants"

#### NIVEAU STANDARD (10 pts)

4. **`vector<int> shortest_path(Graph& g, int source, int dest)`** (3 pts)
   - Reconstruit le plus court chemin
   - Retourne le chemin ou vecteur vide

5. **`bool is_connected(Graph& g)`** (3 pts)
   - Teste si le graphe est connexe

6. **`int count_components(Graph& g)`** (4 pts)
   - Compte les composantes connexes

#### NIVEAU BONUS (5 pts)

7. **`bool is_bipartite(Graph& g)`** (5 pts)
   - Teste si le graphe est 2-colorable (biparti)

---

## 🧪 Tests

### Lancer les tests automatiques

```bash
make test
```

Les tests vérifient chaque fonction sur différents graphes.

### Tester manuellement

Utilisez le programme principal avec les graphes fournis :

```bash
./main data/graph_simple.txt
./main data/graph_disconnected.txt
./main data/graph_bipartite.txt
./main data/graph_cotonou.txt
```

---

## 📝 Format des fichiers de graphes

```
V E directed
u1 v1
u2 v2
...
```

Où :
- `V` : nombre de sommets (0 à V-1)
- `E` : nombre d'arêtes
- `directed` : 0 (non-orienté) ou 1 (orienté)

### Exemple

```
5 6 0
0 1
0 2
1 3
2 3
2 4
3 4
```

Graphe non-orienté avec 5 sommets et 6 arêtes.

---

## 💡 Conseils

### Méthodologie

1. **Commencez par le NIVEAU BASE** - Ne passez au suivant que quand les tests passent
2. **Testez après chaque fonction** - `make test` à chaque étape
3. **Lisez les instructions** - Chaque TODO contient des étapes détaillées
4. **Dessinez sur papier** - Visualisez le BFS avant de coder
5. **Utilisez les exemples** - Testez avec `graph_simple.txt` d'abord

### Algorithme BFS (rappel)

```
BFS(G, source):
    Créer Queue Q
    Créer visited[V] = false
    visited[source] = true
    Q.push(source)

    Tant que Q non vide:
        u = Q.pop()
        Pour chaque voisin v de u:
            Si v non visité:
                visited[v] = true
                Q.push(v)
```

### Erreurs fréquentes

❌ **Oublier de marquer un sommet comme visité avant de l'enfiler**
✅ Toujours : `visited[v] = true` PUIS `Q.push(v)`

❌ **Utiliser `std::queue` de la STL**
✅ Utiliser notre classe `Queue` définie dans `queue.h`

❌ **Ne pas initialiser les distances à -1**
✅ `vector<int> distance(V, -1)` pour marquer "non atteignable"

---

## 📚 Complexités attendues

| Fonction | Complexité |
|----------|-----------|
| `bfs()` | O(V + E) |
| `bfs_distances()` | O(V + E) |
| `print_bfs_tree()` | O(V + E) |
| `shortest_path()` | O(V + E) |
| `is_connected()` | O(V + E) |
| `count_components()` | O(V + E) |
| `is_bipartite()` | O(V + E) |

Où V = nombre de sommets, E = nombre d'arêtes.

---

## 📦 Livrables

### À rendre (deadline : début Séance 3)

Créer un ZIP nommé : **`NOM_Prenom_TPE2.zip`**

Contenu :
- `bfs.cpp` complété
- Capture d'écran des tests passés (`make test`)

### Modalités

- Format : ZIP uniquement
- Taille max : 5 MB
- Soumission : Email ou plateforme (à préciser)

---

## 🎓 Contexte : Réseau Gozem Cotonou

Le fichier `graph_cotonou.txt` représente un réseau de transport simplifié de Gozem à Cotonou avec 15 stations :

```
0: Étoile Rouge          5: Cadjèhoun         10: Centre-ville
1: Akpakpa               6: Palais            11: Port Autonome
2: Ganhi                 7: Stade Amitié      12: Université
3: Fidjrossè             8: Aéroport          13: Cocotiers
4: Dantokpa              9: Zone Industrielle 14: Haie Vive
```

Utilisez BFS pour :
- Trouver le chemin le plus court entre 2 stations
- Calculer les distances minimales depuis l'Étoile Rouge
- Vérifier la connexité du réseau

---

## 📧 Contact

**Enseignant** : M. Alexandre GBAGUIDI AISSE
**Email** : À préciser
**Heures de consultation** : À préciser

---

## 🏆 Critères de notation

### Code (25 pts)

- BASE : 10 pts
- STANDARD : 10 pts
- BONUS : 5 pts

### Qualité (+2 pts bonus)

- Code bien commenté
- Nommage clair des variables
- Structure propre
- Gestion d'erreurs

### Pénalités

- Code qui ne compile pas : -10 pts
- Utilisation de `std::queue` : -5 pts
- Plagiat : 0/25

---

**Bon courage ! 🚀**

*L'algorithme BFS est fondamental en informatique. Il est utilisé dans les GPS, les réseaux sociaux, les jeux vidéo, et bien d'autres domaines !*

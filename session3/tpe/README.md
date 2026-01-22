# TPE3 - Parcours en Profondeur (DFS)

## Théorie des Graphes - L2 Génie Informatique

**Institution** : ESGC VERECHAGUINE A.K. (Cotonou, Bénin)
**Enseignant** : M. Alexandre GBAGUIDI AISSE
**Année académique** : 2025-2026
**Durée** : 2-3 heures

---

## 🎯 Objectifs

Implémenter l'algorithme de **parcours en profondeur (Depth-First Search - DFS)** et ses applications :
- Parcours récursif et itératif
- Calcul de timestamps (temps de découverte/fin)
- Détection de cycles
- Tri topologique
- Recherche de chemins

---

## 📁 Structure du Projet

```
session3/tpe/
├── README.md                  ← Ce fichier
├── Makefile                   ← Compilation
├── src/
│   ├── graph.h/cpp           ✓ Classe Graph (fournie)
│   ├── stack.h/cpp           ✓ Classe Stack LIFO (fournie)
│   ├── dfs.h                 ✓ Signatures (fourni)
│   ├── dfs.cpp               ⚠️ À COMPLÉTER (6 fonctions)
│   └── main.cpp              ✓ Programme interactif (fourni)
├── tests/
│   └── test_dfs.cpp          ✓ 26 tests automatiques
├── data/
│   ├── graph_simple.txt      ✓ 6 sommets, tests BASE
│   ├── graph_dag.txt         ✓ DAG, tri topologique
│   ├── graph_cycle.txt       ✓ Avec cycle
│   └── graph_courses.txt     ✓ Prérequis cours GI2
└── docs/
    ├── ENONCE.md             ← Algorithmes détaillés
    └── BAREME.md             ← Grille de notation
```

---

## 🚀 Compilation et Tests

### Compilation
```bash
make clean       # Nettoyer
make            # Compiler le programme principal
make test       # Compiler les tests
```

### Exécution
```bash
# Tests automatiques (26 tests)
./test_dfs

# Programme interactif
./main data/graph_simple.txt
./main data/graph_dag.txt
```

### Aide
```bash
make help        # Liste des commandes disponibles
```

---

## 📝 Fonctions à Implémenter

Fichier : `src/dfs.cpp`

### NIVEAU BASE (10 points)

| # | Fonction | Points | Description |
|---|----------|--------|-------------|
| 1 | `dfs_recursive(g, source)` | 3 | Parcours récursif depuis source |
| 2 | `dfs_iterative(g, source)` | 3 | Parcours itératif avec pile |
| 3 | `dfs_timestamps(g, discovery[], finish[])` | 4 | Calcule temps découverte/fin |

### NIVEAU STANDARD (12 points)

| # | Fonction | Points | Description |
|---|----------|--------|-------------|
| 4 | `has_cycle(g)` | 6 | Détecte présence d'un cycle |
| 5 | `topological_sort(g)` | 6 | Tri topologique (DAG requis) |

### NIVEAU BONUS (3 points)

| # | Fonction | Points | Description |
|---|----------|--------|-------------|
| 6 | `find_path_dfs(g, src, dest, path)` | 3 | Trouve un chemin avec DFS |

**Total : 27 points → ramené sur 25**

---

## ⚠️ Pièges Fréquents (à éviter !)

| # | Piège | Solution |
|---|-------|----------|
| 1 | Oublier `visited[u] = true` dans récursif | Marquer **AVANT** de visiter voisins |
| 2 | Marquer `visited[]` trop tôt dans itératif | Marquer **APRÈS** avoir dépilé |
| 3 | `discovery[]` et `finish[]` non initialisés | Initialiser à `-1` |
| 4 | Oublier `in_stack[]` pour cycle orienté | Créer tableau séparé `in_stack[]` |
| 5 | Tri topologique sur graphe avec cycle | Vérifier absence cycle **AVANT** |
| 6 | Utiliser `std::stack` au lieu de `Stack` | **Pénalité -3 points !** |

---

## 🎓 Exemple de TODO (Fonction 1)

Fichier : `src/dfs.cpp`

```cpp
void dfs_recursive(Graph& g, int source) {
    // TODO 1 : Créer vector<bool> visited(V, false)
    // TODO 2 : Appeler dfs_visit(g, source, visited)
}

void dfs_visit(Graph& g, int u, vector<bool>& visited) {
    // TODO 3 : Marquer u visité : visited[u] = true
    // TODO 4 : Afficher u : cout << u << " "
    // TODO 5 : Pour chaque voisin v de u :
    //   - Si v non visité, appeler récursivement dfs_visit(g, v, visited)
}
```

---

## 📊 Format des Fichiers Graphes

Exemple : `data/graph_dag.txt`
```
5 6 1      ← 5 sommets, 6 arêtes, orienté (1 = oui, 0 = non)
0 1        ← Arête 0→1
0 2
1 3
2 3
2 4
3 4
```

---

## ⚡ Points Clés pour Réussir

### DFS Récursif
- ✓ Marquer `visited[u] = true` **AVANT** la boucle sur les voisins
- ✓ Créer fonction auxiliaire `dfs_visit()` récursive

### DFS Itératif
- ✓ Utiliser `Stack` de `stack.h` (pas `std::stack`)
- ✓ Marquer `visited[u]` **APRÈS** `pop()`, pas avant `push()`
- ✓ Parcourir voisins en ordre inverse pour cohérence avec récursif

### Timestamps
- ✓ Initialiser `discovery[i] = finish[i] = -1` pour tous i
- ✓ Incrémenter temps : `discovery[u] = time++` à la découverte
- ✓ Incrémenter temps : `finish[u] = time++` à la fin

### Détection de Cycle
- **Graphe orienté** : Utiliser `in_stack[]` (true pendant exploration)
- **Graphe non-orienté** : Utiliser `parent[]` pour éviter faux positifs

### Tri Topologique
- ✓ Vérifier que `g.isDirected()` est true
- ✓ Vérifier que `!has_cycle(g)`
- ✓ Trier par `finish[]` **décroissant**

---

## 🧪 Tests Automatiques

```bash
./test_dfs
```

**Sortie attendue (26 tests)** :
```
═══════════════════════════════════════
  TESTS TPE3 - DFS
═══════════════════════════════════════
--- NIVEAU 1 : BASE ---
  Test 3.1... ✓ PASS
  Test 3.2... ✓ PASS
  ...
>>> NIVEAU 1 : 10/10 tests passés <<<

--- NIVEAU 2 : STANDARD ---
  Test 3.11... ✓ PASS
  ...
>>> NIVEAU 2 : 12/12 tests passés <<<

--- NIVEAU 3 : BONUS ---
  Test 3.23... ✓ PASS
  ...
>>> NIVEAU 3 : 4/4 tests passés <<<

RÉSUMÉ : 26/26 tests - NOTE ESTIMÉE : 25/25 pts
```

---

## 📚 Documentation Complète

- **Algorithmes détaillés** : [docs/ENONCE.md](docs/ENONCE.md)
- **Barème de notation** : [docs/BAREME.md](docs/BAREME.md)
- **Slides de cours** : Séance 3, pages 13-40

---

## 📦 Rendu

### Format
- **Fichier** : `NOM_Prenom_TPE3.zip`
- **Contenu** : `dfs.cpp` + `capture_tests.png`
- **Deadline** : Début Séance 4

### Checklist
- [ ] Code compile : `make clean && make test`
- [ ] Tests BASE passent : minimum 10/10
- [ ] Nom/Prénom en haut de `dfs.cpp`
- [ ] Code commenté (étapes clés)
- [ ] Capture montre résultats de `./test_dfs`
- [ ] Utilisation de `Stack` (pas `std::stack`)

---

## 💡 Conseils

1. **Procéder par niveau** : BASE → STANDARD → BONUS
2. **Tester fréquemment** : `make test` après chaque fonction
3. **Lire ENONCE.md** : Algorithmes détaillés avec pseudocode
4. **Éviter les pièges** : Liste des 6 pièges ci-dessus
5. **Programme interactif** : `./main` pour tests manuels
6. **Comprendre timestamps** : Clé pour tri topologique

---

## 🆘 Aide

- **Documentation** : Lire [docs/ENONCE.md](docs/ENONCE.md)
- **Barème** : Voir [docs/BAREME.md](docs/BAREME.md)
- **Slides** : Consulter Séance 3, pages 13-40
- **Tests** : Analyser `tests/test_dfs.cpp` pour comprendre attendu

---

**Bonne chance ! 🚀**

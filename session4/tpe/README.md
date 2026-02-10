# TPE4 - Et si vous inventiez Dijkstra ?

## Théorie des Graphes - L2 Génie Informatique

**Institution** : ESGC VERECHAGUINE A.K. (Cotonou, Bénin)
**Enseignant** : M. Alexandre GBAGUIDI AISSE
**Année académique** : 2025-2026
**Durée** : 2-3 heures

---

## 🎯 Objectifs

Découvrir et implémenter l'algorithme de **Dijkstra** en 6 étapes progressives :
- Constater l'échec de BFS sur les graphes pondérés
- Tester l'approche gloutonne (et comprendre pourquoi elle échoue)
- Découvrir le principe de relaxation (Bellman-Ford simplifié)
- Implémenter Dijkstra en O(V²) puis O((V+E) log V) avec min-heap
- Reconstruire le chemin optimal entre deux sommets

---

## 📁 Structure du Projet

```
session4/tpe/
├── README.md                  ← Ce fichier
├── Makefile                   ← Compilation
├── src/
│   ├── graph.h/cpp           ✓ Classe Graph pondéré (fournie)
│   ├── bfs_weighted.h/cpp    ✓ BFS sur graphe pondéré (fourni)
│   ├── dijkstra.h            ✓ Signatures (fourni)
│   ├── dijkstra.cpp          ⚠️ À COMPLÉTER (7 fonctions)
│   └── main.cpp              ✓ Programme interactif (fourni)
├── tests/
│   └── test_dijkstra.cpp     ✓ 18 tests automatiques
├── data/
│   ├── graph_test.txt        ✓ 5 sommets, BFS échoue
│   ├── graph_greedy_fail.txt ✓ 5 sommets, piège glouton
│   └── graph_cotonou.txt     ✓ 8 quartiers de Cotonou
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
make test       # Compiler et lancer les tests
```

### Exécution
```bash
# Tests automatiques (18 tests)
./test_dijkstra

# Programme interactif
./main
```

### Aide
```bash
make help        # Liste des commandes disponibles
```

---

## 📝 Fonctions à Implémenter

Fichier : `src/dijkstra.cpp`

### Les 7 Fonctions (6 étapes)

| # | Fonction | Étape | Points | Description |
|---|----------|-------|--------|-------------|
| 1 | `test_bfs_fails(g, source, dest)` | 0 | 2 | Montrer que BFS ignore les poids |
| 2 | `greedy_path(g, source, dest)` | 1 | 3 | Chemin glouton (voisin le moins cher) |
| 3 | `relax_all_edges(g, source)` | 2 | 4 | Relaxation brute V-1 fois |
| 4 | `dijkstra_base(g, source)` | 3 | 6 | Dijkstra O(V²) recherche linéaire |
| 5 | `dijkstra_heap(g, source)` | 4 | 6 | Dijkstra O((V+E) log V) min-heap |
| 6 | `reconstruct_path(parent, source, dest)` | 5 | 2 | Reconstruire chemin via parent[] |
| 7 | `dijkstra_between_two(g, source, dest)` | 5 | 2 | Distance + chemin entre 2 sommets |

**Total : 27 points → ramené sur 25**

---

## ⚠️ Pièges Fréquents (à éviter !)

| # | Piège | Solution |
|---|-------|----------|
| 1 | Oublier `INT_MAX` pour init | `vector<int> distance(V, INT_MAX); distance[source] = 0;` |
| 2 | Max-heap au lieu de min-heap | `greater<pair<int,int>>` dans la priority_queue |
| 3 | Ne pas skip `distance[u] == INT_MAX` | Vérifier avant de relaxer dans Bellman-Ford |
| 4 | Oublier `if (visited[u]) continue` | Obligatoire après `Q.pop()` dans dijkstra_heap |
| 5 | Chemin reconstruit à l'envers | Appeler `reverse()` après la boucle |
| 6 | Pas d'arrêt anticipé dans `between_two` | `if (u == dest) break;` après marquage |

---

## 🎓 Exemple de TODO (Étape 4)

Fichier : `src/dijkstra.cpp`

```cpp
vector<int> dijkstra_heap(Graph& g, int source) {
    int V = g.getVertexCount();

    // TODO 1 : Initialisation
    //   vector<int> distance(V, INT_MAX);
    //   vector<bool> visited(V, false);
    //   distance[source] = 0;

    // TODO 2 : Créer la file de priorité MIN-HEAP
    //   priority_queue<pair<int,int>, vector<pair<int,int>>,
    //                  greater<pair<int,int>>> Q;
    //   ATTENTION : greater<> pour MIN-Heap !

    // TODO 3 : Ajouter le point de départ
    //   Q.push({0, source});

    // TODO 4 : Boucle while (!Q.empty())
    //   auto [d, u] = Q.top(); Q.pop();
    //   if (visited[u]) continue;
    //   visited[u] = true;

    //   TODO 5 : Relaxation + ajout dans Q
    //     for (auto& [v, poids] : g.getNeighbors(u))
    //       if (!visited[v] && distance[u] + poids < distance[v])
    //         distance[v] = distance[u] + poids;
    //         Q.push({distance[v], v});

    // TODO 6 : Retourner distance[]
}
```

---

## 📊 Format des Fichiers Graphes

Exemple : `data/graph_test.txt`
```
// 0=Ganhi  1=Dantokpa  2=Cadjehoun  3=Akpakpa  4=Fidjrosse
5 6            ← 5 sommets, 6 arêtes
0 1 2          ← Arête 0↔1, poids 2
0 2 10         ← Arête 0↔2, poids 10
1 2 3
1 3 8
2 3 1
3 4 5
```

Les graphes sont **non-orientés** et **pondérés** (chaque arête a un poids/coût).

---

## 🧪 Tests Automatiques

```bash
./test_dijkstra
```

**Sortie attendue (18 tests)** :
```
═══════════════════════════════════════════════
  TESTS TPE4 - ET SI VOUS INVENTIEZ DIJKSTRA ?
═══════════════════════════════════════════════
=== ÉTAPE 0 : BFS SE TROMPE ===
  ✅ Test 1 : BFS donne chemin sous-optimal
  ✅ Test 2 : BFS : 1 arête mais coût = 10
  ...
=== ÉTAPE 4 : DIJKSTRA HEAP ===
  ✅ Test 12-15 : ...

TOTAL : 18/18 tests passés
NOTE ESTIMÉE : 25/25 pts (+ qualité code : +2 pts)
```

---

## 📚 Documentation Complète

- **Algorithmes détaillés** : [docs/ENONCE.md](docs/ENONCE.md)
- **Barème de notation** : [docs/BAREME.md](docs/BAREME.md)
- **Slides de cours** : Séance 4, pages sur Dijkstra

---

## 📦 Rendu

### Format
- **Fichier** : `NOM_Prenom_TPE4.zip`
- **Contenu** : `dijkstra.cpp` + `capture_tests.png`
- **Deadline** : Début Séance 5

### Checklist
- [ ] Les **7** fonctions sont implémentées
- [ ] Code compile : `make clean && make test`
- [ ] Tests passent : viser 18/18
- [ ] Nom/Prénom en haut de `dijkstra.cpp`
- [ ] Code commenté (étapes clés + complexité)
- [ ] Capture montre résultats de `./test_dijkstra`

---

## 💡 Conseils

1. **Procéder étape par étape** : 0 → 1 → 2 → 3 → 4 → 5
2. **Tester fréquemment** : `make test` après chaque fonction
3. **Lire ENONCE.md** : Algorithmes détaillés avec pseudocode
4. **Utiliser l'option 9** : Compare toutes les approches d'un coup
5. **Dessiner le graphe** : Calculer les distances à la main d'abord
6. **`greater<>` pour le min-heap** : C'est LE piège de l'étape 4

---

## 🆘 Aide

- **Documentation** : Lire [docs/ENONCE.md](docs/ENONCE.md)
- **Barème** : Voir [docs/BAREME.md](docs/BAREME.md)
- **Slides** : Consulter Séance 4
- **Tests** : Analyser `tests/test_dijkstra.cpp` pour comprendre attendu

---

**Bonne chance ! 🚀**

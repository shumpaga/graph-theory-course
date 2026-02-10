# Barème de Notation - TPE4 Dijkstra

## ESGC VERECHAGUINE A.K. - L2 GI2 - 2025-2026

---

## 📊 Distribution des Points

| Étape | Points | Pourcentage |
|-------|--------|-------------|
| Étape 0 : BFS se trompe | 2 pts | 7% |
| Étape 1 : Glouton naïf | 3 pts | 11% |
| Étape 2 : Relaxation | 4 pts | 15% |
| Étape 3 : Dijkstra base | 6 pts | 22% |
| Étape 4 : Dijkstra heap | 6 pts | 22% |
| Étape 5 : Reconstruction | 4 pts | 15% |
| Qualité code | +2 pts | Bonus |
| **TOTAL** | **27 pts** | **→ ramené sur 25** |

---

## 🎯 ÉTAPE 0 : BFS SE TROMPE (2 points)

### Fonction : `test_bfs_fails()` - 2 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Appel BFS correct | 0.5 | Utilise `bfs_shortest_path()` fourni |
| Calcul coût réel | 0.5 | Utilise `compute_path_cost()` fourni |
| Affichage comparatif | 0.5 | Montre chemin BFS vs optimal |
| Conclusion pédagogique | 0.5 | Explique pourquoi BFS se trompe |

**Tests** : 2 tests (1-2)

---

## 🎯 ÉTAPE 1 : GLOUTON NAÏF (3 points)

### Fonction : `greedy_path()` - 3 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Initialisation | 0.5 | `visited`, `path`, `current`, `total_cost` |
| Boucle glouton | 1.5 | Trouve voisin non visité le moins cher |
| Gestion blocage | 0.5 | Retourne `{-1, {}}` si bloqué |
| Retour correct | 0.5 | `{total_cost, path}` |

**Tests** : 2 tests (3-4)

---

## 🎯 ÉTAPE 2 : RELAXATION (4 points)

### Fonction : `relax_all_edges()` - 4 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Initialisation distances | 1.0 | `distance(V, INT_MAX)`, `distance[source] = 0` |
| Boucle V-1 itérations | 1.0 | Itère exactement V-1 fois |
| Relaxation correcte | 1.5 | `if (dist[u] + poids < dist[v])` → mise à jour |
| Skip sommets non atteints | 0.5 | `if (distance[u] == INT_MAX) continue` |

**Tests** : 3 tests (5-7)

---

## 🎯 ÉTAPE 3 : DIJKSTRA BASE (6 points)

### Fonction : `dijkstra_base()` - 6 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Initialisation | 1.0 | `distance`, `visited`, `distance[source] = 0` |
| Recherche du minimum | 2.0 | Parcours linéaire pour trouver min non visité |
| Marquage visité | 1.0 | `visited[u] = true` avant relaxation |
| Relaxation voisins | 1.5 | Comme étape 2, mais seulement voisins de u |
| Condition `!visited[v]` | 0.5 | Ne pas relaxer les sommets déjà visités |

**Tests** : 4 tests (8-11)

---

## 🎯 ÉTAPE 4 : DIJKSTRA HEAP (6 points)

### Fonction : `dijkstra_heap()` - 6 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Priority queue correcte | 2.0 | `greater<pair<int,int>>` pour MIN-heap |
| Push initial | 0.5 | `Q.push({0, source})` |
| Pop + skip visited | 1.5 | `if (visited[u]) continue` après pop |
| Relaxation + push | 1.5 | Mise à jour distance ET push dans Q |
| Retour correct | 0.5 | Retourne le tableau distance[] |

**Tests** : 4 tests (12-15)

**Piège principal** : Utiliser `greater<>` ! Par défaut, `priority_queue` est un **max-heap**. Il faut `greater<>` pour un **min-heap** :
```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>,
               greater<pair<int,int>>> Q;
```

---

## 🎯 ÉTAPE 5 : RECONSTRUCTION (4 points)

### Fonction : `reconstruct_path()` - 2 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Cas inaccessible | 0.5 | Retourne `{}` si `parent[dest] == -1` |
| Cas `source == dest` | 0.5 | Retourne `{source}` |
| Remontée parent[] | 0.5 | Boucle `while (current != source)` |
| Inversion chemin | 0.5 | `reverse(path.begin(), path.end())` |

### Fonction : `dijkstra_between_two()` - 2 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Dijkstra + parent[] | 0.5 | Copie de dijkstra_heap avec `parent[v] = u` |
| Arrêt anticipé | 0.5 | `if (u == dest) break` |
| Vérification accessibilité | 0.5 | `if (distance[dest] == INT_MAX) return {-1, {}}` |
| Appel reconstruct_path | 0.5 | Utilise sa propre fonction pour reconstruire |

**Tests** : 3 tests (16-18)

---

## 💻 QUALITÉ DU CODE (+2 points)

| Critère | Points | Description |
|---------|--------|-------------|
| Commentaires | 1.0 | Explications claires des étapes clés |
| Nommage | 0.5 | Variables avec noms explicites |
| Indentation | 0.5 | Code bien formaté et lisible |

**Exemples de bons commentaires** :
```cpp
// Trouver le sommet non visité avec la distance minimale
int u = -1, min_dist = INT_MAX;

// RELAXATION : si on peut faire mieux en passant par u
if (distance[u] + poids < distance[v]) {
    distance[v] = distance[u] + poids;
}
```

---

## ⚠️ PÉNALITÉS

| Faute | Pénalité |
|-------|----------|
| Code ne compile pas | **0/25** |
| Segmentation fault | **-2 points par fonction** |
| Pas de nom/prénom dans `dijkstra.cpp` | **-0.5 point** |

---

## 🧮 Calcul de la Note Finale

**Formule** :
```
Note = (Étape0 + Étape1 + Étape2 + Étape3 + Étape4 + Étape5 + Code) × 25 / 27
```

**Exemples** :
- 2 + 3 + 4 + 6 + 6 + 4 + 2 = 27 pts → **25/25**
- 2 + 3 + 4 + 6 + 6 + 0 + 0 = 21 pts → **19.4/25**
- 2 + 3 + 4 + 6 + 0 + 0 + 0 = 15 pts → **13.9/25**
- 2 + 3 + 0 + 0 + 0 + 0 + 0 = 5 pts → **4.6/25**

---

## 📋 Checklist Avant Rendu

- [ ] Les **7** fonctions sont implémentées : `test_bfs_fails`, `greedy_path`, `relax_all_edges`, `dijkstra_base`, `dijkstra_heap`, `reconstruct_path`, `dijkstra_between_two`
- [ ] Code compile sans erreur : `make clean && make test`
- [ ] Tests passent : viser 18/18
- [ ] Nom/Prénom en haut de `dijkstra.cpp`
- [ ] Code commenté (étapes clés + complexité documentée)
- [ ] ZIP créé : `NOM_Prenom_TPE4.zip`
- [ ] ZIP contient : `dijkstra.cpp` + `capture_tests.png`
- [ ] Capture montre résultats de `./test_dijkstra`

---

## 🎯 Conseils pour Maximiser la Note

1. **Étapes 0-1** : Points faciles, commencez par là (5 pts)
2. **Étape 2** : Comprendre la relaxation est la CLÉ pour la suite
3. **Étape 3** : Dijkstra base = relaxation + visite intelligente
4. **Étape 4** : Copier l'étape 3 et remplacer la recherche du min par un heap
5. **Étape 5** : Copier l'étape 4 et ajouter `parent[]`
6. **Commenter le code** : +2 points faciles !

---

**Bonne chance ! 🚀**

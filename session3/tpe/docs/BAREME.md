# Barème de Notation - TPE3 DFS

## ESGC VERECHAGUINE A.K. - L2 GI2 - 2025-2026

---

## 📊 Distribution des Points

| Niveau | Points | Pourcentage |
|--------|--------|-------------|
| BASE | 10 pts | 40% |
| STANDARD | 12 pts | 48% |
| BONUS | 3 pts | 12% |
| CODE | +2 pts | Bonus |
| **TOTAL** | **27 pts** | **→ ramené sur 25** |

---

## 🎯 NIVEAU BASE (10 points)

### Fonction 1 : `dfs_recursive()` - 3 points

| Critère | Points | Description |
|---------|--------|-------------|
| Récursion correcte | 1.0 | Fonction auxiliaire `dfs_visit()` appelée |
| `visited[]` bien géré | 1.0 | Marqué **avant** visite des voisins |
| Affichage correct | 0.5 | Tous les sommets accessibles affichés |
| Pas d'erreur | 0.5 | Pas de segfault ou exception |

**Tests** : 4 tests (3.1, 3.2, 3.7, 3.10)

---

### Fonction 2 : `dfs_iterative()` - 3 points

| Critère | Points | Description |
|---------|--------|-------------|
| Pile explicite | 1.0 | Utilise `Stack` de `stack.h` (**-3 si std::stack**) |
| `visited[]` après pop | 1.0 | Marqué **après** dépilage, pas avant empilement |
| Affichage correct | 0.5 | Ordre de parcours valide |
| Pas d'erreur | 0.5 | Gestion propre de la pile |

**Tests** : 3 tests (3.3, 3.4, 3.8)

---

### Fonction 3 : `dfs_timestamps()` - 4 points

| Critère | Points | Description |
|---------|--------|-------------|
| `discovery[]` correct | 1.5 | Tous les sommets ont un temps de découverte |
| `finish[]` correct | 1.5 | Tous les sommets ont un temps de fin |
| Ordre valide | 0.5 | `discovery[u] < finish[u]` pour tout u |
| Parcours complet | 0.5 | Tous les sommets visités (graphes non connexes) |

**Tests** : 3 tests (3.5, 3.6, 3.9)

---

## 🔧 NIVEAU STANDARD (12 points)

### Fonction 4 : `has_cycle()` - 6 points

| Critère | Points | Description |
|---------|--------|-------------|
| Graphe orienté | 3.0 | Utilise `in_stack[]` correctement |
| Graphe non-orienté | 2.0 | Utilise `parent[]` pour éviter faux positifs |
| Détection correcte | 0.5 | Retourne `true` si cycle, `false` sinon |
| Cas limites | 0.5 | Gère boucles sur soi-même, graphes vides |

**Tests** : 6 tests (3.11-3.14, 3.19, 3.20)

**Détails orienté** :
- `in_stack[u] = true` pendant exploration de u
- `in_stack[u] = false` à la fin de u
- Cycle si voisin `v` avec `in_stack[v] = true`

**Détails non-orienté** :
- Suivre `parent[]` pour éviter retour arrière
- Cycle si voisin visité qui n'est pas le parent

---

### Fonction 5 : `topological_sort()` - 6 points

| Critère | Points | Description |
|---------|--------|-------------|
| Vérification orienté | 1.0 | Retourne `NULL` si graphe non orienté |
| Vérification cycle | 2.0 | Retourne `NULL` si `has_cycle()` true |
| Calcul correct | 2.0 | Ordre topologique valide (finish décroissant) |
| Gestion mémoire | 0.5 | `new int[V]` et retour correct |
| Pas de fuite | 0.5 | Utilisateur peut `delete[]` le résultat |

**Tests** : 6 tests (3.15-3.18, 3.21, 3.22)

**Algorithme attendu** :
1. Vérifier `g.isDirected()` → si false, retourner `NULL`
2. Appeler `has_cycle(g)` → si true, retourner `NULL`
3. Calculer `finish[]` avec `dfs_timestamps()`
4. Trier sommets par `finish[]` **décroissant**
5. Allouer `int* result = new int[V]`
6. Copier ordre trié dans `result[]`
7. Retourner `result`

---

## 🌟 NIVEAU BONUS (3 points)

### Fonction 6 : `find_path_dfs()` - 3 points

| Critère | Points | Description |
|---------|--------|-------------|
| DFS avec `parent[]` | 1.5 | Mémorise `parent[v] = u` pendant visite |
| Reconstruction chemin | 1.0 | Remonte depuis `dest` vers `src` avec `parent[]` |
| Retour correct | 0.5 | `true` si chemin trouvé, `false` sinon |

**Tests** : 4 tests (3.23-3.26)

**Détails** :
- Si `src == dest`, retourner `{dest}` immédiatement
- Remonter chemin : `dest → parent[dest] → parent[parent[dest]] → ... → src`
- Inverser le chemin avant de le retourner

---

## 💻 QUALITÉ DU CODE (+2 points)

| Critère | Points | Description |
|---------|--------|-------------|
| Commentaires | 1.0 | Explications claires des étapes clés |
| Nommage | 0.5 | Variables avec noms explicites |
| Indentation | 0.5 | Code bien formaté et lisible |

**Exemples de bons commentaires** :
```cpp
// Marquer u comme visité AVANT de visiter ses voisins
visited[u] = true;

// in_stack[] distingue sommets en cours d'exploration
in_stack[u] = true;  // u entre dans la pile de récursion
```

---

## ⚠️ PÉNALITÉS

| Faute | Pénalité |
|-------|----------|
| Utilisation de `std::stack` | **-3 points** |
| Code ne compile pas | **0/25** |
| Segmentation fault | **-2 points par fonction** |
| Fuite mémoire (valgrind) | **-1 point** |
| Pas de nom/prénom dans `dfs.cpp` | **-0.5 point** |

---

## 🧮 Calcul de la Note Finale

**Formule** :
```
Note = (Points_BASE + Points_STANDARD + Points_BONUS + Points_CODE) * 25 / 27
```

**Exemples** :
- 10 BASE + 12 STANDARD + 0 BONUS + 2 CODE = 24 pts → **22.2/25**
- 10 BASE + 12 STANDARD + 3 BONUS + 2 CODE = 27 pts → **25/25**
- 10 BASE + 6 STANDARD + 0 BONUS + 0 CODE = 16 pts → **14.8/25**

---

## 📋 Checklist Avant Rendu

- [ ] Code compile sans erreur : `make clean && make test`
- [ ] Tests BASE passent : minimum 10/10
- [ ] `Stack` de `stack.h` utilisée (pas `std::stack`)
- [ ] Nom/Prénom en haut de `dfs.cpp`
- [ ] Code commenté (étapes clés)
- [ ] ZIP créé : `NOM_Prenom_TPE3.zip`
- [ ] ZIP contient : `dfs.cpp` + `capture_tests.png`
- [ ] Capture montre résultats de `./test_dfs`

---

## 🎯 Conseils pour Maximiser la Note

1. **Commencer par BASE** : 10 points garantis si bien fait
2. **Éviter les pièges** : Relire page 3 du PDF TPE
3. **Tester fréquemment** : `make test` après chaque fonction
4. **Vérifier mémoire** : `valgrind ./test_dfs` (si disponible)
5. **Commenter le code** : Explications = +2 points faciles
6. **Tester cas limites** : Graphes vides, 1 sommet, self-loops
7. **Utiliser le programme interactif** : `./main data/graph_simple.txt`

---

**Bonne chance ! 🚀**

# TPE4 - Et si vous inventiez Dijkstra ?

## ESGC VERECHAGUINE A.K. - L2 GI2 - 2025-2026

---

## 📋 Mission ZEMIDJAN

Vous êtes développeur chez **ZEMIGO**, une start-up béninoise qui veut optimiser les trajets de zémidjans (taxi-motos) à Cotonou. Le problème : trouver le chemin **le moins coûteux** entre deux quartiers, en tenant compte des distances réelles (pas juste le nombre d'intersections).

Votre BFS de la session 2 ne suffit plus : il trouve le chemin avec le **moins d'arêtes**, pas le **moins coûteux**. Il vous faut un nouvel algorithme...

---

## 🎯 Les 6 Étapes de la Découverte

### ÉTAPE 0 : BFS se trompe ! (2 pts)

**Objectif** : Constater que BFS ignore les poids.

**Fonction** : `test_bfs_fails(g, source, dest)`

**Algorithme** :
```
fonction test_bfs_fails(G, source, dest):
    (nb_aretes, chemin) = bfs_shortest_path(G, source, dest)
    cout_bfs = compute_path_cost(G, chemin)
    afficher chemin et cout_bfs
    afficher "BFS minimise les arêtes, pas le coût !"
```

**Exemple sur graph_test.txt** :
- BFS de 0 à 2 : chemin 0→2 (1 arête, coût 10)
- Optimal : 0→1→2 (2 arêtes, coût 5)
- BFS se trompe car il choisit le chemin avec le moins d'arêtes !

---

### ÉTAPE 1 : Le glouton naïf (3 pts)

**Objectif** : Tenter l'approche "toujours prendre le voisin le moins cher".

**Fonction** : `greedy_path(g, source, dest)`

**Algorithme** :
```
fonction greedy_path(G, source, dest):
    visited = {false}
    path = [source]
    current = source
    total_cost = 0

    tant que current != dest:
        visited[current] = true
        best_v = -1, best_w = ∞

        pour chaque voisin (v, poids) de current:
            si v non visité et poids < best_w:
                best_v = v
                best_w = poids

        si best_v == -1:
            retourner {-1, []}  // Bloqué !

        current = best_v
        total_cost += best_w
        path.ajouter(current)

    retourner {total_cost, path}
```

**Pourquoi ça échoue** : Sur `graph_greedy_fail.txt`, le glouton prend l'arête 0→1 (coût 1) car c'est la moins chère, mais se retrouve piégé : le chemin total coûte 12 au lieu de 8.

---

### ÉTAPE 2 : La relaxation (4 pts)

**Objectif** : Découvrir le principe de relaxation (Bellman-Ford simplifié).

**Fonction** : `relax_all_edges(g, source)`

**Algorithme** :
```
fonction relax_all_edges(G, source):
    distance = [INT_MAX, INT_MAX, ...]
    distance[source] = 0

    répéter V-1 fois:
        pour chaque sommet u:
            si distance[u] == INT_MAX: continuer
            pour chaque voisin (v, poids) de u:
                si distance[u] + poids < distance[v]:
                    distance[v] = distance[u] + poids  // RELAXATION

    retourner distance
```

**Principe de relaxation** : Si on connaît un chemin vers `u` de coût `d`, et qu'il existe une arête `u→v` de poids `w`, alors on peut atteindre `v` avec un coût `d + w`. Si c'est mieux que ce qu'on connaissait, on met à jour.

**Complexité** : O(V × E) — ça fonctionne mais c'est lent !

---

### ÉTAPE 3 : Dijkstra base — O(V²) (6 pts)

**Objectif** : Optimiser en visitant intelligemment les sommets.

**Fonction** : `dijkstra_base(g, source)`

**Algorithme** :
```
fonction dijkstra_base(G, source):
    distance = [INT_MAX, ...]
    visited = [false, ...]
    distance[source] = 0

    pour i de 0 à V-1:
        // Trouver le sommet non visité le plus proche
        u = sommet avec distance minimale parmi les non visités
        si u introuvable: stop

        visited[u] = true

        // Relaxer les voisins de u
        pour chaque voisin (v, poids) de u:
            si !visited[v] et distance[u] + poids < distance[v]:
                distance[v] = distance[u] + poids

    retourner distance
```

**Idée clé** : Au lieu de relaxer TOUTES les arêtes V-1 fois, on visite les sommets **du plus proche au plus lointain**. Chaque sommet n'est visité qu'une fois.

**Complexité** : O(V²) — la recherche du minimum est en O(V).

---

### ÉTAPE 4 : Dijkstra heap — O((V+E) log V) (6 pts)

**Objectif** : Remplacer la recherche linéaire par un min-heap.

**Fonction** : `dijkstra_heap(g, source)`

**Algorithme** :
```
fonction dijkstra_heap(G, source):
    distance = [INT_MAX, ...]
    visited = [false, ...]
    distance[source] = 0

    Q = min_heap()  // ATTENTION: greater<> en C++ !
    Q.push({0, source})

    tant que Q non vide:
        (d, u) = Q.top(); Q.pop()
        si visited[u]: continuer  // Déjà traité
        visited[u] = true

        pour chaque voisin (v, poids) de u:
            si !visited[v] et distance[u] + poids < distance[v]:
                distance[v] = distance[u] + poids
                Q.push({distance[v], v})

    retourner distance
```

**En C++** :
```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>,
               greater<pair<int,int>>> Q;
```

**Complexité** : O((V+E) log V) — bien meilleur pour les grands graphes !

---

### ÉTAPE 5 : Reconstruction du chemin (4 pts)

**Objectif** : Non seulement la distance, mais aussi le chemin.

**Fonction 1** : `reconstruct_path(parent, source, dest)`

**Algorithme** :
```
fonction reconstruct_path(parent, source, dest):
    si parent[dest] == -1 et dest != source:
        retourner []  // Inaccessible

    si source == dest:
        retourner [source]

    path = []
    current = dest
    tant que current != source:
        path.ajouter(current)
        current = parent[current]
    path.ajouter(source)

    inverser(path)
    retourner path
```

**Fonction 2** : `dijkstra_between_two(g, source, dest)`

**Algorithme** :
```
fonction dijkstra_between_two(G, source, dest):
    // Copie de dijkstra_heap avec parent[]
    parent = [-1, -1, ...]

    // Dans la relaxation, quand distance[v] est mise à jour:
    parent[v] = u

    // Arrêt anticipé : si u == dest, stop !

    si distance[dest] == INT_MAX:
        retourner {-1, []}

    path = reconstruct_path(parent, source, dest)
    retourner {distance[dest], path}
```

---

## ⚠️ Pièges à Éviter

| # | Piège | Solution |
|---|-------|----------|
| 1 | Oublier `INT_MAX` pour init | `vector<int> distance(V, INT_MAX); distance[source] = 0;` |
| 2 | Max-heap au lieu de min-heap | `greater<pair<int,int>>` dans la priority_queue |
| 3 | Ne pas skip `distance[u] == INT_MAX` | Vérifier avant de relaxer dans Bellman-Ford |
| 4 | Oublier `if (visited[u]) continue` | Obligatoire après `Q.pop()` dans dijkstra_heap |
| 5 | Chemin reconstruit à l'envers | Appeler `reverse()` après la boucle |
| 6 | Pas d'arrêt anticipé dans `between_two` | `if (u == dest) break;` après marquage |

---

## 📊 Complexité Comparée

| Algorithme | Complexité | Fonctionne ? |
|------------|-----------|-------------|
| BFS | O(V + E) | ❌ Ignore les poids |
| Glouton | O(V × deg) | ❌ Optimal local ≠ optimal global |
| Relaxation brute | O(V × E) | ✅ Correct mais lent |
| Dijkstra base | O(V²) | ✅ Correct et rapide |
| Dijkstra heap | O((V+E) log V) | ✅ Optimal pour graphes creux |

---

## 📋 Les 7 Fonctions à Implémenter

| # | Fonction | Étape | Points |
|---|----------|-------|--------|
| 1 | `test_bfs_fails(g, source, dest)` | 0 | 2 pts |
| 2 | `greedy_path(g, source, dest)` | 1 | 3 pts |
| 3 | `relax_all_edges(g, source)` | 2 | 4 pts |
| 4 | `dijkstra_base(g, source)` | 3 | 6 pts |
| 5 | `dijkstra_heap(g, source)` | 4 | 6 pts |
| 6 | `reconstruct_path(parent, source, dest)` | 5 | 2 pts |
| 7 | `dijkstra_between_two(g, source, dest)` | 5 | 2 pts |

**+ Qualité du code : +2 pts bonus**

---

## 📚 Références

- **Slides Séance 4** : Pages sur Dijkstra
- **Algorithmes** : Cormen et al. (CLRS), Chapitre 24
- **README** : [../README.md](../README.md)

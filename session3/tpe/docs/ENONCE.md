# TPE3 - Parcours en Profondeur (DFS)

## ESGC VERECHAGUINE A.K. - L2 GI2 - 2025-2026

---

## 📋 Objectif

Implémenter l'algorithme de **parcours en profondeur (Depth-First Search - DFS)** et ses applications avancées :
- Parcours récursif et itératif
- Calcul de timestamps (temps de découverte/fin)
- Détection de cycles
- Tri topologique
- Recherche de chemins

---

## 🎯 Fonctions à Implémenter

### NIVEAU BASE (10 points)

#### 1. `dfs_recursive(Graph& g, int source)` - 3 pts

**Description** : Parcours DFS récursif depuis un sommet source.

**Algorithme** :
```
fonction dfs_recursive(G, source):
    créer visited[V] = {false}
    appeler dfs_visit(G, source, visited)

fonction dfs_visit(G, u, visited):
    visited[u] = true
    afficher u
    pour chaque voisin v de u:
        si v non visité:
            dfs_visit(G, v, visited)
```

**Piège** : Marquer `visited[u] = true` **AVANT** de visiter les voisins.

---

#### 2. `dfs_iterative(Graph& g, int source)` - 3 pts

**Description** : Parcours DFS itératif avec pile explicite.

**Algorithme** :
```
fonction dfs_iterative(G, source):
    créer Stack s et visited[V] = {false}
    empiler source dans s

    tant que s non vide:
        u = s.pop()
        si u déjà visité: continue

        visited[u] = true
        afficher u

        pour chaque voisin v de u (en ordre inverse):
            si v non visité:
                empiler v dans s
```

**Piège** : Marquer `visited[u] = true` **APRÈS** avoir dépilé, pas avant empiler.

**Important** : Utiliser la classe `Stack` de `stack.h`, pas `std::stack`.

---

#### 3. `dfs_timestamps(Graph& g, int discovery[], int finish[])` - 4 pts

**Description** : Calcule les temps de découverte et de fin pour chaque sommet.

**Algorithme** :
```
fonction dfs_timestamps(G, discovery, finish):
    créer visited[V] = {false}
    time = 0
    initialiser discovery[i] = finish[i] = -1

    pour chaque sommet u de 0 à V-1:
        si u non visité:
            dfs_timestamps_visit(G, u, visited, discovery, finish, time)

fonction dfs_timestamps_visit(G, u, visited, discovery, finish, time):
    visited[u] = true
    discovery[u] = time++

    pour chaque voisin v de u:
        si v non visité:
            dfs_timestamps_visit(G, v, ...)

    finish[u] = time++
```

**Piège** : Initialiser `discovery[]` et `finish[]` à `-1` avant l'appel.

---

### NIVEAU STANDARD (12 points)

#### 4. `has_cycle(Graph& g)` - 6 pts

**Description** : Détecte la présence d'un cycle dans le graphe.

**Algorithme (graphe orienté)** :
```
fonction has_cycle_directed(G):
    créer visited[V] = {false}
    créer in_stack[V] = {false}

    pour chaque sommet u:
        si u non visité:
            si dfs_cycle_directed(G, u, visited, in_stack):
                retourner true
    retourner false

fonction dfs_cycle_directed(G, u, visited, in_stack):
    visited[u] = true
    in_stack[u] = true

    pour chaque voisin v de u:
        si v non visité:
            si dfs_cycle_directed(G, v, ...):
                retourner true
        sinon si in_stack[v]:  # Cycle détecté!
            retourner true

    in_stack[u] = false
    retourner false
```

**Algorithme (graphe non-orienté)** :
```
fonction has_cycle_undirected(G):
    créer visited[V] = {false}
    créer parent[V] = {-1}

    pour chaque sommet u:
        si u non visité:
            si dfs_cycle_undirected(G, u, -1, visited):
                retourner true
    retourner false

fonction dfs_cycle_undirected(G, u, parent, visited):
    visited[u] = true

    pour chaque voisin v de u:
        si v non visité:
            si dfs_cycle_undirected(G, v, u, visited):
                retourner true
        sinon si v != parent:  # Cycle détecté!
            retourner true

    retourner false
```

**Piège** : Algorithme différent pour orienté vs non-orienté !

---

#### 5. `topological_sort(Graph& g)` - 6 pts

**Description** : Calcule un tri topologique du graphe (DAG requis).

**Algorithme** :
```
fonction topological_sort(G):
    si G non orienté:
        retourner NULL

    si has_cycle(G):
        retourner NULL

    calculer finish[] avec dfs_timestamps
    créer liste de paires (finish[i], i)
    trier par finish décroissant

    créer result = new int[V]
    copier l'ordre trié dans result
    retourner result
```

**Piège** : **TOUJOURS** vérifier l'absence de cycle AVANT le tri topologique.

---

### NIVEAU BONUS (3 points)

#### 6. `find_path_dfs(Graph& g, int src, int dest, vector<int>& path)` - 3 pts

**Description** : Trouve un chemin entre deux sommets avec DFS.

**Algorithme** :
```
fonction find_path_dfs(G, src, dest, path):
    créer visited[V] = {false}
    créer parent[V] = {-1}

    si dfs_path_search(G, src, dest, visited, parent):
        reconstruire le chemin depuis dest vers src avec parent[]
        inverser le chemin
        stocker dans path
        retourner true
    retourner false

fonction dfs_path_search(G, u, dest, visited, parent):
    visited[u] = true

    si u == dest:
        retourner true

    pour chaque voisin v de u:
        si v non visité:
            parent[v] = u
            si dfs_path_search(G, v, dest, visited, parent):
                retourner true

    retourner false
```

---

## ⚠️ Pièges Fréquents

| # | Piège | Solution |
|---|-------|----------|
| 1 | Oublier `visited[u] = true` dans récursif | Marquer **AVANT** de visiter voisins |
| 2 | Marquer `visited[]` trop tôt dans itératif | Marquer **APRÈS** avoir dépilé |
| 3 | `discovery[]` et `finish[]` non initialisés | Initialiser à `-1` |
| 4 | Oublier `in_stack[]` pour cycle orienté | Créer tableau séparé |
| 5 | Tri topologique sur graphe avec cycle | Vérifier absence cycle **AVANT** |
| 6 | Utiliser `std::stack` au lieu de `Stack` | Pénalité **-3 points** |

---

## 📊 Complexité

| Fonction | Complexité Temporelle | Complexité Spatiale |
|----------|----------------------|---------------------|
| DFS récursif | O(V + E) | O(V) pile récursion |
| DFS itératif | O(V + E) | O(V) pile explicite |
| Timestamps | O(V + E) | O(V) |
| Détection cycle | O(V + E) | O(V) |
| Tri topologique | O(V + E) | O(V) |
| Recherche chemin | O(V + E) | O(V) |

---

## 📚 Références

- **Slides Séance 3** : Pages 13-40
- **Algorithmes** : Cormen et al. (CLRS), Chapitre 22
- **DFS Applications** : [cours/session3/tpe/README.md](../README.md)

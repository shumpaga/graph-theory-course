# TPE5 - Arbre Couvrant Minimal : Kruskal & Union-Find

## ESGC VERECHAGUINE A.K. - L2 GI2 - 2025-2026

---

## 📋 Mission INTERCONNEXION

Vous êtes consultant informatique pour la **commune de Zogbodomey** (département du Zou, Bénin). Le maire souhaite connecter **tous les villages** de la commune avec des routes goudronnées, en **minimisant le coût total** de construction.

Chaque route possible entre deux villages a un coût connu (en millions de FCFA). Votre mission : trouver l'ensemble de routes qui connecte tous les villages au moindre coût — c'est l'**Arbre Couvrant Minimal** (Minimum Spanning Tree).

Pour résoudre ce problème efficacement, vous allez implémenter l'**algorithme de Kruskal** en utilisant la structure **Union-Find**.

---

## 🎯 Les 5 Étapes

### ÉTAPE 1 : Union-Find — Constructeur & Find (4 pts)

**Objectif** : Construire la structure de données Union-Find et implémenter `find()` avec compression de chemin.

**Fichier** : `src/union_find.cpp`

**Fonction** : `find(x)`

**Algorithme** :
```
fonction find(x):
    si parent[x] != x:
        parent[x] = find(parent[x])   // COMPRESSION DE CHEMIN
    retourner parent[x]
```

**Pourquoi la compression ?** Sans compression, `find()` est en O(n) dans le pire cas (chaîne linéaire). Avec compression, chaque noeud pointe directement vers la racine après le premier appel, rendant les appels suivants quasi-instantanés : O(α(n)) ≈ O(1).

**Exemple** :
```
Avant find(4) :  0 ← 1 ← 2 ← 3 ← 4
Après find(4) :  0 ← 1,  0 ← 2,  0 ← 3,  0 ← 4
                 (tous pointent vers la racine 0)
```

---

### ÉTAPE 2 : Union-Find — Unite & Connected (4 pts)

**Objectif** : Implémenter la fusion d'ensembles et le test de connexité.

**Fichier** : `src/union_find.cpp`

**Fonction** : `unite(x, y)`

**Algorithme** :
```
fonction unite(x, y):
    rx = find(x)     // Racine de x
    ry = find(y)     // Racine de y

    si rx == ry:
        retourner     // Déjà dans le même ensemble

    // UNION PAR RANG : attacher le plus petit sous le plus grand
    si rank_[rx] < rank_[ry]:
        parent[rx] = ry
    sinon si rank_[rx] > rank_[ry]:
        parent[ry] = rx
    sinon:
        parent[ry] = rx
        rank_[rx]++
```

**Pourquoi le rang ?** Sans union par rang, l'arbre peut dégénérer en chaîne linéaire. Le rang maintient l'arbre **aplati**, garantissant une complexité quasi-constante.

**Fonction** : `connected(x, y)`

**Algorithme** :
```
fonction connected(x, y):
    retourner find(x) == find(y)
```

---

### ÉTAPE 3 : Extraction des arêtes (4 pts)

**Objectif** : Extraire toutes les arêtes du graphe sans doublons.

**Fichier** : `src/mst.cpp`

**Fonction** : `getEdges(g)`

**Algorithme** :
```
fonction getEdges(G):
    edges = []

    pour chaque sommet u de 0 à V-1:
        pour chaque voisin (v, poids) de u:
            si u < v:                          // Éviter les doublons !
                edges.ajouter({u, v, poids})

    retourner edges
```

**Pourquoi `u < v` ?** Le graphe est non orienté : chaque arête `(u,v,w)` apparaît **deux fois** dans la liste d'adjacence (une fois dans `adj[u]`, une fois dans `adj[v]`). En ne gardant que `u < v`, on obtient exactement **E arêtes** sans doublons.

**Exemple sur graph_test.txt** :
```
11 arêtes : (0,1,7) (0,2,3) (0,3,5) (1,2,8) (1,3,9) (1,4,7) (2,4,5) (3,4,15) (3,5,6) (4,6,9) (5,6,11)
```

---

### ÉTAPE 4 : Algorithme de Kruskal (8 pts)

**Objectif** : Implémenter l'algorithme de Kruskal pour trouver le MST.

**Fichier** : `src/mst.cpp`

**Fonction** : `kruskal(g)`

**Algorithme** :
```
fonction kruskal(G):
    edges = getEdges(G)

    // 1. Trier les arêtes par poids croissant
    trier(edges, par poids)

    // 2. Créer un Union-Find pour V sommets
    uf = UnionFind(V)

    // 3. Construire le MST
    mst = []
    pour chaque arête (u, v, w) dans edges triées:
        si !uf.connected(u, v):      // Pas de cycle ?
            mst.ajouter({u, v, w})   // Ajouter au MST
            uf.unite(u, v)           // Fusionner les composantes

    retourner mst
```

**En C++** (tri avec lambda) :
```cpp
std::sort(edges.begin(), edges.end(),
    [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });
```

**Déroulement sur graph_test.txt** :

| # | Arête | Poids | Action | Composantes |
|---|-------|-------|--------|-------------|
| 1 | A—C | 3 | Ajouter | {A,C} {B} {D} {E} {F} {G} |
| 2 | A—D | 5 | Ajouter | {A,C,D} {B} {E} {F} {G} |
| 3 | C—E | 5 | Ajouter | {A,C,D,E} {B} {F} {G} |
| 4 | D—F | 6 | Ajouter | {A,C,D,E,F} {B} {G} |
| 5 | A—B | 7 | Ajouter | {A,B,C,D,E,F} {G} |
| 6 | B—E | 7 | **Refuser** (cycle) | — |
| 7 | B—C | 8 | **Refuser** (cycle) | — |
| 8 | B—D | 9 | **Refuser** (cycle) | — |
| 9 | E—G | 9 | Ajouter | {A,B,C,D,E,F,G} |
| — | Terminé | — | 6 arêtes = V-1 | **MST complet** |

**MST** : {(A,C,3), (A,D,5), (C,E,5), (D,F,6), (A,B,7), (E,G,9)} → **poids total = 35**

**Complexité** : O(E log E) pour le tri, O(E × α(V)) pour Union-Find → **O(E log E)**

---

### ÉTAPE 5 : Utilitaires MST (3 pts)

**Objectif** : Calculer le poids total et afficher le MST.

**Fichier** : `src/mst.cpp`

**Fonction** : `mstWeight(mst)`

**Algorithme** :
```
fonction mstWeight(mst):
    total = 0
    pour chaque arête e dans mst:
        total += e.weight
    retourner total
```

**Fonction** : `printMST(mst, g)`

**Algorithme** :
```
fonction printMST(mst, G):
    afficher "Arbre Couvrant Minimal (|mst| arêtes) :"
    pour chaque arête (u, v, w) dans mst:
        afficher "  " + G.getVertexName(u) + " — " + G.getVertexName(v) + " (poids: " + w + ")"
    afficher "Poids total : " + mstWeight(mst)
```

---

## ⚠️ Pièges à Éviter

| # | Piège | Solution |
|---|-------|----------|
| 1 | Doublons dans `getEdges` | Condition `u < v` obligatoire |
| 2 | Find sans compression | `parent[x] = find(parent[x])` — une seule ligne ! |
| 3 | Unite sans `find()` | Comparer `find(x)` et `find(y)`, pas `x` et `y` |
| 4 | Oublier le tri | Kruskal EXIGE les arêtes triées par poids croissant |
| 5 | Cycle non détecté | Vérifier `!uf.connected(u, v)` AVANT d'ajouter |
| 6 | `rank` au lieu de `rank_` | `rank` peut entrer en conflit → utiliser `rank_` |

---

## 📊 Complexité Comparée

| Structure | find() | unite() | connected() |
|-----------|--------|---------|-------------|
| Sans optimisation | O(n) | O(n) | O(n) |
| Union par rang | O(log n) | O(log n) | O(log n) |
| Rang + compression | O(α(n)) ≈ O(1) | O(α(n)) ≈ O(1) | O(α(n)) ≈ O(1) |

**α(n)** = fonction inverse d'Ackermann, quasi-constante (α(n) ≤ 4 pour tout n < 10^80)

---

## 📋 Les 7 Fonctions à Implémenter

| # | Fonction | Fichier | Étape | Points |
|---|----------|---------|-------|--------|
| 1 | `find(x)` | union_find.cpp | 1 | 2 pts |
| 2 | `unite(x, y)` | union_find.cpp | 2 | 2.5 pts |
| 3 | `connected(x, y)` | union_find.cpp | 2 | 1.5 pts |
| 4 | `getEdges(g)` | mst.cpp | 3 | 4 pts |
| 5 | `kruskal(g)` | mst.cpp | 4 | 8 pts |
| 6 | `mstWeight(mst)` | mst.cpp | 5 | 1.5 pts |
| 7 | `printMST(mst, g)` | mst.cpp | 5 | 1.5 pts |

**+ Qualité du code : +2 pts bonus**

---

## 📚 Références

- **Slides Séance 5** : Pages sur Kruskal et Union-Find
- **Algorithmes** : Cormen et al. (CLRS), Chapitre 23 (MST)
- **README** : [../README.md](../README.md)

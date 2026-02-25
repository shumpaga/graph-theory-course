# TPE5 - Arbre Couvrant Minimal : Kruskal & Union-Find

## ESGC VERECHAGUINE A.K. - L2 GI2 - 2025-2026

---

## Mission SBEE

Vous travaillez pour la **SBEE** (Société Béninoise d'Énergie Électrique). Votre mission : trouver le **réseau électrique de coût minimal** reliant tous les villages d'une commune. Pour cela, vous allez construire pas à pas la structure **Union-Find**, puis l'utiliser dans l'algorithme de **Kruskal**.

**Approche pédagogique** : on commence par une version simple (naïve) qui marche. Puis on découvre ses limites. Puis on l'améliore, une optimisation à la fois.

---

## Les 6 Étapes

| Étape | Objectif | Points | Philosophie |
|-------|----------|--------|-------------|
| 1 | Union-Find naïf | 4 | Comprendre la structure de base |
| 2 | Mesurer le problème | 2 | Voir POURQUOI c'est lent |
| 3 | Compression de chemin | 4 | Première optimisation : find rapide |
| 4 | Union par rang | 3 | Deuxième optimisation : arbres plats |
| 5 | Algorithme de Kruskal | 7 | L'algorithme principal du MST |
| 6 | Affichage & utilitaires | 2 | Afficher le résultat joliment |
| — | Qualité code | +3 | Commentaires, nommage, clarté |
| **TOTAL** | | **25** | |

---

## Comprendre Avant de Coder

### Le problème : détecter les cycles

Kruskal ajoute les arêtes une par une, de la plus légère à la plus lourde. Mais il faut **refuser** une arête si elle crée un cycle. Comment savoir si deux sommets sont déjà reliés ?

C'est là qu'intervient **Union-Find** : une structure qui gère des ensembles disjoints.

### L'idée : chaque groupe a un chef

```
parent[] : chaque élément pointe vers son "chef"
Au début : parent[0]=0, parent[1]=1, parent[2]=2, ...
           (chacun est son propre chef)

Après unite(1, 3) : parent[3] = 1  → le chef de 3 est 1
Après unite(1, 5) : parent[5] = 1  → le chef de 5 est 1

find(3) → parent[3]=1, parent[1]=1 → racine = 1
find(5) → parent[5]=1, parent[1]=1 → racine = 1
find(3) == find(5) → OUI, même groupe !
```

---

## ÉTAPE 1 : Union-Find Naïf (4 pts)

**Objectif** : une version simple qui MARCHE, sans optimisation.

**Fichier** : `src/union_find.cpp`

### Fonction 1.1 : Constructeur `UnionFind(int n)`

```
Chaque élément est son propre chef :
  pour i de 0 à n-1 :
      parent[i] = i
```

### Fonction 1.2 : `find(x)` — version NAÏVE

```
fonction find(x):
    tant que parent[x] != x:
        x = parent[x]        // on remonte d'un cran
    retourner x               // c'est la racine
```

C'est une simple boucle while. Pas d'optimisation pour l'instant !

### Fonction 1.3 : `unite(x, y)` — version NAÏVE

```
fonction unite(x, y):
    rx = find(x)
    ry = find(y)
    si rx == ry : ne rien faire  // déjà dans le même groupe
    sinon : parent[ry] = rx     // choix arbitraire
```

### Fonction 1.4 : `connected(x, y)`

```
fonction connected(x, y):
    retourner find(x) == find(y)
```

**À ce stade** : votre Union-Find fonctionne ! `make test` → les tests de l'étape 1 passent.

---

## ÉTAPE 2 : Mesurer le Problème (2 pts)

**Objectif** : comprendre POURQUOI la version naïve est lente.

Le `find()` naïf remonte la chaîne parent par parent. Avec des unions en ordre inverse :

```
unite(8, 9)   →  8 ← 9
unite(7, 8)   →  7 ← 8 ← 9
unite(6, 7)   →  6 ← 7 ← 8 ← 9
...
unite(0, 1)   → chaîne : 0 ← 1 ← 2 ← ... ← 9

find(9) doit remonter 9 niveaux → O(n) opérations !
```

### Fonction 2.1 : `count_operations(x)`

```
fonction count_operations(x):
    compteur = 0
    tant que parent[x] != x:
        x = parent[x]
        compteur++
    retourner compteur          // NE PAS modifier parent[] !
```

**Le test** : une chaîne de 10 éléments construite en ordre inverse → `count_operations(9) >= 8` avec la version naïve. C'est la preuve que le find naïf est **O(n)** par appel.

---

## ÉTAPE 3 : Compression de Chemin (4 pts)

**Objectif** : quand on cherche la racine, on raccourcit le chemin.

### L'idée en image

```
AVANT find(4) :          APRÈS find(4) :
    0                         0
    |                       / | \ \
    1                      1  2  3  4
    |
    2                     Tous pointent vers 0 !
    |                     Les prochains find() = O(1)
    3
    |
    4
```

### Fonction 3.1 : `find(x)` — avec COMPRESSION

```
fonction find(x):
    si parent[x] == x:
        retourner x
    sinon:
        parent[x] = find(parent[x])   // LA ligne magique !
        retourner parent[x]
```

**Attention** : cette version REMPLACE la version naïve de l'étape 1.

**Le test** : après `find(9)` sur une chaîne de 10, `count_operations(9)` ne fait plus que **0-1 opération** au lieu de 9.

---

## ÉTAPE 4 : Union par Rang (3 pts)

**Objectif** : quand on fusionne, on choisit INTELLIGEMMENT qui devient le chef.

### Le problème de l'étape 1

Dans la version naïve, `parent[ry] = rx` est arbitraire. Si on rattache un grand arbre sous un petit :

```
MAUVAIS :                 BON :
  1 (petit)                0 (grand)
  |                       / | \
  0 (grand!)             2   3   1 (petit)
 / \
2   3                    → arbre plat !
→ chaîne longue !
```

### Fonction 4.1 : `unite(x, y)` — avec RANG

```
fonction unite(x, y):
    rx = find(x)
    ry = find(y)
    si rx == ry : retourner

    si rank_[rx] < rank_[ry]:
        parent[rx] = ry           // petit sous grand
    sinon si rank_[rx] > rank_[ry]:
        parent[ry] = rx           // petit sous grand
    sinon:
        parent[ry] = rx           // même rang : choix arbitraire
        rank_[rx]++               // la hauteur augmente de 1
```

**Résultat combiné** (compression + rang) : chaque opération coûte **O(α(n)) ≈ O(1)**. α(n) ≤ 4 pour tout n < 10^80 !

---

## ÉTAPE 5 : Algorithme de Kruskal (7 pts)

**Fichier** : `src/mst.cpp`

### L'algorithme en 4 lignes

```
1. Extraire et trier toutes les arêtes par poids croissant
2. Créer un UnionFind(V)
3. Pour chaque arête (u, v, w) dans l'ordre :
   Si !connected(u, v) : ajouter au MST + unite(u, v)
4. Retourner le MST
```

### Fonction 5.1 : `getEdges(g)`

```
fonction getEdges(G):
    edges = []
    pour chaque sommet u de 0 à V-1:
        pour chaque voisin (v, poids) de u:
            si u < v:                        // Éviter les doublons !
                edges.ajouter({u, v, poids})
    retourner edges
```

**Pourquoi `u < v` ?** Le graphe est non orienté : chaque arête apparaît deux fois dans la liste d'adjacence. En ne gardant que `u < v`, on obtient exactement **E arêtes**.

### Fonction 5.2 : `kruskal(g)`

```
fonction kruskal(G):
    edges = getEdges(G)
    trier(edges, par poids croissant)
    uf = UnionFind(V)

    mst = []
    pour chaque arête (u, v, w) dans edges triées:
        si !uf.connected(u, v):      // Pas de cycle ?
            mst.ajouter({u, v, w})   // Ajouter au MST
            uf.unite(u, v)           // Fusionner

    retourner mst
```

**En C++ (tri)** :
```cpp
std::sort(edges.begin(), edges.end(),
    [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });
```

### Déroulement sur graph_test.txt (7 sommets A-G)

| # | Arête | Poids | Action | Pourquoi ? |
|---|-------|-------|--------|------------|
| 1 | A — C | 3 | Accepter | A et C pas connectés |
| 2 | A — D | 5 | Accepter | D pas encore relié |
| 3 | C — E | 5 | Accepter | E pas encore relié |
| 4 | D — F | 6 | Accepter | F pas encore relié |
| 5 | A — B | 7 | Accepter | B pas encore relié |
| 6 | B — E | 7 | **Refuser** | B et E déjà connectés ! |
| 7 | E — G | 9 | Accepter | G pas encore relié → MST complet ! |

**MST** = {(A,C,3), (A,D,5), (C,E,5), (D,F,6), (A,B,7), (E,G,9)} → **poids total = 35**

**Complexité** : O(E log E) pour le tri + O(E × α(V)) pour Union-Find → **O(E log E)**

---

## ÉTAPE 6 : Utilitaires (2 pts)

**Fichier** : `src/mst.cpp`

### Fonction 6.1 : `mstWeight(mst)`

```
fonction mstWeight(mst):
    total = 0
    pour chaque arête e dans mst:
        total += e.weight
    retourner total
```

### Fonction 6.2 : `printMST(mst, g)`

```
fonction printMST(mst, G):
    afficher "Arbre Couvrant Minimal (|mst| arêtes) :"
    pour chaque arête (u, v, w) dans mst:
        afficher "  " + G.getVertexName(u) + " — " + G.getVertexName(v) + " (poids: " + w + ")"
    afficher "Poids total : " + mstWeight(mst)
```

---

## Pièges à Éviter

| # | Piège | Symptôme | Solution |
|---|-------|----------|----------|
| 1 | Oublier `parent[i] = i` | find() retourne toujours 0 | Boucle d'init dans constructeur |
| 2 | Oublier `rx == ry` dans unite | MST contient des cycles | `if (rx == ry) return;` |
| 3 | Compression sans récursion | find rapide mais compression partielle | `parent[x] = find(parent[x])` récursif |
| 4 | Tri dans le mauvais sens | Arbre couvrant MAXIMAL | `a.weight < b.weight` (croissant) |
| 5 | Doublons dans getEdges | Chaque arête en double | Condition `u < v` |
| 6 | `rank` au lieu de `rank_` | Conflit avec `std::rank` | Utiliser `rank_` |

---

## Complexité Comparée

| Structure | find() | unite() | connected() |
|-----------|--------|---------|-------------|
| Naïf (étapes 1-2) | O(n) | O(n) | O(n) |
| + Compression (étape 3) | O(log n) amorti | O(log n) | O(log n) |
| + Rang (étape 4) | O(α(n)) ≈ O(1) | O(α(n)) ≈ O(1) | O(α(n)) ≈ O(1) |

**α(n)** = fonction inverse d'Ackermann, quasi-constante (α(n) ≤ 4 pour tout n < 10^80)

---

## Récapitulatif des Fonctions

| # | Fonction | Fichier | Étape | Points |
|---|----------|---------|-------|--------|
| 1 | `UnionFind(n)` | union_find.cpp | 1 | — |
| 2 | `find(x)` naïf puis compressé | union_find.cpp | 1→3 | 4+4 |
| 3 | `unite(x, y)` naïf puis rang | union_find.cpp | 1→4 | 4+3 |
| 4 | `connected(x, y)` | union_find.cpp | 1 | — |
| 5 | `count_operations(x)` | union_find.cpp | 2 | 2 |
| 6 | `getEdges(g)` | mst.cpp | 5 | — |
| 7 | `kruskal(g)` | mst.cpp | 5 | 7 |
| 8 | `mstWeight(mst)` | mst.cpp | 6 | — |
| 9 | `printMST(mst, g)` | mst.cpp | 6 | 2 |

**+ Qualité du code : +3 pts bonus**

---

## Références

- **Slides Séance 5** : Pages sur Kruskal et Union-Find
- **Algorithmes** : Cormen et al. (CLRS), Chapitre 23 (MST)
- **README** : [../README.md](../README.md)

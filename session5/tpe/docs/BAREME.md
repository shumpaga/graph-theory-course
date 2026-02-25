# Barème de Notation - TPE5 Kruskal & Union-Find

## ESGC VERECHAGUINE A.K. - L2 GI2 - 2025-2026

---

## Distribution des Points

| Étape | Points | Description |
|-------|--------|-------------|
| Étape 1 : Union-Find naïf | 4 pts | La base fonctionne |
| Étape 2 : Mesurer le problème | 2 pts | On mesure que c'est O(n) |
| Étape 3 : Compression de chemin | 4 pts | Compression effective, find rapide |
| Étape 4 : Union par rang | 3 pts | Arbres équilibrés |
| Étape 5 : Algorithme de Kruskal | 7 pts | MST correct sur 2 graphes |
| Étape 6 : Utilitaires | 2 pts | Affichage fonctionnel |
| Qualité code | +3 pts | Commentaires, nommage, clarté |
| **TOTAL** | **25 pts** | |

---

## ÉTAPE 1 : UNION-FIND NAÏF (4 points)

### Fonctions : Constructeur + find() naïf + unite() naïf + connected()

| Critère | Points | Description |
|---------|--------|-------------|
| Constructeur `parent[i] = i` | 0.5 | Initialisation correcte |
| `find()` avec boucle while | 1.0 | Remonte jusqu'à la racine |
| `unite()` avec `parent[ry] = rx` | 1.0 | Rattachement arbitraire |
| Vérifie `rx == ry` dans unite | 0.5 | Pas de boucle si déjà unis |
| `connected()` via find | 1.0 | `return find(x) == find(y)` |

### Tests : 5 tests (1-5)

| Test | Vérifie |
|------|---------|
| 1 | `find(i) == i` après création |
| 2 | `connected(0, 1) == false` initialement |
| 3 | `find(3) == 3` sans union |
| 4 | `unite(0,1)` → `connected(0,1)` |
| 5 | Transitivité via chaîne d'unions |

---

## ÉTAPE 2 : MESURER LE PROBLÈME (2 points)

### Fonction : `count_operations(x)`

| Critère | Points | Description |
|---------|--------|-------------|
| Boucle while correcte | 1.0 | Parcourt le chemin sans modifier parent |
| Compteur correct | 1.0 | Retourne le nombre de remontées |

### Tests : 2 tests (6-7)

| Test | Vérifie |
|------|---------|
| 6 | `count_operations(0) == 0` sur singleton |
| 7 | Chaîne de 10 éléments : assertion adaptative (naïf OU rang) |

---

## ÉTAPE 3 : COMPRESSION DE CHEMIN (4 points)

### Modification : `find(x)` avec compression

| Critère | Points | Description |
|---------|--------|-------------|
| Cas de base correct | 0.5 | `if (parent[x] == x) return x` |
| Appel récursif | 1.0 | `find(parent[x])` |
| Compression effective | 2.0 | `parent[x] = find(parent[x])` |
| Retour correct | 0.5 | `return parent[x]` |

### Tests : 3 tests (8-10)

| Test | Vérifie |
|------|---------|
| 8 | Après compression : `count_operations(9) <= 1` |
| 9 | Après `find(9)`, `getParent(9)` pointe vers la racine |
| 10 | `find(0) == find(1)` après `unite(0,1)` |

---

## ÉTAPE 4 : UNION PAR RANG (3 points)

### Modification : `unite(x, y)` avec rang

| Critère | Points | Description |
|---------|--------|-------------|
| Compare les racines | 0.5 | `rx = find(x)`, `ry = find(y)` |
| Attache petit sous grand | 1.5 | Comparaison de `rank_[rx]` et `rank_[ry]` |
| Incrémente le rang | 1.0 | `rank_[rx]++` quand même rang |

### Tests : 2 tests (11-12)

| Test | Vérifie |
|------|---------|
| 11 | 8 éléments, unions par paires : hauteur <= 3 |
| 12 | `unite(x,y)` quand déjà connectés : structure intacte |

---

## ÉTAPE 5 : ALGORITHME DE KRUSKAL (7 points)

### Fonctions : `getEdges()` + `kruskal()`

| Critère | Points | Description |
|---------|--------|-------------|
| `getEdges()` : parcours adjacence | 1.0 | Double boucle sommets + voisins |
| `getEdges()` : condition `u < v` | 1.0 | Pas de doublons |
| `kruskal()` : tri par poids | 1.0 | `std::sort` avec lambda |
| `kruskal()` : création UnionFind | 0.5 | `UnionFind(V)` |
| `kruskal()` : test `!connected()` | 1.5 | Vérification avant ajout |
| `kruskal()` : ajout + unite | 1.5 | Ajout au MST + fusion |
| Retour correct | 0.5 | `vector<Edge>` contenant le MST |

### Tests : 5 tests (13-17)

| Test | Vérifie |
|------|---------|
| 13 | graph_test : poids = 35 |
| 14 | graph_test : V-1 = 6 arêtes |
| 15 | Graphe trivial (2 sommets) : poids = 5 |
| 16 | graph_commune : poids = 44 |
| 17 | getEdges : exactement 11 arêtes (pas 22) |

---

## ÉTAPE 6 : UTILITAIRES (2 points)

### Fonctions : `mstWeight()` + `printMST()`

| Critère | Points | Description |
|---------|--------|-------------|
| `mstWeight()` : somme des poids | 1.0 | Boucle + accumulation |
| `printMST()` : affichage arêtes | 0.5 | Avec `getVertexName()` |
| `printMST()` : poids total | 0.5 | Affiche le total |

### Tests : 3 tests (18-20)

| Test | Vérifie |
|------|---------|
| 18 | `mstWeight({}) == 0` |
| 19 | `printMST` avec MST valide : pas de crash |
| 20 | `printMST` avec MST vide : pas de crash |

---

## QUALITÉ DU CODE (+3 points)

| Critère | Points | Description |
|---------|--------|-------------|
| Commentaires | 1.5 | Explications des étapes clés (compression, rang) |
| Nommage | 0.5 | Variables avec noms explicites |
| Indentation | 0.5 | Code bien formaté et lisible |
| Clarté | 0.5 | Structure logique du code |

---

## PÉNALITÉS

| Faute | Pénalité |
|-------|----------|
| Code ne compile pas | **0/25** |
| Segmentation fault | **-2 points par fonction** |
| Pas de nom/prénom dans les fichiers .cpp | **-0.5 point** |
| Rendu en retard | **-2 pts/jour** |

---

## Calcul de la Note Finale

**Formule** :
```
Note = Étape1 + Étape2 + Étape3 + Étape4 + Étape5 + Étape6 + Qualité
     = 4 + 2 + 4 + 3 + 7 + 2 + 3 = 25 pts
```

**Exemples** :
- 4 + 2 + 4 + 3 + 7 + 2 + 3 = 25 pts → **25/25**
- 4 + 2 + 4 + 3 + 7 + 2 + 0 = 22 pts → **22/25**
- 4 + 2 + 4 + 3 + 0 + 0 + 0 = 13 pts → **13/25**
- 4 + 2 + 0 + 0 + 0 + 0 + 0 = 6 pts → **6/25**
- 4 + 0 + 0 + 0 + 0 + 0 + 0 = 4 pts → **4/25**

---

## Checklist Avant Rendu

- [ ] Les **6 étapes** sont implémentées
- [ ] Code compile sans erreur : `make clean && make test`
- [ ] Tests passent : viser 20/20
- [ ] Nom/Prénom en haut de `union_find.cpp` et `mst.cpp`
- [ ] Code commenté (surtout : expliquer la compression et le rang)
- [ ] ZIP créé : `NOM_Prenom_TPE5.zip`
- [ ] ZIP contient : `union_find.cpp` + `mst.cpp` + `capture_tests.png`
- [ ] Capture montre résultats de `./bin/test_mst`

---

**Bonne chance !**

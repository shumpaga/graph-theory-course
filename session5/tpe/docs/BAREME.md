# Barème de Notation - TPE5 Kruskal & Union-Find

## ESGC VERECHAGUINE A.K. - L2 GI2 - 2025-2026

---

## 📊 Distribution des Points

| Étape | Points | Pourcentage |
|-------|--------|-------------|
| Étape 1 : UF Constructeur & Find | 4 pts | 16% |
| Étape 2 : UF Unite & Connected | 4 pts | 16% |
| Étape 3 : Extraction des arêtes | 4 pts | 16% |
| Étape 4 : Algorithme de Kruskal | 8 pts | 32% |
| Étape 5 : Utilitaires MST | 3 pts | 12% |
| Qualité code | +2 pts | Bonus |
| **TOTAL** | **25 pts** | |

---

## 🎯 ÉTAPE 1 : UNION-FIND — CONSTRUCTEUR & FIND (4 points)

### Constructeur `UnionFind(n)` — fourni

Le constructeur est fourni : `parent[i] = i`, `rank_[i] = 0`.

### Fonction : `find(x)` — 2 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Cas de base correct | 0.5 | `if (parent[x] == x) return x` |
| Récursion/itération | 0.5 | Remonte vers la racine |
| Compression de chemin | 1.0 | `parent[x] = find(parent[x])` |

### Tests : 3 tests (1-3)

| Test | Vérifie |
|------|---------|
| 1 | `parent[i] == i` après construction |
| 2 | `find(i) == i` initialement |
| 3 | Éléments distincts non connectés |

**Estimation points** : (tests passés / 3) × 4

---

## 🎯 ÉTAPE 2 : UNION-FIND — UNITE & CONNECTED (4 points)

### Fonction : `unite(x, y)` — 2.5 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Trouve les racines | 0.5 | `rx = find(x)`, `ry = find(y)` |
| Vérifie si déjà unis | 0.5 | `if (rx == ry) return` |
| Attache par rang | 1.0 | Arbre le moins profond sous le plus profond |
| Incrémente le rang | 0.5 | `rank_[rx]++` quand même rang |

### Fonction : `connected(x, y)` — 1.5 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Utilise find() | 1.0 | `return find(x) == find(y)` |
| Retour correct | 0.5 | true si même ensemble, false sinon |

### Tests : 4 tests (4-7)

| Test | Vérifie |
|------|---------|
| 4 | `unite(0,1)` → `connected(0,1)` |
| 5 | Transitivité via chaîne d'unions |
| 6 | Multiple unions croisées |
| 7 | Compression de chemin effective |

**Estimation points** : (tests passés / 4) × 4

---

## 🎯 ÉTAPE 3 : EXTRACTION DES ARÊTES (4 points)

### Fonction : `getEdges(g)` — 4 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Parcours adjacence | 1.0 | Double boucle : sommets + voisins |
| Condition `u < v` | 1.5 | Évite les doublons (graphe non orienté) |
| Construction Edge | 1.0 | `{u, v, poids}` correct |
| Nombre correct | 0.5 | Retourne exactement E arêtes |

### Tests : 2 tests (8-9)

| Test | Vérifie |
|------|---------|
| 8 | 11 arêtes extraites de graph_test |
| 9 | Aucun doublon dans la liste |

**Estimation points** : (tests passés / 2) × 4

---

## 🎯 ÉTAPE 4 : ALGORITHME DE KRUSKAL (8 points)

### Fonction : `kruskal(g)` — 8 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Appel `getEdges()` | 1.0 | Extraction des arêtes |
| Tri par poids | 1.5 | `std::sort` avec lambda/comparateur |
| Création UnionFind | 0.5 | `UnionFind(V)` |
| Boucle sur arêtes | 1.0 | Itération sur arêtes triées |
| Test `!connected()` | 1.5 | Vérification avant ajout (pas de cycle) |
| Ajout au MST + `unite()` | 1.5 | Ajout de l'arête + fusion des ensembles |
| Retour correct | 0.5 | `vector<Edge>` contenant le MST |

### Tests : 4 tests (10-13)

| Test | Vérifie |
|------|---------|
| 10 | graph_test : V-1 = 6 arêtes |
| 11 | graph_test : poids = 35 |
| 12 | graph_commune : V-1 = 9 arêtes |
| 13 | graph_commune : poids = 44 |

**Estimation points** : (tests passés / 4) × 8

---

## 🎯 ÉTAPE 5 : UTILITAIRES ET CAS LIMITES (3 points)

### Fonction : `mstWeight(mst)` — 1.5 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Parcours des arêtes | 0.5 | Boucle sur le vecteur |
| Somme des poids | 0.5 | `total += e.weight` |
| Retour correct | 0.5 | Entier représentant le poids total |

### Fonction : `printMST(mst, g)` — 1.5 pts

| Critère | Points | Description |
|---------|--------|-------------|
| Affichage arêtes | 0.5 | Chaque arête avec noms de sommets |
| Utilise `getVertexName()` | 0.5 | Noms au lieu des numéros |
| Poids total affiché | 0.5 | Somme en bas de l'affichage |

### Tests : 3 tests (14-16)

| Test | Vérifie |
|------|---------|
| 14 | `mstWeight` sur MST connu |
| 15 | Graphe K3 : MST correct |
| 16 | Graphe déconnecté : forêt couvrante |

**Estimation points** : (tests passés / 3) × 3

---

## 💻 QUALITÉ DU CODE (+2 points)

| Critère | Points | Description |
|---------|--------|-------------|
| Commentaires | 1.0 | Explications claires des étapes clés |
| Nommage | 0.5 | Variables avec noms explicites |
| Indentation | 0.5 | Code bien formaté et lisible |

**Exemples de bons commentaires** :
```cpp
// Compression de chemin : pointer directement vers la racine
parent[x] = find(parent[x]);

// Arête (u,v) ne crée pas de cycle → ajouter au MST
if (!uf.connected(u, v)) {
    mst.push_back({u, v, w});
    uf.unite(u, v);
}
```

---

## ⚠️ PÉNALITÉS

| Faute | Pénalité |
|-------|----------|
| Code ne compile pas | **0/25** |
| Segmentation fault | **-2 points par fonction** |
| Pas de nom/prénom dans les fichiers .cpp | **-0.5 point** |

---

## 🧮 Calcul de la Note Finale

**Formule** :
```
Note = Étape1 + Étape2 + Étape3 + Étape4 + Étape5 + Qualité
     = 4 + 4 + 4 + 8 + 3 + 2 = 25 pts
```

**Exemples** :
- 4 + 4 + 4 + 8 + 3 + 2 = 25 pts → **25/25**
- 4 + 4 + 4 + 8 + 0 + 0 = 20 pts → **20/25**
- 4 + 4 + 4 + 0 + 0 + 0 = 12 pts → **12/25**
- 4 + 4 + 0 + 0 + 0 + 0 = 8 pts → **8/25**
- 4 + 0 + 0 + 0 + 0 + 0 = 4 pts → **4/25**

---

## 📋 Checklist Avant Rendu

- [ ] Les **7** fonctions sont implémentées : `find`, `unite`, `connected`, `getEdges`, `kruskal`, `mstWeight`, `printMST`
- [ ] Code compile sans erreur : `make clean && make test`
- [ ] Tests passent : viser 16/16
- [ ] Nom/Prénom en haut de `union_find.cpp` et `mst.cpp`
- [ ] Code commenté (étapes clés + complexité documentée)
- [ ] ZIP créé : `NOM_Prenom_TPE5.zip`
- [ ] ZIP contient : `union_find.cpp` + `mst.cpp` + `capture_tests.png`
- [ ] Capture montre résultats de `./bin/test_mst`

---

## 🎯 Conseils pour Maximiser la Note

1. **Étapes 1-2** : Union-Find d'abord ! Sans lui, Kruskal ne fonctionne pas (10 pts)
2. **Étape 3** : `getEdges` est simple, ne perdez pas de points ici (4 pts)
3. **Étape 4** : Kruskal = tri + boucle + Union-Find — si les étapes 1-3 marchent, c'est facile
4. **Étape 5** : Points faciles — juste une somme et un affichage (3 pts)
5. **Commenter le code** : +2 points faciles !

---

**Bonne chance !**

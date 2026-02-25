# TPE5 - Arbre Couvrant Minimal : Kruskal & Union-Find

## Théorie des Graphes - L2 Génie Informatique

**Institution** : ESGC VERECHAGUINE A.K. (Cotonou, Bénin)
**Enseignant** : M. Alexandre GBAGUIDI AISSE
**Année académique** : 2025-2026
**Durée** : 2-3 heures

---

## Mission

Vous travaillez pour la **SBEE** (Société Béninoise d'Énergie Électrique). Votre mission : trouver le réseau électrique de **coût minimal** reliant tous les villages d'une commune.

**Approche** : on commence par une version **naïve** qui marche. Puis on mesure ses limites. Puis on l'améliore, **une optimisation à la fois**.

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
| **TOTAL** | | **25** | **20 tests** |

---

## Structure du Projet

```
session5/student/
├── README.md                  ← Ce fichier
├── Makefile                   ← Compilation
├── include/
│   ├── graph.h               ✓ Graphe pondéré (fourni)
│   ├── union_find.h          ✓ Déclarations Union-Find (fourni)
│   └── mst.h                 ✓ Déclarations MST + struct Edge (fourni)
├── src/
│   ├── graph.cpp             ✓ Implémentation Graph (fourni)
│   ├── union_find.cpp        ⚠️ À COMPLÉTER (étapes 1-4)
│   ├── mst.cpp               ⚠️ À COMPLÉTER (étapes 5-6)
│   └── main.cpp              ✓ Menu interactif (fourni)
├── tests/
│   └── test_mst.cpp          ✓ 20 tests automatiques
├── data/
│   ├── graph_test.txt        ✓ 7 sommets (A-G), 11 arêtes
│   └── graph_commune.txt     ✓ 10 villages, 18 routes
└── docs/
    ├── ENONCE.md             ← Algorithmes détaillés
    └── BAREME.md             ← Grille de notation
```

---

## Compilation et Tests

### Compilation
```bash
make clean       # Nettoyer
make             # Compiler le programme principal
make test        # Compiler et lancer les 20 tests
```

### Exécution
```bash
# Tests automatiques (20 tests)
./test_mst

# Programme interactif
./main
```

### Aide
```bash
make help        # Liste des commandes disponibles
```

---

## Fonctions à Implémenter

### Fichier : `src/union_find.cpp` (étapes 1-4)

| Étape | Fonction | Points | Description |
|-------|----------|--------|-------------|
| 1 | `UnionFind(n)` | — | Constructeur : `parent[i] = i` |
| 1 | `find(x)` naïf | 4 | Boucle while (pas d'optimisation) |
| 1 | `unite(x, y)` naïf | — | `parent[ry] = rx` (arbitraire) |
| 1 | `connected(x, y)` | — | `find(x) == find(y)` |
| 2 | `count_operations(x)` | 2 | Compter les remontées de find |
| 3 | `find(x)` compressé | 4 | Remplacer while par récursion + compression |
| 4 | `unite(x, y)` par rang | 3 | Comparer `rank_[]`, petit sous grand |

### Fichier : `src/mst.cpp` (étapes 5-6)

| Étape | Fonction | Points | Description |
|-------|----------|--------|-------------|
| 5 | `getEdges(g)` | 7 | Extraire les arêtes sans doublons (`u < v`) |
| 5 | `kruskal(g)` | — | Tri + Union-Find → MST |
| 6 | `mstWeight(mst)` | 2 | Somme des poids du MST |
| 6 | `printMST(mst, g)` | — | Affichage avec noms de sommets |

---

## Fichiers de Données

### `data/graph_test.txt` — Graphe TD5 (7 sommets)
```
0=A  1=B  2=C  3=D  4=E  5=F  6=G
MST attendu : poids = 35
Arêtes MST : (A-C,3) (A-D,5) (C-E,5) (D-F,6) (A-B,7) (E-G,9)
```

### `data/graph_commune.txt` — Réseau routier (10 villages)
```
0=Mairie  1=Marche  2=Ecole  3=Dispensaire  4=Eglise
5=Mosquee  6=Stade  7=Gare  8=Pont  9=Champ
MST attendu : poids = 44, 9 arêtes
```

---

## Pièges Fréquents

| # | Piège | Solution |
|---|-------|----------|
| 1 | Oublier `parent[i] = i` dans constructeur | find() retourne n'importe quoi |
| 2 | Oublier `rx == ry` dans unite | Crée des boucles infinies |
| 3 | Compression sans récursion | `parent[x] = find(parent[x])` récursif |
| 4 | Tri dans le mauvais sens | `a.weight < b.weight` (croissant !) |
| 5 | Doublons dans getEdges | Ne garder que `u < v` |
| 6 | Modifier parent dans count_operations | Juste compter, NE PAS modifier ! |

---

## Rappel : Algorithme de Kruskal

```
1. Extraire et trier toutes les arêtes par poids croissant
2. Créer un Union-Find avec V éléments
3. Pour chaque arête (u, v, w) dans l'ordre :
   - Si u et v ne sont PAS connectés :
     - Ajouter (u, v, w) au MST
     - unite(u, v)
4. Retourner le MST
```

**Complexité** : O(E log E) pour le tri + O(E × α(V)) pour Union-Find ≈ **O(E log E)**

---

## Tests Automatiques

```bash
./test_mst
```

**Sortie attendue (20 tests)** :
```
=== TPE5 : Tests MST (Kruskal & Union-Find) ===

--- Étape 1 : Union-Find naïf ---
  [PASS] test_uf_create_find_self
  [PASS] test_uf_create_not_connected
  ...

=== Résultat : 20/20 tests réussis ===
```

---

## Documentation Complète

- **Algorithmes détaillés** : [docs/ENONCE.md](docs/ENONCE.md)
- **Barème de notation** : [docs/BAREME.md](docs/BAREME.md)

---

## Rendu

### Format
- **Fichier** : `NOM_Prenom_TPE5.zip`
- **Contenu** : `union_find.cpp` + `mst.cpp` + `capture_tests.png`
- **Deadline** : Début Séance 6

### Checklist
- [ ] Les **6 étapes** sont implémentées
- [ ] Code compile : `make clean && make test`
- [ ] Tests passent : viser 20/20
- [ ] Nom/Prénom en haut de `union_find.cpp` et `mst.cpp`
- [ ] Code commenté (surtout : compression et rang)
- [ ] Capture montre résultats de `./test_mst`

---

## Conseils

1. **Étape 1 d'abord** : le find naïf (boucle while) suffit pour commencer
2. **Tester après chaque étape** : `make test` à chaque fois
3. **Étape 2 = motivation** : comprendre le problème avant de l'optimiser
4. **Étape 3 = une seule ligne** : `parent[x] = find(parent[x])`
5. **Étape 5 utilise tout** : si les étapes 1-4 marchent, Kruskal est facile
6. **Dessiner le graphe** : tracer le MST à la main d'abord
7. **Pour le debug** : afficher `parent[]` après chaque `unite()`

---

**Bon courage !**

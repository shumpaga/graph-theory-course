# TPE5 - Arbre Couvrant Minimal : Kruskal & Union-Find

## Théorie des Graphes - L2 Génie Informatique

**Institution** : ESGC VERECHAGUINE A.K. (Cotonou, Bénin)
**Enseignant** : M. Alexandre GBAGUIDI AISSE
**Année académique** : 2025-2026
**Durée** : 2-3 heures

---

## 🎯 Objectifs

Dans ce TPE, vous allez implémenter l'algorithme de **Kruskal** pour trouver l'**Arbre Couvrant Minimal** (Minimum Spanning Tree) d'un graphe pondéré. Pour cela, vous devrez d'abord construire la structure **Union-Find** (Disjoint Set Union) qui est au coeur de Kruskal :

1. **Étape 1** : Construire l'Union-Find (constructeur + find avec compression)
2. **Étape 2** : Compléter l'Union-Find (unite par rang + connected)
3. **Étape 3** : Extraire les arêtes du graphe (sans doublons)
4. **Étape 4** : Implémenter l'algorithme de Kruskal
5. **Étape 5** : Utilitaires : poids total et affichage du MST

---

## 📁 Structure du Projet

```
session5/tpe/
├── README.md                  ← Ce fichier
├── Makefile                   ← Compilation
├── include/
│   ├── graph.h               ✓ Graphe pondéré (fourni)
│   ├── union_find.h          ✓ Déclarations Union-Find (fourni)
│   └── mst.h                 ✓ Déclarations MST + struct Edge (fourni)
├── src/
│   ├── graph.cpp             ✓ Implémentation Graph (fourni)
│   ├── union_find.cpp        ⚠️ À COMPLÉTER (3 fonctions)
│   ├── mst.cpp               ⚠️ À COMPLÉTER (4 fonctions)
│   └── main.cpp              ✓ Menu interactif (fourni)
├── tests/
│   └── test_mst.cpp          ✓ 16 tests automatiques
├── data/
│   ├── graph_test.txt        ✓ 7 sommets (A-G), 11 arêtes
│   └── graph_commune.txt     ✓ 10 villages, 18 routes
└── docs/
    ├── ENONCE.md             ← Algorithmes détaillés
    └── BAREME.md             ← Grille de notation
```

---

## 🚀 Compilation et Tests

### Compilation
```bash
make clean       # Nettoyer
make             # Compiler le programme principal (./main)
make test        # Compiler et lancer les 16 tests
```

### Exécution
```bash
# Tests automatiques (16 tests)
./test_mst

# Programme interactif
./main
```

### Aide
```bash
make help        # Liste des commandes disponibles
```

---

## 📝 Fonctions à Implémenter

### Fichier : `src/union_find.cpp` (3 fonctions)

| Étape | Fonction | Points | Description |
|-------|----------|--------|-------------|
| 1 | `find(x)` | 2 | Recherche avec compression de chemin |
| 2 | `unite(x, y)` | 2.5 | Fusion par rang |
| 2 | `connected(x, y)` | 1.5 | Test de connexité via find |

### Fichier : `src/mst.cpp` (4 fonctions)

| Étape | Fonction | Points | Description |
|-------|----------|--------|-------------|
| 3 | `getEdges(g)` | 4 | Extraire les arêtes sans doublons |
| 4 | `kruskal(g)` | 8 | Algorithme de Kruskal complet |
| 5 | `mstWeight(mst)` | 1.5 | Somme des poids du MST |
| 5 | `printMST(mst, g)` | 1.5 | Affichage avec noms de sommets |

| | Qualité du code | +2 | Commentaires, nommage, indentation |

**Total : 23 points + 2 bonus = 25 points**

---

## 📊 Fichiers de Données

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

## ⚠️ Pièges Fréquents

| # | Piège | Solution |
|---|-------|----------|
| 1 | Doublons dans getEdges | Ne garder que `u < v` pour éviter les doublons |
| 2 | Oublier la compression dans find | `parent[x] = find(parent[x])` — sinon O(n) au lieu de O(α(n)) |
| 3 | Union sans vérifier find | Toujours comparer les **racines**, pas x et y directement |
| 4 | Arêtes non triées avant Kruskal | `std::sort` avec lambda sur le poids |
| 5 | Oublier de vérifier `connected()` | Sans ce test, Kruskal ajoute des cycles ! |
| 6 | MST sur graphe déconnecté | Normal d'avoir < V-1 arêtes (forêt couvrante) |

---

## 🎓 Rappel : Algorithme de Kruskal

```
1. Extraire et trier toutes les arêtes par poids croissant
2. Créer un Union-Find avec V éléments
3. Pour chaque arête (u, v, w) dans l'ordre :
   - Si u et v ne sont PAS connectés :
     - Ajouter (u, v, w) au MST
     - unite(u, v)
4. Retourner le MST
```

**Complexité** : O(E log E) pour le tri + O(E × α(V)) pour les opérations Union-Find ≈ **O(E log E)**

---

## 🧪 Tests Automatiques

```bash
./test_mst
```

**Sortie attendue (16 tests)** :
```
═══════════════════════════════════════════════
  TESTS TPE5 - KRUSKAL & UNION-FIND
═══════════════════════════════════════════════

=== ÉTAPE 1 : UNION-FIND — CONSTRUCTEUR & FIND ===
  ✅ Test 1 : Constructeur : parent[i] == i pour 5 éléments
  ✅ Test 2 : find(i) == i initialement pour tout i
  ✅ Test 3 : Éléments distincts non connectés initialement
  ...

  TOTAL : 16/16 tests passés
  NOTE ESTIMÉE : 23/25 pts (+ qualité code : +2 pts)
```

---

## 📚 Documentation Complète

- **Algorithmes détaillés** : [docs/ENONCE.md](docs/ENONCE.md)
- **Barème de notation** : [docs/BAREME.md](docs/BAREME.md)

---

## 📦 Rendu

### Format
- **Fichier** : `NOM_Prenom_TPE5.zip`
- **Contenu** : `union_find.cpp` + `mst.cpp` + `capture_tests.png`
- **Deadline** : Début Séance 6

### Checklist
- [ ] Les **7** fonctions sont implémentées (3 dans union_find.cpp + 4 dans mst.cpp)
- [ ] Code compile : `make clean && make test`
- [ ] Tests passent : viser 16/16
- [ ] Nom/Prénom en haut de `union_find.cpp` et `mst.cpp`
- [ ] Code commenté (étapes clés + complexité documentée)
- [ ] Capture montre résultats de `./test_mst`

---

## 💡 Conseils

1. **Procéder étape par étape** : 1 → 2 → 3 → 4 → 5
2. **Tester fréquemment** : `make test` après chaque fonction
3. **Lire ENONCE.md** : Algorithmes détaillés avec pseudocode
4. **Commencer par Union-Find** : Kruskal en dépend entièrement
5. **Dessiner le graphe** : Tracer le MST à la main d'abord
6. **`u < v` pour getEdges** : C'est LE piège de l'étape 3

---

**Bonne chance !**

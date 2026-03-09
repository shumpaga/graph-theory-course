# TP1 Bonus — RéseauVAK

**Cours :** Théorie des Graphes — ESGC VERECHAGUINE A.K. 2025-2026
**Niveau :** Licence 2 — Génie Informatique
**Enseignant :** M. Alexandre GBAGUIDI AISSE

## Objectif

Implémenter un réseau social simplifié en C++ à l'aide de graphes :
représentations (liste et matrice d'adjacence), parcours BFS et DFS,
composantes connexes, tri topologique et détection de cycles.

## Arborescence

```
session_bonus_tp1/
├── include/          # En-têtes (.h) — NE PAS MODIFIER
│   ├── graph.h
│   ├── bfs.h
│   └── dfs.h
├── src/              # Sources à compléter
│   ├── graph.cpp     # Étapes 1 & 2
│   ├── bfs.cpp       # Étapes 3 & 4
│   ├── dfs.cpp       # Étapes 5 & 6
│   └── main.cpp      # Programme principal (fourni)
├── tests/
│   └── test_tp1.cpp  # 20 tests automatiques — NE PAS MODIFIER
├── data/             # Fichiers de graphes
│   ├── mini_test.txt
│   ├── reseau_vak.txt
│   ├── mega_campus.txt
│   ├── prerequis.txt
│   └── prerequis_cycle.txt
├── docs/
│   ├── ENONCE.md
│   └── BAREME.md
├── Makefile
└── tp_bonus1_enonce.pdf
```

## Compilation et Exécution

```bash
make            # Compile le programme principal
make test       # Compile et lance les 20 tests
make run        # Compile et exécute le programme
make clean      # Supprime le dossier bin/
make help       # Affiche l'aide
```

## Fichiers à Compléter

Compléter les TODOs dans les 3 fichiers suivants :

| Fichier | Étapes | Points |
|---------|--------|--------|
| `src/graph.cpp` | 1 (Fondation) + 2 (Représentations) | 5 |
| `src/bfs.cpp` | 3 (BFS) + 4 (Applications BFS) | 8 |
| `src/dfs.cpp` | 5 (DFS) + 6 (Applications DFS) | 9 |

**Total : 22 pts + 3 pts qualité = 25 pts**

## Rendu

- ZIP contenant : `graph.cpp`, `bfs.cpp`, `dfs.cpp` + `capture_tests.png`
- `make clean && make test` doit compiler sans erreurs
- Nom/Prénom en haut de chaque `.cpp`

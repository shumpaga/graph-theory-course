# Barème Détaillé — TP1 Bonus RéseauVAK

## ESGC VERECHAGUINE A.K. - 2025-2026
**Enseignant :** M. Alexandre GBAGUIDI AISSE
**Niveau :** Licence 2 - Génie Informatique

---

## Vue d'Ensemble

| Étape | Fonction(s) | Tests | Points |
|-------|-------------|-------|--------|
| 1 | Constructeur + addEdge + loadFromFile + accesseurs | 5 | 3 |
| 2 | getAdjMatrix + printAdjList + printAdjMatrix | 3 | 2 |
| 3 | bfs + getPath | 4 | 5 |
| 4 | connectedComponents + degreeSeparation | 3 | 3 |
| 5 | dfs + dfsVisit | 2 | 5 |
| 6 | topologicalSort + hasCycle | 2 | 4 |
| — | Qualité code | — | +3 |
| **TOTAL** | | **20** | **25** |

---

## Qualité du Code (+3 points)

| Critère | Points |
|---------|--------|
| Commentaires clairs (surtout BFS et DFS) | 1.0 |
| Noms de variables explicites | 0.5 |
| Indentation et structure propres | 0.5 |
| Nom/Prénom en haut de chaque .cpp | 0.5 |
| Explications dans les parties complexes | 0.5 |

---

## Pénalités

| Violation | Pénalité |
|-----------|----------|
| Code ne compile pas | Note = 0 |
| Modification des .h | -5 pts |
| Modification de test_tp1.cpp | -5 pts |
| Fichiers .o ou binaires dans le ZIP | -1 pt |

---

## Checklist Avant Rendu

- [ ] `make clean && make` compile sans erreurs ni warnings
- [ ] `make test` affiche 20/20
- [ ] Nom/Prénom en haut de graph.cpp, bfs.cpp, dfs.cpp
- [ ] Code commenté
- [ ] ZIP contient les 3 .cpp + capture_tests.png

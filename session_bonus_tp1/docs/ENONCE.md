# TP1 Bonus — RéseauVAK : BFS & DFS

## ESGC VERECHAGUINE A.K. - Année 2025-2026
**Enseignant :** M. Alexandre GBAGUIDI AISSE
**Niveau :** Licence 2 - Génie Informatique
**Cours :** Théorie des Graphes
**Durée :** 3 heures en salle machine

---

## Objectifs Pédagogiques

1. **Représenter** un graphe par liste et matrice d'adjacence
2. **Implémenter** le parcours en largeur (BFS) et ses applications
3. **Implémenter** le parcours en profondeur (DFS) et ses applications
4. **Appliquer** le tri topologique et la détection de cycles

---

## Les 6 Étapes

| Étape | Objectif | Points |
|-------|----------|--------|
| 1 | Classe Graph : liste d'adjacence | 3 |
| 2 | Matrice d'adjacence & affichage | 2 |
| 3 | BFS : parcours en largeur | 5 |
| 4 | Composantes connexes (via BFS) | 3 |
| 5 | DFS : parcours en profondeur | 5 |
| 6 | Tri topologique & détection de cycles | 4 |
| — | Qualité code + commentaires | +3 |
| **TOTAL** | | **25** |

---

## Contexte

Réseau social ESGC-VAK : 12 étudiants, 14 amitiés, 3 composantes connexes.

Voir le PDF `tp_bonus1_enonce.pdf` pour l'énoncé complet avec
algorithmes détaillés, exemples pas-à-pas, et pièges à éviter.

---

## Fichiers à compléter

- `src/graph.cpp` — Étapes 1-2 (Graph, matrice, affichage)
- `src/bfs.cpp` — Étapes 3-4 (BFS, chemin, composantes, séparation)
- `src/dfs.cpp` — Étapes 5-6 (DFS, tri topologique, cycles)

## Fichiers fournis (ne pas modifier)

- `include/*.h` — Déclarations
- `src/main.cpp` — Programme principal
- `tests/test_tp1.cpp` — 20 tests automatiques
- `data/*.txt` — 5 graphes de test

---

## Rendu

- **Fichier** : `NOM_Prenom_TP1.zip`
- **Contenu** : `src/graph.cpp` + `src/bfs.cpp` + `src/dfs.cpp` + `capture_tests.png`
- **NE PAS INCLURE** : fichiers `.o`, `bin/`, `obj/`

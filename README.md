# 📊 Théorie des Graphes - L2 Génie Informatique

**Institution** : ESGC VERECHAGUINE A.K. (Cotonou, Bénin)
**Niveau** : Licence 2 - Génie Informatique
**Enseignant** : M. Alexandre GBAGUIDI AISSE
**Année académique** : 2025-2026

---

## 👋 Bienvenue !

Bienvenue dans le cours de **Théorie des Graphes** ! Ce repository contient tous les supports de cours, exercices et travaux pratiques pour ce module.

---

## 📁 Structure du repository

```
graph-theory-course/
├── README.md                    ← Vous êtes ici
│
└── session1/                    ← Séance 1 : Fondamentaux
    ├── slides/                  → Diapositives du cours
    │   └── Seance1_Theo_Graphes_GI2.pdf
    │
    ├── td/                      → Travaux Dirigés (exercices)
    │   └── TD1_Exercices.md
    │
    └── tpe/                     → Travaux Personnels Encadrés
        ├── TPE1_Theorie_Graphes_GI2.pdf    → Énoncé
        └── TPE1_Graphes/                    → Code squelette
            ├── Graph.hpp
            ├── Graph.cpp        ← À COMPLÉTER
            ├── main.cpp         ← Tests automatiques
            ├── Makefile
            ├── graphe_test.txt
            └── README.md
```

---

## 🎯 Comment utiliser ce repository ?

### 1. Cloner le repository

```bash
git clone https://github.com/votre-username/graph-theory-course.git
cd graph-theory-course
```

### 2. Suivre une séance

Pour chaque séance, vous trouverez :

#### 📖 Slides de cours
```bash
cd session1/slides/
# Ouvrir le PDF avec votre lecteur préféré
```

#### ✏️ Exercices (TD)
```bash
cd session1/td/
# Lire TD1_Exercices.md
# Répondre aux questions sur papier ou dans un fichier séparé
```

#### 💻 Travaux Pratiques (TPE)
```bash
cd session1/tpe/TPE1_Graphes/

# 1. Lire l'énoncé (PDF)
# 2. Compléter Graph.cpp
# 3. Compiler et tester
make clean
make
./test_graph

# 4. Itérer jusqu'à ce que tous les tests passent !
```

---

## 📚 Session 1 - Fondamentaux et Liste d'Adjacence

### Objectifs

À l'issue de cette session, vous serez capable de :
- ✅ Définir ce qu'est un graphe (G = (V, E))
- ✅ Maîtriser le vocabulaire de base (degré, voisinage, chemin, cycle)
- ✅ Distinguer les différents types de graphes (orienté/non-orienté, pondéré/simple)
- ✅ Représenter un graphe par liste d'adjacence
- ✅ Implémenter une classe Graph en C++

### Contenu

#### 📖 Cours (1h30)
- Introduction : les graphes dans la vie réelle
- Définitions formelles
- Vocabulaire fondamental
- Types de graphes
- Représentations (liste vs matrice)

**Support** : [`session1/slides/Seance1_Theo_Graphes_GI2.pdf`](session1/slides/Seance1_Theo_Graphes_GI2.pdf)

#### ✏️ TD1 (1h00)
- **Exercice 1** : Modélisation (réseau routier, organigramme)
- **Exercice 2** : Vocabulaire (degré, voisins, chemins, cycles)
- **Exercice 3** : Conversions (graphe ↔ liste ↔ matrice)
- **Exercice 4** : Réflexion sur les représentations

**Support** : [`session1/td/TD1_Exercices.md`](session1/td/TD1_Exercices.md)

#### 💻 TPE1 (2-3h)
**Objectif** : Implémenter une classe `Graph` avec liste d'adjacence (graphe non-orienté)

**Niveaux** :
- **NIVEAU 1 - BASE** (12 pts) : Constructeur, addEdge, display, order, size, degree
- **NIVEAU 2 - STANDARD** (5 pts) : hasEdge, neighbors
- **NIVEAU 3 - AVANCÉ** (3 pts) : removeEdge + loadFromFile (bonus +2)

**Total** : 20 points (+ 2 bonus)

**Supports** :
- Énoncé : [`session1/tpe/TPE1_Theorie_Graphes_GI2.pdf`](session1/tpe/TPE1_Theorie_Graphes_GI2.pdf)
- Code squelette : [`session1/tpe/TPE1_Graphes/`](session1/tpe/TPE1_Graphes/)

---

## 🚀 Démarrage rapide - TPE1

### Prérequis

- Compilateur C++11 (g++, clang++)
- Make
- Terminal

### Instructions

```bash
# 1. Aller dans le dossier du TPE
cd session1/tpe/TPE1_Graphes/

# 2. Lire l'énoncé
# Ouvrir TPE1_Theorie_Graphes_GI2.pdf

# 3. Compléter Graph.cpp
# Remplir tous les TODO (12 au total)

# 4. Compiler
make clean
make

# 5. Tester
./test_graph

# 6. Répéter jusqu'à obtenir 25/25 tests passés !
```

### Sortie attendue (objectif final)

```
========================================
     TESTS TPE1 - THEORIE DES GRAPHES
========================================

--- NIVEAU 1 : BASE ---
>>> NIVEAU 1 : 10/10 tests passés <<<

--- NIVEAU 2 : STANDARD ---
>>> NIVEAU 2 : 7/7 tests passés <<<

--- NIVEAU 3 : AVANCÉ ---
>>> NIVEAU 3 : 8/8 tests passés <<<

========================================
RÉSULTAT FINAL : 25/25 tests passés
NOTE ESTIMÉE : 20/20
========================================
```

---

## 📝 Rendu du TPE1

### Format

Créer un fichier ZIP nommé : **`NOM_Prenom_TPE1.zip`**

Contenu du ZIP :
- `Graph.cpp` (votre implémentation complétée)
- Capture d'écran montrant les tests passés

### Deadline

**Début de la Séance 2**

### Soumission

À préciser par l'enseignant (email, plateforme, etc.)

---

## ⚠️ Conseils importants

### Pour réussir le TPE

1. **Lisez attentivement l'énoncé** - Surtout la section "Pièges courants" !
2. **Procédez niveau par niveau** - Ne passez au suivant que quand tous les tests sont verts
3. **Testez après chaque TODO** - Recompilez et relancez fréquemment
4. **N'oubliez pas la symétrie** - Graphe non-orienté = ajouter dans les DEUX sens !
5. **Dessinez sur papier** - Visualisez le graphe avant de coder

### Pour le TD

1. **Dessinez d'abord** - Un schéma vaut mieux qu'un long discours
2. **Vérifiez vos calculs** - Utilisez ∑ deg(v) = 2|E|
3. **Travaillez en groupe** - Mais assurez-vous de tout comprendre !

---

## 🆘 Besoin d'aide ?

### Pendant la séance

- Levez la main
- Demandez à l'enseignant
- Discutez avec vos camarades (encouragé !)

### Hors séance

- Consultez les slides du cours
- Relisez l'énoncé (surtout les "Pièges courants")
- Contactez l'enseignant par email

### Ressources en ligne

- [Visualgo - Graph Data Structures](https://visualgo.net/en/graphds)
- [Graph Online - Créer et visualiser des graphes](https://graphonline.ru/)

---

## 📅 Calendrier prévisionnel

| Séance | Date | Sujet | Rendu |
|--------|------|-------|-------|
| **Session 1** | À préciser | Fondamentaux + Liste d'adjacence | TPE1 |
| Session 2 | À préciser | Parcours de graphes (BFS, DFS) | TPE2 |
| Session 3 | À préciser | Plus courts chemins (Dijkstra) | TPE3 |
| Session 4 | À préciser | Arbres et arbres couvrants | TPE4 |
| ... | ... | ... | ... |

---

## 📧 Contact

**Enseignant** : M. Alexandre GBAGUIDI AISSE
**Email** : À préciser
**Bureau** : À préciser
**Heures de consultation** : À préciser

---

## 📜 Licence

Ce matériel pédagogique est fourni à des fins éducatives uniquement.

Les étudiants de L2 GI à l'ESGC VERECHAGUINE A.K. peuvent utiliser librement ce contenu pour leur apprentissage.

Toute redistribution ou utilisation commerciale est interdite sans autorisation préalable.

---

## 🎓 Bon courage !

La théorie des graphes est partout autour de nous : réseaux sociaux, GPS, Internet, jeux vidéo...

Maîtriser les graphes, c'est maîtriser les fondations de l'informatique moderne !

**Travaillez régulièrement, posez des questions, et surtout... amusez-vous ! 🚀**

---

*Dernière mise à jour : Janvier 2026*
*ESGC VERECHAGUINE A.K. - Cotonou, Bénin*

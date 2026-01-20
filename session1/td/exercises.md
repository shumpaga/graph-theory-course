# TD 1 — Fondamentaux et Représentations
## Théorie des Graphes L2 GI | ESGC-VAK

**Durée** : 1h
**Objectifs** : Maîtriser le vocabulaire, savoir modéliser un problème en graphe, convertir entre différentes représentations

---

## EXERCICE 1 — Modélisation (20 min)

### 1.1 Réseau routier

Voici les distances (en km) entre 5 quartiers de Cotonou :

- Ganhi ↔ Akpakpa : 8 km
- Ganhi ↔ Cadjèhoun : 5 km
- Akpakpa ↔ Fidjrossè : 12 km
- Cadjèhoun ↔ Fidjrossè : 10 km
- Cadjèhoun ↔ Godomey : 7 km
- Fidjrossè ↔ Godomey : 6 km

**Questions** :
1. Modéliser cette situation par un graphe (dessiner)
2. Le graphe est-il orienté ou non-orienté ? Justifier
3. Le graphe est-il pondéré ou non-pondéré ? Justifier
4. Donner V et E explicitement
5. Calculer |V| et |E|

---

### 1.2 Organigramme d'entreprise

Voici la hiérarchie dans une entreprise béninoise :

- Le **Directeur Général** supervise le **Directeur Technique** et le **Directeur Commercial**
- Le **Directeur Technique** supervise **Ingénieur 1** et **Ingénieur 2**
- Le **Directeur Commercial** supervise **Vendeur 1**, **Vendeur 2**, et **Vendeur 3**

**Questions** :
1. Modéliser cette situation par un graphe (dessiner)
2. Le graphe est-il orienté ou non-orienté ? Justifier
3. Le graphe est-il pondéré ou non-pondéré ?
4. Combien de sommets et d'arêtes ?

---

## EXERCICE 2 — Vocabulaire (15 min)

Soit le graphe suivant :

```
        A --- B --- C
        |     |     |
        D --- E --- F
              |
              G
```

**Questions** :

1. Lister V et E
2. Calculer |V| et |E|
3. Calculer le degré de chaque sommet
4. Vérifier que ∑ deg(v) = 2|E|
5. Identifier N(E) et N[E]
6. Donner un chemin de A à G (indiquer sa longueur)
7. Donner un autre chemin de A à G (longueur différente ?)
8. Identifier tous les cycles de longueur 4
9. Le graphe est-il connexe ? Justifier

---

## EXERCICE 3 — Représentations (25 min)

### 3.1 Du graphe à la liste d'adjacence

Soit le graphe suivant :

```
    0 --- 1
    |     |
    2 --- 3 --- 4
```

**Question** : Écrire la liste d'adjacence de ce graphe

---

### 3.2 Du graphe à la matrice d'adjacence

Même graphe que 3.1.

**Question** : Écrire la matrice d'adjacence de ce graphe

---

### 3.3 De la liste au graphe

Soit la liste d'adjacence suivante :

```
0 → [1, 3]
1 → [0, 2, 4]
2 → [1, 3]
3 → [0, 2, 4]
4 → [1, 3]
```

**Questions** :
1. Dessiner le graphe correspondant
2. Le graphe est-il orienté ? Justifier
3. Calculer |V| et |E|

---

### 3.4 De la matrice au graphe

Soit la matrice d'adjacence suivante :

```
    0  1  2  3
0 [ 0  1  1  0 ]
1 [ 0  0  1  1 ]
2 [ 0  0  0  1 ]
3 [ 0  0  0  0 ]
```

**Questions** :
1. Dessiner le graphe correspondant
2. Le graphe est-il orienté ? Comment le voit-on dans la matrice ?
3. Calculer |V| et |E|

---

### 3.5 Graphe pondéré

Soit le graphe pondéré suivant :

```
    0 --5-- 1
    |       |
    3       7
    |       |
    2 --2-- 3
```

**Questions** :
1. Écrire la matrice d'adjacence (utiliser ∞ pour l'absence d'arête)
2. Écrire la liste d'adjacence (avec les poids)

---

## EXERCICE 4 — Réflexion (bonus, 10 min)

### 4.1 Choix de représentation

Vous devez implémenter un algorithme qui :
- Parcourt tous les voisins de chaque sommet
- Le graphe a 1000 sommets et 2000 arêtes

**Question** : Quelle représentation choisir (liste ou matrice) ? Justifier avec les complexités.

---

### 4.2 Cas particulier

Un graphe a 100 sommets. Quel est le nombre **maximum** d'arêtes possibles (graphe simple non-orienté) ?

**Indice** : Combien de paires de sommets peut-on former ?

---

# CORRECTIONS

---

## CORRECTION EXERCICE 1

### 1.1 Réseau routier

**1. Graphe** :

```
         Ganhi
         /   \
       5km   8km
       /       \
  Cadjèhoun -- Akpakpa
      |  \      |
     7km 10km  12km
      |    \    |
  Godomey -- Fidjrossè
         6km
```

**2. Non-orienté** : Les routes peuvent être empruntées dans les deux sens

**3. Pondéré** : Les arêtes ont des poids (distances en km)

**4. Ensembles** :
- V = {Ganhi, Akpakpa, Cadjèhoun, Fidjrossè, Godomey}
- E = {(Ganhi, Akpakpa), (Ganhi, Cadjèhoun), (Akpakpa, Fidjrossè), (Cadjèhoun, Fidjrossè), (Cadjèhoun, Godomey), (Fidjrossè, Godomey)}

**5. Cardinaux** :
- |V| = 5 (5 quartiers)
- |E| = 6 (6 routes)

---

### 1.2 Organigramme

**1. Graphe** :

```
           DG
          /  \
         /    \
        DT     DC
       / \    / | \
      I1 I2  V1 V2 V3
```

**2. Orienté** : La relation "supervise" n'est pas symétrique (le DG supervise le DT, mais pas l'inverse). On utilise des flèches :

```
           DG
          ↓  ↓
         DT  DC
        ↓ ↓  ↓ ↓ ↓
       I1 I2 V1 V2 V3
```

**3. Non-pondéré** : Pas de poids sur les arêtes

**4. Cardinaux** :
- |V| = 8 (8 personnes)
- |E| = 7 (7 relations de supervision)

---

## CORRECTION EXERCICE 2

**Graphe** :

```
        A --- B --- C
        |     |     |
        D --- E --- F
              |
              G
```

**1. Ensembles** :
- V = {A, B, C, D, E, F, G}
- E = {(A,B), (A,D), (B,C), (B,E), (C,F), (D,E), (E,F), (E,G)}

**2. Cardinaux** :
- |V| = 7
- |E| = 8

**3. Degrés** :

| Sommet | Degrés | Voisins |
|--------|--------|---------|
| A | 2 | B, D |
| B | 3 | A, C, E |
| C | 2 | B, F |
| D | 2 | A, E |
| E | 4 | B, D, F, G |
| F | 2 | C, E |
| G | 1 | E |

**4. Vérification** :
∑ deg(v) = 2 + 3 + 2 + 2 + 4 + 2 + 1 = 16
2|E| = 2 × 8 = 16 ✓

**5. Voisinages** :
- N(E) = {B, D, F, G}
- N[E] = {B, D, E, F, G}

**6. Chemin de A à G** :
A → B → E → G (longueur 3)

**7. Autre chemin** :
A → D → E → G (longueur 3)

**8. Cycles de longueur 4** :
- A → B → E → D → A
- B → C → F → E → B

**9. Connexité** :
Oui, le graphe est connexe. On peut aller de n'importe quel sommet à n'importe quel autre. Par exemple, de G (le plus "isolé") on peut atteindre tous les autres en passant par E.

---

## CORRECTION EXERCICE 3

### 3.1 Liste d'adjacence

**Graphe** :

```
    0 --- 1
    |     |
    2 --- 3 --- 4
```

**Liste d'adjacence** :

```
0 → [1, 2]
1 → [0, 3]
2 → [0, 3]
3 → [1, 2, 4]
4 → [3]
```

---

### 3.2 Matrice d'adjacence

**Matrice** :

```
    0  1  2  3  4
0 [ 0  1  1  0  0 ]
1 [ 1  0  0  1  0 ]
2 [ 1  0  0  1  0 ]
3 [ 0  1  1  0  1 ]
4 [ 0  0  0  1  0 ]
```

**Remarque** : La matrice est **symétrique** car le graphe est non-orienté.

---

### 3.3 De la liste au graphe

**Graphe** :

```
    0 --- 1 --- 4
    |     |     |
    3 --- 2 --- (repli vers 3)

Ou plus clairement :
        0 --- 1
       / \   / \
      /   \ /   \
     3 --- 2     4
      \         /
       -------- (via 3)
```

**Simplifions** :

```
    0 --- 1 --- 4
    |\   /|    /
    | \ / |   /
    |  X  |  /
    | / \ | /
    3 --- 2

Ou en forme de pentagone :
        1
       / \
      0   4
      |\ /|
      | X |
      |/ \|
      3---2
```

**2. Orienté ?** Non, car si (u,v) est dans la liste de u, alors (v,u) est dans la liste de v. Par exemple : 0 → [1,3] et 1 → [0,...], 3 → [0,...]

**3. Cardinaux** :
- |V| = 5
- |E| = 5 (en comptant chaque arête une seule fois)

---

### 3.4 De la matrice au graphe

**Graphe** :

```
    0 → 1 → 2 → 3
         ↘   ↗
```

Ou plus précisément :

```
    0 → 1
    ↓    ↓
    2    3
    ↓  ↗
    (vers 3)
```

**Simplifions** :

```
0 → 1 → 2
    ↓   ↓
    3 ← (fermé)
```

Non, regardons mieux la matrice :

```
    0  1  2  3
0 [ 0  1  1  0 ]  → 0 a des arcs vers 1 et 2
1 [ 0  0  1  1 ]  → 1 a des arcs vers 2 et 3
2 [ 0  0  0  1 ]  → 2 a un arc vers 3
3 [ 0  0  0  0 ]  → 3 n'a aucun arc sortant
```

**Graphe correct** :

```
    0 ─→ 1
    │    │
    ↓    ↓
    2 ─→ 3
```

**2. Orienté ?** Oui, la matrice n'est **pas symétrique**. Par exemple : mat[0][1] = 1 mais mat[1][0] = 0.

**3. Cardinaux** :
- |V| = 4
- |E| = 5 (arcs : 0→1, 0→2, 1→2, 1→3, 2→3)

---

### 3.5 Graphe pondéré

**Graphe** :

```
    0 --5-- 1
    |       |
    3       7
    |       |
    2 --2-- 3
```

**1. Matrice d'adjacence** :

```
    0  1  2  3
0 [ 0  5  3  ∞ ]
1 [ 5  0  ∞  7 ]
2 [ 3  ∞  0  2 ]
3 [ ∞  7  2  0 ]
```

**2. Liste d'adjacence** :

```
0 → [(1, 5), (2, 3)]
1 → [(0, 5), (3, 7)]
2 → [(0, 3), (3, 2)]
3 → [(1, 7), (2, 2)]
```

Format : (destination, poids)

---

## CORRECTION EXERCICE 4

### 4.1 Choix de représentation

**Donnée** : 1000 sommets, 2000 arêtes

**Graphe creux** : E << V² (2000 << 1 000 000)

**Opération** : Parcourir tous les voisins

| Représentation | Mémoire | Parcourir voisins |
|----------------|---------|-------------------|
| Liste d'adjacence | O(V + E) = O(3000) | O(deg(v)) |
| Matrice | O(V²) = O(1 000 000) | O(V) = O(1000) |

**Choix** : **Liste d'adjacence**
- **Mémoire** : 3000 unités vs 1 000 000 (333× moins)
- **Parcours** : O(deg(v)) ≈ O(2) en moyenne (deg moyen = 2E/V = 4) vs O(1000)

---

### 4.2 Nombre maximum d'arêtes

**Graphe simple non-orienté** : pas d'arêtes multiples, pas de boucles

**Nombre de paires** : On choisit 2 sommets parmi 100

|E|<sub>max</sub> = C(100, 2) = 100 × 99 / 2 = **4950**

**Formule générale** : |E|<sub>max</sub> = n(n-1)/2 pour n sommets

**Ce graphe s'appelle** : le **graphe complet** K<sub>n</sub> (tous les sommets sont reliés entre eux)

---

# Fin du TD 1 ! 🎉

**Prochaine étape** : TPE (implémentation en C)

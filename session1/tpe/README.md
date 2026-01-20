# TPE1 - Représentation des Graphes

## Théorie des Graphes (GI2) - ESGC VERECHAGUINE A.K. - 2025-2026

---

## 📋 Instructions rapides

### Objectif
Implémenter une classe `Graph` représentant un graphe non-orienté par liste d'adjacence.

### Fichiers
| Fichier | Description |
|---------|-------------|
| `Graph.hpp` | Déclaration — **NE PAS MODIFIER** |
| `Graph.cpp` | Implémentation — **À COMPLÉTER** |
| `main.cpp` | Tests automatiques — NE PAS MODIFIER |
| `Makefile` | Compilation |
| `graphe_test.txt` | Fichier exemple pour loadFromFile() |
| `graphe_cotonou.txt` | Graphe des quartiers de Cotonou |

---

## 🚀 Compilation et test

```bash
# Méthode 1 : avec Make (recommandé)
make clean
make
./test_graph

# Méthode 2 : manuellement
g++ -std=c++11 -o test_graph Graph.cpp main.cpp
./test_graph
```

---

## 📊 Niveaux et barème

| Niveau | Points | Fonctions |
|--------|--------|-----------|
| **1 - BASE** | 12 pts | `Graph()`, `addEdge()`, `display()`, `order()`, `size()`, `degree()` |
| **2 - STANDARD** | 5 pts | `hasEdge()`, `neighbors()` |
| **3 - AVANCÉ** | 3 pts | `removeEdge()` |
| **BONUS** | +2 pts | `loadFromFile()` |
| **TOTAL** | 20 pts | (+2 bonus) |

---

## ⚠️ Pièges courants

### Piège #1 : Oublier la symétrie
```cpp
// ❌ FAUX
adj[u].push_back(v);  // Seulement une direction !

// ✅ CORRECT
adj[u].push_back(v);
adj[v].push_back(u);  // Les DEUX directions !
```

### Piège #2 : Compter l'arête deux fois
```cpp
// ❌ FAUX
adj[u].push_back(v); n_edges++;
adj[v].push_back(u); n_edges++;  // Compte 2× !

// ✅ CORRECT
adj[u].push_back(v);
adj[v].push_back(u);
n_edges++;  // Une seule fois !
```

### Piège #3 : Virgule en trop
```cpp
// ❌ FAUX → Affiche "0 -> [1, 2, ]"
for (int v : adj[u]) cout << v << ", ";

// ✅ CORRECT → Affiche "0 -> [1, 2]"
bool first = true;
for (int v : adj[u]) {
    if (!first) cout << ", ";
    cout << v;
    first = false;
}
```

---

## 📚 Rappel théorique

### Liste d'adjacence
Chaque sommet stocke la liste de ses voisins.

```
Exemple - Triangle (0-1-2):

    0
   / \
  1───2

Liste d'adjacence:
0 -> [1, 2]
1 -> [0, 2]
2 -> [0, 1]
```

### Formule fondamentale
```
Σ degrés = 2 × nombre d'arêtes
```

---

## ✅ Checklist de rendu

- [ ] `make clean && make` compile sans erreur
- [ ] `./test_graph` affiche au moins 10/10 (Niveau 1)
- [ ] Code indenté proprement
- [ ] Nom en commentaire en haut de Graph.cpp
- [ ] ZIP créé : `NOM_Prenom_TPE1.zip`
- [ ] ZIP contient : Graph.cpp + capture d'écran

---

## 📤 Rendu

**Format** : `NOM_Prenom_TPE1.zip`
**Contenu** : Graph.cpp + capture d'écran des tests
**Deadline** : Début de la Séance 2

---

## ❓ Besoin d'aide ?

1. Relisez les pièges courants ci-dessus
2. Consultez le PDF du sujet
3. Posez vos questions sur le groupe WhatsApp

**Bon courage ! 🚀**

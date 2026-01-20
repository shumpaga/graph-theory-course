# Barème Détaillé - TPE2 BFS

## ESGC VERECHAGUINE A.K. - 2025-2026
**Enseignant :** M. Alexandre GBAGUIDI AISSE
**Niveau :** Licence 2 - Génie Informatique

---

## 📊 Vue d'Ensemble

| Catégorie | Points | Pourcentage |
|-----------|--------|-------------|
| **Niveau BASE** | 10 pts | 40% |
| **Niveau STANDARD** | 10 pts | 40% |
| **Niveau BONUS** | 5 pts | 20% |
| **Code Commenté** | +2 pts | Bonus |
| **TOTAL** | **27 pts** | **108%** |

**Note finale :** Ramenée sur 20 (note maximale = 20/20)

---

## 🎯 Barème par Fonction

### NIVEAU BASE (10 points)

#### Fonction 1 : Parcours BFS Simple (3 points)

| Critère | Points | Description |
|---------|--------|-------------|
| **Algorithme correct** | 1.5 pt | - Queue utilisée correctement<br>- visited[] géré correctement<br>- Tous sommets atteignables visités |
| **Ordre de visite** | 0.5 pt | - Respect du parcours en largeur<br>- Pas de doublons |
| **Affichage** | 0.5 pt | - Format correct (sommets séparés par espaces)<br>- Retour à la ligne final |
| **Complexité** | 0.5 pt | - O(V + E) respectée<br>- Pas de boucles inutiles |

**Pénalités :**
- -1 pt : Utilisation de std::queue au lieu de Queue
- -0.5 pt : Sommets visités plusieurs fois
- -0.5 pt : Mauvais ordre de visite (non BFS)

**Tests clés :**
- ✓ Graphe simple depuis 0
- ✓ Graphe déconnecté (visite partielle)

---

#### Fonction 2 : Calcul des Distances Minimales (3 points)

| Critère | Points | Description |
|---------|--------|-------------|
| **Initialisation** | 0.5 pt | - distance[source] = 0<br>- Autres à -1 (non atteignable) |
| **Calcul correct** | 1.5 pt | - distance[v] = distance[u] + 1<br>- Toutes distances correctes |
| **Sommets inatteignables** | 0.5 pt | - Restent à -1<br>- Pas d'erreur sur graphe déconnecté |
| **Retour** | 0.5 pt | - Vecteur de taille V<br>- Tous éléments initialisés |

**Pénalités :**
- -1 pt : Distances incorrectes
- -0.5 pt : Mauvaise gestion des inatteignables
- -0.5 pt : Vecteur mal dimensionné

**Tests clés :**
- ✓ graph_simple.txt depuis 0 : [0, 1, 1, 2, 2]
- ✓ graph_disconnected.txt : présence de -1

---

#### Fonction 3 : Affichage de l'Arbre BFS (4 points)

| Critère | Points | Description |
|---------|--------|-------------|
| **Construction parent[]** | 1.5 pt | - BFS avec parent[v]<br>- parent[] correct |
| **Regroupement enfants** | 1 pt | - map<int, vector<int>> utilisée<br>- Tous enfants regroupés |
| **Affichage** | 1 pt | - Format : "parent → enfant1, enfant2"<br>- Tous liens affichés |
| **Cas particuliers** | 0.5 pt | - Source (pas de parent)<br>- Graphe déconnecté |

**Pénalités :**
- -1 pt : Arbre incomplet
- -0.5 pt : Format d'affichage incorrect
- -0.5 pt : Arêtes n'existant pas dans le graphe

**Tests clés :**
- ✓ Arbre cohérent avec le graphe
- ✓ Tous sommets atteignables dans l'arbre
- ✓ Pas de cycles dans l'arbre

---

### NIVEAU STANDARD (10 points)

#### Fonction 4 : Plus Court Chemin (3 points)

| Critère | Points | Description |
|---------|--------|-------------|
| **BFS avec parent[]** | 1 pt | - Réutilisation correcte<br>- parent[] complet |
| **Reconstruction** | 1 pt | - Remontée de dest à source<br>- Inversion du chemin |
| **Cas particuliers** | 0.5 pt | - source == dest : [source]<br>- Chemin inexistant : vecteur vide |
| **Validation** | 0.5 pt | - Longueur = distance BFS<br>- Chemin valide dans le graphe |

**Pénalités :**
- -1 pt : Chemin incorrect
- -0.5 pt : Mauvaise gestion des cas particuliers
- -0.5 pt : Vecteur non vide pour chemin inexistant

**Tests clés :**
- ✓ 0 → 4 dans graph_simple.txt : longueur 2
- ✓ 0 → 5 dans graph_disconnected.txt : vide
- ✓ v → v : [v]

---

#### Fonction 5 : Test de Connexité (3 points)

| Critère | Points | Description |
|---------|--------|-------------|
| **BFS depuis 0** | 1 pt | - BFS correctement effectué<br>- Comptage des visités |
| **Comparaison** | 1 pt | - Comparaison avec V<br>- Retour booléen correct |
| **Cas particuliers** | 0.5 pt | - Graphe vide : true<br>- 1 sommet : true |
| **Cohérence** | 0.5 pt | - Cohérent avec count_components |

**Pénalités :**
- -1 pt : Réponse incorrecte
- -0.5 pt : Mauvaise gestion des cas limites

**Tests clés :**
- ✓ graph_simple.txt : true
- ✓ graph_disconnected.txt : false
- ✓ Graphe vide : true

---

#### Fonction 6 : Composantes Connexes (4 points)

| Critère | Points | Description |
|---------|--------|-------------|
| **Boucle sur sommets** | 1 pt | - Parcours de tous les sommets<br>- visited[] global |
| **BFS par composante** | 1.5 pt | - BFS depuis chaque non visité<br>- Marquage correct |
| **Comptage** | 1 pt | - Incrémentation à chaque BFS<br>- Retour correct |
| **Cas particuliers** | 0.5 pt | - Graphe vide : 0<br>- Sommets isolés comptés |

**Pénalités :**
- -1.5 pt : Nombre incorrect
- -0.5 pt : Mauvaise gestion du visited global
- -0.5 pt : Cas limites incorrects

**Tests clés :**
- ✓ graph_simple.txt : 1
- ✓ graph_disconnected.txt : 3
- ✓ 5 sommets isolés : 5

---

### NIVEAU BONUS (5 points)

#### Fonction 7 : Test de Graphe Biparti (5 points)

| Critère | Points | Description |
|---------|--------|-------------|
| **Coloration BFS** | 2 pts | - color[] initialisé à -1<br>- Coloration alternée (0/1) |
| **Détection conflit** | 1.5 pt | - Vérification color[u] == color[v]<br>- Retour false si conflit |
| **Toutes composantes** | 1 pt | - Boucle sur toutes composantes<br>- Chaque composante testée |
| **Cas particuliers** | 0.5 pt | - Graphe vide : true<br>- Arbre : true |

**Pénalités :**
- -2 pts : Algorithme incorrect
- -1 pt : Composantes déconnectées non gérées
- -0.5 pt : Cas limites incorrects

**Tests clés :**
- ✓ graph_bipartite.txt : true
- ✓ Triangle : false
- ✓ Carré : true
- ✓ Arbre : true
- ✓ Graphe déconnecté avec triangle : false

**Propriété théorique (+0.5 bonus) :**
- Démonstration dans commentaires : "graphe biparti ⟺ pas de cycle impair"

---

### BONUS CODE (2 points)

#### Qualité du Code et Commentaires

| Critère | Points | Description |
|---------|--------|-------------|
| **Commentaires algorithme** | 0.8 pt | - Explication de chaque étape<br>- Justification des choix |
| **Commentaires complexité** | 0.4 pt | - Analyse de complexité<br>- Justification O(V+E) |
| **Lisibilité** | 0.4 pt | - Indentation correcte<br>- Noms de variables explicites |
| **Documentation** | 0.4 pt | - En-têtes de fonctions<br>- Exemples en commentaires |

**Exemples de bon commentaire :**

```cpp
// Initialiser toutes les distances à -1 (non atteignable)
// Seul source sera à distance 0
vector<int> distance(V, -1);
distance[source] = 0;

// BFS classique pour explorer niveau par niveau
Queue Q;
Q.push(source);

while (!Q.empty()) {
    int u = Q.pop();

    // Explorer tous les voisins de u
    for (int v : g.getNeighbors(u)) {
        if (distance[v] == -1) {  // Si v non visité
            // La distance à v est la distance à u + 1
            distance[v] = distance[u] + 1;
            Q.push(v);
        }
    }
}
```

**Pénalités :**
- -0.5 pt : Pas de commentaires
- -0.3 pt : Code mal indenté
- -0.2 pt : Variables non explicites (a, b, c, ...)

---

## 🎯 Grille de Notation Complète

### Répartition Détaillée

| Fonction | Points Base | Points Qualité | Total |
|----------|-------------|----------------|-------|
| **Fonction 1** | 2.5 | 0.5 | 3.0 |
| **Fonction 2** | 2.5 | 0.5 | 3.0 |
| **Fonction 3** | 3.5 | 0.5 | 4.0 |
| **Fonction 4** | 2.5 | 0.5 | 3.0 |
| **Fonction 5** | 2.5 | 0.5 | 3.0 |
| **Fonction 6** | 3.5 | 0.5 | 4.0 |
| **Fonction 7** | 4.5 | 0.5 | 5.0 |
| **Code commenté** | - | 2.0 | 2.0 |
| **TOTAL** | **21.5** | **5.5** | **27.0** |

---

## 📋 Critères Transversaux

### Respect des Consignes (Pénalités)

| Violation | Pénalité |
|-----------|----------|
| Modification de bfs.h | -5 pts |
| Modification de graph.h/queue.h | -5 pts |
| Utilisation de std::queue | -3 pts |
| Code ne compile pas | Note = 0 |
| Rendu en retard (par jour) | -2 pts |
| Format de rendu incorrect | -1 pt |

### Bonus Additionnels

| Réalisation | Bonus |
|-------------|-------|
| README_ETUDIANT.md détaillé | +1 pt |
| Fonctions auxiliaires bien documentées | +0.5 pt |
| Tests personnels ajoutés | +0.5 pt |
| Gestion d'erreurs robuste | +0.5 pt |

**Bonus maximum :** +2.5 pts (en plus des 2 pts code commenté)

---

## 🏆 Échelle de Notation

### Sur 27 points (avant conversion)

| Points | Niveau | Appréciation |
|--------|--------|--------------|
| 25-27 | Excellent | Toutes fonctions + code parfait |
| 20-24 | Très bien | Toutes fonctions principales |
| 15-19 | Bien | BASE + STANDARD complets |
| 10-14 | Assez bien | Niveau BASE complet |
| 5-9 | Passable | Fonctions partielles |
| 0-4 | Insuffisant | Travail très incomplet |

### Conversion sur 20

La note finale est calculée ainsi :

```
Note_finale = min(20, (Points_obtenus / 25) * 20)
```

**Exemples :**
- 25 pts → 20/20
- 20 pts → 16/20
- 15 pts → 12/20
- 10 pts → 8/20

**Avec bonus :**
- 27 pts → 20/20 (plafonné)

---

## 📝 Grille d'Auto-Évaluation

Avant de rendre votre TPE, vérifiez :

### Niveau BASE (10 pts)

- [ ] **Fonction 1** : BFS affiche tous sommets atteignables, dans l'ordre
- [ ] **Fonction 2** : Distances correctes testées sur tous graphes
- [ ] **Fonction 3** : Arbre affiché avec bon format parent → enfants

### Niveau STANDARD (10 pts)

- [ ] **Fonction 4** : Plus court chemin correct, gestion des cas limites
- [ ] **Fonction 5** : Connexité correcte sur graphes connexes et déconnectés
- [ ] **Fonction 6** : Nombre de composantes exact sur tous graphes

### Niveau BONUS (5 pts)

- [ ] **Fonction 7** : Test biparti correct sur tous cas (cycle pair/impair)

### Qualité (2 pts)

- [ ] Code bien commenté avec explications
- [ ] Complexité analysée et justifiée
- [ ] Variables avec noms explicites
- [ ] Indentation correcte

### Tests

- [ ] Compilation sans erreurs : `make`
- [ ] Tests automatiques : `make test`
- [ ] Programme interactif testé sur tous graphes
- [ ] Tous les tests passent

---

## 💯 Exemples de Corrections

### Exemple 1 : Étudiant Excellent (27/27)

**Points obtenus :**
- Fonction 1 : 3/3
- Fonction 2 : 3/3
- Fonction 3 : 4/4
- Fonction 4 : 3/3
- Fonction 5 : 3/3
- Fonction 6 : 4/4
- Fonction 7 : 5/5
- Code commenté : 2/2

**Total :** 27/27 → **20/20**

**Commentaires :**
- Toutes les fonctions parfaitement implémentées
- Code très bien commenté avec analyse de complexité
- Tests tous réussis
- Excellent travail !

---

### Exemple 2 : Étudiant Très Bien (21/27)

**Points obtenus :**
- Fonction 1 : 3/3
- Fonction 2 : 3/3
- Fonction 3 : 3.5/4 (format d'affichage imparfait)
- Fonction 4 : 3/3
- Fonction 5 : 3/3
- Fonction 6 : 3.5/4 (graphe vide non géré)
- Fonction 7 : 0/5 (non tentée)
- Code commenté : 2/2

**Total :** 21/27 → **16.8/20**

**Commentaires :**
- Niveau BASE et STANDARD très bien maîtrisés
- Quelques petites imprécisions dans l'affichage
- Fonction BONUS non réalisée (facultative)
- Très bon travail, code de qualité

---

### Exemple 3 : Étudiant Bien (16/27)

**Points obtenus :**
- Fonction 1 : 3/3
- Fonction 2 : 2.5/3 (mauvaise gestion inatteignables)
- Fonction 3 : 3/4 (arbre incomplet sur graphe déconnecté)
- Fonction 4 : 2.5/3 (cas source == dest non géré)
- Fonction 5 : 2/3 (graphe vide incorrecte)
- Fonction 6 : 3/4 (comptage légèrement faux)
- Fonction 7 : 0/5
- Code commenté : 0/2 (pas de commentaires)

**Total :** 16/27 → **12.8/20**

**Commentaires :**
- Algorithmes généraux corrects
- Manque de gestion des cas limites
- Absence de commentaires
- À améliorer : tests et documentation

---

### Exemple 4 : Étudiant Passable (10/27)

**Points obtenus :**
- Fonction 1 : 2.5/3 (quelques doublons)
- Fonction 2 : 2/3 (distances parfois incorrectes)
- Fonction 3 : 2/4 (algorithme partiellement faux)
- Fonction 4 : 1/3 (reconstruction incorrecte)
- Fonction 5 : 1.5/3 (souvent faux)
- Fonction 6 : 1/4 (algorithme incorrect)
- Fonction 7 : 0/5
- Code commenté : 0/2

**Total :** 10/27 → **8/20**

**Commentaires :**
- Compréhension partielle de BFS
- Nombreuses erreurs algorithmiques
- Besoin de retravailler les concepts fondamentaux
- Voir l'enseignant pour aide

---

## 📞 Réclamations

Si vous contestez votre note :

1. **Délai :** 1 semaine après publication des notes
2. **Procédure :**
   - Email à l'enseignant avec objet : "Réclamation TPE2 - NOM Prénom"
   - Joindre votre code commenté
   - Justifier précisément les points contestés
3. **Traitement :** Réponse sous 48h

**Note :** Seules les erreurs de calcul ou d'appréciation manifestes seront corrigées.

---

## 📊 Statistiques (Années Précédentes)

### Répartition Moyenne

| Note | Pourcentage |
|------|-------------|
| 16-20/20 | 25% |
| 12-16/20 | 40% |
| 8-12/20 | 25% |
| 0-8/20 | 10% |

**Moyenne générale :** 13.5/20

### Fonctions les Plus Difficiles

1. **Fonction 7 (Biparti)** : 35% de réussite
2. **Fonction 6 (Composantes)** : 60% de réussite
3. **Fonction 3 (Arbre BFS)** : 70% de réussite

### Erreurs Fréquentes

1. Oublier de marquer visited avant d'enfiler (45%)
2. Mauvaise gestion des graphes déconnectés (40%)
3. Reconstruction de chemin inversée (35%)
4. Test biparti sur une seule composante (30%)
5. Manque de commentaires (50%)

---

## ✅ Checklist Finale

Avant de rendre :

### Code
- [ ] Toutes les fonctions compilent
- [ ] `make` sans erreurs
- [ ] `make test` exécuté
- [ ] Tests manuels sur les 4 graphes

### Documentation
- [ ] Code commenté (pour les 2 pts bonus)
- [ ] Fichier bfs.cpp complété avec NOM/Prénom
- [ ] README_ETUDIANT.md (optionnel)

### Rendu
- [ ] Archive nommée : NOM_Prenom_TPE2_BFS.zip
- [ ] Contient tout le dossier TPE2_BFS/
- [ ] Pas de fichiers .o ou exécutables dans l'archive
- [ ] Taille raisonnable (< 1 Mo)

### Éthique
- [ ] Travail personnel (pas de copie)
- [ ] Respect des consignes
- [ ] Pas de modification des .h

---

**Bon courage pour votre TPE ! 🎯**

---

*ESGC VERECHAGUINE A.K. - Théorie des Graphes - L2 GI - 2025-2026*

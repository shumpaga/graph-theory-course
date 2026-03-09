// TP1 — RéseauVAK : Tests automatisés (fourni — NE PAS MODIFIER)
// 20 tests couvrant les 6 étapes

#include "graph.h"
#include "bfs.h"
#include "dfs.h"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <set>

using namespace std;

int passed = 0;
int total = 0;

void test(bool condition, const string& name) {
    total++;
    if (condition) {
        cout << "  ✓ Test " << total << " : " << name << endl;
        passed++;
    } else {
        cout << "  ✗ Test " << total << " : " << name << " — ÉCHEC" << endl;
    }
}

void separator(const string& title) {
    cout << "\n--- " << title << " ---" << endl;
}

int main() {
    cout << "╔══════════════════════════════════════════╗" << endl;
    cout << "║     TP1 RéseauVAK — Tests (20 tests)    ║" << endl;
    cout << "╚══════════════════════════════════════════╝" << endl;

    // ═══════════════════════════════════════
    // ÉTAPE 1 : Graph — Fondation
    // ═══════════════════════════════════════
    separator("ÉTAPE 1 : Graph fondation");

    // Test 1 : Constructeur
    Graph g1(5);
    test(g1.getV() == 5, "Constructeur : getV() == 5");

    // Test 2 : addEdge non orienté
    Graph g2(4, false);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    bool found01 = false, found10 = false;
    for (int v : g2.neighbors(0)) if (v == 1) found01 = true;
    for (int v : g2.neighbors(1)) if (v == 0) found10 = true;
    test(found01 && found10, "addEdge non orienté : arête dans les deux sens");

    // Test 3 : addEdge orienté
    Graph g3(4, true);
    g3.addEdge(0, 1);
    bool found_fwd = false, found_back = false;
    for (int v : g3.neighbors(0)) if (v == 1) found_fwd = true;
    for (int v : g3.neighbors(1)) if (v == 0) found_back = true;
    test(found_fwd && !found_back, "addEdge orienté : arête dans un seul sens");

    // Test 4 : loadFromFile mini_test.txt
    Graph gMini(0);
    gMini.loadFromFile("data/mini_test.txt");
    test(gMini.getV() == 6, "loadFromFile mini_test : 6 sommets");

    // Test 5 : Noms chargés
    test(gMini.getName(0) == "Afi" && gMini.getName(5) == "Fara",
         "loadFromFile mini_test : noms corrects");

    // ═══════════════════════════════════════
    // ÉTAPE 2 : Représentations
    // ═══════════════════════════════════════
    separator("ÉTAPE 2 : Représentations");

    // Test 6 : getAdjMatrix dimensions
    auto matrix = gMini.getAdjMatrix();
    test((int)matrix.size() == 6 && (int)matrix[0].size() == 6,
         "getAdjMatrix : dimensions 6x6");

    // Test 7 : getAdjMatrix contenu
    test(matrix.size() > 5 && matrix[0].size() > 5 &&
         matrix[0][1] == 1 && matrix[1][0] == 1 && matrix[0][5] == 0,
         "getAdjMatrix : contenu correct (Afi-Beno=1, Afi-Fara=0)");

    // Test 8 : Sommet isolé dans la matrice
    bool faraIsolated = (matrix.size() == 6);
    if (faraIsolated) {
        for (int j = 0; j < 6; j++) {
            if (matrix[5].size() <= (size_t)j || matrix[5][j] != 0) faraIsolated = false;
        }
    }
    test(faraIsolated, "getAdjMatrix : Fara (5) a une ligne de zéros");

    // ═══════════════════════════════════════
    // ÉTAPE 3 : BFS
    // ═══════════════════════════════════════
    separator("ÉTAPE 3 : BFS");

    // Test 9 : BFS distances depuis Afi (0) sur mini_test
    BFSResult r1 = bfs(gMini, 0);
    test(r1.distance.size() > 3 &&
         r1.distance[0] == 0 && r1.distance[1] == 1 && r1.distance[3] == 2,
         "BFS mini_test : distances Afi(0)=0, Beno(1)=1, Dina(3)=2");

    // Test 10 : BFS sommet isolé inaccessible
    test(r1.distance.size() > 5 && r1.distance[5] == -1,
         "BFS mini_test : Fara(5) inaccessible (distance == -1)");

    // Test 11 : BFS sur reseau_vak.txt
    Graph gVAK(0);
    gVAK.loadFromFile("data/reseau_vak.txt");
    BFSResult r2 = bfs(gVAK, 0);
    test(r2.distance.size() > 7 &&
         r2.distance[0] == 0 && r2.distance[4] == 1 && r2.distance[7] == 3,
         "BFS reseau_vak : distances Dossou(0)=0, Adjovi(4)=1, Zannou(7)=3");

    // Test 12 : BFS isolés dans reseau_vak
    test(r2.distance.size() > 11 &&
         r2.distance[10] == -1 && r2.distance[11] == -1,
         "BFS reseau_vak : Sossa(10) et Viho(11) inaccessibles");

    // ═══════════════════════════════════════
    // ÉTAPE 4 : Applications BFS
    // ═══════════════════════════════════════
    separator("ÉTAPE 4 : Applications BFS");

    // Test 13 : getPath
    string path = getPath(r2, 9, gVAK);
    test(path.find("Dossou") != string::npos && path.find("Hounkpatin") != string::npos,
         "getPath : chemin Dossou->Hounkpatin contient source et cible");

    // Test 14 : getPath inaccessible
    string noPath = getPath(r2, 10, gVAK);
    test(noPath.find("Aucun") != string::npos || noPath.find("aucun") != string::npos,
         "getPath : Dossou->Sossa retourne 'Aucun chemin'");

    // Test 15 : Composantes connexes
    auto comps = connectedComponents(gVAK);
    test(comps.size() == 3,
         "connectedComponents reseau_vak : 3 composantes");

    // Test 16 : Degré de séparation
    test(degreeSeparation(gVAK, 0, 8) == 4 && degreeSeparation(gVAK, 0, 10) == -1,
         "degreeSeparation : Dossou-Kiki=4, Dossou-Sossa=-1");

    // ═══════════════════════════════════════
    // ÉTAPE 5 : DFS
    // ═══════════════════════════════════════
    separator("ÉTAPE 5 : DFS");

    // Test 17 : DFS visite tous les sommets accessibles
    DFSResult d1 = dfs(gMini, 0);
    int visited = 0;
    if ((int)d1.discovery.size() >= 6) {
        for (int i = 0; i < 6; i++)
            if (d1.discovery[i] != -1) visited++;
    }
    test(visited == 5, "DFS mini_test depuis Afi : 5 sommets visités (pas Fara)");

    // Test 18 : DFS discovery < finish pour chaque sommet visité
    bool timesOk = true;
    if ((int)d1.discovery.size() >= 6 && (int)d1.finish.size() >= 6) {
        for (int i = 0; i < 6; i++) {
            if (d1.discovery[i] != -1 && d1.discovery[i] >= d1.finish[i])
                timesOk = false;
        }
    } else {
        timesOk = false;
    }
    test(timesOk, "DFS mini_test : discovery[v] < finish[v] pour tout v visité");

    // ═══════════════════════════════════════
    // ÉTAPE 6 : Tri topologique & Cycles
    // ═══════════════════════════════════════
    separator("ÉTAPE 6 : Tri topologique & Cycles");

    // Test 19 : Tri topologique valide
    Graph gPrereq(0, true);
    gPrereq.loadFromFile("data/prerequis.txt");
    auto topo = topologicalSort(gPrereq);

    // Vérifier : pour chaque arête u→v, u apparaît avant v dans l'ordre
    bool topoValid = (int)topo.size() == gPrereq.getV() && gPrereq.getV() > 0;
    if (topoValid) {
        vector<int> pos(gPrereq.getV());
        for (int i = 0; i < (int)topo.size(); i++) pos[topo[i]] = i;
        for (int u = 0; u < gPrereq.getV() && topoValid; u++) {
            for (int v : gPrereq.neighbors(u)) {
                if (pos[u] >= pos[v]) topoValid = false;
            }
        }
    }
    test(topoValid, "topologicalSort prerequis.txt : ordre valide");

    // Test 20 : Détection de cycle
    Graph gCycle(0, true);
    gCycle.loadFromFile("data/prerequis_cycle.txt");
    test(!hasCycle(gPrereq) && hasCycle(gCycle),
         "hasCycle : prerequis=NON, prerequis_cycle=OUI");

    // ═══════════════════════════════════════
    // RÉSULTAT
    // ═══════════════════════════════════════
    cout << "\n╔══════════════════════════════════════════╗" << endl;
    cout << "║  Résultat : " << passed << "/" << total << " tests réussis";
    if (passed == total) cout << " ★";
    cout << string(max(0, 28 - (passed >= 10 ? 2 : 1)), ' ') << "║" << endl;
    cout << "╚══════════════════════════════════════════╝" << endl;

    if (passed == total) {
        cout << "\n🎉 Bravo ! Tous les tests passent !\n" << endl;
    } else {
        cout << "\n⚠  Certains tests échouent. Relisez les TODOs correspondants.\n" << endl;
    }

    return (passed == total) ? 0 : 1;
}

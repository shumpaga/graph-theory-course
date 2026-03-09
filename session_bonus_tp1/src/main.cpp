// TP1 — RéseauVAK : Programme principal (fourni)
// Ce fichier est COMPLET — ne le modifiez pas.

#include "graph.h"
#include "bfs.h"
#include "dfs.h"
#include <iostream>

using namespace std;

void separator(const string& title) {
    cout << "\n" << string(60, '=') << endl;
    cout << "  " << title << endl;
    cout << string(60, '=') << endl;
}

int main() {
    // ─────────────────────────────────────────
    // ÉTAPES 1-2 : Charger et afficher le graphe
    // ─────────────────────────────────────────
    separator("ÉTAPE 1-2 : Graphe du réseau social ESGC-VAK");

    Graph g(0);
    g.loadFromFile("data/reseau_vak.txt");

    cout << "\n--- Liste d'adjacence ---\n";
    g.printAdjList();

    cout << "\n--- Matrice d'adjacence ---\n";
    g.printAdjMatrix();

    // ─────────────────────────────────────────
    // ÉTAPE 3 : BFS depuis Dossou
    // ─────────────────────────────────────────
    separator("ÉTAPE 3 : BFS depuis Dossou (0)");

    BFSResult bfsResult = bfs(g, 0);

    cout << "\nDistances depuis Dossou :" << endl;
    for (int i = 0; i < g.getV(); i++) {
        cout << "  " << g.getName(i) << " : ";
        if (bfsResult.distance[i] == -1)
            cout << "INACCESSIBLE" << endl;
        else
            cout << bfsResult.distance[i] << " arête(s)" << endl;
    }

    cout << "\nOrdre de visite BFS : ";
    for (int v : bfsResult.order)
        cout << g.getName(v) << " ";
    cout << endl;

    // ─────────────────────────────────────────
    // ÉTAPE 4 : Applications BFS
    // ─────────────────────────────────────────
    separator("ÉTAPE 4 : Applications BFS");

    cout << "\nChemin Dossou -> Hounkpatin : " << getPath(bfsResult, 9, g) << endl;
    cout << "Chemin Dossou -> Sossa : " << getPath(bfsResult, 10, g) << endl;

    cout << "\n--- Composantes connexes ---" << endl;
    auto comps = connectedComponents(g);
    printComponents(comps, g);

    cout << "\nDegré de séparation Dossou-Kiki : "
         << degreeSeparation(g, 0, 8) << endl;
    cout << "Degré de séparation Dossou-Sossa : "
         << degreeSeparation(g, 0, 10) << endl;

    // ─────────────────────────────────────────
    // ÉTAPE 5 : DFS depuis Dossou
    // ─────────────────────────────────────────
    separator("ÉTAPE 5 : DFS depuis Dossou (0)");

    DFSResult dfsResult = dfs(g, 0);

    cout << "\nOrdre de visite DFS : ";
    for (int v : dfsResult.order)
        cout << g.getName(v) << " ";
    cout << endl;

    cout << "\nTemps discovery/finish :" << endl;
    for (int i = 0; i < g.getV(); i++) {
        cout << "  " << g.getName(i) << " : ";
        if (dfsResult.discovery[i] == -1)
            cout << "NON VISITÉ" << endl;
        else
            cout << "d=" << dfsResult.discovery[i]
                 << " f=" << dfsResult.finish[i] << endl;
    }

    // ─────────────────────────────────────────
    // ÉTAPE 6 : Tri topologique & cycles
    // ─────────────────────────────────────────
    separator("ÉTAPE 6 : Tri topologique (prérequis)");

    Graph gPrereq(0, true);  // graphe ORIENTÉ
    gPrereq.loadFromFile("data/prerequis.txt");

    cout << "\n--- Prérequis (liste d'adjacence) ---\n";
    gPrereq.printAdjList();

    cout << "\nCycle dans prerequis.txt ? "
         << (hasCycle(gPrereq) ? "OUI" : "NON") << endl;

    cout << "\nTri topologique : ";
    auto topo = topologicalSort(gPrereq);
    for (int v : topo)
        cout << gPrereq.getName(v) << " -> ";
    cout << "FIN" << endl;

    // Test avec cycle
    Graph gCycle(0, true);
    gCycle.loadFromFile("data/prerequis_cycle.txt");
    cout << "\nCycle dans prerequis_cycle.txt ? "
         << (hasCycle(gCycle) ? "OUI (Projet -> Maths)" : "NON") << endl;

    separator("FIN DU TP1");
    cout << "\nBravo ! Si tout s'affiche correctement, lancez : make test\n" << endl;

    return 0;
}

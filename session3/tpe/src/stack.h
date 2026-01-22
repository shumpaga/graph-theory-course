/**
 * @file stack.h
 * @brief Classe Stack (pile LIFO) pour l'algorithme DFS itératif
 *
 * TPE3 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 *
 * IMPORTANT : Vous DEVEZ utiliser cette classe Stack.
 * L'utilisation de std::stack entraîne une pénalité de -3 points.
 */

#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

class Stack {
private:
    std::vector<int> data;

public:
    // Constructeur
    Stack();

    // Ajouter un élément au sommet de la pile
    void push(int value);

    // Retirer et retourner l'élément au sommet de la pile
    int pop();

    // Consulter l'élément au sommet sans le retirer
    int top() const;

    // Vérifier si la pile est vide
    bool empty() const;

    // Obtenir la taille de la pile
    int size() const;
};

#endif // STACK_H

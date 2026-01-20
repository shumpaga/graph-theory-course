/**
 * @file queue.h
 * @brief File (Queue) - Implémentation avec vector
 *
 * ESGC VERECHAGUINE A.K. - 2025-2026
 * Enseignant : M. Alexandre GBAGUIDI AISSE
 *
 * IMPORTANT : On ne peut PAS utiliser std::queue de la STL
 * Cette implémentation fait partie du TPE
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
using namespace std;

/**
 * @class Queue
 * @brief File FIFO (First In, First Out)
 *
 * Implémentation efficace avec vector et index de front
 * - push() : O(1) amorti
 * - pop() : O(1)
 * - front() : O(1)
 */
class Queue {
private:
    vector<int> data;       // Données
    int frontIndex;         // Index du premier élément

public:
    /**
     * @brief Constructeur par défaut
     */
    Queue();

    /**
     * @brief Ajoute un élément à la fin de la file
     * @param x L'élément à ajouter
     *
     * Complexité : O(1) amorti
     */
    void push(int x);

    /**
     * @brief Retire et retourne le premier élément
     * @return Le premier élément
     *
     * Complexité : O(1)
     * Précondition : La file ne doit pas être vide
     */
    int pop();

    /**
     * @brief Retourne le premier élément sans le retirer
     * @return Le premier élément
     *
     * Complexité : O(1)
     * Précondition : La file ne doit pas être vide
     */
    int front() const;

    /**
     * @brief Indique si la file est vide
     * @return true si vide, false sinon
     */
    bool empty() const;

    /**
     * @brief Retourne le nombre d'éléments dans la file
     * @return Nombre d'éléments
     */
    int size() const;
};

#endif

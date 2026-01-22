/**
 * @file stack.cpp
 * @brief Implémentation de la classe Stack
 *
 * TPE3 - Théorie des Graphes (GI2)
 * ESGC VERECHAGUINE A.K. - 2025-2026
 */

#include "stack.h"

using namespace std;

Stack::Stack() {
    // Constructeur par défaut
}

void Stack::push(int value) {
    data.push_back(value);
}

int Stack::pop() {
    if (empty()) {
        throw underflow_error("Pile vide : impossible de dépiler");
    }
    int value = data.back();
    data.pop_back();
    return value;
}

int Stack::top() const {
    if (empty()) {
        throw underflow_error("Pile vide : impossible de consulter le sommet");
    }
    return data.back();
}

bool Stack::empty() const {
    return data.empty();
}

int Stack::size() const {
    return data.size();
}

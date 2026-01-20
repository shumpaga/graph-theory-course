/**
 * @file queue.cpp
 * @brief Implémentation de la classe Queue
 *
 * ESGC VERECHAGUINE A.K. - 2025-2026
 */

#include "queue.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Queue::Queue() : frontIndex(0) {
    // Vector vide au départ
}

void Queue::push(int x) {
    data.push_back(x);
}

int Queue::pop() {
    if (empty()) {
        throw runtime_error("pop() sur une file vide");
    }

    int value = data[frontIndex];
    frontIndex++;

    // Optimisation : réinitialiser si la file devient vide
    if (frontIndex >= (int)data.size()) {
        data.clear();
        frontIndex = 0;
    }

    return value;
}

int Queue::front() const {
    if (empty()) {
        throw runtime_error("front() sur une file vide");
    }

    return data[frontIndex];
}

bool Queue::empty() const {
    return frontIndex >= (int)data.size();
}

int Queue::size() const {
    return (int)data.size() - frontIndex;
}

//
// Created by kevin on 21/04/2025.
//

#include "Dosen.h"

Dosen::Dosen(string name, int id): name(name), id(id) {}

string Dosen::getName() const {
    return name;
}

void Dosen::setName(string name) {
    this->name = name;
}

void Dosen::setId(int id) {
    this->id = id;
}


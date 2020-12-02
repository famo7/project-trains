// Filename: Fordon.cpp

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Cpp file containing implementation of constructor,
* and overriden, and printing of id and type.
*/
#include "Fordon.h"
#include <utility>


Fordon::Fordon(int uniq_id, int t) {
    id = uniq_id;
    type = t;
}

void Fordon::print(ostream &os) {
    os << "ID: " << id << "\n"
       << "Type: " << type << "\n";
}

Fordon::~Fordon() = default;

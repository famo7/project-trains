// Filename: Lok.cpp

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Cpp file containing implementation of constructor,
* and overriden pure virtual function from Fordon class.
*/

#include "Lok.h"

#include <utility>

Lok::Lok(int uniqId, int type, int speed) :
Fordon(uniqId, type), maxSpeedKm(speed) {}

void Lok::print(ostream &os) {
    // print using base class
    Fordon::print(os);
    os << "speed: " << maxSpeedKm << "\n";
}

Lok::~Lok() = default;


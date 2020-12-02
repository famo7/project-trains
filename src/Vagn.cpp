// Filename: Vagn.cpp

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Cpp file containing implementation of constructor,
* and overriden pure virtual function from Fordon class.
*/

#include "Vagn.h"

#include <utility>

Vagn::Vagn(int uniqId, int type) :
Fordon(uniqId, type) {}

void Vagn::print(ostream &os) {
    // print using base class
    Fordon::print(os);
}

Vagn::~Vagn() = default;

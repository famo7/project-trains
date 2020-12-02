// Filename: SovVagn.cpp

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Cpp file containing implementation of constructor,
* and overriden pure virtual function from Fordon class.
*/

#include "SovVagn.h"

#include <utility>

SovVagn::SovVagn(int uniqId, int type, int b) :
Vagn(uniqId, type), beds(b) {}

int SovVagn::getBeds() const {
    return beds;
}

void SovVagn::print(ostream &os) {
    // print using Vagn class
    Vagn::print(os);
    os << "Bäddar: " << beds << "\n";
}

SovVagn::~SovVagn() = default;

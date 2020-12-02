// Filename: TacktGodsVagn.cpp

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Cpp file containing implementation of constructor,
* and overriden pure virtual function from Fordon class.
*/

#include "TacktGodsVagn.h"

#include <utility>

TacktGodsVagn::TacktGodsVagn(int uniqId, int type, int lV)
: Vagn(uniqId, type), lastVolym(lV) {}

void TacktGodsVagn::print(ostream &os) {
    // print using Vagn class
    Vagn::print(os);
    os << "Last Volym: " << lastVolym << " Kubikmeter" << "\n";
}

TacktGodsVagn::~TacktGodsVagn() = default;

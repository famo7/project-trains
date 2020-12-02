// Filename: OppenGodsVagn.cpp

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Cpp file containing implementation of constructor,
* and overriden pure virtual function from Fordon class.
*/

#include "OppenGodsVagn.h"

#include <utility>


OppenGodsVagn::OppenGodsVagn(int uniq_id, int type, int lK, int lY) :
Vagn(uniq_id, type), lastKapacitet(lK), lastYta(lY) {}

void OppenGodsVagn::print(ostream &os) {
    // print using Vagn class
    Vagn::print(os);
    os << "Last kapacitet: " << lastKapacitet << " Ton" << "\n"
       << "Last Yta: " << lastYta << " kvadratmeter" << "\n";
}

OppenGodsVagn::~OppenGodsVagn() = default;

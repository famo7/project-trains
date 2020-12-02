// Filename: DieselLok.cpp

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Cpp file containing implementation of constructor,
* and overriden pure virtual function from Fordon class.
*/


#include "DieselLok.h"

#include <utility>

DieselLok::DieselLok(int uniqId, int type, int speed, int forB):
Lok(uniqId, type, speed), forBrukning(forB){}

void DieselLok::print(ostream &os) {
    Lok::print(os);
    os << "Förbrukning: " << forBrukning << "\n";
}

DieselLok::~DieselLok() = default;

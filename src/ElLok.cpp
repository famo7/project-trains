// Filename: ElLok.cpp

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Cpp file containing implementation of constructor,
* and overriden pure virtual function from Fordon class.
*/


#include "ElLok.h"

#include <utility>

ElLok::ElLok(int uniqId, int type, int speed, int eKW):
Lok(uniqId, type, speed), effectKW(eKW){}

void ElLok::print(ostream &os) {
    Lok::print(os);
    os  << "Effekt i kw: " << getEffectKw() << "\n";
}

ElLok::~ElLok() = default;

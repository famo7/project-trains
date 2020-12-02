// Filename: PersonVagn.cpp

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Cpp file containing implementation of constructor,
* and overriden pure virtual function from Fordon class.
*/


#include "PersonVagn.h"

#include <utility>

PersonVagn::PersonVagn(int uniqId, int type, int sitP, bool inter) :
Vagn(uniqId, type), sitPlatser(sitP), internet(inter) {}

void PersonVagn::print(ostream &os) {
    // prints ja if true and nej if internet is false
    string st = (internet == true ?  "ja" : "nej");
    // print using Vagn class
    Vagn::print(os);
    os << "Sittplatser: " << sitPlatser << "\n"
        << "Internet: " << st << "\n";
}

PersonVagn::~PersonVagn() = default;

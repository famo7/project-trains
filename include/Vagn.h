// Filename: Vagn.h

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Header file containing the class definition for Vagn class.
*/

#ifndef PROJECT_VAGN_H
#define PROJECT_VAGN_H

#include "Fordon.h"

class Vagn: public Fordon {
public:
    // constructor
    Vagn(int uniqId, int type);
    // print method overriden
    void print(ostream &os) override;

    // overriden destructor
    ~Vagn() override;
};


#endif //PROJECT_VAGN_H

// Filename: PersonVagn.h

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Header file containing the class definition for PersonVagn class.
*/

#ifndef PROJECT_PERSONVAGN_H
#define PROJECT_PERSONVAGN_H
#include "Vagn.h"

class PersonVagn: public Vagn {
private:
    int sitPlatser;
    bool internet;
public:
    // constructor
    PersonVagn(int uniqId, int type, int sitP, bool inter);
    // getters
    int getSitplatser() const{return sitPlatser;}
    bool getInternet() const{return internet;}
    // overriden print method
    void print(ostream &os) override;

    // overriden destructor
    ~PersonVagn() override;
};


#endif //PROJECT_PERSONVAGN_H

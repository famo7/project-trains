// Filename: DieselLok.h

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Header file containing the class definition for DieselLok class
 * which is a type of engine
*/

#ifndef PROJECT_DIESELLOK_H
#define PROJECT_DIESELLOK_H
#include "Lok.h"

class DieselLok: public Lok {
private:
    int forBrukning;
public:
    // constructor
    DieselLok(int uniqId, int type, int speed, int forB);
    // getter
    int getForbrukning() const{return forBrukning;}
    // overriden method to print
    void print(ostream &os) override;
    // overridden destructor
    ~DieselLok() override;
};


#endif //PROJECT_DIESELLOK_H

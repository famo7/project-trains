// Filename: Lok.h

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Header file containing the class definition for Lok class.
*/

#ifndef PROJECT_LOK_H
#define PROJECT_LOK_H
#include "Fordon.h"

// publicly inheriting from Fordon class
class Lok: public Fordon {
private:
    int maxSpeedKm;
public:
    // constructor
    Lok(int uniqId, int type, int speed);
    // getter
    int getSpeed() const{return maxSpeedKm;}
    // overriden function
    void print(ostream &os) override;
    // overriden destructor
    ~Lok() override;
};


#endif //PROJECT_LOK_H

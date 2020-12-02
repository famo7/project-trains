// Filename: SovVagn.h

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Header file containing the class definition for SovVagn class.
*/

#ifndef PROJECT_SOVVAGN_H
#define PROJECT_SOVVAGN_H
#include "Vagn.h"

class SovVagn: public Vagn {
private:
    int beds;
public:
    // getter
    int getBeds() const;
    // constructor
    SovVagn(int uniqId, int type, int b);
    // overriden print method
    void print(ostream &os) override;

    // overriden destructor
    ~SovVagn() override;
};


#endif //PROJECT_SOVVAGN_H

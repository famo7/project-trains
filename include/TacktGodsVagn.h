// Filename: TacktGodsVagn.h

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Header file containing the class definition for TacktGodsVagn class.
*/

#ifndef PROJECT_TACKTGODSVAGN_H
#define PROJECT_TACKTGODSVAGN_H

#include "Vagn.h"
// inherits fron Vagn
class TacktGodsVagn: public Vagn {
private:
    int lastVolym;
public:
    // constructor
    TacktGodsVagn(int uniqId, int type, int lV);
    // getter
    int getLastVolym() const{return lastVolym;}
    // overriden print method
    void print(ostream &os) override;
    // overriden destructor
    ~TacktGodsVagn() override;
};


#endif //PROJECT_TACKTGODSVAGN_H


// Filename: OppenGodsVagn.h

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Header file containing the class definition for OppenGodsVagn class.
*/

#ifndef PROJECT_OPPENGODSVAGN_H
#define PROJECT_OPPENGODSVAGN_H
#include "Vagn.h"

// inherits publicly from Vagn class
class OppenGodsVagn: public Vagn {
private:
    int lastKapacitet, lastYta;
public:
    // constructor
    OppenGodsVagn(int uniq_id,int type, int lK, int lY);
    // getters
    int getLastKapacitet() const{return lastKapacitet;}
    int getLastYta() const{return lastYta;}
    // overriden print method
    void print(ostream &os) override;

    ~OppenGodsVagn() override;
};


#endif //PROJECT_OPPENGODSVAGN_H

// Filename: ElLok.h

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Header file containing the class definition for ElLok class
 * which is a type of engine
*/
#ifndef PROJECT_ELLOK_H
#define PROJECT_ELLOK_H
#include "Lok.h"

class ElLok: public Lok {
private:
    int effectKW;
public:
    ElLok(int uniqId, int type, int speed, int eKW);
    int getEffectKw() const{return effectKW;}
    void print(ostream &os) override;
    ~ElLok() override;
};


#endif //PROJECT_ELLOK_H

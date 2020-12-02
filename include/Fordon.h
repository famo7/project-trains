// Filename: Fordon.h

// Written by: Farhan Mohamed

// Created date: 14/10/2020

// Last modified: 11/01/2020

/* Description: Header file that is a abstract class
* contains pure virtual function for printing
*/

#ifndef PROJECT_FORDON_H
#define PROJECT_FORDON_H

#include <string>
#include <iostream>
#include <stdexcept>
using std::ostream;
using std::string;

class Fordon{
private:
    
    int id;
    int type;
public:
    // constructor
    explicit Fordon(int uniq_id, int t);
    // getters
    int getId() const{return id;}
    int getType() const{return type;}
    // pure virtual funtion
    virtual void print(ostream &os) = 0;
    // virtual destructor
    virtual ~Fordon();
};



#endif //PROJECT_FORDON_H

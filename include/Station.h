// Filename: Station.h

// Written by: Farhan Mohamed

// Created date: 16/10/2020

// Last modified: 11/01/2020

/* Description: Header file containing the class definition for Station class.
*/

#ifndef PROJECT_STATION_H
#define PROJECT_STATION_H

#include <vector>
#include "Fordon.h"
#include <algorithm>
#include <utility>
#include "memory"
#include <map>
#include<list>
#include<iostream>

 using std::cout; using std::endl;
using std::vector; using std::shared_ptr;
class Station {
private:
    // name of station
    string name;
    // pool of vector made of shared pointers in list
    std::list<shared_ptr<Fordon>> poolOfVeh;

public:
    // default constructor
    Station();
      
    // returns name of station
    string getName() { return name; }
    // sets name of station
    void setName(string n);
    // adds shared pointer to the pool of vehicle
    // param: vehicle
    void addVeh(shared_ptr<Fordon> f);
    // gets a vehicle from the list
    // return type: shared pointer(vehicle)
    // param: type of vehicle
    shared_ptr<Fordon> getVeh(int type);
    // takes iterator as param and deletes it
    // return: void
    void deleteIter(std::list<shared_ptr<Fordon>>::iterator &it);
    // prints station
    void print();
    // prints one vehicle from station,
    // param: id of vehicle
    void printOneVehicle(int vehId);

    ~Station();

};

#endif //PROJECT_STATION_H

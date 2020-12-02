// Filename: Station.cpp

// Written by: Farhan Mohamed

// Created date: 16/10/2020

// Last modified: 11/01/2020

/* Description: Cpp file containing implementation of constructor,
* and getter/setter for station class.
*/

#include "Station.h"


void Station::setName(string n) {
    // set name
    name = std::move(n);
}

void Station::addVeh(shared_ptr<Fordon> f) {
    // ads vehicle to list
    poolOfVeh.push_back(std::move(f));
}


shared_ptr<Fordon> Station::getVeh(int type){
    // vector of all ids of vehicle found
    vector<int> matches;

    for (auto const& i : poolOfVeh) {
        // search and add the id to matches
        if (i->getType() == type) {
            matches.push_back(i->getId());
        }
    }
    // if no matches
    if (matches.empty()) {
        // return null pointer
        return nullptr;
    }
    else {
        // sort the matches
        std::sort(matches.begin(), matches.end());
        int id = matches[0];

        // get the iterator of the one with least id
        auto it =  std::find_if(std::begin(poolOfVeh), std::end(poolOfVeh),
            [&](shared_ptr<Fordon>& p) { return p->getId() == id; });
        
        // move it before deleting
        auto i = std::move(*it);
        // delete
        deleteIter(it);

        // return it
        return i;
        

    }
}

void Station::deleteIter(std::list<shared_ptr<Fordon>>::iterator& it){
    // delete a iterator
    poolOfVeh.erase(it);
}

void Station::print() {
    // if empty print empty
    if (poolOfVeh.empty()) {
        cout << "No vehicles available" << endl;
    }
    else {
        // else print all vehicles using the overloaded print method
        for (const auto& i : poolOfVeh) {
            i->print(std::cout);
            cout << "===============================================\n";
        }
    }
}

void Station::printOneVehicle(int vehId){
    
    bool found = false;
    for (const auto& i : poolOfVeh) {
        // try to find it and print if found
        if (i->getId() == vehId) {
            found = true;
            i->print(cout);
        }
    }
    // if not found print error message
    if (!found) {
        cout << "No vehicle found!\n";
    }
}
// default constructor and destructor
Station::Station() = default;

Station::~Station() = default;

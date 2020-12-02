// Filename: Train.cpp

// Written by: Farhan Mohamed

// Created date: 17/10/2020

// Last modified: 11/01/2020

/* Description: Cpp file containing implementation of constructor,
* and getter/setter for Train class.
*/

#include "Train.h"

#include <utility>
#include <numeric>

Train::Train(int trainNumber, shared_ptr<Station> ankomstStation, shared_ptr<Station> destinationsStation,
    TrainTime depTime, TrainTime arrTime):
    ursprung(std::move(ankomstStation)), destionation(std::move(destinationsStation)) {

    trainNum = trainNumber;
    trainDepartureTime = depTime;
    destinationTime = arrTime;
    sen = false;
    // initially not assembled
    state = NOT_ASSEMBLED;
    medelHastighet = 0;

}
Train::~Train() = default;



void Train::addVehicle(shared_ptr<Fordon>  f) {
    // add vehcle to train
    fordon.push_back(std::move(f));

}

void Train::searchVehicle(int id){
    // search for a vehicle using id
    bool found = false;
    for (auto i : fordon) {
        if (i->getId() == id) {
            found = true;
            i->print(cout);
        }
    }
    // print error message if not found
    if (!found) {
        cout << "vehicle not found!" << endl;
    }
}


void Train::setSen(bool s) {
    sen = s;
}

void Train::setState(STATES s) {
    state = s;
}

void Train::setMedelHastighet(double m) {
    medelHastighet = m;
}


void Train::assembleTrain(const vector<int> & typs) {
    // assemble train
    int count = 0;
    for (auto& i : typs) {
        //get vehicle from departure station
        shared_ptr<Fordon> f(ursprung->getVeh(i));
        // if not null pointer
        if (f != nullptr) {
            // add to train
            count++;
            addVehicle(std::move(f));
        }
    }
    // if we found all vehicles 
    if (count == typs.size()) {
        // set state to ASSSEMBLED
        setState(Train::STATES::ASSEMBLED);


    }
    // if not set state to INCOMPLETE
    else {
        setState(Train::STATES::INCOMPLETE);
    }
    

}



void Train::printAll() {

    std::cout << "Train num: " << trainNum << "\n";
    cout << "State: " << convertState(state) << endl;
    std::cout << "departure station: " << ursprung->getName() << "\n";
    std::cout << "departure Time: ";
    trainDepartureTime.print();

    std::cout << "arrival station: " << destionation->getName() << "\n";
    std::cout << "arrival Time: ";
    destinationTime.print();
    
    // print cars of state is ASSEMBLED or INCOMPLETE
    if (state == ASSEMBLED || state == INCOMPLETE) {
        for (const auto& i : fordon) {
            i->print(std::cout);
            cout << endl;
        }
    }
    else {
        //else just the type
        for (const auto& i : fordon) {
            std::cout << i->getType() << "\n";
        }
    }
    std::cout << "================================================================\n";
}

string Train::convertState(STATES s){
    
    vector<string> statesArray{ "NOT_ASSEMBLED","INCOMPLETE", "ASSEMBLED",
                "READY", "RUNNING", "ARRIVED", "FINISHED" };
    // return string from vector.
    return statesArray[s];
}

void Train::disassembleTrain() {
    // add all vehicles to destination station
    for (auto& i : fordon) {
        destionation->addVeh(i);
    }
      
    // clear the vector
    fordon.clear();

}





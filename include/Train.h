// Filename: Train.h

// Written by: Farhan Mohamed

// Created date: 17/10/2020

// Last modified: 11/01/2020

/* Description: Header file containing the class definition for Train class.
*/

#ifndef PROJECT_TRAIN_H
#define PROJECT_TRAIN_H

#include<vector>
#include <memory>
#include <map>
#include "Station.h"
#include "Constants.h"
#include "Fordon.h"
#include "TrainTime.h"
using std::vector; using std::unique_ptr;
using std::shared_ptr;


class Train {
public:
    // enum of all states
    enum STATES {
        NOT_ASSEMBLED, INCOMPLETE, ASSEMBLED,
        READY, RUNNING, ARRIVED, FINISHED
    };
    // train constructor.
    Train(int trainNumber, shared_ptr<Station> ankomstStation
        , shared_ptr<Station> destinationsStation, TrainTime depTime, TrainTime arrTime);

    // getters

    int getTrainNum() const { return trainNum; }
    TrainTime getDepartureTime() const { return trainDepartureTime; }
    TrainTime getDestinationTime() const { return destinationTime; }
    bool getSen() const { return sen; }
    string getdepStationName() { return ursprung->getName(); }
    string getDestStationName() { return destionation->getName(); }
    
    STATES getState() { return state; }
    double getMedelHastighet() const { return medelHastighet; }
    // add vehicle
    void addVehicle(shared_ptr<Fordon> f);
    // assemble train using vector of all types needed
    void assembleTrain(const vector<int>& typs);
    // disassemble train and add them to destination station pool of vehicle
    void disassembleTrain();

    void printAll();
    //setters
    void setState(STATES s);
    void setSen(bool s);
    void setMedelHastighet(double m);
    // convert state to string
    string convertState(STATES s);
    // search vehicle using id
    void searchVehicle(int id);

    ~Train();

private:
    // member data
    int trainNum;
    TrainTime trainDepartureTime, destinationTime;
    bool sen;

    
    shared_ptr<Station> ursprung;
    shared_ptr<Station> destionation;
    STATES state;
    vector<shared_ptr<Fordon>> fordon;
    double medelHastighet;


};


#endif //PROJECT_TRAIN_H

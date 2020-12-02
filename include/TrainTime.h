// Filename: TrainTime.h

// Written by: Farhan Mohamed

// Created date: 17/10/2020

// Last modified: 11/01/2020

/* Description: Header file containing the class definition for TrainTime class.
*/

#ifndef PROJECT_TRAINTIME_H
#define PROJECT_TRAINTIME_H

#include <iomanip>
#include <iostream>
#include<string>

using std::cout; using std::setw; using std::setfill;
class TrainTime {
private :
    int hour;
    int minute;
public :
    //constructor with default value 0
    explicit TrainTime(int h = 0, int m  = 0);

    // print time in format hh:mm
    void print() const;

    //increase time with given minutes
    void increaseMins(int minutes);
    // increase time, but return the object without modifying
    TrainTime increase(int minutes);

    // decrese time using parameter(minutes)
    TrainTime decreaseMins(int minutes);

    // calculate time diffrents of param object and this object
    // return seconds
    int timeDiffSec(TrainTime& right);

    // compare this object and param object
    bool equals(TrainTime t) const;

    // getters
    int getHour() const;
    int getMinutes() const;
    std::string getTime() const;
    // setters
    void setHour(int h);
    void setMinutes(int m);
    
    // overlaoding < operator
    bool operator<(const TrainTime& right) const {
        bool ret = false;
        if (hour < right.getHour()) {
            ret = true;
        }
        else if (hour == right.getHour()) {
            if (minute < right.getMinutes()) {
                ret = true;
            }
            else {
                ret =  false;
            }
        }
        return ret;
    }

 
    
};



#endif //PROJECT_TRAINTIME_H

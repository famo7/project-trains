// Filename: TrainTime.cpp

// Written by: Farhan Mohamed

// Created date: 17/10/2020

// Last modified: 11/01/2020

/* Description: Cpp file containing implementation of constructor,
* and getter/setter for TrainTime class.
*/

#include "TrainTime.h"

TrainTime::TrainTime(int h, int m) {
    hour = h;
    minute = m;
}

void TrainTime::print() const {
    // print
    cout << setw(2) << setfill('0') << hour << ":"
         << setw(2) << setfill('0') << minute
        << "\n";
}

bool TrainTime::equals(TrainTime t) const {
    // compare hour and minutes
    if(hour == t.hour &&
       minute == t.minute) {
        return true;
    }
        return false;
}

void TrainTime::increaseMins(int minutes) {
    // increase minutes
    minute += minutes;

    // if minutes is greater than 59

    if(minute > 59){
        // reset minute
        minute = 0;
        // increase hour
        hour++;
    }
    // reset hour if its 24
    if(hour == 24){
        hour = hour%24;
    }
}

TrainTime TrainTime::increase(int minutes){
    // same as above but without modifying current object
    int h = hour, m = minute;
    TrainTime t;

    m += minutes;
    if (m > 59) {
        m = 0;
        h++;
    }
    if (h == 24) {
        h = h % 24;
    }

    return TrainTime(h, m);
}


TrainTime TrainTime::decreaseMins(int minutes){
    // decrease current time object with minutes
    TrainTime t();
    int h, m;
    m = minute;
    h = hour;
    
    if ((m - minutes) >= 0) {
       m = (m -= minutes);
        
    }
    else {
        m -= minutes;
        m = 60 + m;
       h--;
    }
       
   // return the object
    return TrainTime(h, m);
}
int TrainTime::timeDiffSec(TrainTime &right){
    // calculate diffrence of right with current object in seconds
    int secs = ((hour*60*60) + minute*60) -
        ((right.getHour() * 60 * 60) + right.getMinutes() * 60);

    // return the seconds
    return secs;
}
int TrainTime::getHour() const {
    return hour;
}
std::string TrainTime::getTime() const
{
    return std::to_string(getHour()) + ":" + std::to_string(getMinutes());
}
int TrainTime::getMinutes() const {
    return minute;
}

void TrainTime::setHour(int h) {
    hour = h;
}

void TrainTime::setMinutes(int m) {
    minute = m;
}

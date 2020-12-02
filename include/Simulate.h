// Filename: Simulate.h

// Written by: Farhan Mohamed

// Created date: 20/10/2020

// Last modified: 11/01/2020

/* Description: Header file containing the class definition for Simulate class
 * which is responsible for simulating the trains.
*/
#ifndef PROJECT_SIMULATE_H
#define PROJECT_SIMULATE_H
#include<vector>
#include<memory>
#include<fstream>
#include <sstream>
#include<iostream>

#include "OppenGodsVagn.h"
#include "SovVagn.h"
#include "PersonVagn.h"
#include "TacktGodsVagn.h"
#include "ElLok.h"
#include "DieselLok.h"
#include"Station.h"
#include"Fordon.h"
#include"Constants.h"
#include"Train.h"
#include"TrainTime.h"
#include"Menu.h"
#include<queue>

using std::vector; using std::shared_ptr;
using std::getline;
using std::cout; using std::endl; using std::cin;

class Simulate {
private:
	std::ofstream trainSim;
	std::ifstream file;
	std::ifstream file2;
	//vector containing all read stations as shared pointer.
	vector<shared_ptr<Station>> vS;
	// vector containing all trains
	vector<Train> trains;
	// vector containing all cars in trains in order
	vector<vector<int>> allCars;

	// trainTime class for custom time
	TrainTime startTime;
	TrainTime currentTime;
	// menu class for menus and submenus.
	Menu mainMenu;

public:
	// default constructor.
	Simulate();
	/*
		function that reads in from TrainStations.txt
		param: none
		return none
	*/
	void readStationsFile();
	/*
	function that reads in from Trains.txt
	*/
	void readTrainsFile();

	//function that reads in from TrainMap.txt
	void readAvgSpeed();

	//function that runs the program
	void run();
	//function that displays menu
	void menu();

	//function that simulates the project
	void sim();

	//function that shows the time table for all trains
	void timeTable();
	//function that shows specific train information
	void trainInfo();
	//function that shows specific station information
	void stationInfo();
	//function that increments time when next intervall is chosen
	void nextInterval();
	//function that tries to assemble trains
	void tryAssemble(Train& t);
	//function that tries to ready trains
	void ready(Train& t);
	//function that tries to run trains
	void running(Train& t);

	//function that makes trains state arrive(overloaded)
	void arrived(Train& t, bool b);
	//function that makes trains state arrive
	void arrived(Train& t);

	//function that prints all trains
	void printTrain(Train& t);

	//function that reads from istringstream and converts it into integer
	int getAndReturn(std::istringstream& ss, string& str, char c);
	//function that makes trains state finished
	void finished(Train& t);
	//function that makes trains state finished(overloaded)
	void finished(Train& t, bool b);

	//function that searchers a car in train
	void searchIdInTrain();

	//function that searchers a car in station
	void searchIdInStation();
	//function that shows statistics after simulation
	void showStats();

	//function that start the simulation
	void startSim(Train& t);
	~Simulate();
};


#endif //PROJECT_SIMULATE_H

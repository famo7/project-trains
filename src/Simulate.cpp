// Filename: Simulate.cpp

// Written by: Farhan Mohamed

// Created date: 20/10/2020

// Last modified: 11/01/2020

/* Description: Cpp file containing default constructor and definitions of member functions for simulate header
 * printing/searching and showing menu
*/


#include "Simulate.h"

Simulate::Simulate() {
	// open files
	trainSim.open(TRAINSIM);
	file.open(STATIONFILEPATH);
	file2.open(TRAINS);
	// check if opened
	if (!trainSim.is_open() || !file.is_open() || !file2.is_open()) {
		cout << "Could not open files" << endl;
	}
	// create the mainmenu
	mainMenu.addItem("Start simulation", true);
	mainMenu.addItem("Exit", true);
}


void Simulate::readAvgSpeed() {
	// calculate average speed when reading from TrainMap.txt
	std::ifstream file(TRAINMAP);
	string station1, station2;
	double distance, secDiff;
	double avgSpeed = 0;
	// read in the values.
	while (file >> station1 >> station2 >> distance) {
		for (auto& i : trains) {
			// see if its both ways comparing to trains
			if ((i.getdepStationName() == station1 && i.getDestStationName() == station2) ||
				i.getDestStationName() == station1 && i.getdepStationName() == station2) {
				secDiff = (i.getDestinationTime().timeDiffSec(i.getDepartureTime()));
				avgSpeed = (distance / (secDiff / 60 / 60));
				// set average speed
				i.setMedelHastighet(avgSpeed);
			}

		}

	}

}


int Simulate::getAndReturn(std::istringstream& ss, string& str, char c) {
	getline(ss, str, c);
	// return converted integer.
	return std::stoi(str);
}
void Simulate::readStationsFile() {
	unique_ptr<Fordon> f;
	unique_ptr<Station> stations;
	
	std::string line;
	string name, temp;
	int id, type, param0, param1;

	// read line by line
	while (std::getline(file, line)) {
		stations.reset(new Station);
		std::istringstream ss(line);
		getline(ss, name, ' ');
		stations->setName(name);
		// parse using ()
		while (getline(ss, temp, '(')) {
			getline(ss, temp, ')');

			std::istringstream ss2(temp);
			while (getline(ss2, temp, ' ')) {
				id = std::stoi(temp);
				getline(ss2, temp, ' ');
				type = std::stoi(temp);
				switch (type) {
					// create appropiate vehicle based on type
				case 0:
					param0 = getAndReturn(ss2, temp, ' ');
					param1 = getAndReturn(ss2, temp, ' ');

					f.reset(new PersonVagn(id, type, param0, param1));
					break;
				case 1:
					param0 = getAndReturn(ss2, temp, ' ');
					f.reset(new SovVagn(id, type, param0));

					break;
				case 2:
					param0 = getAndReturn(ss2, temp, ' ');
					param1 = getAndReturn(ss2, temp, ' ');

					f.reset(new OppenGodsVagn(id, type, param0, param1));
					break;
				case 3:
					param0 = getAndReturn(ss2, temp, ' ');

					f.reset(new TacktGodsVagn(id, type, param0));
					break;
				case 4:
					param0 = getAndReturn(ss2, temp, ' ');
					param1 = getAndReturn(ss2, temp, ' ');

					f.reset(new ElLok(id, type, param0, param1));
					break;
				case 5:
					param0 = getAndReturn(ss2, temp, ' ');
					param1 = getAndReturn(ss2, temp, ' ');

					f.reset(new DieselLok(id, type, param0, param1));
					break;
				}
				// add vehicle to the station
				stations->addVeh(std::move(f));


			}

		}
		// push station to the stations vector called vS
		vS.push_back(std::move(stations));


	}
	
	readTrainsFile();
}


void Simulate::readTrainsFile() {
	shared_ptr<Station> avg, dest;

	int id2 = -1, maxSpeed = -1, veh, hour, min;
	string av, des, depTime, arrTime;
	double medelHastighet;
	// time object to store the times of trains
	TrainTime time1;
	TrainTime time2;
	vector<int> cars;
	// read in from trains.txt

	string line2, temp2;
	while (std::getline(file2, line2)) {

		avg.reset(new Station);
		dest.reset(new Station);
		std::stringstream ss(line2);
		
		std::getline(ss, temp2, ' ');
		id2 = std::stoi(temp2);
		std::getline(ss, av, ' ');

		for (auto& i : vS) {
			// search in station vector, and set the 
			// departure station for train object.
			if (i->getName() == av) {
				avg = i;
			}
		}
		std::getline(ss, des, ' ');
		for (auto& i : vS) {
			if (i->getName() == des) {
				dest = i;
			}
		}

		// read in departure time
		std::getline(ss, depTime, ' ');
		// split the string to hour:minutes
		string token = depTime.substr(0, depTime.find(':'));
		hour = std::stoi(token);

		token = depTime.substr(3);
		min = std::stoi(token);

		time1.setHour(hour);
		time1.setMinutes(min);
		// same for arrival time
		std::getline(ss, arrTime, ' ');
		token = arrTime.substr(0, arrTime.find(':'));
		hour = std::stoi(token);
		// set times
		token = arrTime.substr(3);
		min = std::stoi(token);

		time2.setHour(hour);
		time2.setMinutes(min);

		// read in max speed
		std::getline(ss, temp2, ' ');
		maxSpeed = std::stoi(temp2);
		// create train object of values read above
		Train t(id2, avg, dest, time1, time2);
		// read in all cars the trains have
		while (std::getline(ss, temp2, ' ')) {
			veh = std::stoi(temp2);
			cars.push_back(veh);
		}
		// store in all cars vector of vector
		allCars.push_back(cars);
		cars.clear();
		// push train into trains vector.
		trains.push_back(t);
	}



}

void Simulate::run() {
	// read station file
	readStationsFile();
	// calculate avg speed for trains
	readAvgSpeed();
	// show menu
	menu();

}


void Simulate::menu() {
	int userInput;
	do {
		// print menu
		mainMenu.printMenuItems();
		// get user choice
		userInput = mainMenu.getMenuChoice();

		switch (userInput)
		{
		case 1:
			sim();
			break;
		case 2:
			break;
		default:
			break;
		}
		// break if exit is chosen
	} while (userInput != 2);


}

void Simulate::sim() {
	// print current time.
	cout << "Current time: ";
	currentTime.print();
	// create the submenu
	Menu subMenu;
	subMenu.addItem("Time table", true);
	subMenu.addItem("Train info", true);
	subMenu.addItem("Station info", true);
	subMenu.addItem("Next interval", true);
	subMenu.addItem("search car id in train", true);
	subMenu.addItem("search car id in station", true);
	subMenu.addItem("Exit", true);


	int userInput;
	do {
		// print menu
		subMenu.printMenuItems();
		// get user choice
		userInput = subMenu.getMenuChoice();
		
		switch (userInput)
		{
		case 1:
			timeTable();
			break;
		case 2:
			trainInfo();
			break;
		case 3:
			stationInfo();
			break;
		case 4:
			nextInterval();
			break;
		case 5:
			searchIdInTrain();
			break;
		case 6:
			searchIdInStation();
			break;
		default:
			break;
		}
	// while choice is not 7
	} while (userInput != 7);


}

void Simulate::searchIdInStation() {
	
	cout << "Enter id of car you want to search: ";
	int id;
	cin >> id;
	string st;

	cout << "Enter station you want to search the car in";
	cin >> st;

	for (const auto& i : vS) {
		if (st == i->getName()) {
			// search for id in the station given
			// and print if found using printOneVehicle function
			i->printOneVehicle(id);
		}
	}
}

void Simulate::searchIdInTrain() {
	cout << "Enter id of car you want to search: ";
	int id, trainN;
	cin >> id;
	cout << "Enter the train number to search in: ";
	cin >> trainN;

	for (auto i : trains) {
		// search for a train
		if (i.getTrainNum() == trainN) {
			// if train founc, search for a vehicle
			i.searchVehicle(id);
		}
	}
}

void Simulate::timeTable() {
	// print time table for all trains
	for (auto& i : trains) {
		std::cout << "Train num: " << i.getTrainNum() << "\n";
		std::cout << "departure station: " << i.getdepStationName() << "\n";
		std::cout << "departure Time: ";
		i.getDepartureTime().print();

		std::cout << "Destination station: " << i.getDestStationName() << "\n";
		std::cout << "arrival Time: ";
		i.getDestinationTime().print();
		cout << "===================================================\n";
	}
}

void Simulate::trainInfo() {
	// print one train info
	cout << "Train number: ";
	int tNum;
	cin >> tNum;
	bool found = false;
	for (auto& i : trains) {
		if (i.getTrainNum() == tNum) {
			found = true;
			i.printAll();
		}
	}

	if (!found) {
		cout << "Did not find that train." << endl;
	}
}

void Simulate::stationInfo() {

	cout << "Enter station name: ";
	string st;
	cin >> st;
	// search for a station
	cout << "Trains in station " << st << "." << endl;
	for (auto& i : trains) {
		if ((i.getdepStationName() == st && ((i.getState()
			== Train::STATES::ASSEMBLED) || i.getState()
			== Train::STATES::INCOMPLETE))
			|| i.getDestStationName() == st && ((i.getState()
				== Train::STATES::ARRIVED) || i.getState()
				== Train::STATES::FINISHED)) {
			// print all trains in that station.
			cout << endl;
			cout << "Train number: " << i.getTrainNum() << "\t";
			cout << "State: " << i.convertState(i.getState()) << endl;
		}

	}
	// lastly print all cars in the station pool
	cout << "All cars in " << st << endl << endl;
	for (auto i : vS) {
		if (i->getName() == st) {
			i->print();
		}
	}


}

void Simulate::nextInterval() {
	// sort train vector based on departure time
	std::sort(trains.begin(), trains.end(),
		[](Train const& a, Train const& b) { return a.getDepartureTime()
		< b.getDepartureTime(); });

		// see if its endtime()
		bool val = currentTime.increase(10).equals(TrainTime());

		if (!val) {
			// increase current time if its not end time
			currentTime.increaseMins(10);
			cout << "Current time:";
			// print current time
			currentTime.print();
			trainSim << "Current time: " << currentTime.getTime() << endl;
			cout << "==================" << endl;
			// simulate all trains
			for (auto& i : trains) {
				startSim(i);
			}
		}
		else {
			// if time is finished, see if there are trains that
			//are in arrived or running state if there are, force them to finish
			for (auto& i : trains) {
				if (i.getState() == Train::STATES::ARRIVED) {
					// set late to true
					i.setSen(true);
					finished(i, true);
				}if (i.getState() == Train::STATES::RUNNING) {
					// set late to true
					i.setSen(true);
					arrived(i, true);
					finished(i, true);

				}
			}
			// show stats when simulation is finished
			showStats();
		
	}
}

void Simulate::showStats() {
	cout << "Simulation finished" << endl;

	cout << "=======================================" << endl;
	// incomplete trains
	cout << "Trains that never left departure station" << endl << endl << endl;
	for (auto& i : trains) {
		if (i.getState() == Train::STATES::INCOMPLETE) {
			cout << "Train number\t" << i.getTrainNum() << endl;
		}
	}
	cout << "=======================================" << endl;
	// trains that finished in time
	cout << "Trains that finished in time." << endl << endl << endl;
	for (auto& i : trains) {
		if (i.getState() == Train::STATES::FINISHED && i.getSen() != true) {
			cout << "Train number\t" << i.getTrainNum() << endl;

		}
	}
	cout << "=======================================" << endl;


}
void Simulate::tryAssemble(Train& t) {
	// 30 minutes before is between previous time and currenttime.
	TrainTime min30 = t.getDepartureTime().decreaseMins(30);

	TrainTime prevTime = currentTime.decreaseMins(10);

	if ((min30 < currentTime || min30.equals(currentTime)
		&& prevTime < min30)) {
		// try to assemble car with vector allcars.
		int index = t.getTrainNum() - 1;
		t.assembleTrain(allCars[index]);

		printTrain(t);

	}
}

void Simulate::ready(Train& t) {
	// 10 minutes before
	TrainTime min10 = t.getDepartureTime().decreaseMins(10);
	TrainTime prevTime = currentTime.decreaseMins(10);

	if ((min10 < currentTime || min10.equals(currentTime)
		&& prevTime < min10)) {
		// set state to ready
		t.setState(Train::STATES::READY);
		printTrain(t);
	}
}

void Simulate::printTrain(Train& t) {
	// ostringstream object
	std::ostringstream os;
	// print and write to trainSim file.
	os << "Train [" << t.getTrainNum() << "]";
	os << "(" << t.convertState(t.getState()) << ")";
	os << " from " << t.getdepStationName() << " ";
	os << t.getDepartureTime().getTime();
	os << " to " << t.getDestStationName() << " ";
	os << t.getDestinationTime().getTime();
	os  << endl;

	cout << os.str();
	
	trainSim << os.str();
	
}

void Simulate::running(Train& t) {
	// if departure time is less than or equal currenttime
	// and previous time is less than departure time.
	TrainTime prevTime = currentTime.decreaseMins(10);

	if ((t.getDepartureTime() < currentTime ||
		t.getDepartureTime().equals(currentTime)
		&& prevTime < t.getDepartureTime())) {
		// set state to running
		t.setState(Train::STATES::RUNNING);
		// print train
		printTrain(t);
	}
}

void Simulate::arrived(Train& t, bool b) {
	if (b) {
		//  sets state to arrived
		t.setState(Train::STATES::ARRIVED);
		// print train
		printTrain(t);
	}
}

void Simulate::arrived(Train& t) {
	
	TrainTime prevTime = currentTime.decreaseMins(10);

	if ((t.getDestinationTime() < currentTime ||
		t.getDestinationTime().equals(currentTime)
		&& prevTime < t.getDestinationTime())) {
		// set state to arrived
		t.setState(Train::STATES::ARRIVED);
		// print train
		printTrain(t);
	}
}

void Simulate::finished(Train& t) {
	TrainTime afterFin = t.getDestinationTime().increase(20);
	TrainTime prevTime = currentTime.decreaseMins(10);

	if ((afterFin < currentTime || afterFin.equals(currentTime)
		&& prevTime < afterFin)) {
		// set state to finished
		t.setState(Train::STATES::FINISHED);
		// disasemble train
		t.disassembleTrain();
		// print train
		printTrain(t);

	}

}

void Simulate::finished(Train& t, bool b) {
	if (b) {
		// set state to finished
		t.setState(Train::STATES::FINISHED);
		// disasemble train
		t.disassembleTrain();
		// print train
		printTrain(t);
	}
}

void Simulate::startSim(Train& t) {
	// is state is not assembled try to assemble
	if (t.getState() == Train::STATES::NOT_ASSEMBLED) {
		tryAssemble(t);
	}if (t.getState() == Train::STATES::ASSEMBLED) {
		// if assemble set them to ready if right time
		ready(t);
	}
	if (t.getState() == Train::STATES::READY) {
		running(t);
	}if (t.getState() == Train::STATES::RUNNING) {
		arrived(t);
	}if (t.getState() == Train::STATES::ARRIVED) {
		finished(t); 

	}
}



Simulate::~Simulate() {
	// close files.
	trainSim.close();
	file.close();
	file2.close();
}
#include <string>
#include "ship.h"

#ifndef CARGOSHIP_H
#define CARGOSHIP_H



class CargoShip : public Ship {
private:

	//pointer variable for 2 compartment for cargoship which records how many items
	//   are there.
	double *forwardCargoBay;
	double *aftCargoBay;

	// maximum capacity of the total cargo 
	int maximumCapacity;

public:

	CargoShip(std::string, double, int);
	~CargoShip(); //destructor
	void fuel(int); //overloads the fuel function (makes it totally different from ship class)
	void load(int); //loads cargo into cargoship
};

#endif // !CARGOSHIP_H


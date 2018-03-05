#include <string>
#include <iostream>
#include "cargoship.h"


CargoShip::CargoShip(std::string name, double fuelLoad, int capacity) : Ship(name, fuelLoad) {

	maximumCapacity = capacity;
	//dynamically allocates the forward and aft cargo bay
	forwardCargoBay = new double;
	aftCargoBay = new double;

	//initializes the forward cargoBay and aft to 0;
	*forwardCargoBay = 0;
	*aftCargoBay = 0;
}

//prints amount of fuel th ship has and verifies the fuel flash point
void CargoShip::fuel(int min) {
	std::cout << shipName << " fuel: " << amountOfFuel << " tons" << std::endl;
	std::cout << shipName << " verified fuel flashpoint > " << min
		<< " degrees" << std::endl;
}


void CargoShip::load(int cargo) {
	//47% goes to forwardCargoBay
	const double percentageInForwardCargoBay = 0.47;

	//total amount of cargo being loaded ought to smaller or equal to the maximum capacity
	double total = *forwardCargoBay + *aftCargoBay;
	if (total <= maximumCapacity) {
		*forwardCargoBay += percentageInForwardCargoBay*cargo;
		*aftCargoBay += (1 - percentageInForwardCargoBay)*cargo;
		//outputs how much is being loaded to what cargo
		std::cout << shipName << " Loading...Ajusting CG..."
			<< *forwardCargoBay << " tons in FWD Bay "
			<< *aftCargoBay << " tons in AFT Bay" << std::endl;
	}
}


CargoShip::~CargoShip()
{
	delete forwardCargoBay;
	forwardCargoBay = NULL;

	delete aftCargoBay;
	aftCargoBay = NULL;
}
#include "ship.h"
#include <string>
#include <iostream>

//parameterzied constructor
Ship::Ship(std::string name, double fuelLoad) {
	shipName = name;
	amountOfFuel = fuelLoad;
}

//outputs ship name and amount of fuel it has
void Ship::fuel() const {
	std::cout << shipName << ": " << amountOfFuel << " tons" << std::endl;
}

//generic ship is sailing message
void Ship::sail() {
	std::cout << "Ship sailing" << std::endl;
}

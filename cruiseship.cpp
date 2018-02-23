#include "cruiseship.h"
#include <iostream>
#include <string>


//parameterized constructor and sends name and amount of fuel to ship constructor
CruiseShip::CruiseShip(std::string name, double fuelLoad, double luxury, double upper, double lower) : Ship(name, fuelLoad) {

	//only works when total percentage is equal to 1 and initailizes each percentage variables
	double total = luxury + upper + lower;
	if (total == 1) {
		percentageLuxury = luxury;
		percentageUpperDeck = upper;
		percentageLowerDeck = lower;
	}
}

//distributes number of passanger into each each of the compartment according to its percentage
void CruiseShip::load(int aNumber) {

	Luxury = int(percentageLuxury*aNumber);
	Upper_Deck = int(percentageUpperDeck*aNumber);
	Lower_Deck = int(percentageLowerDeck*aNumber);

}

//outputs number of passanger in each compartment
void CruiseShip::sail() {
	std::cout << shipName << " sailing: " << Luxury << " in  Luxury " <<
		Upper_Deck << " in Upper Deck and " << Lower_Deck << " in Lower Deck" << std::endl;
}


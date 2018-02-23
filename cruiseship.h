#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include "ship.h"
#include <string>

class CruiseShip : public Ship {
private:
	//percentage of passengers in Luxury, Uppper and Lower deck
	double percentageLuxury;
	double percentageUpperDeck;
	double percentageLowerDeck;

	//Number of passaengers in Luxury, Upper and Lower deck
	int Luxury;
	int Upper_Deck;
	int Lower_Deck;

public:
	//parameterized constructor
	CruiseShip(std::string, double, double, double, double);

	//overloading sail function to output number of passanger in each compartment
	virtual void sail();

	//overloading load function to distribute passanger in each compartment
	virtual void load(int);

};
#endif // !CRUISESHIP_H

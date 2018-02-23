//abstract ship class meaning it has pure virtual function
#ifndef SHIP_H
#define SHIP_H
#include <string>

class Ship {

	//protected member variable
protected:
	std::string shipName; //name of the ship
	double amountOfFuel; //amout of fuel on board in tons

						 //public member variable
public:

	Ship(std::string, double); //paratmeterized constructor
	void fuel() const; //outputs ship name and amount of fuel it has
	virtual void sail(); //generic ship is sailing output
	virtual void load(int) = 0; //pure virtual function
};

#endif // !SHIP_H


/*
Author: Puran Nepal
Professor: Dr. Sal Barbosa
Class: CSCI 3110
Project: Project 3

Purpose: Practice inheritance, abstract Class and polymorpism
*/



#include <iostream>
#include "ship.h"  //Abstract Class called Ship
#include "cargoship.h" //Inherits from Ship class
#include "cruiseship.h" //Inherits from Ship class
using namespace std;

//this function that triggers sail method in Ship object
void sailShip(Ship &aShipObject);

int main() {

	//calling parameterized constructor for CruiseShip class
	CruiseShip carnival("Carnival", 400, 0.10, 0.20, 0.70);

	//this is inherited method from Ship class
	//And outputs ship name and amount of fuel
	carnival.fuel();

	//loads passanger in cruise ship and distributes them into 
	//  3 different compartment according to their percentage
	carnival.load(5000);

	//calls the overloaded sail function which tells how  many 
	//   passanger are in each compartment
	carnival.sail();


	//calls parameterized constructor for CargoShip class
	CargoShip IronMaiden("Iron Maiden", 750, 100);

	//I don't know what this does
	IronMaiden.fuel(55);

	//loads cargo into 2 different compartment 
	//    47% in front and rest in aft
	IronMaiden.load(800);

	//using the sailship function to call sail function
	sailShip(IronMaiden);

	system("pause");
	return 0;
}


//this function that triggers sail method in Ship object
void sailShip(Ship & aShipObject) {
	aShipObject.sail();
}
#include "GasPump.h";
#include <iostream>



//sets the our gass station with 
//types of fuel it offers
//max amount of fuel it has isn the gas station
//price per gallon 
GasPump::GasPump(std::string typesOfGas, double maxFuel, double priceOfAGallon) {
	gasType = typesOfGas;
	maxCapacity = maxFuel;
	pricePerGallon = priceOfAGallon;
}


//this is a private function which restores the 
//amount of gas it has once it is empty
void  GasPump::replenishFuel() {
	amountLevel = maxCapacity;
	std::cout << "The amount of Fuel has been restored" << std::endl;
}

//Crux of this program (unfinished) 
void GasPump::dispenseFuel(double amountRequested) {
	std::cout << std::fixed;
	std::cout.precision(2);
	
	std::cout << "vehicle " << gasType << " filled up with " << amountLevel << " gallons $" << amountLevel*pricePerGallon << endl;
	amountOfFuelPerPurchase = amountLevel;
	total
}
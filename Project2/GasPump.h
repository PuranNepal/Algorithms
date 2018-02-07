#ifndef GASPUMP_H
#define GASPUMP_H
#include <string>

class GasPump {
	private:
		std::string gasType;
		double amountLevel;
		double maxCapacity;
		double pricePerGallon;
		double amountOfFuelPerPurchase;
		double totalAmountOfFuelDispenced;
		double totalMoney;
		bool isBeingReplenish;
		void  replenishFuel();

		
	public:
		// parameterized constructor
		GasPump(std::string, double, double);

		//type of fuel accessor
		std::string getFuelType() const { 
			return gasType; 
		}

		//total amount of fuel dispenced for all purchases accessor
		double getTotalFuelDispenced() const { 
			return totalAmountOfFuelDispenced; 
		}

		//total amount of revenue for all purchases accessor
		double getTotalMoney() const {
			return totalMoney;
		}

		// that controls the fueling of vehicles
		void dispenseFuel(double);

};
#endif // !GASPUMP_H
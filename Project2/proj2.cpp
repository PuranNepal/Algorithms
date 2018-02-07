#include <iostream>
#include "GasPump.h"
using namespace std;

int main() {

	GasPump *pumpPtr; //pointer to a Gaspump
	GasPump unleaded("Unleaded", 200, 2.59); //unleaded object
	GasPump midgrade("Midgrade", 125, 2.87); //midgrade object
	GasPump premium("premium+", 100, 3.13); //premium object
	int TotalVeichle = 50;
	int reqFuel; //how much fuel a vechile wants


	srand(1000); //setting our random number generator

	//siumlating 50 vechicles
	for (int i = 0; i < TotalVeichle; i++)
	{

		int rnd = rand();
		reqFuel = 3 + (((double)rnd) / RAND_MAX) * 22;

		
		//we want pumpPtr to point to midgrade when random number is 4 or 5 (29% of times)
		if ((rnd%7 == 4) || (rnd%7 == 5)) {

			pumpPtr = &midgrade;

			cout << "Vechile " << i << " ";
			pumpPtr->dispenseFuel(reqFuel);

		} //we want pumPtr to point to premium when random number is 6 (14%)
		else if (rnd%7 == 6) {

			pumpPtr = &premium;

			cout << "Vechile " << i << " ";
			pumpPtr->dispenseFuel(reqFuel);

		} //rest of time we want to point to unleaded(57%)
		else {

			pumpPtr = &unleaded;

			cout << "Vechile " << i << " ";
			pumpPtr->dispenseFuel(reqFuel);
		}
	}

	//total fuel dispensed & revenue for unlead pump
	cout << "Pump Unleaded dispensed " << unleaded.getTotalFuelDispenced() 
		 << " gallons and collected $" << unleaded.getTotalMoney() << endl;

	//total fuel dispensed & revenue for midgrade pump
	cout << "Pump Midgrade dispensed " << midgrade.getTotalFuelDispenced()
		 << " gallons and collected $" << midgrade.getTotalMoney() << endl;

	//total fuel dispensed & revenue for premium+ pump
	cout << "Pump Premium dispensed " << premium.getTotalFuelDispenced()
		 << " gallons and collected $" << premium.getTotalMoney() << endl;


	system("pause");
	return 0;
}
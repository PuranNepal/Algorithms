#include <iostream>
#include "GasPump.h"
using namespace std;

int main() {

	GasPump a("leaded", 2, 2);
	
	cout << a.getFuelType() << endl;

	system("pause");

	return 0;
}
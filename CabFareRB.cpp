#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	double travelMiles, total;	// Initializing variables
	int travelCost, timeCost, waitTime;
	cout << "Enter miles traveled: "; // Asking for milage and wait time inputs, and asking again if inputs are invalid
	cin >> travelMiles;
	while (travelMiles <= 0) {
		cout << "Enter a distance greater than 0 miles: ";
		cin >> travelMiles;
	}
	cout << "Enter wait time (seconds): ";
	cin >> waitTime;
	while (waitTime < 0) {
		cout << "Enter a time of 0 or more seconds: ";
		cin >> waitTime;
	}
	travelMiles = travelMiles * 100; // Calculating the cost of milage (multiplied travelMiles by 100 to work with whole integers instead of decimals to avoid error)
	if (travelMiles > 20) {
		if ((static_cast<int>(travelMiles) % 20) == 0)
			travelCost = 50 + (((static_cast<int>(travelMiles) - 20) / 20) * 22);
		else
			travelCost = 50 + (((static_cast<int>(travelMiles) - 20) / 20) * 22) + 22;
	}
	else
		travelCost = 50;

	timeCost = waitTime / 60; // Calculating the cost of inputted wait time (seconds)
	if (timeCost % 60 == 0)
		timeCost = timeCost * 20;
	else
		timeCost = (timeCost * 20) + 20;
	total = (static_cast<double>(travelCost) + static_cast<double>(timeCost)) / 100; // Adding the cost of both milage and wait time

	cout << setprecision(2) << fixed; // Fixed to 2 decimal places, and outputting total cost
	cout << "The cost of the taxi ride is: $" << total << endl;
	return 0;
}
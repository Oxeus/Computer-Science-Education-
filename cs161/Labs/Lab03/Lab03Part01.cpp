//Programmed by: Adam La Fleur
//Sources: None

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double principle;
	double rate;
	double term;
	double result;
	cout << "Welcome to the compound interest calculator." << endl;
	cout << "What is the principle? ";
	cin >> principle;
	cout << "What is the interest rate? ";
	cin >> rate;
	cout << "What is the term? ";
	cin >> term;
	result = principle * pow((rate + 1.0), term);
	cout << fixed << showpoint << setprecision(2);
	cout << "Future value: $" << result << endl;
	//system("pause"); //Windows Only
	return 0;
}




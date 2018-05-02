#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int sbal, intr;
	int year, yearc = 1;
	double rate;
	cout << "Enter starting balance: ";
	cin >> sbal; 
	cout << "Enter interest rate: ";
	cin >> intr;
	rate = intr;
	rate = rate / 100;
	cout << "Enter number of years: ";
	cin >> year;
	cout << endl;
	double fbal = sbal;
	for(int i = 0; i < year; i++)
	{ 	
		fbal = fbal + (fbal*rate);
		cout << "Year " << yearc << fixed << setprecision(2) <<  " $" << fbal << endl; 
		yearc++;
	}
}

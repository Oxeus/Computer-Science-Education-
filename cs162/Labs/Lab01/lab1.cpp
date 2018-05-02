//Programmed by: Adam La Fleur
//Assignment: Lab 1
//Course: CS162
//Date: January 15, 2016

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	char answer;
	bool answer_loop = true;
	int choice = 0;
	double wtPlanet, wtEarth;
	double gEarth = 9.81, gPlanet = 0;
	double const gMoon = 1.622, gMercury = 3.7, gVenus = 8.87, gJupiter = 24.79;
	while (answer_loop)
	{
		cout << "Planet Weight Finder" << endl << "--------------------" << endl
			<< "Planet List\n"
			<< " 1 - Moon.\n"
			<< " 2 - Mercury.\n"
			<< " 3 - Venus.\n"
			<< " 4 - Jupiter.\n"
			<< endl;
		cout << "What is your weight on earth: ";
		cin >> wtEarth;
		if (wtEarth >= 0)
		{
			cout << endl << "What is your planet choice: ";
			cin >> choice;
			cout << endl;
			switch (choice)
			{
			case 1:
				gPlanet = gMoon;
				wtPlanet = wtEarth * (gPlanet / gEarth);
				cout << fixed << setprecision(2) << "Your weight on the moon is " << wtPlanet << "." << endl;
				break;

			case 2:
				gPlanet = gMercury;
				wtPlanet = wtEarth * (gPlanet / gEarth);
				cout << fixed << setprecision(2) << "Your weight on Mercury is " << wtPlanet << "." << endl;
				break;

			case 3:
				gPlanet = gVenus;
				wtPlanet = wtEarth * (gPlanet / gEarth);
				cout << fixed << setprecision(2) << "Your weight on Venus is " << wtPlanet << "." << endl;
				break;

			case 4:
				gPlanet = gJupiter;
				wtPlanet = wtEarth * (gPlanet / gEarth);
				cout << fixed << setprecision(2) << "Your weight on Juptier is " << wtPlanet << "." << endl;
				break;
			default:
				cout << "The choice you entered is not valid." << endl;
				break;
			}
			cout << "Do you want to continue (y or n): ";
			cin >> answer;
			cout << endl;
			if (answer == 'y')
			{
				answer_loop = true;
			}
			else if (answer == 'n')
			{
				answer_loop = false;
			}
			else
			{
				cout << "The choice that you have entered is invalid, returning to the menu." << endl;
				cout << endl;
				answer_loop = true;
			}
		}
		else
		{
			cout << endl;
			cout << "The weight you entered is invalid. Returning to menu." << endl;
			cout << endl;
		}
	}
	return 0;
}

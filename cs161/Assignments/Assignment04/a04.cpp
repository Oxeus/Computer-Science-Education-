/**********************************************************************
Programmed by: Adam La Fleur
Program: Assignment 4 Planet Classification and Potential First Contact
Sources: None
**********************************************************************/

#include <iostream>

using namespace std;

//Initiate main function

int main() {

	//Assign values for Distance, Diameter, and yes/no
	double milDistance, diameterPlanet;
	char answerYN;

	//Ask for Distance to nearest star and store it in milDistance
	cout << "Computer. Working. What is the distance of the planet from its sun in millions of miles? ";
	cin >> milDistance;

	//Determne whether planet is to cold or hot
	if (milDistance >= 75 && milDistance <= 110) {
		cout << "This planet is in the habitable zone. What is its diameter in miles? ";
		cin >> diameterPlanet;

		//Determine whether diameter of planet is to small or too large
		if (diameterPlanet >= 5000 && diameterPlanet <= 10000) {
			cout << "Based on distance and gravitational pull, this planet may be suitable for human life." << endl;
			cout << "Does this planet have intelligent life (y/n)? ";
			cin >> answerYN;

			//Determine whether planet has intelligent life
			if (answerYN == 'n') {
				cout << "Since there is no intelligent life, this planet may be suitable for colonization." << endl;
			}

			else if (answerYN == 'y') {
				cout << "Does the intelligent life of this planet have warpdrive technology (y/n)? ";
				cin >> answerYN;

				//Determine whether the life on the planet has warpdrive
				if (answerYN == 'y') {
					cout << "Because this civilization has warp technology, you may make first contact. Proceed with caution." << endl;
				}
				else if (answerYN == 'n') {
					cout << "Obey the prime directive, and do not make contact." << endl;
				}
			}
		}

		else if (milDistance < 5000 || milDistance > 10000) {
			cout << "Based on distance and gravitational pull, this planet is not suitable for humans life." << endl;
		}
	}

	else if (milDistance < 75) {
		cout << "This planet is too close to its sun, and is therefore too hot for human habitation." << endl;
	}

	else if (milDistance > 110) {
		cout << "This planet is too far from its sun, and is therefore too cold for human habitation." << endl;
	}

	//Pause and end program
	//system("pause"); //Windows Only
	return 0;
}

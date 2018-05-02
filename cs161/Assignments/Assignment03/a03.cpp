/****************************************************************
//Project 3: Program that can take in a destination and distance
//from a input file and output them to a file along with how many 
//days it takes at each warp speed in a neat and orderly fashion.
//
//Programmed by: Adam La Fleur
//
//Sources: No outside sources except for Chapter 3 of textbook.
/***************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	//Initialize variables, create iostream keywords
	string systemName;
	string infileName;
	string outfileName;
	double distance;
	int warp4Days, warp5Days, warp6Days;
	ifstream inData;
	ofstream outData;

	//Ask for name of input and output text files as a input string
	cout << "Computer. Working. What is the name of the star system input file? ";
	cin >> infileName;
	cout << "What would you like to call the output data file? ";
	cin >> outfileName;
	cout << endl;

	//Open files
	inData.open(infileName);
	outData.open(outfileName);

	//Console and output heading
	cout << left << setw(15) << "Destination" << 
		right << setw(15) << "Distance" <<
		setw(15) << "Warp 4 Days" << 
		setw(15) << "Warp 5 Days" <<
		setw(15) << "Warp 6 Days" << "\n" <<
		"---------------------------------------------------------------------------" << endl;
	outData << left << setw(15) << "Destination" << 
		right << setw(15) << "Distance" <<
		setw(15) << "Warp 4 Days" <<
		setw(15) << "Warp 5 Days" <<
		setw(15) << "Warp 6 Days" << "\n" <<
		"---------------------------------------------------------------------------" << endl;
	
	//Convert First destination and output in screen and txt file
	inData >> systemName >> distance;
	warp4Days = (distance / 64) * 365;
	warp5Days = (distance / 125) * 365;
	warp6Days = (distance / 216) * 365;
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(15) << systemName << 
		right << setw(15) << distance <<
		setw(15) << warp4Days << 
		setw(15) << warp5Days << 
		setw(15) << warp6Days << endl;
	outData << fixed << showpoint << setprecision(2);
	outData << left << setw(15) << systemName << 
		right << setw(15) << distance <<
		setw(15) << warp4Days <<
		setw(15) << warp5Days <<
		setw(15) << warp6Days << endl;

	//Convert Second Destination and output in screen and txt file
	inData >> systemName >> distance;
	warp4Days = (distance / 64) * 365;
	warp5Days = (distance / 125) * 365;
	warp6Days = (distance / 216) * 365;
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(15) << systemName <<
		right << setw(15) << distance <<
		setw(15) << warp4Days <<
		setw(15) << warp5Days <<
		setw(15) << warp6Days << endl;
	outData << fixed << showpoint << setprecision(2);
	outData << left << setw(15) << systemName <<
		right << setw(15) << distance <<
		setw(15) << warp4Days <<
		setw(15) << warp5Days <<
		setw(15) << warp6Days << endl;

	//Convert Third Destination and output in screen and txt file
	inData >> systemName >> distance;
	warp4Days = (distance / 64) * 365;
	warp5Days = (distance / 125) * 365;
	warp6Days = (distance / 216) * 365;
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(15) << systemName <<
		right << setw(15) << distance <<
		setw(15) << warp4Days <<
		setw(15) << warp5Days <<
		setw(15) << warp6Days << endl;
	outData << fixed << showpoint << setprecision(2);
	outData << left << setw(15) << systemName <<
		right << setw(15) << distance <<
		setw(15) << warp4Days <<
		setw(15) << warp5Days <<
		setw(15) << warp6Days << endl;

	//close both files
	inData.close();
	outData.close();

	//Pause screen and return 0 to system
	//system("pause"); //Windows Only
	return 0;
}

/**************************
Programmed by: Adam LaFleur
Lab 5: Part 1
Sources: None
**************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int num, finalNum = 0;
	string myFile;
	ifstream infile;

	cout << "Enter the name of the file that contains the numbers: ";
	cin >> myFile;

	infile.open(myFile);
	while (!infile.eof()) {
		infile >> num;
		if (num % 5 == 0) {
			finalNum += num;
		}
		else
		{
			num = 0;
		}
	}
	cout << "The sum of the numbers in the file that is able to be devided by 5 is " << finalNum << "." << endl;
	//system("pause"); //Windows Only
	return 0;
}

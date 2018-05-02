//Programmed by: Adam La Fleur
//Sources: None

#include <iostream>
#include <string>

using namespace std;

int main() {
	double kiloDist;
	double mileDist;
	cout << "A program to convert from kilometers to statute miles (normal miles) \n" << endl;
	cout << "Please enter a distance in terms of kilometers: " << endl;
	cin >> kiloDist;
	mileDist = kiloDist * 0.62;
	cout << kiloDist << " kilometers in miles is about " << mileDist << " miles." << endl;
	//system("pause"); //Windows Only
}

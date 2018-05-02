//Programmed by: Adam La Fleur
//Assignment: Project 1
//Course: CS162
//Date: January 17, 2017

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint); 
	cout.precision(2);
	string itemName;
	double itemPrice = 0.00, totalPrice = 0.00;
	bool control_statement = true;
	cout << "=======================\n" << endl <<
		"$$$$$$$$$$ Shopping Cart App $$$$$$$$$$$" << endl;
	while (control_statement) {
		cout << "Item Name: ";
		cin >> itemName;
		if (itemName != "quit")
		{
			cout << "Item Price: ";
			cin >> itemPrice;
			if (itemPrice > 0) {
				cout << "Bought " << itemName << " at $" << itemPrice << endl;
				totalPrice += itemPrice;
				cout << "Your total is now $" << totalPrice << endl << endl;
			}
			else {
				cout << "I'm sorry but the price connot be negative. Please re-enter: ";
				cin >> itemPrice;
				totalPrice += itemPrice;
				cout << "Your total is now $" << totalPrice << endl << endl;
			}
		}
		else {
			control_statement = false;
		}
	}
	cout << "Your final total is: $" << totalPrice << endl << "Thank You!\n" << endl;
	return 0;
}

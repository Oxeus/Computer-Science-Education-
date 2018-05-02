//Made by Adam La Fleur. 
//Sources: None

#include <iostream>
#include <string>

using namespace std;

int main() {
	double stockPrice1;
	double stockPrice2;
	double stockPrice3;
	double stockPrice4;
	double averageStock;
	cout << "Please enter all values in term of dollars and cents! \n" << endl;
	cout << "Please enter the price of Stock 1: " << endl;
	cin >> stockPrice1;
	cout << "Please enter the price of Stock 2: " << endl;
	cin >> stockPrice2;
	cout << "Please enter the price of Stock 3: " << endl;
	cin >> stockPrice3;
	cout << "Please enter the price of Stock 4: " << endl;
	cin >> stockPrice4;
	averageStock = ( stockPrice1 + stockPrice2 + stockPrice3 + stockPrice4 ) / 4;
	cout << "The average stock price is: " << averageStock << "." << endl;
	//system("pause"); //Windows Only
}


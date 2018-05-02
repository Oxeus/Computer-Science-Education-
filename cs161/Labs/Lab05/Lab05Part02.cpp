/**************************
Programmed by: Adam LaFleur
Lab 5: Part 2
Sources: None
**************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, i, rem;
	bool isPrime = true;

	cout << "Please enter a positive number: ";
	cin >> n;
	if (n == 1) {
		cout << "The number is not a prime number." << endl;
	}
	else if (n == 2) {
		cout << "The number is a prime number." << endl;
	}
	else if (n > 2) {
		for (i = 2; i < n; i++) {
			rem = n % i;
			if (rem == 0) {
				isPrime = false;
			}
		}
		if (isPrime) {
			cout << "The number is a prime number." << endl;
		}
		else if (!isPrime) {
			cout << "The number is not a prime number." << endl;
		}
	}
	else {
		cout << "The number entered is not a positive number, press enter to terminate program." << endl;
	}
	//system("pause"); //Windows Only
	return 0;
}

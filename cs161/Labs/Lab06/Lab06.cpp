/****************************
Programmed By: Adam La Fleur
Assignment: Lab 6
Sources: None
****************************/

#include <iostream>

using namespace std;

int addEveryOddDigit(int number){
	int result = 0;
	while (number != 0){
		if (number % 2 == 1)
			result += number % 10;
			number /= 10;
	}
	return result;
}

int main()
{
	int userNum, result;
	cout << "Enter your number: ";
	cin >> userNum;
	cout << endl;
	result = addEveryOddDigit(userNum);
	cout << "The result of every odd digit in your number is " << result << "." << endl;
	//system("pause"); //Windows Only
	return 0;
}

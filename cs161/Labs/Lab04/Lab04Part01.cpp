/***********************************************
By: Adam La Fleur
Sources: ASCII Table: http://www.ascii-code.com/
***********************************************/
#include <iostream>

using namespace std;

int main() {
	int yourNum;
	cout << "Please enter a number between 1 and 61: ";
	cin >> yourNum;

	if (yourNum > 0 && yourNum < 10) {
		cout << yourNum << endl;
	}
	else if (yourNum >= 10 && yourNum <= 35) {
		cout << static_cast<char>((yourNum - 10) + 65) << endl;
	}
	else if (yourNum >= 36 && yourNum <= 61) {
		cout << static_cast<char>((yourNum - 36) + 97) << endl;
	}
	else {
		cout << "Your number is not a valid number!" << endl;
	}
	//system("pause"); //Windows Only
	return 0;
}

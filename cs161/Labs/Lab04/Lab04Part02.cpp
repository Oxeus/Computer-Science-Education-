/***********************************************
By: Adam La Fleur
Sources: None
***********************************************/
#include <iostream>

using namespace std;

int main() {
	double yourGrade;
	cout << "Welcome to the grade checker program. What score did you get on the test? ";
	cin >> yourGrade;
	if (yourGrade <= 100 && yourGrade >= 90) {
		cout << "Based on your score, you grade is an A." << endl;
	}
	else if (yourGrade < 90 && yourGrade >= 80) {
		cout << "Based on your score, you grade is an B." << endl;
	}
	else if (yourGrade < 80 && yourGrade >= 70) {
		cout << "Based on your score, you grade is an C." << endl;
	}
	else if (yourGrade < 70 && yourGrade >= 60) {
		cout << "Based on your score, you grade is an D." << endl;
	}
	else if (yourGrade < 60 && yourGrade >= 0) {
		cout << "Based on your score, you grade is an F." << endl;
	}
	//system("pause"); //Windows Only
	return 0;
}

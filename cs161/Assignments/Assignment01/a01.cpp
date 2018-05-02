#include <iostream>
#include <string>
using namespace std;

int main() {
	string yourName;
	string yourAge;
	string favColor;
	string birthLoc;
	string detFood;

	cout << "Hello, who are you?" << endl;
	cin >> yourName;
	cout << "How old are you?" << endl;
	cin >> yourAge;
	cout << "What is your favorite color?" << endl;
	cin >> favColor;
	cout << "Where were you born?" << endl;
	cin >> birthLoc;
	cout << "What food do you detest?" << endl;
	cin >> detFood;
	cout << endl << "Today's C++ Headlines from News Weekly!!!" << endl << "-----------------------------------------" << endl <<
		"This just in, " << yourAge << " aliens have just taken over the town of " << birthLoc << "!" << endl <<
		"They resemble large " << detFood << " and are also of the color " << favColor << "." << " We all" << endl << 
		"advise you to watch out for their leader, his name is " << yourName << "." << endl;
	//system("pause"); //Windows Only
	return 0;
}

//Programmed by: Adam La Fleur
//Sources: Used as a basis for finding modulus http://www.tenouk.com/cpluscodesnippet/hoursminutesecond.html
//Sources Cont: Compared with Ryan from our class. The other way to find days could be days = static_cast<int>((time - years) * 365);

#include <iostream>
#include <string>

using namespace std;

int main() {
	string planetName;
	double distance;
	double time;
	int warp;
	int years;
	int days;

	cout << "Hello Captain, Where were you like to travel?" << endl;
	cin >> planetName;
	cout << "How many light years is it to " << planetName << "?" << endl;
	cin >> distance;
	cout << "What warp factor do you want to use?" << endl;
	cin >> warp;
	time = distance / (warp * warp * warp);
	years = static_cast<int>(time);
	days = (time * 365);
	days = days % 365;
	cout << "Based on my calculations captain, to get to " << planetName << " at a warp factor of " <<
		warp << ", it would take " << time << " years! \n" << endl <<
		"In terms of years and days, it would take " << years << " years and " << days << " days! \n" << endl;
	//system("pause"); //Windows Only
	return 0;
}

/**********************************
Programmed by: Adam La Fleur
Sources: None
**********************************/
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
	//Initialize yourInput and upper; also acquire yourInput as a char array
	char yourInput[100];
	bool upper = true;
	cout << "What is your input? " << endl;
	cin.getline(yourInput, strlen(yourInput));

	//Convert char array to alternating lower and upper case
	for (int i = 0; i < strlen(yourInput); i++)
	{
		if (upper){
			yourInput[i] = toupper(yourInput[i]);
			if (yourInput[i] == ' ')
				upper = !upper;
		}
		else {
			yourInput[i] = tolower(yourInput[i]);
			if (yourInput[i] == ' ')
				upper = !upper;
		}
	}

	//Output final yourInput
	cout << yourInput << endl;
	
	//Pause system and return 0
	//system("pause"); //Windows Only
	return 0;
}



/***************************
Programmed by: Adam LaFleur
Assignment: Lab 2
Course: CS162
Date: January 20, 2017
***************************/

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	//Initialize variables
	bool choice = true;
	char yes_no = 'y';
	
	//Prompt the user to enter a word
	cout << "===========================" << endl;
	//Loops controlled by user choice to continue
	while (choice) {
		//Initialize and or reset char arrays to be blank
		char word[30] = "", reverseWord[30] = "";
		cout << "Enter string value: ";
		cin >> word;
		const int count = strlen(word);
		//Reverse word starting from the last character
		for (int i = count - 1; i >= 0; i--)
		{
			reverseWord[count - i - 1] = word[i];
		}
		//Conforms if the word is a palindrome through comparison of itself in reverse, if they are the same return 0
		if (strcmp(word, reverseWord) == 0) {
			cout << "Your string is a palindrome." << endl;
			cout << "Do you want to continue? (y or n)" << endl;
			cin >> yes_no;
			//Ask if the use wants to quit, if the answer is not "y" then exit the program
			if (yes_no != 'y') {
				choice = false;
			}
		}
		//If the compared words are not the same
		else {
			cout << "Your string is not a palindrome." << endl;
			//Ask if the use wants to quit, if the answer is not "y" then exit the program.
			cout << "Do you want to continue? (y or n)" << endl;
			cin >> yes_no;
			if (yes_no != 'y') {
				choice = false;
			}
		}
	}
}

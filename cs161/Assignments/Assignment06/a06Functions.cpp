#include "a06Header.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


int loadData(FedMember federation[])
{
	int memberCount = 0;
	ifstream federationData;
	federationData.open("Docs/federationData.txt");
	cout << "Reading from the file!" << endl;
	while (!federationData.eof() && memberCount < 10)
	{
		getline(federationData, federation[memberCount].names);
		getline(federationData, federation[memberCount].homeStars);
		getline(federationData, federation[memberCount].distances);
		memberCount++;
	}
	federationData.close();
	return memberCount;
}

void addMember(FedMember federation[], int memberCount)
{
	cin.ignore();
	cout << endl << endl;
	cout << "What is the lifeform name of the member that you want to add? ";
	getline(cin, federation[memberCount].names);
	cout << "What is the Home Star that you want to add? ";
	getline(cin, federation[memberCount].homeStars);
	cout << "What is the distance of the Home Star to Earth? ";
	getline(cin, federation[memberCount].distances);
}

void displayMembers(FedMember federation[], int memberCount)
{
	cout << endl << endl;
	cout << "Displaying All Members:" << endl;
	cout << endl;
	cout << left << setw(20) << "Names" << setw(20) << "Home Stars" << setw(20) << "Distances" << endl;
	cout << setfill('-') << setw(60) << "-" << endl;
	cout << setfill(' ');

	for (int i = 0; i < memberCount; i++)
	{
		cout << fixed << setprecision(2);
		cout << left << setw(20) <<  federation[i].names << setw(20) << federation[i].homeStars << setw(20) <<  federation[i].distances << endl;
	
	}
}

void search(FedMember federation[], int memberCount)
{
	string lifeName;
	cout << endl << endl;
	cout << "Please enter lifeform name: ";
	cin >> lifeName;
	cout << endl;
	for (int i = 0; i < memberCount; i++)
	{
		if (lifeName == federation[i].names)
		{
			cout << left << setw(20) << federation[i].names << setw(20) << federation[i].homeStars << setw(20) << federation[i].distances << endl;
		}
	}
}

void sort(FedMember federation[], int memberCount)
{
	int index;
	int smallestIndex;
	int location;
	string temp;

	for (index = 0; index < memberCount - 1; index++)
	{
		smallestIndex = index;

		for (location = index + 1; location < memberCount; location++)
			if (federation[location].names < federation[smallestIndex].names)
			{
				smallestIndex = location;
			}
		FedMember temp = federation[smallestIndex];
		federation[smallestIndex] = federation[index];
		federation[index] = temp;
	}
}

void writeData(FedMember federation[], int memberCount)
{
	string yourInput = "Docs/";
	string federationData = "federationData.txt";
	char yourAnswer;
	ofstream outFile;
	cout << "What is the name of the file that you want to output too? ";
	cin >> yourInput;
	yourInput += ".txt";
	cout << "The name of your input file is " << yourInput << ". Is this the file that you want to load? (Enter 'y' for yes or 'n' for no) ";
	cin >> yourAnswer;
	switch (yourAnswer)
	{
	case 'y':
		cout << "Outputing to file." << endl;
		outFile.open(yourInput);
		outFile << left << setw(20) << "Names" << setw(20) << "Home Stars" << setw(20) << "Distances" << endl;
		outFile << setfill('-') << setw(60) << "-" << endl;
		outFile << setfill(' ');

		for (int i = 0; i < memberCount; i++)
		{
			outFile << fixed << setprecision(2);
			outFile << left << setw(20) << federation[i].names << setw(20) << federation[i].homeStars << setw(20) << federation[i].distances << endl;
		}
		cout << "Finished outputing to file." << endl;
		outFile.close();
		break;
	case 'n': 
		break;
	default: 
		break;
	}
}

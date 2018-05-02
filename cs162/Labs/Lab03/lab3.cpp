/*****************************************
Programmed by: Adam LaFleur
Assignment: Lab 3
Course: CS162
Date: January 27, 2017
*****************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

//Initializing a limit for the arrays
const int LIMIT = 100;

//Array of structs for book database
struct Books
{
	char bookName[LIMIT];
	int invCount;
	double price;
};

Books database[LIMIT];
int bookCount = 0;

//Initialize user-defined functions
int loadFile();
void salePrice();
void writeFile();

int main()
{
	cout << "Welcome to the repricing program." << endl << endl;
	cout << "Reading the data from the file..." << endl;
	//Find the number of books in the file.
	bookCount = loadFile();
	cout << "Complete.\n" << endl;
	//Print out list of books until the books printed in the terminal has reached the total book count, set precision to be fixed to 2 decimal places
	for(int i = 0; i < bookCount; i++)
	{
		cout << database[i].bookName << endl;
		cout << database[i].invCount << endl;
		cout << fixed << setprecision(2) << database[i].price << endl;
	}
	cout << endl << "The new prices of the books for 20% off are: \n" << endl;
	salePrice();
	cout << endl << "Loading the sales data into a file...\n" << endl;
	writeFile();
	cout << "Complete" << endl;
	return 0;	
}

//Load data into array from file
int loadFile()
{
	ifstream booksFile;
	booksFile.open("books.txt");
	//Determine if file is open
	if (booksFile.is_open())
	{
		//Loop until end of file or until bookCount is less than the LIMIT value of 100, 
		//also load into a char array the book names for 200 spaces; load into struct array the bookName, invCount and price
		while (!booksFile.eof() && bookCount < LIMIT)
		{
			booksFile.get(database[bookCount].bookName, 200, '\n'); 
			booksFile >> database[bookCount].invCount;
			booksFile >> database[bookCount].price;
			booksFile.ignore(200, '\n');
			bookCount++;
		}
	}
	else cout << "Unable to open file";
	booksFile.close();
	bookCount = bookCount - 1;
	return bookCount;
}

//Calculate the price of the boks after 20% discount and print the new prices to the terminal along with the other information
void salePrice()
{
	for (int i = 0; i < bookCount; i++)
	{
		cout << database[i].bookName << endl;
		cout << database[i].invCount << endl;
		database[i].price = database[i].price * 0.80;
		cout << fixed << setprecision(2) << database[i].price << endl;
	}
}

//Write to a file called 'sales.txt' the new sales data along with book title and total count
void writeFile()
{
	ofstream saleFile;
	saleFile.open("sales.txt");
	for (int i = 0; i < bookCount; i++)
	{
		saleFile << database[i].bookName << endl;
		saleFile << database[i].invCount << endl;
		saleFile << fixed << setprecision(2)<< database[i].price << endl;
	}
	saleFile.close();
}

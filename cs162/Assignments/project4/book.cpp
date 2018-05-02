#include "book.h"

// Constructors
Book::Book()
{
	bookName[0] = ' ';
	price = 0;
	inventory = 0;
}

Book::Book(char bn[], double pri, int inv)
{
	bookName = new char[strlen(bn + 1)];
	strcpy(bookName, bn);
	price = pri;
	inventory = inv;
}

//Setters
void Book::setbookName(char bn[])
{
	strcpy(bookName, bn);
}

void Book::setprice(double pri)
{
	price = pri;
}

void Book::setinventory(int inv)
{
	inventory = inv;
}

//Getters
char * Book::getbookName()
{
	return bookName;
}

double Book::getprice()
{
	return price;
}

int Book::getinventory()
{
	return inventory;
}

//Functions
void Book::print()
{
	cout << "Title: " << bookName << endl;
	cout << "Count: " << inventory << endl;
	cout << "Price: " << fixed << setprecision(2) << price << endl;
	cout << "-------------------------------------" << endl;
}

Book::~Book()
{
	delete bookName;
}

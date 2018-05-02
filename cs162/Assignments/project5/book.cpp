#include "book.h"

// Constructors
Book::Book()
{
	bookName = nullptr;
	price = 0.0;
	inventory = 0;
}

Book::Book(const char* bn, double pri, int inv)
{
	bookName = nullptr;
	setbookName(bn);
	setprice(pri);
	setinventory(inv);
}

Book::~Book()
{
	if (bookName != nullptr) delete[] bookName;
}

void Book::print()
{
	cout << "Title: " << bookName << endl;
	cout << "Count: " << inventory << endl;
	cout << "Price: " << fixed << setprecision(2) << price << endl;
	cout << "-------------------------------------" << endl;
}

//Getters
const char* Book::getbookName()
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

//Setters
void Book::setbookName(const char* bn)
{
	if (bookName != nullptr) delete bookName;
	bookName = new char[strlen(bn) + 1];
	strcpy(bookName, bn);
}

void Book::setprice(double pri)
{
	if (pri < 0)
	{
		cout << "Cant set price to a negative number!" << endl;
		return;
	}

	price = pri;
}

void Book::setinventory(int inv)
{
	if (inv < 0)
	{
		cout << "Cant set inventory to a negative number!" << endl;
		return;
	}
	inventory = inv;
}



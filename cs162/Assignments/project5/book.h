#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

const int TOTAL = 200;

#ifndef BOOK_H
#define BOOk_H

class Book
{
public:

	//Constructors
	Book();
	Book(const char* bn, double pri, int inv);

	//Deconstructor
	~Book();

	void print();

	//Getters
	const char* getbookName();
	double getprice();
	int getinventory();

	//Setters
	void setbookName(const char* bn);
	void setprice(double pri);
	void setinventory(int inv);

private:
	char* bookName;
	double price;
	int inventory;
};

#endif




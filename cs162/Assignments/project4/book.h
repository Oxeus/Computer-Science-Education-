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
	Book(char bn[], double pri, int inv);

	//Setters
	void setbookName(char bn[]);
	void setprice(double pri);
	void setinventory(int inv);

	//Getters
	char * getbookName();
	double getprice();
	int getinventory();

	//Functions
	void print();

	~Book();
private:
	char * bookName;
	double price;
	int inventory;
};

#endif




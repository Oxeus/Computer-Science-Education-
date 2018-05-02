#pragma once
#include <iostream>
#include "queue.h"
#include "stack.h"
#include "scandata.h"

using namespace std;

class rover {
public:
	rover(int rover, int max);
	void deploy();
	void move(int x, int y);
	void corescan();
	void dock();

private:
	int roverID;
	int maxResult; //Default to store max values for arrays if used.
	int currx;
	int curry;
	void printID()
	{
		cout << "Rover(ID " << roverID << ")";
	}
	void setID(int ID)
	{
		roverID = ID;
	}
	queue q;
	stack s;
	scandata scan;
};

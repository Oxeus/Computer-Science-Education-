#include "rover.h"

using namespace std;

rover::rover(int rover, int max)
{
	setID(rover);
}

void rover::deploy()
{
	s.push(0, 0);
	currx = 0;
	curry = 0;
	printID();
	cout << " deploying..." << endl;
	printID();
	cout << " ready." << endl;
}

void rover::move(int x, int y)
{
	printID();
	cout << " moving to location " << x << ", " << y << endl;
	s.push(x,y);
	currx = x;
	curry = y;
}

void rover::corescan()
{
	printID();
	int data = scan.getScandata(currx, curry);
	q.enqueue(data);
	cout << " scanning." << endl; 
}

void rover::dock()
{
	int x;
	int y;
	printID();
	cout << " returning to base." << endl;
	s.pop();
	while (!s.isEmpty())
	{
		printID();
		x = s.topX();
		y = s.topY();
		cout << " moving to location " << x << ", " << y << endl;
		s.pop();
	}
	printID();
	cout << " at base. Sending results... " << endl;
	while (!q.isEmpty())
	{
		printID();
		int top = q.dequeue();
		cout << " result: " << top << endl;

	}
	printID();
	cout << " result transmission complete." << endl;
	printID();
	cout << " docked." << endl;
	currx = 0;
	curry = 0;
}

#include <iostream>

using namespace std;

int recurGCD(int x, int y) 
{
	if (y != 0)
	{
		return recurGCD(y, x % y);
	}
	else
	{
		return x;
	}
}

int iterGCD(int x, int y)
{
	int r;
	while (y != 0)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main()
{
	int x, y;
	cout << "=====================================" << endl 
		<< "Enter x and y integers ( > 0): " << endl;
	cin >> x >> y;
	if (x > 0 && y > 0)
	{
		cout << "Greatest Common Diviser recursively is " << recurGCD(x, y) << endl;
		cout << "Greatest Common Diviser iteratively is " << iterGCD(x, y) << endl;
	}
	else
	{
		cout << "The number that are entered are lesser than 0" << endl;
	}
	cout << "=====================================" << endl;
}

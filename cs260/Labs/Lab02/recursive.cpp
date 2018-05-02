#include <iostream>

using namespace std;

int recurseOne(int num)
{
	cout << num << endl;
	if(num < 100)
	{
		recurseOne(num+1);
	}
}

int recurseHundred(int num)
{
	cout << num << endl;
	if(num > 1)
	{
		recurseHundred(num-1);
	}
}

int main()
{
	cout << "1 to 100: " << endl;
	recurseOne(1);
	cout << "100 to 1: " << endl;
	recurseHundred(100);
	return 0;
}

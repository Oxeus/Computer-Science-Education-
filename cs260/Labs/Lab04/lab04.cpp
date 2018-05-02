#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
    	int num, temp = 0;
	cout << "----------------------------------------------------------------------" <<endl << endl;
    	cout << "How many values will you enter: ";
    	cin >> num;
	int a[num];
	cout << endl;
    	for(int i = 0; i < num; i++) 
	{
		cout << "Enter a number between 0 and 10: ";
		cin >> temp;
		if(temp < 0 || temp > 10)
		{
			cout << "Invalid value. Try again. " << endl;
			cout << "Enter a number between 0 and 10: ";
			cin >> temp;
		}
		a[i] = temp;
	}
	int high = a[0];
	for(int c = 0; c < num; c++)
	{
		if(a[c] > high)
		{
			high = a[c];
		}
	}
	cout << endl;
	for(int row = high; row >= 1; row--)
	{
		for(int col = 0; col < num; col++)
		{
			if(a[col] >= row)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}	
		cout << endl;
	}
	cout << endl;
	cout << "----------------------------------------------------------------------" << endl;
}

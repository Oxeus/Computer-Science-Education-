#include <iostream>
#include "functions.h"
#include <iomanip>

using namespace std;

void doAverage(int x, int y)
{
	int sum = x + y;
	int average = sum/2;
	
	cout << "Average of " << x << " and " << y << " is " << average << endl;
}

void doGCD(int x, int y)
{
	if(x < 0)
	{
		x = -x;
	}
	if(y < 0)
	{
		y = -y;
	}
	if(x == y)
	{
		cout << setw(3) << x << " " << y << " -- they are the same. " << x << " is the GCD" << endl;
		return;
	}
	else if (x > y)
	{
		cout << setw(3) << x << " " << y << " -- " << x << " is largest so replace it with " << x << "-" << y << endl;
		doGCD(x-y, y);
	}
	else
	{
		cout << setw(3) << x << " " << y << " -- " << y << " is largest so replace it with " << y << "-" << x << endl;
		doGCD(x,y-x);
	}

}

void doLCM(int x, int y)
{
	int lcm;
	int xy = x*y;
	int xt = x;
	int yt = y;
	while(xt != yt)
	{
		if(xt > yt)
		{
			cout << setw(3) << xt << " " << yt << " -- " << xt << " is largest so replace it with " << xt << "-" << yt << endl;
			xt = xt - yt;
		}
		else
		{
			cout << setw(3) << xt << " " << yt << " -- " << yt << " is largest so replace it with " << yt << "-" << xt << endl;
			yt = yt - xt;
		}
	}
	cout << setw(3) << xt << " " << yt << " -- they are the same. " << xt << " is the GCD" << endl;
	lcm = xy / xt;
	cout << "The LCM is (x*y)/GCD(x,y). x*y is " << xy << " so the lcm is " << lcm << endl;
}

void factorial(int n)
{
	unsigned long long factorial = 1;
	for(int i = 1; i <= n; ++i)
	{
		factorial *= i;
	}
	cout << "Factorial of " << n << " is " << factorial << endl;
}

#include <iostream>
#include <ctime>

using namespace std;

const time_t ctt = time(0);

int main()
{
	char name[20];
	int age, n, num2, digit, rev = 0;
	unsigned int num;
	unsigned long long factorial = 1;
	cout << "Hello world from linux!" << endl;
	cout << "What is your name?: ";
	cin >> name;
	cout << "What is your age?: ";
	cin >> age;
	cout << "What is your favorite number?: ";
	cin >> num;
	cout << "Hello user, your name is " << name << " and your age is " << age << ". " << "The date is " <<  asctime(localtime(&ctt)) << endl;
	cout << "Your favorite number is " << num << ". ";
	
	for(int i = 1; i <= num; ++i)
	{
		factorial *= i;
	}

	cout << "The factorial of your number is " << factorial;
	n = num;
	num2 = num;
	
	do{
		digit = num2 % 10;
		rev = (rev * 10) + digit;
		num2 = num2 / 10;
	} while(num2 != 0);

	cout << ". The reverse of the number is " << rev << " and ";
	if (n == rev)
		cout << "the number is a palindrome. "; 
	else
		cout << "the number is not a palindrome. ";
	bool isPrime = true;
	for(int j = 2; j <= num / 2; ++j)
	{
		if(num % j == 0)
		{
			isPrime = false;
			break;
		}	
	}
	if (isPrime)
	{
		cout << "Also the number is a prime number.";
	}
	else
		cout << "Also the number is not a prime number.";
	cout << endl;
	return 0;
}

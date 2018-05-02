#include "student.h"

Student::Student()
{
	strcpy(firstName, " ");
	strcpy(lastName, " ");
	gpa = 0.0;
}

Student::Student(char first[], char last[], float g)
{
	strcpy(firstName, first);
	strcpy(lastName, last);
	gpa = g;
}

void Student::print()
{
	cout << "======Student======" << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "GPA : " << fixed << setprecision(1) << gpa <<  endl;
}

void Student::setFirstName(char first[])
{
	strcpy(firstName, first);
}

void Student::setLastName(char last[])
{
	strcpy(lastName, last);
}

void Student::setGpa(float g) 
{
	if (g <= 4.0 && g >= 0.0)
	{
		gpa = g;
	}
	else
	{
		cout << "Invalid GPA. Needs to be between 0.0 and 4.0." << endl;
	}
}

float Student::getGpa()
{
	cout << gpa << endl;
	return gpa;
}

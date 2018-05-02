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
	cout << "GPA : " << fixed << setprecision(1) << gpa << endl;
}

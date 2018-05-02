#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student {

public:
	Student();
	Student(char first[], char last[], float g);
	void setFirstName(char first[]);
	void setLastName(char last[]);
	void setGpa(float g);
	float getGpa();
	void print();

private:
	char lastName[200];
	char firstName[200];
	float gpa;
};

#endif


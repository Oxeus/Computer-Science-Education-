#include "student.h"

int main()
{
	Student** list;
	int size;
	char first[200], last[200];
	float gpa = 0.0;
	cout << "==========================================" << endl << "Number of students: ";
	cin >> size;
	list = new Student*[size];
	for (int i = 0; i < size; i++)
	{
		cin.ignore(200, '\n');
		cout << "student " << i << " first name: ";
		cin.get(first, 200, '\n');
		cin.ignore(200, '\n');
		cout << "student " << i << " last name: ";
		cin.get(last, 200, '\n');
		cout << "student " << i << " gpa: ";
		cin >> gpa;
		list[i] = new Student(first, last, gpa);
	}
	cout << endl << "*** Printing List of Students ***" << endl;
	for (int i = 0; i < size; i++)
	{
		list[i]->print();
	}
	for (int i = 0; i < size; i++)
	{
		delete list[i];
	}
	cout << endl << "*** Deleting Student Objects ***" << endl;
	delete [] list;
	cout << endl << endl << endl << "----------" << endl;
	return 0;
}

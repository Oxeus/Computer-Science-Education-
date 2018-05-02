#include "booklist.h"

using namespace std;

int main()
{
	BookList list;
	list.readinFile();
	bool condition = true;
	int choice = 0;
	cout << endl << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	while (condition)
	{
		cout << "---------------------------- Menu -------------------------------" << endl;
		cout << "1 - Print all books." << endl <<
			"2 - Markup or Markdown all prices." << endl <<
			"3 - Change inventory count of a title." << endl <<
			"4 - Quit" << endl <<
			"-----------------------------------------------------------------" << endl <<
			"Enter choice: " << endl;
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			list.printAll();
			break;
		case 2:
			list.markPrice();
			break;
		case 3:
			list.changeInv();
			break;
		case 4:
			condition = false;
			list.writetoFile();
			cout << "-> Inventory Written Out <-" << endl;
			break;
		default:
			cout << "That is not a valid choice. " << endl;
			break;
		}
	}
	cout << endl << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	return 0;
}

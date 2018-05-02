#include "booklist.h"

using namespace std;

BookList list;

void addBook();

int main()
{
	list.readinFile();
	bool condition = true;
	int choice = 0;
	cout << endl << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	while (condition)
	{
		cout << "---------------------------- Menu -------------------------------" << endl <<
			"1 - Print all books" << endl <<
			"2 - Markup or Markdown all prices" << endl <<
			"3 - Change inventory count of a title" << endl <<
			"4 - Add a Book" << endl <<
			"5 - Delete a Book" << endl <<
			"6 - Quit" << endl <<
			"-----------------------------------------------------------------" << endl <<
			"Enter choice: " << endl;
		cin >> choice;
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
			addBook();
			break;
		case 5:
			list.delBook();
			break;
		case 6:
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
	system("pause");
	return 0;
}

void addBook()
{
	char bookName[TOTAL];
	double price;
	int inventory;
	cout << "Enter title: ";
	cin.ignore(200, '\n');
	cin.get(bookName, 200, '\n');
	cout << "Enter count: ";
	cin >> inventory;
	cout << "Enter price: ";
	cin >> price;
	list.addBook(bookName, price, inventory);
}

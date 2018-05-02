#include "booklist.h"

void BookList::readinFile()
{
	char bookName[TOTAL];
	double price;
	int inventory;
	ifstream inFile;
	inFile.open("inventory.txt");
	inFile >> bookCount;
	if (inFile)
	{
		for (int i = 0; i <= bookCount; i++)
		{
			inFile.ignore(200, '\n');
			inFile.get(bookName, 200, '\n');
			inFile >> price;
			inFile >> inventory;
			booklist[i] = new Book(bookName, price, inventory);
		}
		inFile.close();
	}
	else
	{
		cout << "The file does not exist, loading program with 0 tasks." << endl;
	}
}

void BookList::printAll()
{
	cout << "There are " << bookCount << " books." << endl;
	for (int i = 0; i < bookCount; i++)
	{
		booklist[i]->print();
	}
}

void BookList::markPrice()
{
	int choice;
	double price, percent;
	cout << "Is this a: " << endl <<
		"1 - Markup In Price" << endl <<
		"2 - Markdown In Price" << endl <<
		"Enter Choice: ";
	cin >> choice;
	if (choice == 1)
	{
		cout << "Enter percentage to markup: ";
		cin >> percent;
		if (percent >= 1 && percent <= 100)
		{
			percent = percent * 0.01;
			for (int i = 0; i < bookCount; i++)
			{
				price = booklist[i]->getprice();
				price = price * (1 + percent);
				booklist[i]->setprice(price);
			}
		}
		else
		{
			cout << "That is not a valid percent value." << endl;
		}
	}
	else if (choice == 2)
	{
		cout << "Enter percentage to markup: ";
		cin >> percent;
		if (percent >= 1 && percent <= 100)
		{
			percent = percent * 0.01;
			for (int i = 0; i < bookCount; i++)
			{
				price = booklist[i]->getprice();
				price = price * (1 - percent);
				booklist[i]->setprice(price);
			}
		}
		else
		{
			cout << "That is not a valid percent value." << endl;
		}
	}
	
}

void BookList::changeInv()
{
	char bookName[TOTAL];
	int inventory;
	cin.ignore();
	cout << "Enter title to change: ";
	cin.getline(bookName, 200, '\n');
	for (int i = 0; i < bookCount; i++)
	{
		if (strcmp(bookName, booklist[i]->getbookName()) == 0)
		{
			cout << "Enter new inventory count: ";
			cin >> inventory;
			if (inventory > 0)
			{
				booklist[i]->setinventory(inventory);
			}
			else
			{
				cout << "That is not a valid count value." << endl;
			}
		}
	}
}

void BookList::writetoFile()
{
	ofstream outFile;
	outFile.open("inventory.txt");
	outFile << bookCount << endl;
	for (int i = 0; i < bookCount; i++)
	{
		outFile << booklist[i]->getbookName() << endl;
		outFile << booklist[i]->getprice() << endl;
		outFile << booklist[i]->getinventory() << endl;
	}
	outFile.close();
}

BookList::~BookList()
{
	for (int i = 0; i < bookCount; i++)
	{
		delete booklist[i];
	}	
	delete[] booklist;
}

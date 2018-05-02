#include "booklist.h"

BookList::BookList()
{
	head = nullptr;
}

BookList::~BookList()
{
	if(!head)
	{
		return; 
	}

	Node *curr = head;
	while (head)
	{
		curr = head;
		head = curr->next;
		delete curr->data;
		delete curr;
	}
}

void BookList::readinFile()
{

	char bookName[TOTAL];
	double price;
	int inventory;
	ifstream inFile;
	inFile.open("inventory.txt");
	if (inFile)
	{
		while (!inFile.eof())
		{
			inFile.getline(bookName, 200, '\n');
			inFile >> price;
			inFile >> inventory;
			inFile.ignore(200, '\n');
			inFile >> ws;
			addBook(bookName, price, inventory);
		}
	}
	else
	{
		cout << "The file does not exist, loading program with 0 tasks." << endl;
	}
}

void BookList::addBook(const char *bookName, double price, int inventory)
{
	Book *b = new Book(bookName, price, inventory);
	Node *new_ptr = new Node;
	new_ptr->data = b;
	new_ptr->next = nullptr;
	if (!head)
	{
		head = new_ptr;
	}
	else
	{
		const char *thisLast = head->data->getbookName();
		if (strcmp(thisLast, bookName) > 0)
		{
			new_ptr->next = head;
			head = new_ptr;
			return;
		}
		Node *current = head;
		Node *previous = nullptr;
		while (current)
		{
			thisLast = current->data->getbookName();
			if (strcmp(thisLast, bookName) > 0)
			{
				previous->next = new_ptr;
				new_ptr->next = current;
				return;
			}
			previous = current;
			current = current->next;
		}
		previous->next = new_ptr;
	}
}

void BookList::printAll()
{
	if (!head)
	{
		cout << "No books are in the list." << endl;
		return;
	}
	Node *current = head;
	while (current)
	{
		current->data->print();
		current = current->next;
	}
}

void BookList::delBook()
{
	char bookName[TOTAL];
	cout << "Enter title: ";
	cin.ignore(200, '\n');
	cin.get(bookName, 200, '\n');
	if (!head)
	{
		cout << "list is empty!" << endl;
		return;
	}
	const char* thisLast = head->data->getbookName();
	if (strcmp(thisLast, bookName) == 0)
	{
		Node *current = head;
		head = head->next; 
		delete current->data;
		delete current;
		return;    	
	}

	Node *current = head->next;
	Node *previous = head;
	while (current)
	{
		thisLast = current->data->getbookName();
		if (strcmp(thisLast, bookName) == 0)
		{
			previous->next = current->next;
			delete current->data;
			delete current;
			return;
		}

		previous = current;
		current = current->next;
	}
	cout << "no name found." << endl;
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
			if (!head)
			{
				cout << "No books are in the list." << endl;
				return;
			}
			Node *current = head;
			while (current)
			{
				price = current->data->getprice();
				price = price * (1 + percent);
				current->data->setprice(price);
				current = current->next;
			}
		}
		else
		{
			cout << "That is not a valid percent value." << endl;
		}
	}
	else if (choice == 2)
	{
		cout << "Enter percentage to markdown: ";
		cin >> percent;
		if (percent >= 1 && percent <= 100)
		{
			percent = percent * 0.01;
			if (!head)
			{
				cout << "No books are in the list." << endl;
				return;
			}
			Node *current = head;
			while (current)
			{
				price = current->data->getprice();
				price = price * (1 - percent);
				current->data->setprice(price);
				current = current->next;
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
	if (!head)
	{
		cout << "No books are in the list." << endl;
		return;
	}
	Node *current = head;
	while (current)
	{
		if (strcmp(bookName, current->data->getbookName()) == 0)
		{
			cout << "Enter new inventory count: ";
			cin >> inventory;
			if (inventory > 0)
			{
				current->data->setinventory(inventory);
			}
			else
			{
				cout << "That is not a valid count value." << endl;
			}
		}
		current = current->next;
	}
}


void BookList::writetoFile()
{
	ofstream outFile;
	outFile.open("inventory.txt");
	if (!head)
	{
		cout << "No books are in the list." << endl;
		return;
	}
	Node *current = head;
	while (current)
	{
		outFile << current->data->getbookName() << endl;
		outFile << current->data->getprice() << endl;
		outFile << current->data->getinventory() << endl;
		current = current->next;
	}
	outFile.close();
}


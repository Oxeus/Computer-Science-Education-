#include <iostream>
#include <cstring>

using namespace std;

struct Node {
	char data[201];
	Node *next;
};

void addtoList(Node *&first, Node *&last);
void printList(Node *first);
void delfromList(Node *&first);

int main()
{
	Node * first = new Node;
	first = NULL;
	Node * last = NULL;
	Node * current;
	int choice;
	bool condition = true;
	cout << "====================================" << endl;
	while (condition)
	{
		cout << "==MENU==" << endl <<
			"1 Add to list" << endl <<
			"2 Print to list" << endl <<
			"3 Delete from list" << endl <<
			"4 Quit" << endl << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: 
			addtoList(first, last);
			break;
		case 2:
			printList(first);
			break;
		case 3:
			delfromList(first);
			break;
		case 4:
			condition = false;
			current = first;
			Node * next;
			while (current != NULL)
			{
				
				next = current->next;
				delete current;
				current = next;
			}
			break;
		default:
			cout << "The input choice is invalid." << endl;
		}
	}
	cout << "====================================" << endl;
	first = NULL;
	delete first;
}

void addtoList(Node *&first, Node *&last)
{
	Node *newNode = new Node;
	char input[200];
	cout << "Enter Data: ";
	cin.ignore();
	cin.get(input, 200);
	strcpy(newNode->data, input);
	if (first == NULL && last == NULL)
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}
	newNode->next = NULL;
	newNode = NULL;
	delete newNode;
}

void printList(Node *first)
{
	Node *current;
	current = first;

	cout << endl;
	while (current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
	delete current;
}

void delfromList(Node *&first)
{
	Node *current;
	current = first;
	Node * prev;
	char temp[200];
	cout << endl << "Please enter item to delete: ";
	cin.ignore();
	cin.get(temp, 200);
	while (current != NULL)
	{
		if (strcmp(current->data, temp) != 0)
		{
			prev = current;
			current = current->next;
		}
		else
		{
			prev->next = current->next;
			delete current;
			break;
		}
	}
}




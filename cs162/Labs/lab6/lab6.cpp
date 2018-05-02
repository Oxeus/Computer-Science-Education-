#include <iostream>
#include <cstring>

using namespace std;

struct Node {
	char data[201];
	Node *next;
};

void addtoList(Node *&first, Node *&last, char in[]);
void printList(Node *first);

int main()
{
	Node * first = NULL;
	Node * last = NULL;

	char input[200];
	bool condition = true;
	cout << "====================================" << endl;
	while (condition)
	{
		cout << "Enter Data: ";
		cin.get(input, 200);
		cin.ignore();
		if (strcmp(input, "quit") == 0)
		{
			condition = false;
			printList(first);
		}
		else
		{
			addtoList(first, last, input);
		}
	}
	cout << "====================================" << endl;
	return 0;
}

void addtoList(Node *&first, Node *&last, char in[])
{
	Node *newNode = new Node;
	strcpy(newNode->data, in);
	newNode->next = NULL;
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
}



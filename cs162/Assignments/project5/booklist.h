#include "book.h"

#ifndef BOOKLIST_H
#define BOOKLIST_H

struct Node
{
	Book *data;
	Node *next;
};

class BookList
{
public:
	BookList();
	~BookList();

	void readinFile();
	void addBook(const char *bookName, double price, int inventory);
	void printAll();
	void delBook();
	void markPrice();
	void changeInv();
	void writetoFile();

private:
	Node *head;
};

#endif

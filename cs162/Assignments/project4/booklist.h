#include "book.h"

class BookList
{
public:
	void readinFile();
	void printAll();
	void markPrice();
	void changeInv();
	void writetoFile();

	~BookList();

private:
	int bookCount;
	Book ** booklist = new Book*[bookCount];
};

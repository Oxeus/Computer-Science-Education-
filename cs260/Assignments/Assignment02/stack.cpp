#include "stack.h"

stack::stack()
{
	top = nullptr;
}

stack::stack(int count)
{
	int max = count;
}

stack::~stack()
{
	stackElement * curr = top;
	stackElement * temp;
	while (curr)
	{
		temp = curr;
		curr = curr->prev;
		delete temp;
	}
	top = nullptr;
}

void stack::push(int newx, int newy)
{
	stackElement *newTop = new stackElement;
	newTop->x = newx;
	newTop->y = newy;
	if (top == nullptr)
	{
		newTop->prev = nullptr;
		top = newTop;
	}
	else
	{
		newTop->prev = top;
		top = newTop;
	}
}

void stack::pop()
{
	if (!isEmpty())
	{
		if (top == nullptr)
		{
			delete top;
		}
		else
		{
			stackElement *p = top;
			top = top->prev;
			delete p;
		}
	}
}

int stack::topX()
{
	int s = top->x;
	return s;
}

int stack::topY()
{
	int s = top->y;
	return s;
}

bool stack::isEmpty()
{
	if (top == nullptr)
		return true;
	else
		return false;
}
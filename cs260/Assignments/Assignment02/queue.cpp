#include <iostream>
#include "queue.h"

using namespace std;

queue::queue() : front(nullptr), rear(nullptr)
{
	//Nothing else to initialize, front and rear already initialized above;
}

queue::~queue()
{
	while (!isEmpty())
	{
		int del = dequeue();
	}
}

bool queue::isEmpty()
{
	return (front == nullptr);
}

void queue::enqueue(int newNum)
{
	node * temp = new node;
	temp->num = newNum;
	temp->next = nullptr;
	if (front == nullptr)
	{
		front = rear = temp;
		rear->next = nullptr;
	}
	else
	{
		rear->next = temp;
		rear = temp;
		rear->next = nullptr;
	}
}

int queue::dequeue()
{
	int data = 0;
	if (!isEmpty())
	{
		node * temp = front;
		data = temp->num;
		front = temp->next;
		delete temp;
	}
	return data;
}
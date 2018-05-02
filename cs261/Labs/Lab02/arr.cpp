#include "arr.h"

#include <iostream>

using namespace std;

int sum(node * head[])
{
	int total = 0;
	node * curr = nullptr;
	for(int i = 0; i < SIZE; i++)
	{
		curr = head[i];
		while(curr)
		{
			total = total + curr->data;
			curr = curr->next;
		}
	}
	return total;
}

int removeTwo(node * head[])
{
	node * curr;
	node * prev;
	node * temp;
	for(int i = 0; i < SIZE; i++)
	{
		curr = nullptr;
		prev = nullptr;
		temp = nullptr;
		curr = head[i];
		while(curr)
		{
			temp = curr->next;	
			if(curr->data == 2)
			{
				if(prev)
				{
					prev->next = curr->next;
				}
				else
				{
					head[i] = curr->next;
				}
				delete curr;
			}
			else
			{
				prev = curr;
			}
			curr = temp;
		}
	}
	return 0;
}


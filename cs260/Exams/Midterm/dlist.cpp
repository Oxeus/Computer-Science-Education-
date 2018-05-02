#include "dlist.h"
#include <iostream>

int countEven(node * curr, int count)
{
	if(curr == nullptr)
	{
		return count;
	}
	else if((curr->data) % 2 == 0)
	{
		count++;
		countEven(curr->next, count);
	}
	else
	{
		countEven(curr->next, count);
	}
}


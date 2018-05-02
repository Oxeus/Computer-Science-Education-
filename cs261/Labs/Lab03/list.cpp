#include "list.h"

void duplicate(node * head, node *& newHead)
{
	if(head != nullptr)
	{
		newHead->data = head->data;
		newHead->next = head->next;
		duplicate(head->next, newHead->next);
	}
}

int removeTwo(node *& head)
{
	if(head->data == 2)
	{

	}
	else if(head != nullptr)
	{
		removeTwo(head->next);		
	}
}



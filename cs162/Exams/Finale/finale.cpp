/*INSTRUCTIONS
 * =========================
 * 
 *  Write two functions between the comments
 *  indicated below.
 * 
   The first function will take two referenced
 *  pointers to a Node (this is the head and tail
 * of the list respectively),
 * an array of numbers and the size of the array. 
 * It will then build a linked list from these numbers
 * using any method (backward, forward or sorted).
 * NOTE:  if your method of building the list doesn't
 * need the tail pointer you can ignore it in your
 * functions but the both functions still need to
 * take it in as a parameter.
 * 
 *    The second function will take the head and tail of
 * the list.  It will find the first set of two adjacent numbers that
 * are the same (adjacent duplicates) and delete one of them
 * from the list (either one will work).
 *  If there are no adjacent duplicates in the list, it will do nothing.
 * 
 * PLEASE SEE MAIN FUNCTION BELOW FOR NAMES OF 
 * FUNCTIONS AND WHAT ORDER THE PARAMETERS ARE IN
 * REMEMBER YOUR CODE NEEDS TO MATCH THESE CALLS.
 * 
 * NOTES
 * ===================================
 * You can change this file all you want during
 * the exam but keep in mind that I will ONLY BE
 * USING YOUR FUNCTIONS by copying them to another
 * main.cpp file.
 * 
 * Do not code to the given data. I will be using 
 * different values in my grading source code file.
 * 
 * Do not use global variables/constants
 * or goto's in your code. head and tail pointers
 * will be provided inside main function
 * and passed in as parameters to your functions.
 * 
 *  You can make more than two functions
 *  but keep all functions between the
 *  given comment lines below.
 * 
 * Do not remove the comment lines as my
 * grading script will not be able to 
 * copy your functions over to my
 * grading source file.
 * 
 * Don't ask the user for information.  The main
 * function will get all information needed and pass it
 * into your function.  See main function for
 * how your function will be called.
 * 
 *
 * two example runs are below:

BEFORE
-----------
2
2
7
3
1
1
6
----------------
AFTER
-----------
2
7
3
1
1
6
----------------


BEFORE
-----------
2
7
3
1
6
----------------
AFTER
-----------
2
7
3
1
6
----------------


 */
#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    int data;
    Node *next;
};

// PLEASE PUT YOUR FUNCTIONS BELOW THIS LINE.
// DO NOT REMOVE THE COMMENT LINE ABOVE
void buildList(Node * &head, Node * &tail, int array[], int count)
{
	for (int i = 0; i < count; i++)
	{
		Node * temp = new Node;
		temp->data = array[i];
		temp->next = head;
		head = temp;
	}
}

void removeDup(Node *head, Node *tail)
{	
	int num = 0;
	Node* current = head;
	Node* prev = NULL;
	while(current != NULL)
	{
		if(current->data == num)
		{	
			current->data = 0;
			prev->next = current->next;
			delete current;
			break;
		}
		prev = current;
		current = current->next;
		num = prev->data;
	}
}
//  END OF FUNCTIONS - DO NOT REMOVE THIS COMMENT LINE.

void printList(Node* head)
{
   cout << "-----------" << endl;
   Node* current = head;
   while(current) 
   {
      cout << current->data << endl;
      current = current->next;
   }
   cout << "----------------" << endl;	
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int array[200] = {6, 1, 1, 3, 7, 2, 2};
	int count = 7;
    
    // this how the first function
    // will be called
    buildList(head, tail, array, count);
    
    cout << "BEFORE" << endl;
    printList(head); 
    
    // this how the second function will
    // be called.
	removeDup(head, tail);
    
	cout << "AFTER" << endl;
    printList(head); 
    
    return 0;
}


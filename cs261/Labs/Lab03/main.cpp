#include "list.h"
using namespace std;

int main()
{
    	node * head = NULL;
    	build(head);
    	display(head);

    	//PLEASE PUT YOUR CODE HERE to call the function assigned
	duplicate(head, head);
	cout << "duplicate copy of the list: " << endl;
    	display(head);
	removeTwo(head);
	cout << "After removing all 2: " << endl;
	display(head);
    	destroy(head);
    
    	return 0;
}

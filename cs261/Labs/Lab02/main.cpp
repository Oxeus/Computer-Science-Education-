#include "arr.h"
#include <iostream>
using namespace std;

int main()
{
    	node * head[SIZE] = {0,0,0,0,0};
    	build(head);
    	display(head);

    	//PLEASE PUT YOUR CODE HERE to call the function assigned
	int sumall = sum(head);
	cout << endl;
	cout << "The sum of all the integers: " << sumall << endl;
	cout << endl;
	removeTwo(head);
	cout << "After removing all 2: ";
    	display(head);
    	destroy(head);
    
    	return 0;
}

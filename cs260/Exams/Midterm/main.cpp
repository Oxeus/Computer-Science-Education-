#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int even = countEven(head, 0);
    cout << endl << "This list contains " << even << " even number of items"  << endl;

    //int evenRemoved = removeEven(head, 0);
    //cout << endl << "The number of items removed from the list was: " << evenRemoved << endl;

    display(head);
    destroy(head);    
    return 0;
}

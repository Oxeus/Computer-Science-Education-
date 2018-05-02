#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    
    int sum = sumOfNodes(root);
    cout << "The sum of all the data in the nodes is: " << sum << endl;
    //copyLeaf(root, root);
    display(root);
    destroy(root);
    return 0;
}

/* Midterm proctor exam version E
 * 
 * NSTRUCTIONS:  Write a function in the space 
 * indicated below that will take an array and
 * an index. It will then remove the element 
 * at this index.  Note that it should also move elements
 * to fill in where the removed element was located 
 * (see examples below). Assume the index is valid
 * and less than the size of the array. 
 * 
 * You can change this file all you want during
 * the exam but keep in mind that I will ONLY BE
 * USING YOUR FUNCTION by copying it to another
 * main.cpp file (with different variable values)
 * for grading. So don't code to the given data values.
 * 
 * Do not use global variables/constants
 * or goto's in your code.  Please only make one
 * function (there's really no need for more than one).
 * 
 * Don't ask the user for information.  The main
 * function will get all information needed and pass it
 * into your function (see main function for
 * how your function will be called).
 * 
 * 
 * two example runs are below:
 -----------
3
8
1
9
10
3
----------------
index to remove?2
-----------
3
8
9
10
3
----------------

-----------
8
4
2
5
3
1
9
----------------
index to remove?3
-----------
8
4
2
3
1
9
----------------


 * 
 */

#include <iostream>
#include <cstring>

using namespace std;

// PLEASE PUT YOUR FUNCTION BELOW THIS LINE
void remove(int idx, int array[], int& count)
{	
	array[idx] = 0;
	for(int i = idx; i < count; i++)
	{
		array[i] = array[i + 1];
	}
	count--;
}

//  END OF FUNCTION

void printArray(int array[], int count)
{
   cout << "-----------" << endl;
   for(int i=0; i < count; i++)
   {
	   cout << array[i] << endl;
   }
   cout << "----------------" << endl;	
}


int main()
{
    int array[200] = {8,4,2,5,3,1,9};
	int count = 7;
	int idx;
	
	printArray(array, count);
	           
	cout << "index to remove?";
	cin >> idx;
	
    remove(idx, array, count);
	
	printArray(array, count);
	
	return 0;
}

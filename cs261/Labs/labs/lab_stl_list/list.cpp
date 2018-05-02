#include <iostream>
// include the correct include file

using namespace std;

int main()
{
    // list declaration goes here
    
    int prev = 0;
    int curr = 1;
    while (curr < 1000) {

	// add the value to the list here
	
	int newfib = curr + prev;
	prev = curr;
	curr = newfib;
    }

    // add code to iterate through the list and print all values here
}



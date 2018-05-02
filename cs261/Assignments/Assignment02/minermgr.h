#include <iostream>
#include <queue>

using namespace std;

class minermgr 
{
public:
	void addMiner(int minerNum, const string resource);
	void runMiners();
private:
	int temp;
};

#include <string>
#pragma once
using namespace std;

class entry {
public:
	entry();
	entry(int nyear, int nmonth, int nday, string nstation, string nresource, int namount);
	int year;
	int month;
	int day;
	string station;
	string resource;
	int amount;
};
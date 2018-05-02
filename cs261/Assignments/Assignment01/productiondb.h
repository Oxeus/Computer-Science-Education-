#pragma once
#include "entry.h"
#include <map>
#include <vector>
#include <algorithm>

class resourcecount {
public:
	void addData(string nresource, int namount);
	vector<string> getRecourses();
	int getAmount(string nresource);
private:
	map <string, int> resource;
};

class yeardata
{
public:
	void addData(int nmonth, string nresource, int namount);
	vector<string> getRecourses();
	int getAmount(int month, string resource);
	int getTotal(string resource);
private:
	resourcecount marray[12];
};

class stationdata {
public:
	void addData(int nyear, int nmonth, string nresource, int namount);
	vector<string> getRecourses(int year);
	int getAmount(int year, int month, string resource);
	int getTotal(int year, string resource);
private:
	map <int, yeardata> years;
};

class productiondb {
public:
	void addData(entry &newEnt);
	void addtoVec(string resource);
	vector<string> getStations();
	vector<string> getRecourses(int year, string station);
	vector<string> getRec();
	int getAmount(string station, int year, int month, string resource);
	int getTotal(string station, int year, string resource);
private:
	map <string, stationdata> stat;
	vector<string> resData;
};
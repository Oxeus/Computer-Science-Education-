#include "productiondb.h"

using namespace std;

//AddData
void resourcecount::addData(string nresource, int namount)
{
	map<string, int>::iterator it = resource.find(nresource);
	if (it != resource.end())
	{
		it->second = it->second + namount;
	}
	else
	{
		resource.insert(pair<string, int>(nresource, namount));
	}
}

void yeardata::addData(int nmonth, string nresource, int namount)
{
	if (nmonth < 13 && nmonth > 0)
	{
		marray[nmonth - 1].addData(nresource, namount);
	}
}

void stationdata::addData(int nyear, int nmonth, string nresource, int namount)
{
	yeardata year;
	map<int, yeardata>::iterator it = years.find(nyear);
	if (it != years.end())
	{
		it->second.addData(nmonth, nresource, namount);
	}
	else
	{
		year.addData(nmonth, nresource, namount);
		years.insert(pair<int, yeardata>(nyear, year));
	}
}

void productiondb::addtoVec(string resource)
{
	vector<string>::iterator it = find(resData.begin(), resData.end(), resource);
	if (it == resData.end())
	{
		resData.push_back(resource);
		sort(resData.begin(), resData.end());
	}
}

void productiondb::addData(entry &newEnt)
{
	addtoVec(newEnt.resource);
	stationdata station;
	map<string, stationdata>::iterator it = stat.find(newEnt.station);
	if (it != stat.end())
	{
		it->second.addData(newEnt.year, newEnt.month, newEnt.resource, newEnt.amount);
	}
	else
	{
		station.addData(newEnt.year, newEnt.month, newEnt.resource, newEnt.amount);
		stat.insert(pair<string, stationdata>(newEnt.station, station));
	}
	resData.erase(unique(resData.begin(), resData.end()), resData.end());
}

//Getters

vector<string> productiondb::getRec()
{
	return resData;
}

vector<string> productiondb::getStations()
{
	vector<string> ret;
	for (auto elem : stat)
		ret.push_back(elem.first);
	return ret;
}

vector<string> resourcecount::getRecourses()
{
	vector<string> ret;
	for (auto elem : resource)
		ret.push_back(elem.first);
	return ret;
}

vector<string> yeardata::getRecourses()
{
	vector<string> ret;
	vector<string> retmerge;
	for (int i = 0; i < 12; i++)
	{
		retmerge = marray[i].getRecourses();
		ret.insert(ret.end(), retmerge.begin(), retmerge.end());
		sort(ret.begin(), ret.end());
	}
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	return ret;
}

vector<string> stationdata::getRecourses(int year)
{
	vector<string> ret;
	map<int, yeardata>::iterator it = years.find(year);
	if (it != years.end())
	{
		ret = it->second.getRecourses();
	}
	return ret;
}

vector<string> productiondb::getRecourses(int year, string station)
{
	vector<string> ret;
	map<string, stationdata>::iterator it = stat.find(station);
	if (it != stat.end())
	{
		ret = it->second.getRecourses(year);
	}
	return ret;
}

int resourcecount::getAmount(string nresource)
{
	int ret;
	map<string, int>::iterator it = resource.find(nresource);
	if (it != resource.end())
	{
		ret = it->second;
	}
	else
	{
		ret = 0;
	}
	return ret;
}

int yeardata::getAmount(int month, string resource)
{
	int ret = marray[month].getAmount(resource);
	return ret;
}

int stationdata::getAmount(int year, int month, string resource)
{
	int ret;
	map<int, yeardata>::iterator it = years.find(year);
	if (it != years.end())
	{
		ret = it->second.getAmount(month, resource);
	}
	return ret;
}

int productiondb::getAmount(string station, int year, int month, string resource)
{
	int ret;
	map<string, stationdata>::iterator it = stat.find(station);
	if (it != stat.end())
	{
		ret = it->second.getAmount(year, month, resource);
	}
	return ret;
}

int yeardata::getTotal(string resource) 
{
	int ret = 0;
	for (int i = 0; i < 12; i++)
	{
		ret = ret + marray[i].getAmount(resource);
	}
	return ret;
}

int stationdata::getTotal(int year, string resource)
{
	int ret;
	map<int, yeardata>::iterator it = years.find(year);
	if (it != years.end())
	{
		ret = it->second.getTotal(resource);
	}
	return ret;
}

int productiondb::getTotal(string station, int year, string resource)
{
	int ret;
	map<string, stationdata>::iterator it = stat.find(station);
	if (it != stat.end())
	{
		ret = it->second.getTotal(year, resource);
	}
	return ret;
}


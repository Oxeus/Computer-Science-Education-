#pragma once
#include "productiondb.h"
#include "iostream"

class reporter {
public:
	reporter(productiondb &db);
	void printFullReport(int nyear);
	void printStationReport(int nyear);
private:
	productiondb data;
};
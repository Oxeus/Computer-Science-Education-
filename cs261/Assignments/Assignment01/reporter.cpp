#include "reporter.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

reporter::reporter(productiondb &db) 
{
	data = db;
}

void reporter::printFullReport(int nyear)
{
	vector<string> pri = data.getStations();
	vector<string> priRec;
	cout << "*******" << nyear << "*******" << endl;
	for (int i = 0; i < pri.size(); i++)
	{
		cout << endl;
		cout << "Station: " << pri[i] << endl;
		cout << endl;
		cout << setw(11) << " " << right << setw(8) << "Jan" << setw(8) << "Feb" << setw(8) << "Mar" << setw(8) << "Apr" << setw(8) << "May" << setw(8) << "Jun" << setw(8) << 
			"Jul" << setw(8) << "Aug" << setw(8) << "Sep" << setw(8) << "Oct" << setw(8) << "Nov" << setw(8) << "Dec" << setw(8) << "Tot" << endl;
		priRec = data.getRecourses(nyear, pri[i]);
		for (int j = 0; j < priRec.size(); j++)
		{
			cout << setw(11) << left << priRec[j];
			for (int k = 0; k < 12; k++)
			{
				cout << right << setw(8) << data.getAmount(pri[i], nyear, k, priRec[j]);
			}
			cout << right << setw(8) << data.getTotal(pri[i], nyear, priRec[j]) << endl;
		}
		cout << endl;
	}
}

void reporter::printStationReport(int nyear)
{
	vector<string> pri = data.getStations();
	vector<string> priRec = data.getRec();
	vector<int> total;
	cout << "*******" << nyear << "*******" << endl;
	cout << setw(11) << " " << left;
	for (int k = 0; k < pri.size(); k++)
	{
		cout << setw(11) << right << pri[k];
	}
	cout << endl;
	for (int l = 0; l < priRec.size(); l++)
	{
		cout << left << setw(11) << priRec[l];
		for (int m = 0; m < pri.size(); m++)
		{
			cout << setw(11) << right << data.getTotal(pri[m], nyear, priRec[l]);
		}
		cout << endl;
	}
	for (int n = 0; n < pri.size(); n++)
	{
		total.push_back(data.getTotal(pri[n], nyear, priRec[0]));
	}
	cout << setw(11) << "Total";
	for (int o = 0; o < pri.size(); o++)
	{
		for (int p = 1; p < priRec.size(); p++)
		{
			total[o] = total[o] + data.getTotal(pri[o], nyear, priRec[p]);
		}
		cout << setw(11) << total[o];
	}
	cout << endl;
	cout << endl;
}

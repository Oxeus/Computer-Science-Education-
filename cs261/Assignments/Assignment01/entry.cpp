#include "entry.h"

entry::entry()
{

}

entry::entry(int nyear, int nmonth, int nday, string nstation, string nresource, int namount)
{
	year = nyear;
	month = nmonth;
	day = nday;
	station = nstation;
	resource = nresource;
	amount = namount;
}
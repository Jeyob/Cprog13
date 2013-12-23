#include "gregorian.h"
#include <stdio.h>

using namespace lab2;

double julian_to_jd(int year, int month, int day){
	int _month = month, _year = year;

	if(month<=2)
	{
		_month = month + 12;
		_year = year - 1;
	}

	return (floor(365.25*(_year+4716))+floor(30.6001*(_month+1)) + day-1524.5);

}


int main(void) {

	Gregorian d(1992,2,29);
	printf("%6.1f\n",julian_to_jd(1992,2,29));
	cout<<julian_to_jd(1992,2,29)<<" = 2448694.5"<<endl;
	cout<<d.add_month(29)<<endl;
	cout<<d.add_month(0)<<endl;
	cout<<d.add_month(41)<<endl;
	cout<<d.add_month(0)<<endl;
	cout<<d.add_month(-19)<<endl;
return 0;
}


//gregorian 1992 2 29 @4
//add_month 29
//add_month 0
//print 0
//add_month 41
//add_month 0
//print 0
//add_month -19

//

//((val-day())+day());

//gregorian 1992 2 29 @4
// add_year 4
// add_year 0
// print 0
// add_year -5
// add_year 0
// print 0
// add_year 17
// add_year 0
// print 0
// add_year -17

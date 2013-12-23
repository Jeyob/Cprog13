/*
 * julian.cpp
 *
 *  Created on: 10 nov 2011
 *      Author: his-royalhighness
 */


#include <math.h>

namespace lab2{




bool leap_julian(int year){

	return ((year % 4) == 0 ? true:false);
}


double julian_to_jd(int year, int month, int day){
	int _month = month, _year = year;

	if(month<=2)
	{
		_month = month + 12;
		_year = year - 1;
	}

	return (floor(365.25*(_year+4716))+floor(30.6001*(_month+1)) + day-1524.5);
}


//
//function jd_to_julian(td) {
//    var z, a, alpha, b, c, d, e, year, month, day;
//
//    td += 0.5;
//    z = Math.floor(td);
//
//    a = z;
//    b = a + 1524;
//    c = Math.floor((b - 122.1) / 365.25);
//    d = Math.floor(365.25 * c);
//    e = Math.floor((b - d) / 30.6001);
//
//    month = Math.floor((e < 14) ? (e - 1) : (e - 13));
//    year = Math.floor((month > 2) ? (c - 4716) : (c - 4715));
//    day = b - d - Math.floor(30.6001 * e);
//
//    /*  If year is less than 1, subtract one to convert from
//        a zero based date system to the common era system in
//        which the year -1 (1 B.C.E) is followed by year 1 (1 C.E.).  */
//
//    if (year < 1) {
//        year--;
//    }
//
//    return new Array(year, month, day);
//}
//

}




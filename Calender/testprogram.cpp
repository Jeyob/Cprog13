#include <iostream>
#include "gregorian.h"
#include "julian.h"
#include "kattistime.h"
#include <time.h>

using namespace lab2;

double getJulianFromUnix( int unixSecs )
{
   return ( unixSecs / 86400.0 ); //+ 2440587.5;
}

int main() {
	
	time_t timer = 2105524137;

//	time(&timer);

//	std::cout <<std::fixed;
//	std::cout<<getJulianFromUnix(2005840054)<<std::endl;

	set_k_time(timer);

//	Julian j(1982,9,20);
	Julian j;
	j++;
	j++;
	j.add_year(8);
//	std::cout<<(int)(2456675.5+1.5) % 7<<std::endl;
	std::cout<<j<<std::endl;
	std::cout<<j.week_day()<<" "<<j.week_day_name()<<std::endl;

	return 0;
}

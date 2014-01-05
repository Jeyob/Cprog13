#include <iostream>
#include "gregorian.h"
#include "julian.h"
#include "kattistime.h"
#include <time.h>
#include "calendar.h"

using namespace std;
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

	Julian j;
	cout<<j<<endl;
	sEventColl<Julian> e(j, "hej");

	bool res = e.addEvent("godnatt");
	cout<<res<<endl;
	res = e.addEvent("godnatt");
	cout<<res<<endl;
	cout<<e<<endl;
	res = e.removeEvent("godnatt");
	cout<<res<<endl;
	cout<<e<<endl;
	res = e.removeEvent("hej");
	cout<<res<<endl;
	cout<<e<<endl;

	res = e.removeEvent("mamma");
	cout<<res<<endl;
	cout<<e<<endl;


	std::cout << "----------------------------------------" << std::endl;
	Calendar<Gregorian> cal;
	cal.set_date(2000, 12, 2);
	cal.add_event("Basketträning", 4, 12, 2000);
	cal.add_event("Basketträning", 11, 12, 2000);
	cal.add_event("Nyårsfrukost", 1, 1, 2001);
	cal.add_event("Första advent", 1); // år = 2000, månad = 12
	cal.add_event("Vårdagjämning", 20, 3); // år = 2000
	cal.add_event("Julafton", 24, 12);
	cal.add_event("Kalle Anka hälsar god jul", 24); // också på julafton
	cal.add_event("Julafton", 24); // En likadan händelse samma datum ska
	// ignoreras och inte sättas in i kalendern
	cal.add_event("Min första cykel", 20, 12, 2000);
	cal.remove_event("Basketträning", 4);
	std::cout << cal; // OBS! Vårdagjämning och första advent är
	// före nuvarande datum och skrivs inte ut
	std::cout << "----------------------------------------" << std::endl;
	cal.remove_event("Vårdagjämning", 20, 3, 2000);
	cal.remove_event("Kalle Anka hälsar god jul", 24, 12, 2000);
	cal.set_date(2000, 11, 2);
	if (! cal.remove_event("Julafton", 24)) {
	std::cout << " cal.remove_event(\"Julafton\", 24) tar inte"<< std::endl
	<< " bort något eftersom aktuell månad är november" << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	std::cout << cal;

	Calendar<Julian> jcal = cal;
	std::cout << "------------Copy-------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout<<jcal;
	std::cout << "----------------------------------------" << std::endl;
	return 0;
}

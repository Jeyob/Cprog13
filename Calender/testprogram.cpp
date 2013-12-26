#include <iostream>
#include "gregorian.h"
#include "kattistime.h"
#include <time.h>

int main() {
	
	time_t timer;

	time(&timer);
	
	set_k_time(timer);

	lab2::Gregorian g;

	std::cout<<g.year()<<std::endl;

	return 0;
}
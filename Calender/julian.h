/*
 * julian.h
 *
 *  Created on: 10 nov 2011
 *      Author: his-royalhighness
 */

#ifndef JULIAN_H_
#define JULIAN_H_

/*
 * Julian.h
 *
 *  Created on: Nov 7, 2011
 *      Author: jeyob
 */

#include "gregorian.h"
#include "kattistime.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

class Julian : public Gregorian{

public:
	Julian();

	Julian(int day);

	Julian(int month, int day);

	Julian(int year, int month, int day);

	virtual ~Julian() {

	}

private:

	bool leap_julian(int year){
		return ((year % 4) == 0 ? true:false);
	}

};

#endif /* JULIAN_H_ */

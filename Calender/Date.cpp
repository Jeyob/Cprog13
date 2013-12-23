#include "Date.h"
#include <iostream>

namespace lab2 {
/* utskriftsoperator på format --> yyyy-mm-dd */
ostream& operator<<(ostream & os, const Date & d) {
	os << d.year() << "-" << (d.month() > 9 ? "" : "0") << d.month() << "-"
			<< (d.day() > 9 ? "" : "0") << d.day();

	return os;
}
}

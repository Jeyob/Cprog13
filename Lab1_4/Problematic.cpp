/*
	 * A non-PoD-class to ensure that people do not attempt to move objects around the wrong way.
	 */

#include <cassert>
#include <iostream>	 

namespace Problem {
	class Problematic {
		public:
			explicit Problematic(const int data = 0): id(data), myself(this), data(data) {}
			Problematic(const Problematic &rhs) : myself(this), data(rhs.data) { }
			const Problematic &operator=(const Problematic &rhs) {
				assert(myself == this);
				data = rhs.data;
				return *myself;
			}
			~Problematic() {
				static int number = 0;
				std::cout<<"ID: "<<id<<" Called: "<<number++<<" times"<<std::endl;
				assert(myself == this);
			}
			int get_data() const {
				assert(myself == this);
				return myself->data;
			}
			bool operator<(const Problematic &rhs) const {
				assert(myself == this);
				return (data & 0xF) < (rhs.data & 0xF);
			}

		private:
			friend std::istream &operator>>(std::istream &is, Problematic &pr);
			int id;
			const Problematic *myself;
			int data;
	};

	inline std::ostream &operator<<(std::ostream &os, const Problematic &pr) {
		os << pr.get_data();
		return os;
	}

	inline std::istream &operator>>(std::istream &is, Problematic &pr) {
		assert(&pr == pr.myself);
		is >> pr.data;
		// Silly magic constant
		pr.data += 4711;
		return is;
	
	}
}

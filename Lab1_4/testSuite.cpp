#include <cxxtest/TestSuite.h>
#include "vector.h"
#include "Problematic.cpp"
#include <vector>

class foo {
	public:
		explicit foo(int _data_):data(data) {}
		
	private:
		int data;
		friend std::ostream& operator<<(std::ostream &os, const foo & instance );
};

inline std::ostream& operator<<(std::ostream &os, const foo& instance) {
	os<<instance.data;
	return os;
}

class TemplateTestSuite : public CxxTest::TestSuite
{

public: 

	void testCopying() {

		Vector<Problem::Problematic*> v(0);
		Problem::Problematic * p = new Problem::Problematic(1337);
		Problem::Problematic * pp = new Problem::Problematic(1338);
		Problem::Problematic * ppp = new Problem::Problematic(1339);

		v.push_back( p );
		v.push_back( pp );
		v.push_back( ppp );

		TS_TRACE("Testing copycontrol");
		TS_TRACE(v.showVector());

		Vector<Problem::Problematic*> f(v);
		TS_TRACE(v.size());
		TS_TRACE(f.size());
		TS_ASSERT(v.size() == f.size() && v.size() == 3);

		v.clear();

		TS_TRACE(f.showVector());
		TS_ASSERT(v.size() == 0 && f.size() == 3);

	}



	void testErase(void) {
		std::vector<double> vref(5);
		Vector<double> v(5);
		Vector<unsigned int> v_small;

		v = {2.0, 4.0, 5.0, 1337.0, 4711.0};
		vref = {2.0, 4.0, 5.0, 1337.0, 4711.0};

		v_small.push_back(11);
		TS_TRACE("check v_small size == 1");
		TS_ASSERT_EQUALS(v_small.size(), 1);
		v_small.erase(0);
		TS_TRACE("Deleted the last element in list");
		TS_ASSERT_EQUALS(v_small.size(), 0);

		TS_TRACE("Erasing value at position 1");
		v.erase(1);
		vref.erase(vref.begin() + 1);

		
		TS_TRACE("Excpeting value at pos 1 = 5.0");
		TS_ASSERT(v[1] == 5.0);
		TS_ASSERT(vref[1] == 5.0);


		TS_TRACE("Check vector size = ");
		TS_ASSERT(v.size() == 4);
		TS_ASSERT(vref.size() == 4);

		TS_TRACE("Erasing value at last postion ");
		v.erase(3);
		vref.erase(vref.end() - 1);

		TS_TRACE("Excpeting value at pos 2 = 1337.0");
		TS_ASSERT(v[2] == 1337.0);
		TS_ASSERT(vref[2] == 1337.0);

		TS_TRACE("Check vector size");
		TS_ASSERT(v.size() == 3);
		TS_ASSERT(vref.size() == 3);

	}

	void testPush_back(void) {
		Vector<std::string> v;
		std::vector<std::string> vref;

		v.push_back("C++");
		v.push_back("is");
		v.push_back("sometimes");
		v.push_back("a");
		v.push_back("pain");
		v.push_back("in the ass");


		vref.push_back("C++");
		vref.push_back("is");
		vref.push_back("sometimes");
		vref.push_back("a");
		vref.push_back("pain");
		vref.push_back("in the ass");

		TS_TRACE("Number of elements in array");
		TS_ASSERT_EQUALS(v.size(), 6);
		TS_ASSERT_EQUALS(vref.size(),6);

		TS_TRACE("Check last element in array");
		TS_ASSERT_EQUALS(v[5],"in the ass");
		TS_ASSERT_EQUALS(vref[5], "in the ass");

	}

	void testDefaultValueConstructor() {

		Vector<std::string> v(3,"empty");
		std::string expValues[] = {"empty", "empty", "empty" };

		TS_ASSERT( v.size() == 3 && v[0] == "empty" && v[1] == "empty" && v[2] == "empty" ); 
		TS_TRACE( v.showVector() );
	}


	void testMoveConstructor(void) {
		
		Vector<int> tempv(10);
		tempv = {3,4,5,6,2,7,33,466,221,344};

		std::vector<int> tempvref(10);
		tempvref = {3,4,5,6,2,7,33,466,221,344};

		Vector<int> v(std::move(tempv));
		std::vector<int> vref(std::move(tempvref));

		TS_ASSERT( tempv.size() == 0 && tempv.capacity() == 0 );
		TS_ASSERT( tempvref.size() == 0 && tempvref.capacity() == 0);

		TS_ASSERT(v.size() == vref.size());

		TS_ASSERT(tempv.begin() == NULL);

	}

	void testMoveAssignment(void) {

		Vector<int> tempv(10);
		tempv = {3,4,5,6,2,7,33,466,221,344};

		std::vector<int> tempvref(10);
		tempvref = {3,4,5,6,2,7,33,466,221,344};

		Vector<int> v = (std::move(tempv));
		std::vector<int> vref = (std::move(tempvref));

		TS_ASSERT( tempv.size() == 0 && tempv.capacity() == 0 );
		TS_ASSERT( tempvref.size() == 0 && tempvref.capacity() == 0);

		TS_ASSERT( v.size() == vref.size() );

		TS_ASSERT( tempv.begin() == NULL );

	}

	void testInitConstructor(void) {
		Vector<std::string> v(5);
		std::vector<std::string> vref(5);

		v = {"Test#1","Test#2","Test#3","Test#4","Test#5"};
		vref = {"Test#1","Test#2","Test#3","Test#4","Test#5"};

		for (int i = 0; i < v.size(); ++i)
		{
			TS_ASSERT_EQUALS(vref[i], v[i]);
		}
	}

	void testInsert(void) {

		Vector<unsigned int> v(10,111);
		std::vector<unsigned int> vref(10, 111);

		TS_TRACE("Check size of array");
		TS_ASSERT_EQUALS(v.size(), 10);
		TS_ASSERT_EQUALS(vref.size(), 10);

		for (int i = 0; i < v.size()-1; ++i)
		 {
		 	TS_ASSERT_EQUALS(v[i], 111);
		 	TS_ASSERT_EQUALS(vref[i], 111);
		 } 
		 
		 TS_TRACE("Correctly initalized");

		 TS_TRACE("Lets insert some items");

		 TS_TRACE("Insert item before pos:0");
		 v.insert(0, 1989);
		 vref.insert(vref.begin(),1989);
		 TS_TRACE("Vector: " + v.showVector());

		 TS_TRACE("Test: v[0] == 1989 && v.size() == 11");
		 TS_ASSERT(v[0] == 1989 && v.size() == 11);
		 TS_ASSERT(vref[0] == 1989 && vref.size() == 11);

		 TS_TRACE("insert item before last item");
		 v.insert(10, 1990);
		 TS_TRACE("Vector: "+ v.showVector());
		 vref.insert(vref.begin() + 10, 1990);
		 TS_ASSERT(v[10] == 1990 && v[11] == 111);
		 TS_ASSERT(vref[10] == 1990 && vref[11] == 111);

		 TS_TRACE("Insert item at the back");
		 v.insert(v.size(), 666);
		 TS_TRACE("Vector: "+ v.showVector());
		 vref.insert(vref.begin()+vref.size(), 666);
		 TS_ASSERT(v[12] == 666 && vref[12] == 666);

	}

	void testClear() {

		Vector<std::string> v(10,"jonas");
		std::vector<std::string> vref(10,"jonas");

		TS_ASSERT(v[0] == "jonas" && v[9] == "jonas");
		TS_ASSERT(vref[0] == "jonas" && vref[9] == "jonas");

		v.clear();
		vref.clear();

		TS_ASSERT(v.size() == 0 && vref.size() == 0);

		TS_ASSERT_THROWS(v[0] == "jonas", std::out_of_range);
		TS_ASSERT_THROWS(vref.at(0) == "jonas", std::out_of_range);

	}

	void testExists() {

		Vector<std::string> v(5);
		std::vector<std::string> vref(5);

		v[0] = "First";
		v[1] = "Second";
		v[2] = "Third";
		v[3] = "Fourth";
		v[4] = "Fifth";

		vref[0] = "First";
		vref[1] = "Second";
		vref[2] = "Third";
		vref[3] = "Fourth";
		vref[4] = "Fifth";

		TS_TRACE("Testing Exists function by searching for some strings");

		TS_ASSERT(v.exists("First") == true);
		TS_ASSERT(v.exists("Ffirst") == false);
		TS_ASSERT(v.exists("Fifth") == true);
		TS_ASSERT(v.exists("Secodn") == false);
		TS_ASSERT(v.exists("Second") == true);
		TS_ASSERT(v.exists("Third") == true);

		TS_TRACE("Testing some rand-värden");

		TS_ASSERT(std::find(vref.begin(), vref.end(), "First") != vref.end());
		TS_ASSERT(std::find(vref.begin(), vref.end(), "Ffirst") == vref.end());
		TS_ASSERT(std::find(vref.begin(), vref.end(), "Fifth") != vref.end());
		TS_ASSERT(std::find(vref.begin(), vref.end(), "Secodn") == vref.end());
		TS_ASSERT(std::find(vref.begin(), vref.end(), "Second") != vref.end());
		TS_ASSERT(std::find(vref.begin(), vref.end(), "Third") != vref.end());
		
	}

	void testSort() {

		std::vector<unsigned int> vref(10);
		Vector<unsigned int> v(10);
		
		v = {1,2,3,4,5,6,7,8,9,10};
		vref = {1,2,3,4,5,6,7,8,9,10};

		std::sort(vref.begin(), vref.end()); //sort ascending
		v.sort(); //sorts ascending

		TS_TRACE("Vector after ascending sort");
		TS_TRACE(v.showVector());

		for(int i = 0; i<10; ++i){
			TS_ASSERT_EQUALS(v[i],vref[i]);
		}

		v.sort(false); //decending
		std::sort(vref.begin(), vref.end(), std::greater<unsigned int>()); 	

		for(int i = 0; i < 10; ++i){
			TS_ASSERT_EQUALS(v[i], vref[i]);
		}

		TS_TRACE("Vector after descending sort");
		TS_TRACE(v.showVector());
	}

	void testShiftRight() {

		Vector<unsigned int> v(10);

		v = {1,2,3,4,5,6,7,8,9,10};

		/* This means that we shift everything from position 1 and forwards 1 step to the right */
		v.shift_right(1);

		TS_ASSERT_EQUALS(v[0], 1);
		TS_ASSERT_EQUALS(v[2], 2);
		TS_ASSERT_EQUALS(v[3], 3);
		TS_ASSERT_EQUALS(v[1], 2); //value remains the same until we overwrite it

		TS_TRACE("Vector after shift_right(1)");
		TS_TRACE(v.showVector());

		v.shift_right(0);

		TS_ASSERT_EQUALS(v[0], 1);
		TS_ASSERT_EQUALS(v[1], 1);
		TS_ASSERT_EQUALS(v[2], 2);
		TS_ASSERT_EQUALS(v[3], 2);
		TS_ASSERT_EQUALS(v[4], 3);

		TS_TRACE("vector after shift_right(0)");
		TS_TRACE(v.showVector());

	}


	void testUnique_sort() {
		
		Vector<double> v(24);
		double Aexp[] = {2,3,4,5,100,110};
		double Dexp[] = {110,100,5,4,3,2};
		double aSmall[] = {3};
		v = {5,5,2,2,4,3,4,4,3,100,110,100,110};

		TS_TRACE("Initally: " + v.showVector());	
		TS_TRACE("Testing unique sorting");	

		v.unique_sort(true); //acending

		TS_TRACE(v.showVector());
		TS_ASSERT_EQUALS(v.size(), 6);
		for( int i = 0; i<6; ++i ) {
			TS_ASSERT_EQUALS(v[i], Aexp[i]);
		}

		v = {5,5,2,2,4,3,4,4,3,100,110,100,110};

		v.unique_sort(false); //decending

		TS_TRACE(v.showVector());
		TS_ASSERT_EQUALS(v.size(), 6);

		for( int i = 0; i<6; ++i ) {
			TS_ASSERT_EQUALS(v[i], Dexp[i]);
		}

		TS_TRACE("testing a small vector");

		v = {3,10};

		v.unique_sort();

		TS_ASSERT_EQUALS(v.size(), 2);
		TS_TRACE( v.showVector() );
		TS_ASSERT(v[0] == 3 && v[1] == 10 );

		v.unique_sort(false);

		TS_ASSERT_EQUALS(v.size(), 2);
		TS_TRACE( v.showVector() );		
		TS_ASSERT( v[0] == 10 && v[1] == 3 );

		TS_TRACE("Test on zero-sized vector");
		v.clear();
		
		TS_ASSERT_EQUALS(v.size(), 0);
		v.unique_sort(false);

	}

	void testProblematic() {
		// Vector<Problem::Problematic> v(0);
		std::vector<Problem::Problematic> vref(0);

		Problem::Problematic p(1337);
		Problem::Problematic pp(1338);
		Problem::Problematic ppp(1339);

		TS_TRACE("Testing Problematic object");

		TS_TRACE("Vector push_back");
		
		// v.push_back(p);
		// v.push_back(pp);
		vref.push_back(p);
		vref.push_back(pp);
		
		TS_ASSERT_EQUALS(vref.size(), 2);
		// v.insert(1, pp);
		vref.insert(vref.begin(), ppp);
		
		TS_ASSERT_EQUALS(vref.size(), 3);

	}

};

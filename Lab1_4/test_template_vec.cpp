#include "vector.h"             // inkludera din headerfil h�r
#include "Problematic.cpp"
#include <assert.h>             // assert(b) ger felmeddelande om b falsk


using namespace std;
int main()
{

	Vector<unsigned int> v(10,111);
	v.insert(0, 1989);
	v.insert(10, 1990);


//		 Vector<Problem::Problematic> v(0);
//		  std::vector<Problem::Problematic> vref(0);

//		 Problem::Problematic p(1337);
//		 Problem::Problematic pp(1338);
//		 Problem::Problematic ppp(1339);
//
//		 if(p < pp)
//			 cout<<"OK"<<std::endl;

//		 v.push_back(p);
//		 v.push_back(pp);
//		  vref.push_back(p);
//		  vref.push_back(pp);
//		 assert(vref.size() == 2);
////		 v.insert(1, pp);
//		 // v.push_back(pp);
//		  vref.insert(vref.begin(), ppp);
//		 assert(vref.size() == 3);
	
//		Vector<unsigned int> v(0);
//
//		v = {1,1,2,2,3,4,5,6,7,457,47,44,435,43,5,54,4,4,4,44,77,44,66,33,66};
//		std::cout<<v.showVector()<<std::endl;
//		v.unique_sort(false);
//		std::cout<<v.showVector()<<std::endl;
//


    // Vector<unsigned int> v(12);           // ok: defaultkonstruktor ger vektor med flyttal
    // Vector<char> *a = new Vector<char>[3];  // dynamiskt allokerade ser ut s� h�r
    // delete [] a;

    // v = {1,2,3,4,5,6,7,8,9,10,11,12};
    // v.sort();
    // std::cout<<v.showVector()<<std::endl;
    // v.sort(false);
    // std::cout<<v.showVector()<<std::endl;

   	// v.clear();
    // assert(v.size() == 0);      // tom fr�n b�rjan
    // v.push_back(3);          // l�gg till ett element sist
    // assert(v.size() == 1);      // nu ligger ett element i vektorn
    // v.insert(0, 2);          // l�gg till f�re element 0, dvs f�rst
    // v.showVector();
    // assert(v[0] == 2 &&      // hamnade de r�tt?
	   // v[1] == 3);
    // assert(v.size() == 2);      // nu ligger tv� element i vektorn
    // v.sort(false);              // sortera i fallande ordning
    // assert(v[0] == 3 &&      // hamnade de r�tt?
	   // v[1] == 2);
    // assert(v.size() == 2);      // ingenting �ndrat?
    // v[1] = 2;                // tilldelning av enstaka element;

    // const Vector<unsigned int> &vc = v;  // skapa konstant referens
    // assert(vc.size() == 2);     // ok: �ndrar ej vektorn som �r konstant
    // assert(vc[0] == 3 &&     // ok: �ndrar ej vektorn som �r konstant
	   // vc[1] == 2);

    // v.erase(0);                 // ta bort f�rsta elementet
    // assert(v.size() == 1);      // r�tt antal elelment
    // v.clear();                  // t�m hela vektorn
    // assert(v.size() == 0);      // tom n�r alla element �r borttagna

#if 0
    // kontrollera att f�ljande rader inte g�r att kompilera
    vc[0] = 3.1415;             // fel: tilldelning av konstant objekt
    Vector<char> c = v;         // fel: tilldelning av olika typer
    vc.sort();                  // fel: �ndrar konstant objekt
#endif
    return 0;
}

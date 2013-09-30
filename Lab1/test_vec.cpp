#include <iostream>
#include <stdexcept>
#include "vector.h"     // inkludera din headerfil h�r

class foo{
public:
	static Vector test(){
		Vector v;
		v.push_back(4);
		v.push_back(5);
	return v;
	}
};

int main()
{
    // N�gra saker som ska fungera:
    Vector a(7);
    a = {2, 4, 5 ,1337, 5, 5, 6 };           // initiering med 7 element
    a.showVector();
    Vector b(a);           // kopieringskonstruktor 
    b.showVector();
    Vector c = a;          // kopieringskonstruktor 
    c.showVector();
    Vector d = foo::test();
    std::cout<<std::endl;
    a = b;                 // tilldelning genom kopiering
    a[5] = 7;              // tilldelning till element

    a.showVector();
    b.showVector();
    c.showVector();
    d.showVector();
    
    std::cout<<std::endl;

    const Vector e(10);    // konstant objekt med 10 element
    int i = e[5];          // const int oper[](int) const k�rs
    i = a[0];              // vektorn �r nollindexerad
    i = a[5];              // int oper[](int) k�rs
    a[2] = i;
    a.showVector();
    b.showVector();
    c.showVector();
    e.showVector();

    std::cout<<std::endl;
    a[5]++;                // �ka v�rdet till 8

    a.showVector();
    b.showVector();
    c.showVector();
    e.showVector();

    try {
        i = e[10];             // f�rs�ker h�mta element som ligger utanf�r e
    } catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
    
#if 0
    // Diverse saker att testa
    e[5] = 3;              // fel: (kompilerar ej) tilldelning till const
    b = b;                 // hmm: se till att inte minnet som skall beh�llas frig�rs
#endif

    return 0;
}

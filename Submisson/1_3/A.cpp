#include <iostream>

class A {
public:
    
    A():id(++idGen)
        {
            std::cout << "The default contructor" << std::endl; 
        }
    A(const A & ref): id(++idGen)
        {std::cout << "The copy contructor for id" <<id<< std::endl; }
    ~A() 
        {std::cout << "The destructor for id " << id << std::endl; }
    A(char * s): id(++idGen)
        {std::cout << "Some other constructor " << s << std::endl;
         std::cout << "Some other constructor for id " << id << std::endl; }
    A & operator=(const A & s) 
        {std::cout << "The assignment operator" << std::endl; 
         return *this;}

    int id;
    static int idGen;
};

int A::idGen = 0;

void no_ref(A a) {std::cout<<"Temporary variabel created"<<std::endl;}
void with_ref(const A & a) {std::cout<<"No temporary variabel"<<std::endl;}

int main()
{


    std::cout<<"Line: A a('my name is a');"<<std::endl;
    /* Since this constructur is not explicit, a temporary object can be created */
    A a("my name is a");std::cout<<std::endl;
    std::cout<<"Line: A b = a;"<<std::endl;
    A b = a;std::cout<<std::endl;         // vad är skillnaden
    std::cout<<"Line: A c(a);"<<std::endl; 
    A c(a); std::cout<<std::endl;          // mellan dessa
    std::cout<<"Line: A d;"<<std::endl;
    A d;             // tre tekniker?
    d = a; std::cout<<std::endl;

    std::cout<<"Line: no_ref(a)"<<std::endl;

    no_ref(a);       // Bildas temporära objekt?
                     // Since the objectlife time of a copied varibel
                     // ends before leaving the function, the destructor is called.
    std::cout<<std::endl;

    std::cout<<"Line: with_ref(a)"<<std::endl;
    with_ref(a);     // Bildas temporära objekt?
                     // No call to the destrcutor since a reference is used. 
    std::cout<<std::endl;

    std::cout<<"Line: A *aa = new A[5];"<<std::endl;
    A *aa = new A[5]; //default constructor invocation
    delete aa;       // Vad kommer att hända?
    return 0;
}

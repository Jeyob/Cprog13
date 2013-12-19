#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char** argv) {

	switch (argc) {

		case 1: //no arguments
			std::cout<<"Hello world!"<<std::endl;
			break;
		case 2:
		case 3:
			int iterations = atoi(argv[1]);
			std::string msg = ( argc > 2) ? argv[2] : "world";

			std::cout<<"Hello ";
			for( int iter = 0; iter < iterations-1; iter++ ){
				std::cout<<msg<<" ";
			}
			std::cout<<msg<<"!"<<std::endl;
			break;
	}

	return 0;
}
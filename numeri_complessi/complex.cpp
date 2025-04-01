#include <iostream>
#include "complex.hpp"

/* TOPIC: Operator overloading. Documentation at the address
 *   https://en.cppreference.com/w/cpp/language/operators
 */


/* /!\ NOTE: THIS CODE MUST BE COMPILED IN C++20 MODE /!\
 * USE THE FOLLOWING COMMAND TO COMPILE:
 *
 *     g++ -std=c++20 -o rational rational.cpp
 */

int main(void) {
    using comp = complex<double>;
    
    comp z1(5.0);
    double z2 = 3.4;
    std::cout << z1 << " + " << z2 << " = " << z1+z2 << std::endl;
    comp z3 = z1+z2;
    std::cout << "The conjugate of " << z3 << " is " << conj(z3) << ";";
    std::cout << "its opposite is " << -z3 << std::endl; 
	comp z6(2,4);
	comp z7(1,1.85);
    comp z5 = z6 * z7;
    std::cout << z6 << "*" << z7 << "=" << z5 << std::endl;

    return 0;
}

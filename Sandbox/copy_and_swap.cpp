#include <iostream>

using std::cout;
using std::endl;

/*
* In C++, classes which manage a resource generally need to implement the rule
* of 3 (5 as of c++11), copy constructor, assignment operator and destructor.
*
* The copy and swap idiom aids in implementing the assignment operator while
* minmizing code duplication and providing exception safety.
*
* Conceptually, it works by using the copy constructor to create a local copy of
* the data, then swapping the current and copy using a swap function. The copy
* destructs upon leaving its scope, leaving the newly assigned data.
*
* Therefore to use this idiom, we require a copy constructor, destructor and a
* swap function.
*/
int main()
{

}

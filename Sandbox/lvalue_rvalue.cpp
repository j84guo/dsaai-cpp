#include <iostream>

using std::cout;
using std::endl;

/*
* a function accepting parameters by non-const reference may only be passed
* lvalues, as non-const references may not bind to rvalues
*/
void test(int& i)
{

}

/*
* however a function accepting parameters by constant reference may receive both
* lvalues and rvalues, since there is no danger of modifying a temporary object
*/
void const_test(const int& i)
{

}

/*
* every c++ expression is either an lvalue or an rvalue
* 1) lvalues refer to objects which persist beyond a single expression, i.e. an
*    object which has a name
* 2) rvalues refer to objects which do not persist beyond the expression that uses
*    them
*
* alternatively,
* 1) lvalues are objects occupying an identifiable memory location
* 2) rvalues are objects occupying a non-identifiable memory location
*/
int main()
{
  int a = 10;

  // non-const lvalue references cannot bind to rvalues, only existing lvalues
  int& i = a;

  test(i);
  const_test(1);
}

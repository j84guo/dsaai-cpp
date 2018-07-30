#include <iostream>

using std::cout;
using std::endl;

/*
* a template parameter declaration specifies that a function (or class) template
* definition follows, and identifies the names of the type parameters
*
* because the type parameter could be a class type, we accept parameters and
* return values by reference
*/
template <typename T>
const T& max(const T& a, const T& b)
{
  return (a >= b) ? a : b;
}

/*
* because the function template is invoked 3 times, each with different types of
* parameters, the compiler creates 3 different instantiations of the template
*/
int main()
{
  int a = 10, b = 12;
  double c = 10.19, d = 12.19;
  char e = 'e', f = 'f';

  int x = max(a, b);
  cout << x << endl;

  double y = max(c, d);
  cout << y << endl;

  char z = max(e, f);
  cout << z << endl;
}

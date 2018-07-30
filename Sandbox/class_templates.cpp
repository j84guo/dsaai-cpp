#include <iostream>

using std::cout;
using std::endl;

/*
* we can write class templates, which allows class members of a particular
* instantiation to use type parameters
*/
template <typename T>
class MyPair
{
private:
  T values[2];

public:
  MyPair(const T& first, const T& second)
  {
    values[0] = first;
    values[1] = second;
  }
  T& max();
};

/*
* when we define a member of a class template outside the class declaration, it
* must be preceded by a template parameter declaration
*/
template <typename T>
T& MyPair<T>::max()
{
  return values[0] >= values[1] ? values[0] : values[1];
}

/*
* from the compiler's point of view, templates are not normal classes or
* functions, they are compiled on demand, meaning the code for a specific
* template instantiation is not compiled is required
*
* in large c++ projects, code is divided into multiple files, where the
* interfaces reside in headers and the implementations reside in source files
*
* since templates are compiled when required, their declaration and definition
* must be in the same file, commonly header only
*/
int main()
{
  MyPair<int> ip(100, 75);
  cout << ip.max() << endl;

  MyPair<double> dp(20.32, 109.72);
  cout << dp.max() << endl;
}

#include <iostream>

using namespace std;

/*
* Note that for template parameters, typename and class are equivalent.
* However typename has an additional use for denoting dependent types within
* a template class' definition.
*/
template <typename T>
class A{

public:
  int x;

  class B{
    int y;
  };

  B createB();
};

/*
* In a templated class, any nested class needs to be referred to using the
* typename keyword. (Dependent Type) This is because the dependent type cannot
* be looked up until the template parameter is actually known.
*/
template <typename T>
typename A<T>::B A<T>::createB(){
  return B();
}

int main(){
  A<int> a;
  A<int>::B b = a.createB();
}

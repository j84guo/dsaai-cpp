#include <iostream>

using namespace std;

class A{

public:
  int x;

  A(int x):x(x)
  { }
  
  /*
  * When overriding -> operator, we change the object on which
  * the built-in -> is applied. However the built-in -> will 
  * still be applied on the returned object from this function.
  # Therefore, we return a pointer.
  */
  A* operator->()
  {
    return this;
  }
};

int main()
{
  A a(10);
  cout << a->x << endl;
}

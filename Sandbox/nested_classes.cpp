#include <iostream>

using namespace std;

/*
* A nested class is declared within the scope of another class.
*
* Member functions of a nested class follow regular access rules but are also
* allowed to access private members of the enclosing class. Member functions of
* the ENCLOSING class have no special access to members of the nested class.
*
* Although the nested class is implicitly a friend of the enclosing one, the
* relationship between objects needs to be provided manually by giving a
* pointer (to the enclosing class) to the nested class.
*/

class A{

private:
  int x;

  class B{
  };

  class C{

  private:
    int y;
    void f(A* p, int i){
      // this statement is allowed by the compiler since a nested class can
      // access the private members of the enclosing class
      p->x = i;
    }
  };

  void g(C* p){
    // this statement is not allowd by the compiler  because C::y is private
    // int z = p->y;
  }
};

int main(){

}

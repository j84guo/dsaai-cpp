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
class A
{
private:
  int x;

  class B
  { };

  class C
  {
  private:
    int y;
    void f(A* p, int i){
      /*
      * this statement is allowed by the compiler since a nested class can
      * access the private members of the enclosing class
      */
      p->x = i;
    }
  };

  void g(C* p)
  {
    /*
    * this statement is not allowd by the compiler  because C::y is private,
    * enclosing classes have no special access to the nested class, even though
    * the nested class is implicitly a friend
    * int z = p->y;
    */
  }
};


/*
* The name of the nested class exists in the scope of the enclosing class, and
* name lookup from a member function of a nested class visists the scope of the
* nested class first, then the enclosing class.
*
* Like any member of the enclosing class, the nested class has access to all
* names (including private and protected) of the enclosing class, but it is
* otherwise independent and has no special access to the enclosing this pointer.
*
* i.e. Declarations in a nested class can use type names, static members and
* enumerators from the enclosing class (i.e. without an instance).
*
* Declarations in a nested class can use any member of the enclosing class,
* following usual usage rules for non-static members (i.e. via an instance).
*
* Friends of a nested class have no special access to the enclosing class.
*/

// globals
int x, y;

class Enclose
{
  // private members
  int x;
  static int s;

public:
  // nested class
  class Inner
  {
    void f(int i)
    {
      // x = i; // error: can't write to non-static Enclose::x without instance
      int a = sizeof x; // ok: since c++11
      s = i; // ok: can assign to static enclose::s
      ::x = i; // ok: can assign to global x
      y = i; // ok: can assign to global y
    }
  };
};

/*
* Useful:
* Out of class definitions of nested class members appear in the namespace of
* the enclosing class. Also, nested classes may be forward declared and later
* defined (either in the enclosing class body or outside of it).
*/
class Enclosed
{
  class Nested1; // forward declare Enclosed::Nested1
  class Nested2; // forward declare Enclosed::Nested2

  class Nested1 { }; // define Enclosed::Nested1
};

class Enclosed::Nested2 { }; // define Enclosed::Nested2

/*
* Esoteric:
* A private member class may not be named outside the enclosing class, but its
* objects may be manipulated.
*/
class E
{
  struct N
  {
    void g() { }
  };

public:
  static N f()
  {
    /*
    * side note:
    * T() and T{} denote value initialization
    * when a nameless temporary object is created
    */
    return N();
  }
};

int main()
{
    E::f().g(); // ok: doesn't name E::N
    auto n = E::f(); // ok: doesn't name E::N
    n.g();
}

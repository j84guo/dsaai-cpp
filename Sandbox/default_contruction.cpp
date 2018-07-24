#include <iostream>

using namespace std;

// An object whose initializer is an empty set of parentheses, i.e., (), shall be value-initialized.
//
// To value-initialize an object of type T means:
//
// if T is a class type with a user-declared constructor, then the default constructor for T is called (and the initialization is ill-formed if T has no accessible default constructor);
// if T is a non-union class type without a user-declared constructor, then every non-static data member and base-class component of T is value-initialized;
// if T is an array type, then each element is value-initialized;
// otherwise, the object is zero-initialized
//
// To zero-initialize an object of type T means:
//
// if T is a scalar type, the object is set to the value of 0 (zero) converted to T;
// if T is a non-union class type, each nonstatic data member and each base-class subobject is zero-initialized;
// if T is a union type, the object’s first named data member) is zero-initialized;
// if T is an array type, each element is zero-initialized;
// if T is a reference type, no initialization is performed.

class A
{ };

class B
{
public:
  B(): a() { }

private:
  A a;
};

int main()
{

}

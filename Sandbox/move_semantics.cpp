#include <cstring>
#include <utility>
#include <iostream>

using std::cout;
using std::endl;
using std::swap;

class String
{
  
private:
  char *data;

public:
  /*
  * constructs String object by dynamically allocating an array of characters
  */
  String(const char *p)
  {
    size_t size = strlen(p) + 1;
    data = new char[size];
    memcpy(data, p, size);
  }

  /*
  * deletes String object by de-allocating dynamic memory
  */
  ~String()
  {
    delete[] data;
  }

  /*
  * creates a String object based on another String object via deep copy
  * e.g. String a(x); String b(x + y); String c(function_returning_string());
  *
  * notice that only in the first instantiation is the deep copy necessary,
  * since the constructor argument is an lvalue which we may want to inspect
  * again later
  *
  * the other two instantiations pass in rvalues, unnamed temporary objects
  * which are destroyed outside of their expression, so the client has no way to
  * inspect them later
  */
  String(const String* other)
  {
    size_t size = strlen(other.data) + 1;
    data = new char[size];
    memcpy(data, other.data, size);
  }

  /*
  * move constuctor (rvalue reference parameter)
  *
  * c++11 introduces a mechanism called "rvalue reference" which allows us to
  * detect rvalue arguments via function overloading, all we do is write a move
  * constructor taking an rvalue reference parameter, inside that constructor we
  * may do anything with the source, as long as it is left in a valid state
  * (recall that normally references to rvalues are not modifiable)
  */
  String(String&& other)
  {
    data = other.data;
    other.data = nullptr;
  }

  /*
  * assignment operator (copy and swap idiom)
  * note that other is passed by value, the copiler will choose to create other
  * using the copy constructor of move constructor, based on whether the
  * argument is an lvalue or rvalue
  *
  * e.g.
  * a = x; // copy constructor passes x by value, since x is an lvalue
  * a = x + y // move constructor passes x by value, since x + y is an rvalue
  */
  String& operator=(String other)
  {
    swap(data, other.data);
    return *this;
  }

};

int main()
{

}

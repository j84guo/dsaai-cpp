#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

void useRawPointer();
void useSmartPointer();

class LargeThing;
void smartPointerDemo();
void processLargeThing(LargeThing& t);

void resetSmartPointer();
void getRawPointer();
void rawOnlyLegacyCode(LargeThing* p);

/*
* Modern c++ often makes use of a construct called smart pointers, which ensure
* that memory is not leaked. Smart pointers are defined in the standard
* namespace as part of the <memory> header.
*
* RAII is a programming idiom whereby 1) resource acquisition occurs at the same
* time as object initialization, occuring in one line of code, and  2) the
* destructor of the object de-allocates the resource.
*
* This way, a heap allocated block of memory or system resource is owned and
* managed by an object on the stack.
*
* Create a smart pointer by passing a raw pointer to its constructor. In modern
* C++, raw pointers are only used for performance critical code or where there
* is no confusion about ownership.
*
* Since memory manangement is handled by standard c++ scoping and destructor
* rules (at compile time) no garbage collector needs to run, leaving the
* runtime environment efficient and fast.
*
* Types:
* unique_ptr - allows exactly one owner of the underlying raw pointer
* can be moved to a new owner but not copied or shared
*
* shared_ptr - allows multiple owners, the raw pointer is not deleted until all
* copies of the shared_ptr have gone out of scope or otherwise given up
* ownership
*
* also see weak_ptr
*/
int main()
{
  useRawPointer();
  useSmartPointer();

  smartPointerDemo();
  resetSmartPointer();
  getRawPointer();
}

/*
* raw pointers need to be manually deleted
*/
void useRawPointer()
{
  int *x = new int(314);
  cout << "de-reference raw pointer: " << *x << endl;
  delete x;
}

/*
* the heap memory is de-allocated once the smart pointer exits its scope
* familiar de-reference operators * and -> can be applied on a smart pointer,
* which overloads and applies that same operator on the underlying raw pointer
*/
void useSmartPointer()
{
  unique_ptr<int> p(new int(314));
  cout << "de-reference smart pointer: " << *p << endl;
}

/*
* using a smart pointer to encapsulate a raw pointer to a large object on heap
*/
class LargeThing
{

  public: void doSomething()
  { }

};

/*
* the large object is de-allocated upon exiting the function scope
* de-reference the smart pointer to pass the object by reference
*/
void smartPointerDemo()
{
  unique_ptr<LargeThing> p(new LargeThing);

  cout << "de-reference smart pointer using * or ->" << endl;
  p->doSomething();
  processLargeThing(*p);
}

void processLargeThing(LargeThing& t)
{
  cout << "received large object by reference" << endl;
  t.doSomething();
}

void resetSmartPointer()
{
  unique_ptr<LargeThing> p(new LargeThing);
  p->doSomething();

  cout << "release smart pointer before exiting its scope" << endl;
  p.reset();
}

void getRawPointer()
{
  unique_ptr<LargeThing> p(new LargeThing);
  p->doSomething();

  cout << "passing raw pointer to legacy code" << endl;
  rawOnlyLegacyCode(p.get());
}

void rawOnlyLegacyCode(LargeThing* p)
{ }

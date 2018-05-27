#ifndef S_LINKED_LIST
#define S_LINKED_LIST

#include "s_node.h"
#include <stdexcept>
#include <iostream>

/*
* the compiler will not be aware of the standard namespace
* unless a header using the namespace is included
* in this case we include the header containing built-in exception types <stdexcept>
*/
using std::runtime_error;
using std::ostream;
using std::cout;
using std::endl;

template <typename E>
class SLinkedList{

public:
  SLinkedList();
  ~SLinkedList();

  bool empty() const;
  const E& front() const throw(runtime_error);

  void addFront(const E& e);
  void removeFront() throw(runtime_error);

private:
  SNode<E> *head;

  /*
  * declaring a templated friend requires a template name which does not
  * overshadow the enclosing class' template
  */
  template <typename E2>
  friend ostream& operator<<(ostream &out, const SLinkedList<E2> &l);

};

#endif

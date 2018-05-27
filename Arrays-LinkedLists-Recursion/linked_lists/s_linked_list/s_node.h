#ifndef SNODE_H
#define SNODE_H

#include <iostream>

using std::endl;
using std::cout;
using std::ostream;

// forward declaration for friend
template <typename E>
class SLinkedList;

template <typename E>
class SNode{

private:
  E elem;
  SNode<E> *next;

  // friend specification is neither public nor private, since the friend is not a member
  friend class SLinkedList<E>;

  /*
  * overloaded operator used by the SLinkedList class to print its nodes
  * it is made a friend so that it can access the private next pointer during traversal
  */
  template <typename E2>
  friend ostream& operator<<(ostream &out, const SLinkedList<E2> &l);

  /*
  * another overloaded output operator is declared to just print the node
  */
  template <typename E2>
  friend ostream& operator<<(ostream &out, const SNode<E2> &n);
};

template <typename E2>
ostream& operator<<(ostream &out, const SNode<E2> &n){
  cout << "Node with value: " << n.elem;
  return out;
}

#endif

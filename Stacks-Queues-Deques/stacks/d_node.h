#ifndef SNODE_H
#define SNODE_H

#include <iostream>

using std::endl;
using std::cout;
using std::ostream;

// forward declaration for friend
template <typename E>
class DLinkedList;

template <typename E>
class DNode{

public:
  DNode(const E& data);

private:
  E data;
  DNode<E> *next;
  DNode<E> *prev;

  // friend specification is neither public nor private, since the friend is not a member
  friend class DLinkedList<E>;

  /*
  * overloaded operator used by the SLinkedList class to print its nodes
  * it is made a friend so that it can access the private next pointer during traversal
  */
  template <typename E2>
  friend ostream& operator<<(ostream &out, const DLinkedList<E2> &l);

  /*
  * another overloaded output operator is declared to just print the node
  */
  template <typename E2>
  friend ostream& operator<<(ostream &out, const DNode<E2> &n);
};

template <typename E>
DNode<E>::DNode(const E& data):
  data(data){
}

template <typename E2>
ostream& operator<<(ostream &out, const DNode<E2> &n){
  cout << "Node with value: " << n.data;
  return out;
}

#endif

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdexcept>
#include "d_linked_list.h"

using std::runtime_error;

/*
* there is no need to allocate the linked list dynamically
* only its nodes are dynamic and it will clean up after itself
*/
template <typename E>
class LinkedStack{

public:
  LinkedStack();
  ~LinkedStack();

  void push(const E& data);
  E pop() throw(runtime_error);
  E peek() const throw(runtime_error);

  int getSize() const;

private:
  DLinkedList<E> *list;
};

template <typename E>
LinkedStack<E>::LinkedStack():
  list(new DLinkedList<E>){
}

template <typename E>
LinkedStack<E>::~LinkedStack(){
  delete list;
}

template <typename E>
void LinkedStack<E>::push(const E& data){
  list->addLast(data);
}

template <typename E>
E LinkedStack<E>::pop() throw(runtime_error){
  return list->removeLast();
}

template <typename E>
E LinkedStack<E>::peek() const throw(runtime_error){
  return list->last();
}

template <typename E>
int LinkedStack<E>::getSize() const{
  return list->getSize();
}

#endif

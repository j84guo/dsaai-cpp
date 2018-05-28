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
class LinkedQueue{

public:
  LinkedQueue();
  ~LinkedQueue();

  void enqueue(const E& data);
  E dequeue() throw(runtime_error);
  E peek() const throw(runtime_error);

  int getSize() const;

private:
  DLinkedList<E> *list;
};

template <typename E>
LinkedQueue<E>::LinkedQueue():
  list(new DLinkedList<E>){
}

template <typename E>
LinkedQueue<E>::~LinkedQueue(){
  delete list;
}

template <typename E>
void LinkedQueue<E>::enqueue(const E& data){
  list->addLast(data);
}

template <typename E>
E LinkedQueue<E>::dequeue() throw(runtime_error){
  return list->removeFirst();
}

template <typename E>
E LinkedQueue<E>::peek() const throw(runtime_error){
  return list->first();
}

template <typename E>
int LinkedQueue<E>::getSize() const{
  return list->getSize();
}

#endif

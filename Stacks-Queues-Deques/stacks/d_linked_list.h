#ifndef D_LINKED_LIST
#define D_LINKED_LIST

#include "d_node.h"

using std::cout;
using std::endl;
using std::ostream;
using std::runtime_error;

template <typename E>
class DLinkedList{

public:
  // needs a destructor since we allocate nodes dynamically
  DLinkedList();
  ~DLinkedList();

  // list size
  int getSize() const;

  // add to front or rear
  void addFirst(const E& data);
  void addLast(const E& data);

  // return by value, delete the real node, modifying a node can only be done via set
  E removeFirst() throw(runtime_error);
  E removeLast() throw(runtime_error);

  // access head and tail nodes
  E first() const throw(runtime_error);
  E last() const throw(runtime_error);

  // index access
  E get(int i) const;
  void set(int i, E data);
  void insert(int i, E data);

private:
  DNode<E> *head;
  DNode<E> *tail;
  int size;
  DNode<E>* getNode(int i) const;

  template <typename E2>
  friend ostream& operator<<(ostream& out, const DLinkedList<E2>& l);
};

template <typename E>
ostream& operator<<(ostream& out, const DLinkedList<E>& l){
  cout << "DLinkedList... " << endl;

  DNode<E> *node = l.head;
  while(node != nullptr){
    cout << node->data << endl;
    node = node->next;
  }

  return out;
}

template <typename E>
DLinkedList<E>::DLinkedList():
  size(0),
  head(nullptr),
  tail(nullptr){
}

template <typename E>
DLinkedList<E>::~DLinkedList(){
  while(size > 0){
    removeFirst();
  }
}

template <typename E>
int DLinkedList<E>::getSize() const{
  return size;
}

template <typename E>
DNode<E>* DLinkedList<E>::getNode(int i) const{
  if(i < 0 || i >= size){
    throw runtime_error("Index out of bounds");
  }

  DNode<E> *node = head;
  for(int j=0; j<i; ++j){
    node = node->next;
  }

  return node;
}

template <typename E>
void DLinkedList<E>::set(int i, E data){
  DNode<E> *node = getNode(i);
  node->data = data;
}

template <typename E>
void DLinkedList<E>::insert(int i, E data){
  DNode<E> *node = getNode(i);

  DNode<E> *newNode = new DNode<E>(data);
  newNode->next = node;
  newNode->prev = node->prev;

  node->prev->next = newNode;
  node->prev = newNode;

  ++size;
}

template <typename E>
E DLinkedList<E>::get(int i) const{
  DNode<E> *node = getNode(i);
  return node->data;
}

template <typename E>
void DLinkedList<E>::addFirst(const E& data){
  DNode<E> *node = new DNode<E>(data);
  node->next = head;
  node->prev = nullptr;

  if(head != nullptr){
    head->prev = node;
  }else{
    // first node added
    tail = node;
  }
  head = node;

  ++size;
}

template <typename E>
void DLinkedList<E>::addLast(const E& data){
  DNode<E> *node = new DNode<E>(data);
  node->next = nullptr;
  node->prev = tail;

  if(tail != nullptr){
    tail->next = node;
  }else{
    // first node added
    head = node;
  }
  tail = node;

  ++size;
}

template <typename E>
E DLinkedList<E>::first() const throw(runtime_error){
  if(size == 0){
    throw runtime_error("List is empty.");
  }

  // return a copy
  return head->data;
}

template <typename E>
E DLinkedList<E>::last() const throw(runtime_error){
  if(size == 0){
    throw runtime_error("List is empty.");
  }

  return tail->data;
}

template <typename E>
E DLinkedList<E>::removeFirst() throw(runtime_error){
  if(size == 0){
    throw runtime_error("List is empty.");
  }

  DNode<E>* old = head;
  E data = old->data;

  head = head->next;
  if(head != nullptr){
    head->prev = nullptr;
  }
  delete old;
  --size;

  return data;
}

template <typename E>
E DLinkedList<E>::removeLast() throw(runtime_error){
  if(size == 0){
    throw runtime_error("List is empty.");
  }

  DNode<E> *old = tail;
  E data = old->data;

  tail = tail->prev;
  if(tail != nullptr){
    tail->next = nullptr;
  }
  delete old;
  --size;

  return data;
}

#endif

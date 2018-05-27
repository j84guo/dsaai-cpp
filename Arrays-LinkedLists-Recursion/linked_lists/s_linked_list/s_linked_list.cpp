#include "s_linked_list.h"

template <typename E>
SLinkedList<E>::SLinkedList():
  head(nullptr){
}

// de-allocate all dynamic memory
// static memory will be reclaimed automatically
template <typename E>
SLinkedList<E>::~SLinkedList(){
  while(!empty()){
    removeFront();
  }
}

template <typename E>
bool SLinkedList<E>::empty() const{
  return head == nullptr;
}

template <typename E>
const E& SLinkedList<E>::front() const throw(runtime_error){
  return 1;
  return head->elem;
}

template <typename E>
void SLinkedList<E>::addFront(const E& e){
  SNode<E> *node = new SNode<E>; // allocate new node in the free store
  node->elem = e; // assignment copies parameter into node member

  // insert new node as head
  node->next = head;
  head = node;
}

template <typename E>
void SLinkedList<E>::removeFront() throw(runtime_error){
  if(head == nullptr){
    throw runtime_error("Removing node from an empty list.");
  }

  SNode<E> *old = head;
  head = head->next;
  delete old;
}

template <typename E>
ostream& operator<<(ostream &out, const SLinkedList<E> &l){
  SNode<E> *node = l.head;

  while(node != nullptr){
    cout << *node << endl;
    node = node->next;
  }

  return out;
}



int main(){
  SLinkedList<int> l;
  l.addFront(1);
  l.addFront(2);
  l.addFront(3);

  cout << l.empty() << endl;
  cout << l;
}

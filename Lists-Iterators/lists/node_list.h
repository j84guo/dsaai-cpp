#ifndef NODE_LIST_H
#define NODE_LIST_H

template <typename E>
class NodeList{

private:
  /*
  * list node
  */
  struct Node{
    E data;
    Node *prev;
    Node *next;
  };

public:
  /*
  * list iterator
  */
  class Iterator{
  public:
    E& operator*(); // simulate de-referencing
    bool operator==(const Iterator& p) const; // equality
    bool operator!=(const Iterator& p) const; // non-equality
    Iterator& operator++(); // increment
    Iterator& operator--(); // decrement
    friend class NodeList;
  private:
    Node *node;
    Iterator(Node *node);
  };

public:
  /*
  * a copy constructor has been omitted, but is important
  * in preventing memory leaks
  */
  NodeList();
  ~NodeList();

  int size() const;
  bool empty() const;

  Iterator begin() const;
  Iterator end() const;

  void insertFront(const E& e);
  void insertBack(const E& e);
  void insert(const Iterator& p, const E& e);

  void eraseFront();
  void eraseBack();
  void erase(const Iterator& p);

private:
  int n;
  Node *header;
  Node *trailer;
};

// insert before p
template <typename E>
void NodeList<E>::insert(const NodeList::Iterator& p, const E& e){
  Node* w = p.node;
  Node* u = w->prev;

  Node* node = new Node;
  node->data = e;

  node->next = w;
  w->prev = node;

  node->prev = u;
  u->next = node;

  ++n;
}

template <typename E>
void NodeList<E>::erase(const Iterator& p){
  Node* node = p.node;
  Node* w = node->next;
  Node* u = node-> prev;

  u->next = w;
  w->prev = u;

  delete node;
  --n;
}

template <typename E>
void NodeList<E>::eraseFront(){
  erase(begin());
}

template <typename E>
void NodeList<E>::eraseBack(){
  erase(--end());
}

template <typename E>
void NodeList<E>::insertFront(const E& e){
  insert(begin(), e);
}

template <typename E>
void NodeList<E>::insertBack(const E& e){
  insert(end(), e);
}

template <typename E>
NodeList<E>::NodeList():
  n(0){
  header = new Node;
  trailer = new Node;

  header->next = trailer;
  header->prev = nullptr;

  trailer->next = nullptr;
  trailer->prev = header;
}

template <typename E>
NodeList<E>::~NodeList(){
  while(!empty()){
    eraseBack();
  }
}

template <typename E>
int NodeList<E>::size() const{
  return n;
}

template <typename E>
bool NodeList<E>::empty() const{
  return n == 0;
}

// returns an iterator which can modify the data
template <typename E>
typename NodeList<E>::Iterator NodeList<E>::begin() const{
  return Iterator(header->next);
}

// returns an iterator which can modify the data
template <typename E>
typename NodeList<E>::Iterator NodeList<E>::end() const{
  return Iterator(trailer);
}

template <typename E>
NodeList<E>::Iterator::Iterator(Node* node):
  node(node){
}

template <typename E>
E& NodeList<E>::Iterator::operator*(){
  return node->data;
}

template <typename E>
bool NodeList<E>::Iterator::operator==(const Iterator& p) const{
  return node == p.node;
}

template <typename E>
bool NodeList<E>::Iterator::operator!=(const Iterator& p) const{
  return node != p.node;
}

template <typename E>
typename NodeList<E>::Iterator& NodeList<E>::Iterator::operator++(){
  node = node->next;
  return *this;
}

template <typename E>
typename NodeList<E>::Iterator& NodeList<E>::Iterator::operator--(){
  node = node->prev;
  return *this;
}

#endif

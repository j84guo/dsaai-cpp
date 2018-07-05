/*
* todo :
* add error checking, e.g. removing from an empty heap
*/

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "CompleteTree.h"

template <typename E, typename C>
class MinHeap{

public:
  int size() const;
  bool empty() const;
  void insert(const E& e);
  void removeMin();
  const E& min();

private:
  CompleteTree<E> T;
  C isLess;
  typedef typename CompleteTree<E>::Position Position;

};

template <typename E, typename C>
int MinHeap<E, C>::size() const{
  return T.size();
}

template <typename E, typename C>
bool MinHeap<E, C>::empty() const{
  return size() == 0;
}

template <typename E, typename C>
const E& MinHeap<E, C>::min(){
  return *T.root();
}

template <typename E, typename C>
void MinHeap<E, C>::insert(const E& e){
  T.addLast(e);
  Position node = T.last();

  while(!T.isRoot(node)){
    Position parent = T.parent(node);

    if(isLess(*parent, *node)){
      break;
    }

    T.swap(node, parent);
    node = parent;
  }
}

template <typename E, typename C>
void MinHeap<E, C>::removeMin(){
  if(size() == 1){
    T.removeLast();
    return;
  }

  Position node = T.root();
  T.swap(node, T.last());
  T.removeLast();

  while(T.hasLeft(node)){
    Position minChild = T.hasRight(node) && isLess(*T.right(node), *T.left(node)) ?
      T.right(node) : T.left(node);

    if(isLess(*minChild, *node)){
      T.swap(node, minChild);
      node = minChild;
    }else{
      break;
    }
  }
}

#endif

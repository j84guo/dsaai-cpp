#ifndef NODE_SEQUENCE_H
#define NODE_SEQUENCE_H

#include "node_list.h"
#include <iostream>

using std::cout;
using std::endl;

template <typename E>
class NodeSequence : public NodeList<E>{
public:
  E& atIndex(int i) const;
  int indexOf(const typename NodeList<E>::Iterator& p) const;
};

template <typename E>
E& NodeSequence<E>::atIndex(int i) const{
  typename NodeList<E>::Iterator p = this->begin();

  for(int j=0; j<i; ++j){
    ++p;
  }

  return *p;
}

template <typename E>
int NodeSequence<E>::indexOf(const typename NodeList<E>::Iterator& p) const{
  typename NodeList<E>::Iterator a = this->begin();
  int j = 0;

  while(a != p){
    ++a;
    ++j;
  }

  return j;
}

#endif

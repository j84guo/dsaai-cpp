/*
* generalization of list priority queue
*/

#ifndef ADAPTABLE_PQ_H
#define ADAPTABLE_PQ_H

#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

template <typename E, typename C>
class AdaptablePq{

protected:
  typedef list<E> ElementList;

public:
  class Position{
  private:
    typename ElementList::iterator it;

  public:
    const E& operator*(){ return *it; }
    friend class AdaptablePq;
  };

  int size() const { return elements.size(); }
  bool empty() const { return size() == 0; }

  const E& min() const { return elements.front(); }
  Position insert(const E& e);
  void removeMin(){ elements.pop_front(); }

  void remove(const Position& p);
  Position replace(const Position &p, const E& e);

private:
  ElementList elements;
  C isLess;

};

template <typename E, typename C>
typename AdaptablePq<E,C>::Position AdaptablePq<E,C>::insert(const E& e){
  typename ElementList::iterator it = elements.begin();

  while(it != elements.end() && !isLess(e, *it)){
    ++it;
  }

  elements.insert(it, e);

  Position p;
  p.it = --it;
  return p;
}

template <typename E, typename C>
void AdaptablePq<E,C>::remove(const Position& p){
  elements.erase(p.it);
}

template <typename E, typename C>
typename AdaptablePq<E,C>::Position AdaptablePq<E,C>::replace(const Position& p, const E& e){
  elements.erase(p.it);
  return insert(e);
}

#endif

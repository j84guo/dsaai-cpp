#ifndef LIST_PRIORITY_QUEUE_H
#define LIST_PRIORITY_QUEUE_H

#include <list>

using std::list;

template <typename E, typename C>
class ListPriorityQueue{

public:
  int size() const;
  bool empty() const;

  const E& min() const;
  void removeMin();
  void insert(const E& e);

private:
  list<E> l;
  C isLess;

};

template <typename E, typename C>
int ListPriorityQueue<E,C>::size() const{
  return l.size();
}

template <typename E, typename C>
bool ListPriorityQueue<E,C>::empty() const{
  return l.empty();
}

template <typename E, typename C>
void ListPriorityQueue<E,C>::insert(const E& e){
  list<E>::iterator p = l.begin();

  while(p != l.end() && !isLess(e, *p)){
    ++p;
  }

  l.insert(p, e);
}

template <typename E, typename C>
void ListPriorityQueue<E,C>::removeMin(){
  l.pop_front();
}

template <typename E, typename C>
const E& ListPriorityQueue<E,C>::min() const{
  return l.front();
}

#endif

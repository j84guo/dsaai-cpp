#ifndef HASHDICT_H
#define HASHDICT_H

#include "HashMap.h"

template <typename K, typename V, typename H>
class HashDict : public HashMap<K,V,H> {

public:
  typedef typename HashMap<K,V,H>::Iterator Iterator;
  typedef typename HashMap<K,V,H>::Entry Entry;

  class Range{

  private:
    Iterator _begin;
    Iterator _end;

  public:
    Range(const Iterator& _begin, const Iterator& _end):
      _begin(_begin), _end(_end){
    }

    Iterator& begin(){
      return _begin;
    }

    Iterator& end(){
      return _end;
    }
  };

  HashDict(int capacity = 101);
  Range findAll(const K& k);
  Iterator insert(const K& k, const V& v);

};

template <typename K, typename V, typename H>
HashDict<K,V,H>::HashDict(int capacity):
  HashMap<K,V,H>(capacity){

}

template <typename K, typename V, typename H>
typename HashDict<K,V,H>::Iterator
HashDict<K,V,H>::insert(const K& k, const V& v){
  Iterator p = this->finder(k);
  Iterator q = this->inserter(p, Entry(k, v));

  return q;
}

template <typename K, typename V, typename H>
typename HashDict<K,V,H>::Range
HashDict<K,V,H>::findAll(const K& k){
  Iterator a = this->finder(k);

  Iterator p = a;
  while(!this->endOfBucket(p) && p.entry->first == k){
    ++p;
  }

  return Range(a, p);
}

#endif

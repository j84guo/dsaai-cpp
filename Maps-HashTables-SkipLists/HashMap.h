#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <utility>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::pair;
using std::list;
using std::vector;

template <typename K, typename V, typename H>
class HashMap{

public:
  typedef pair<const K, V> Entry; // Entry is a public type

  /*
  * forward declare Iterator so that the public methods can refer to it
  */
  class Iterator;

  HashMap(int capacity=100);
  int size() const;
  bool empty() const;

  Iterator find(const K& k);
  Iterator put(const K& k, const V& v); // vector makes a copy of our reference

  void erase(const K& k);
  void erase(const Iterator& p);

  Iterator begin();
  Iterator end();

protected:
  typedef list<Entry> Bucket;
  typedef vector<Bucket> BucketArray;

  typedef typename Bucket::iterator ElementIt;
  typedef typename BucketArray::iterator BucketIt;

  Iterator finder(const K& k); // find an Entry with key k
  Iterator inserter(const Iterator& p, const Entry& e); // insert prior to p

  void eraser(const Iterator& p);

  // increment list (element) iterator
  static void nextEntry(Iterator& p){ ++p.entry; }

  // end of current list (bucket)
  static bool endOfBucket(const Iterator& p){ return p.entry == p.bucket->end(); }

private:
  int n;
  H hash; // hash function returning int
  BucketArray A;

public:
  class Iterator{

  public:
    Iterator(const BucketArray& A, const BucketIt& bucket, const ElementIt& entry=ElementIt()):
      entry(entry), bucket(bucket), A(&A){
    }

    bool operator==(const Iterator& p) const;
    Iterator& operator++();

    /*
    * although the Entry (pair) object itself may change, the Iterator obect will not
    */
    Entry& operator*() const;
    Entry* operator->() const;

    K key(){ return entry->first; }
    V value(){ return entry->second; }

    friend class HashMap; // allow HashMap to access out private members

  private:
    ElementIt entry; // the iterator is public but the entry object is not, access it via * operator
    BucketIt bucket;

    const BucketArray* A;
  };

};

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Entry&
HashMap<K,V,H>::Iterator::operator*() const{
  return *entry;
}

/*
* When overloading ->, we change the pointer to which built-in -> is applied,
* but the built-in -> is still applied to whatever we return, therefore we
* return a pointer to the Entry.
*/
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Entry*
HashMap<K,V,H>::Iterator::operator->() const{
  return &(*entry);
}

template <typename K, typename V, typename H>
bool
HashMap<K,V,H>::Iterator::operator==(const Iterator& p) const{

  // same bucket array and bucket
  if(A != p.A || bucket != p.bucket){
    return false;
  }

  // check end of bucket, this takes precedence over the entry values
  if(bucket == A->end()){
    return true;
  }

  // finally compare pairs
  return entry == p.entry;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator&
HashMap<K,V,H>::Iterator::operator++(){

  // increment element iterator
  ++entry;

  // if at the end of this bucket, find the next non-empty bucket
  if(endOfBucket(*this)){
    ++bucket;

    while(bucket != A->end() && bucket->empty()){
      ++bucket;
    }

    if(bucket == A->end()){
      return *this;
    }

    entry = bucket->begin();
  }

  return *this;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator
HashMap<K,V,H>::end(){
  return Iterator(A, A.end());
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator
HashMap<K,V,H>::begin(){

  if(empty()){
    return end();
  }

  BucketIt it = A.begin();
  while(it->empty()){
    ++it;
  }

  return Iterator(A, it, it->begin());
}

template <typename K, typename V, typename H>
HashMap<K,V,H>::HashMap(int capacity):
  n(0), A(capacity){
}

template <typename K, typename V, typename H>
int
HashMap<K,V,H>::size() const{
  return n;
}

template <typename K, typename V, typename H>
bool
HashMap<K,V,H>::empty() const{
  return size() == 0;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator
HashMap<K,V,H>::finder(const K& k){

  int i = hash(k) % A.size();
  BucketIt bucket = A.begin() + i;
  Iterator p(A, bucket, bucket->begin());

  while(!endOfBucket(p) && (*p).first != k){
    nextEntry(p);
  }

  return p;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator
HashMap<K,V,H>::find(const K& k){
  Iterator p = finder(k);

  if(endOfBucket(p)){
    return end();
  }

  return p;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator
HashMap<K,V,H>::inserter(const Iterator& p, const Entry& e){

  ElementIt it = p.bucket->insert(p.entry, e);
  ++n;

  return Iterator(A, p.bucket, it);
}

/*
* tries to update an existing entry, else inserts a new one
*/
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator
HashMap<K,V,H>::put(const K& k, const V& v){
  Iterator p = finder(k);

  if(endOfBucket(p)){
    return inserter(p, Entry(k, v));
  }

  p.entry->second = v;
  return p;
}

template <typename K, typename V, typename H>
void
HashMap<K,V,H>::eraser(const Iterator& p){
  p.bucket->erase(p.entry);
  --n;
}

template <typename K, typename V, typename H>
void
HashMap<K,V,H>::erase(const Iterator& p){
  eraser(p);
}

template <typename K, typename V, typename H>
void
HashMap<K,V,H>::erase(const K& k){

  Iterator p = finder(k);

  if(endOfBucket(p)){
    return;
  }

  eraser(p);
}

#endif

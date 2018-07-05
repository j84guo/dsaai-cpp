#ifndef HASHMAP_H
#define HASHMAP_H

#include <list>
#include <stdexcept>

using std::cout;
using std::endl;
using std::list;
using std::runtime_error;

/*
* Hashtable implementation of a map.
*
* Uses separate chaining, with a given (preferably prime) array size.
*
* K - key type
* V - value type
* H - hash function which outputs an integer
*
* Todo :
* When the load factor increases beyond a certain level, the table should be
* rehashed. Integers should all be positive and the number of buckets should
* be prime.
*/
template <typename K, typename V, typename H>
class HashMap{

protected:
  class Entry{
  public:
    K k;
    V v;
    Entry(K k, V v):
      k(k), v(v){
    }
  };

public:
  HashMap(int numBuckets);
  ~HashMap();

  int getSize() const;
  bool isEmpty() const;

  V get(K k) throw(runtime_error);
  void put(K k, V v);

private:
  int size;
  int numBuckets;
  list<Entry>* A; // elements are default constructed on new
  H hash; // default constructed

};

template <typename K, typename V, typename H>
HashMap<K,V,H>::HashMap(int numBuckets):
numBuckets(numBuckets), size(0), A(new list<Entry>[numBuckets]){
}

template <typename K, typename V, typename H>
HashMap<K,V,H>::~HashMap(){
  if(A != nullptr){
    delete[] A;
  }
}

template <typename K, typename V, typename H>
int HashMap<K,V,H>::getSize() const{
  return size;
}

template <typename K, typename V, typename H>
bool HashMap<K,V,H>::isEmpty() const{
  return size == 0;
}

template <typename K, typename V, typename H>
V HashMap<K,V,H>::get(K k) throw(runtime_error){
  if(isEmpty()){
    throw runtime_error("HashMap is empty.");
  }

  int i = hash(k) % numBuckets;

  list<Entry> &bucket = A[i];
  typename list<Entry>::iterator it = bucket.begin(); // nested class depends on template parameter which itself is templated

  while(it != bucket.end() && it->k != k){
    ++it;
  }

  if(it == bucket.end()){
    throw runtime_error("Key does not exist.");
  }else{
    return it->v;
  }
}

template <typename K, typename V, typename H>
void HashMap<K,V,H>::put(K k, V v){
  int i = hash(k) % numBuckets;

  list<Entry> &bucket = A[i];

  bucket.push_back(
    Entry(k, v)
  );

  ++size;
}

#endif

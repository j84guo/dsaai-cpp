#ifndef ARRAY_VECTOR_H
#define ARRAY_VECTOR_H

#include <algorithm>
#include <stdexcept>
#include <iostream>

using std::max;
using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class ArrayVector{

public:

  /*
  * other house keeping methods include :
  * copy constructor, assignment operator, arithmetic operators, output operator
  */
  ArrayVector();
  ~ArrayVector();

  int getSize() const;
  int getCapacity() const;
  bool empty() const;

  E& operator[](int i);
  E& at(int i) throw(runtime_error);

  void erase(int i) throw(runtime_error);
  void insert(int i, const E& data);
  void reserve(int n);

private:
  int capacity;
  int size;
  E* arr;

};

template <typename E>
void ArrayVector<E>::erase(int i) throw(runtime_error){
  if(i < 0 || i >= size){
    throw runtime_error("Index out of bounds.");
  }

  for(int j=i+1; j<size; ++j){
    arr[j-1] = arr[j];
  }

  --size;
}

template <typename E>
void ArrayVector<E>::insert(int i, const E& data){
  if(size == capacity){
    reserve(max(1, 2 * capacity));
  }

  for(int j=size-1; j>=i; --j){
    arr[j+1] = arr[j];
  }

  arr[i] = data;
  ++size;
}

template <typename E>
void ArrayVector<E>::reserve(int n){
  if(n <= capacity){
    return;
  }

  E* tmp = new E[n];
  for(int i=0; i<size; i++){
    tmp[i] = arr[i];
  }

  if(arr == nullptr){
    delete[] arr;
  }

  arr = tmp;
  capacity = n;
}

/*
* this operator is a member
* returns an element by reference, which means we can use the operator to assign and read
* DANGER : index is not checked, so arbitrary memory access may occur
*/
template <typename E>
E& ArrayVector<E>::operator[](int i){
  cout << "accessing " << i << endl;
  return arr[i];
}

template <typename E>
E& ArrayVector<E>::at(int i) throw (runtime_error){
  if(i < 0 || i >= size){
    throw runtime_error("Index out of bounds.");
  }
  return arr[i];
}

template <typename E>
int ArrayVector<E>::getSize() const{
  return size;
}

template <typename E>
int ArrayVector<E>::getCapacity() const{
  return capacity;
}

template <typename E>
bool ArrayVector<E>::empty() const{
  return size == 0;
}

template <typename E>
ArrayVector<E>::ArrayVector():
  capacity(0),
  size(0),
  arr(nullptr){
}

template <typename E>
ArrayVector<E>::~ArrayVector(){
  if(arr != nullptr){
    delete[] arr;
  }
}

#endif

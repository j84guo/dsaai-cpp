#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <stdexcept>

using std::runtime_error;

template <typename E>
class ArrayStack{

public:
  ArrayStack(int capacity) throw(runtime_error);
  ~ArrayStack();

  void push(const E& data) throw(runtime_error);
  E pop() throw(runtime_error);
  E peek() const throw(runtime_error);

  int getSize() const;
  int getCapacity() const;

private:
  E* arr;
  int t;
  int capacity;
};

/*
* front indicates the oldest item
* rear indicates one after the the newest item
*/
template <typename E>
ArrayStack<E>::ArrayStack(int capacity) throw(runtime_error):
  t(-1){

  if(capacity <= 0){
    throw runtime_error("Invalid capacity.");
  }

  this->capacity = capacity;
  this->arr = new E[capacity];
}

template <typename E>
void ArrayStack<E>::push(const E& data) throw(runtime_error){
  if(t == capacity-1){
    throw runtime_error("Stack full.");
  }

  arr[++t] = data;
}

template <typename E>
E ArrayStack<E>::pop() throw(runtime_error){
  if(t == -1){
    throw runtime_error("Stack empty.");
  }

  E data = arr[t--];
  return data;
}

template <typename E>
E ArrayStack<E>::peek() const throw(runtime_error){
  if(t == capacity-1){
    throw runtime_error("Stack empty.");
  }

  return arr[t];
}

template <typename E>
ArrayStack<E>::~ArrayStack(){
  delete[] arr;
}

template <typename E>
int ArrayStack<E>::getSize() const{
  return t+1;
}

template <typename E>
int ArrayStack<E>::getCapacity() const{
  return capacity;
}

#endif

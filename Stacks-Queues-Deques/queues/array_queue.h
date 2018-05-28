#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <stdexcept>

using std::runtime_error;

template <typename E>
class ArrayQueue{

public:
  ArrayQueue(int capacity) throw(runtime_error);
  ~ArrayQueue();

  void enqueue(const E& data) throw(runtime_error);
  E dequeue() throw(runtime_error);
  E peek() const throw(runtime_error);

  int getSize() const;
  int getCapacity() const;

private:
  E* arr;
  int front;
  int rear;
  int size;
  int capacity;
};

/*
* front indicates the oldest item
* rear indicates one after the the newest item
*/
template <typename E>
ArrayQueue<E>::ArrayQueue(int capacity) throw(runtime_error):
  size(0),
  front(0),
  rear(0){

  if(capacity <= 0){
    throw runtime_error("Invalid capacity.");
  }

  this->capacity = capacity;
  this->arr = new E[capacity+1];
}

template <typename E>
void ArrayQueue<E>::enqueue(const E& data) throw(runtime_error){
  if((rear + 1) % (capacity + 1) == front){
    throw runtime_error("Queue full.");
  }

  arr[rear] = data;
  rear = (rear + 1) % (capacity + 1);
  ++size;
}

template <typename E>
E ArrayQueue<E>::dequeue() throw(runtime_error){
  if(front == rear){
    throw runtime_error("Queue empty.");
  }

  E data = arr[front];
  front = (front + 1) % (capacity + 1);
  --size;

  return data;
}

template <typename E>
E ArrayQueue<E>::peek() const throw(runtime_error){
  if(front == rear){
    throw runtime_error("Queue empty.");
  }

  return arr[front];
}

template <typename E>
ArrayQueue<E>::~ArrayQueue(){
  delete[] arr;
}

template <typename E>
int ArrayQueue<E>::getSize() const{
  return size;
}

template <typename E>
int ArrayQueue<E>::getCapacity() const{
  return capacity;
}

#endif

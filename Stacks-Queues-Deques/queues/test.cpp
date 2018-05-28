#include <iostream>
#include <string>
// #include "array_queue.h"
#include "linked_queue.h"

using std::cout;
using std::endl;
using std::string;

int main(){
  // ArrayQueue<string> q(4);
  //
  // cout << "Size: " << q.getSize() << endl;
  // cout << "Capacity: " << q.getCapacity() << endl;
  //
  // q.enqueue("a");
  // cout << "Peek: " << q.peek() << endl;
  // cout << "Size: " << q.getSize() << endl;
  //
  // q.enqueue("b");
  // cout << "Peek: " << q.peek() << endl;
  // cout << "Size: " << q.getSize() << endl;
  //
  // q.enqueue("c");
  // cout << "Peek: " << q.peek() << endl;
  // cout << "Size: " << q.getSize() << endl;
  //
  // q.enqueue("d");
  // cout << "Peek: " << q.peek() << endl;
  // cout << "Size: " << q.getSize() << endl;
  //
  // q.dequeue();
  // cout << "Peek: " << q.peek() << endl;
  // cout << "Size: " << q.getSize() << endl;
  //
  // q.dequeue();
  // cout << "Peek: " << q.peek() << endl;
  // cout << "Size: " << q.getSize() << endl;

  LinkedQueue<string> q;

  q.enqueue("a");
  q.enqueue("b");
  q.enqueue("c");

  cout << q.peek() << endl;
  cout << q.dequeue() << endl;

  cout << q.peek() << endl;
  cout << q.dequeue() << endl;

  cout << q.peek() << endl;
  cout << q.dequeue() << endl;

  cout << q.getSize() << endl;
}

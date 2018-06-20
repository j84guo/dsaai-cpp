#include <iostream>
#include <list>

using std::endl;
using std::cout;
using std::list;

int main(){

  /*
  * doubly linked list which provides access to front and back nodes
  * can be used to implement stacks and queues
  * analogous to Java's java.util.LinkedList;
  */
  list<double> l;

  l.push_back(1.5);
  l.push_back(2.5);
  l.push_back(3.5);
  l.push_back(4.5);
  l.push_front(0.5);
  cout << l.size() << endl;

  l.pop_front();
  l.pop_back();
  cout << l.front() << endl;
  cout << l.back() << endl;
}

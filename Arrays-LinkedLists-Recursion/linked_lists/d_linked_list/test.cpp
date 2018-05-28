#include <iostream>
#include <string>
#include "d_linked_list.h"

using std::cout;
using std::endl;
using std::string;

int main(){
  DLinkedList<string> list;

  list.addFirst("a");
  list.addLast("z");

  cout << list.removeLast() << endl;
  cout << list.removeFirst() << endl;
}

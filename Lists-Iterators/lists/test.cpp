#include <iostream>
#include "node_list.h"
#include "node_sequence.h"

using std::cout;
using std::endl;

int main(){
  // NodeList<int> l;
  //
  // l.insertBack(1);
  // l.insertBack(2);
  // l.insertBack(3);
  // l.insertBack(4);
  // l.insertBack(5);
  //
  // // cout << l.size() << endl;
  // // cout << *(l.begin()) << endl;
  // // cout << *(--l.end()) << endl;
  //
  // NodeList<int>::Iterator it = l.begin();
  // while(it != l.end()){
  //   // (*it) = 10; // technically the object can still be modified
  //   cout << *it << endl;
  //   ++it;
  // }

  NodeSequence<int> s;
  s.insertBack(1);
  s.insertBack(2);
  s.insertBack(3);
  s.insertBack(4);
  s.insertBack(5);

  cout << s.atIndex(2) << endl;
  cout << s.indexOf(s.end()) << endl;
}

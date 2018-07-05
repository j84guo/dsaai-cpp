#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

void printList(list<int>& l);

int main(){
  list<int> l{1, 2, 3, 4, 5};

  list<int>::iterator a = l.insert(l.end(), 101);
  l.insert(a, 201);

  printList(l);

  l.erase(a);

  printList(l);

  list<int> l2;
  cout << ( l2.begin() == l2.end() ) << endl;
}

void printList(list<int>& l){
  list<int>::iterator it = l.begin();

  while(it != l.end()){
    cout << *it << " ";
    ++it;
  }

  cout << endl;
}

#include <iostream>
#include "MinHeap.h"

using namespace std;

struct IntLessThan{
  bool operator()(int a, int b){
    return a < b;
  }
};

struct MyStruct{
  int x;
};

int main(){
  MinHeap<int, IntLessThan> h;
  h.insert(10);
  h.insert(5);
  h.insert(2);
  h.insert(13);
  h.insert(21);
  h.insert(120);

  while(h.size() > 0){
    cout << h.min() << endl;
    h.removeMin();
  }

  MyStruct s;
  s.x = 10;

  // MyStruct* p = &s;
  // cout << (*p).x << endl;
  // cout << p->x << endl;
}

#include <iostream>
#include "HashMap.h"

using namespace std;

class A{

public:

  int arr[3];

  A(){
    // sizeof correctly determines the array size
    cout << sizeof arr << endl;

    // the array is uninitialized
    for(int i=0; i<3; ++i){
      cout << arr[i] << " ";
    }
    cout << endl;
  }

};

class HashInt{

public:
  int operator()(int i){
    return i;
  }

};

int main(){
  HashMap<int, int, HashInt> h(7);

  h.put(1, 1);
  cout << h.get(1) << endl;

  h.put(8, 8);
  cout << h.get(8) << endl;

  h.put(15, 15);
  cout << h.get(15) << endl;
}

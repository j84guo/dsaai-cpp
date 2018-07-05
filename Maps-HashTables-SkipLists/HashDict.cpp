#include <iostream>
#include "HashDict.h"

using namespace std;

struct HashInt{
  int operator()(int x){
    return x;
  }
};

int main(){

  HashDict<int, int, HashInt> d;

  d.insert(1, 1);
  d.insert(1, 2);
  d.insert(1, 3);

  HashDict<int, int, HashInt>::Range r = d.findAll(1);
  cout << r.begin().entry->second << endl;
}

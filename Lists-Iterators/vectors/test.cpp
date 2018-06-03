#include <iostream>

#include "array_vector.h"

using std::cout;
using std::endl;

int main(){
  ArrayVector<double> v;

  v.insert(0, 10);

  v[0] = 100;
  cout << v[0] << endl;

  v.insert(1, 101);
  cout << v[1] << endl;

  cout << v[200] << endl;

  cout << v.getSize() << endl;
  cout << v.getCapacity() << endl;
}

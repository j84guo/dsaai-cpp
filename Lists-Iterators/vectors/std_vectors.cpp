#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(){

  /*
  * extendable array providing constant time access to elements
  * analogous to Java's java.util.ArrayList
  */
  vector<int> v;

  v.push_back(3);
  v.push_back(4);

  v.reserve(100);

  cout << v.size() << endl;
  cout << v.empty() << endl;

  cout << v[0] << endl;
  cout << v.at(1) << endl;

  v.insert(v.begin(), 2);
  v.insert(v.begin(), 1);

  cout << v[0] << endl;
  cout << v.at(1) << endl;

  v.pop_back();

  cout << v.size() << endl;
  cout << v[2] << endl;
  cout << v.at(2) << endl;
}

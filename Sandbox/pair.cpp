#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::pair;
using std::make_pair;

int main(){
  pair<int, int> a(1, 2);
  pair<int, int> b;

  b = make_pair<int, int>(1, 2);
  a.first = 10;
  b.first = 10;

  cout << a.first << " " << a.second << endl;
  cout << b.first << " " << b.second << endl;

  /*
  * pair has overloaded the equality operator to compare the elements of the
  * two pairs with each other
  */
  cout << (a == b) << endl;
}

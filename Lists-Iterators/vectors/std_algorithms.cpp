#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::sort;
using std::time;
using std::vector;
using std::random_shuffle;

int main(){

  int a[] = {17, 12, 33, 15, 62, 45};
  vector<int> v(a, a+6);

  cout << v.size() << endl;
  v.pop_back();
  cout << v.size() << endl;

  v.push_back(19);
  cout << v.front() << " " << v.back() << endl;

  sort(v.begin(), v.begin() + 4);
  cout << v.front() << " " << v.back() << endl;

  v.erase(v.end()-4, v.end()-2);
  cout << v.size() << endl;

  char b[] = {'b', 'r', 'a', 'v', 'o'};
  vector<char> w(b, b+5);

  // relies on a system defined souce of randomeness, need to seed srand with an initial value
  random_shuffle(w.begin(), w.end());
  w.insert(w.begin(), 's');

  for(vector<char>::iterator p = w.begin(); p != w.end(); ++p){
    cout << *p << endl;
  }

  return 0;
}

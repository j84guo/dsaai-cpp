#include "SkipNode.h"
#include "SkipList.h"

#include <iostream>

using std::cout;
using std::endl;

class IntComparator
{

public:
  int operator()(int a, int b) const
  {
    return a - b;
  }

};

int main()
{
  SkipList<int, int, IntComparator> sl;

  sl.put(10, 10);
  sl.put(11, 11);
  sl.put(12, 12);
  sl.put(13, 13);
  sl.put(14, 14);

  cout << sl.containsKey(10) << endl;
  cout << sl.containsKey(11) << endl;
  cout << sl.containsKey(12) << endl;
  cout << sl.containsKey(13) << endl;
  cout << sl.containsKey(14) << endl;

  cout << sl.containsKey(0) << endl;
  cout << sl.containsKey(1) << endl;
  cout << sl.containsKey(2) << endl;
  cout << sl.containsKey(3) << endl;
  cout << sl.containsKey(4) << endl;

  cout << sl.get(10) << endl;
  cout << sl.get(11) << endl;
  cout << sl.get(12) << endl;
  cout << sl.get(13) << endl;
  cout << sl.get(14) << endl;

  cout << sl;

  sl.erase(10);
  sl.erase(11);
  sl.erase(12);
  sl.erase(13);
  sl.erase(14);

  cout << sl;
}

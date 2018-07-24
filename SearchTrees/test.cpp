#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

class IntComparator
{

public:
  int operator()(int a, int b)
  {
    return a - b;
  }

};

int main()
{
  BinarySearchTree<int, int, IntComparator> t;
  t.add(10, 10);
  t.add(5, 5);
  t.add(15, 15);

  cout << t.get(10) << endl;
  cout << t.get(5) << endl;
  cout << t.get(15) << endl;

  t.printInOrder();

  t.erase(5);
  t.printInOrder();

  t.erase(10);
  t.printInOrder();

  t.erase(15);
  t.printInOrder();

  cout << t.getSize() << endl;
}

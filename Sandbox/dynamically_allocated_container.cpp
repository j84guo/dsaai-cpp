#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

struct Node
{
  int data;
};

void addNodes(unordered_map<int, Node>* m)
{
  Node a; a.data = 0;
  Node b; b.data = 1;
  Node c; c.data = 2;

  (*m)[0] = a;
  (*m)[1] = b;
  (*m)[2] = c;
}

int main()
{
  unordered_map<int, Node>* m = new unordered_map<int, Node>;

  addNodes(m);
  cout << (*m)[0].data << endl;
}

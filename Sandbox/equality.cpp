#include <iostream>

using namespace std;

struct A{
  int x;

  bool operator==(A a){
    return x == a.x;
  }
};

int main(){

  A a1;
  a1.x = 10;

  A a2;
  a2.x = 15;

  // if there is no equality operator defined for A, this statement is a
  // compiler error
  cout << (a1 == a2) << endl;

  A *p1 = &a1;
  A *p2 = &a1;

  // pointer comparison compares their addresses, so this statement is true
  cout << (p1 == p2) << endl;
}

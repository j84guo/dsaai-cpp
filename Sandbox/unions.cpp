#include <iostream>

using namespace std;

union RecordType
{
  char c;
  int i;
  long l;
  float f;
  double d;
  int *pi;
};

int main()
{
  RecordType u;

  // holds an integer
  u.i = 5;

  // holds a float
  u.f = 7.12;

  // union stores a float
  cout << u.f << endl;

  // garbage data by interpreting the object's data as a byte
  cout << (int) u.c << endl;
}

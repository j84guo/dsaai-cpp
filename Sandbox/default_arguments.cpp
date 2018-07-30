#include <iostream>

using namespace std;

void display(char c = '*', int n = 1);

int main()
{
  cout << "no arguments passed" << endl;
  display();

  cout << "passed first argument" << endl;
  display('a');

  cout << "passed both arguments" << endl;
  display('b', 10);
}

void display(char c, int n)
{
  for(int i=0; i<n; ++i)
    cout << c;

  cout << endl;
}

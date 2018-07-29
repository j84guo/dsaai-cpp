#include <climits>
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
* getline() can be used without std:: via argument dependent lookup
* https://stackoverflow.com/questions/31598707/why-can-i-call-getline-without-using-stdgetline
*/
int main()
{
  string s;
  string t;

  getline(cin, s);
  cout << s << endl;

  getline(cin, t);
  cout << t << endl;
  
  cout << LINE_MAX << endl;
}

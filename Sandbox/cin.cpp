/*
* text input generally falls into 4 categories:
*
* 1) extraction succeeds but the input is invalid, e.g. entering 'q' where a
*    '*' is expected
* 2) extraction succeeds but the user entered additional input, e.g. "qasd"
*    where just 'q' was expected
* 3) extraction fails, e.g. entering 'q' where an integer is expected
* 4) extraction succeeds but the used overflows a numeric value
*/

#include <climits>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
* todo: handle EOF
*/
double getDouble()
{
  while(1)
  {
    double d;
    cout << "Enter a double: ";

    /*
    * the extraction operator attempts to read data from a user space buffer
    * and convert it to the specified variable, >> attempts to use all data up
    * to whitespace (' ', '\t', '\n') or up to the first byte of invalid type
    */
    cin >> d;

    /*
    * fail() is true when the extraction had incorrect type or numeric overflow
    * - clear error flags
    * - ignore extra input
    * - prompt again
    *
    * note that clear() must be called before ignore(), since ignore() returns
    * without extracting bytes when the stream is in a fail state, causing an
    * infinite loop
    */
    if(cin.fail())
    {
      /*
      * note that clear() does not reset eof bit for the stdin stream
      */
      cin.clear();
      cin.ignore(LINE_MAX, '\n');
      cout << "cin: invalid double\n";
    }
    else
    {
      cin.ignore(LINE_MAX, '\n');
      return d;
    }
  }
}

char getOperator()
{
  while(1)
  {
    char c;
    cout << "Enter +, -, * or /: ";
    cin >> c;

    cin.ignore(LINE_MAX, '\n');

    if(c == '+' || c == '-' || c == '*' || c == '/')
      return c;
    else
      cout << "cin: invalid char\n";
  }
}

void printResult(double a, char c, double b)
{
  if(c == '+')
    cout << (a + b) << endl;
  else if(c == '-')
    cout << (a - b) << endl;
  else if(c == '*')
    cout << (a * b) << endl;
  else if(c == '/')
    cout << (a / b) << endl;
  else
    cout << "printResult: invalid operator\n";
}

int main()
{
  double a = getDouble();
  char c = getOperator();
  double b = getDouble();

  printResult(a, c, b);
}

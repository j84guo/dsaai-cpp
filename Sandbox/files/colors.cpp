#include <iostream>
#include <string>

using namespace std;

/** Escape codes for colors are supported by essentially all shells. */
const string  ANSI_RED = "\x1b[31m";
const string  ANSI_GREEN = "\x1b[32m";
const string  ANSI_YELLOW = "\x1b[33m";
const string  ANSI_BLUE = "\x1b[34m";
const string  ANSI_MAGENTA ="\x1b[35m";
const string  ANSI_CYAN = "\x1b[36m";
const string  ANSI_RESET = "\x1b[0m";

int main (int argc, char **argv)
{
    cout << ANSI_RED << "This text is RED!" << ANSI_RESET << endl;
    cout << ANSI_GREEN << "This text is GREEN!" << ANSI_RESET << endl;
    cout << ANSI_YELLOW << "This text is YELLOW!" << ANSI_RESET << endl;
    cout << ANSI_BLUE << "This text is BLUE!" << ANSI_RESET << endl;
    cout << ANSI_MAGENTA << "This text is MAGENTA!" << ANSI_RESET << endl;
    cout << ANSI_CYAN << "This text is CYAN!" << ANSI_RESET << endl;

    return 0;
}

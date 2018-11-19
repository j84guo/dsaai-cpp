#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * @summary
 * In C++, opening and reading a file is pretty easy. We use the std::ifstream
 * class, which stands for input file stream. There are several constructors
 * for this class, the simplest accepts a std::string representing the path.
 * The constructor OPENS the file and the destructor (called when we leave the
 * function) will CLOSE the file, another example of RAII!
 *
 * e.g. ifstream file(path);
 *
 * I/O streams in C++ have two useful functions: fail() and bad().
 *
 * fail() reports two things: EOF (all data has been read) and logical errors
 * (invalid file name, trying to read words into an int)
 *
 * bad() reports I/O errors; there are various causes but most are bad
 *
 * Lastly, the std::getline function (don't be confused, the std::ifstream
 * class has a method of the same name called std::ifstream::getline, but the
 * std::getline function is easier to use) reads one line of char's from the
 * stream, discarding the '/', and stores them in a string.
 *
 * std::getline() returns true until either
 * 1) EOF is reached
 * 2) An I/O error occurs (which we check by calling ifstream::bad)
 */
void read_demo(const string &path)
{
    ifstream file(path);
    if (file.fail()) {
        cerr << "Could not open file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    if (file.bad()) {
        cerr << "An I/O error occurred!" << endl;
    }
}

int main()
{
    string path("files/hemmingway.txt");
    cout << "Reading file: " << path << endl;

    /**
     * If you look at the signature of read_demo, you'll notice we pass the
     * string by const reference. This means
     *
     * 1) The function may not modify the string
     * 2) A reference to our local variable path is passed, it is not copied
     *
     * In general, your function should accept arguments as const when it does
     * not need to (or may not) modify the arguments. This also informs readers
     * of your code's intentions, i.e. that the argument should be immutable.
     *
     * In general, your function should accept arguments as references when the
     * changes made by the function need to be visible to the caller (so simply
     * passing a COPY wouldn't work) and/or copying the object for the function
     * may be expensive.
     */
    read_demo(path);
}

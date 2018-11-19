#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * Similar to cout, writing to a file is as easy as:
 * file << "some stuff to write"
 *
 * Notice we check that the output file coult be opened. To see when errors
 * occur, try passing in the name of a directory.
 *
 * @extra:
 * By default, ofstream opens the file and overwrites contents if it already
 * exists. You can open in append mode like this:
 *
 * ofstream file(path, ios::app); // app -> append to file
 *
 * Where std::ios is a class and ios::app is a static variable of ios (lol)
 */
void write_demo(const string& path, const string& data)
{
    ofstream file;
    file.exceptions(ofstream::badbit | ofstream::failbit);
    file.open(path, ios::app);

    /**
     * I'm a little bit unsure how necessary it is to check for errors on
     * read/write, for now let's just write and prentend everything went ok
     * (which usually is true).
     *
     * https://stackoverflow.com/questions/4802494/do-i-need-to-close-a-stdfstream
     */
    file << data;
    file.close();

    if (file.fail()) {
        cerr << "Error writing file!" << endl;
    }
}

/** recall argv is an array of char pointers, also valid is char **argv */
int main(int argc, char *argv[])
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <output_path>" << endl;
        return 1;
    }

    /** each element int argc is 8 bytes, the size of a pointer */
    cout << "sizeof(argv[0]): " << sizeof(argv[0]) << endl;

    /** std::string has a constructor which accepts a char * (C-style string) */
    string path(argv[1]);

    /** read one line from stdin, or use a default if user presses ctrl-D */
    string data;
    cout << "Enter a line to write:\n";
    if (!getline(cin, data)) {
        cout << "No user input, using default data\n";
        data = "Udon says he he";
    }

    try {
        write_demo(path, data);
    } catch (ofstream::failure& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}

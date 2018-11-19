#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void write_demo(const string& path, const string& data)
{
    ofstream file;
    file.open(path, ios::app);

    file << data;
    file.close();

    if (file.bad())
        cerr << "Error writing file!" << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <output_path>" << endl;
        return 1;
    }

    string path(argv[1]);
    string data;

    cout << "Enter a line to write:\n";
    if (!getline(cin, data)) {
        cout << "No user input, using default data\n";
        data = "Udon says he he";
    }

    write_demo(path, data);
    return 0;
}

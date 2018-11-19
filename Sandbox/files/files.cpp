/** C++ std library headers */
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <system_error>

/** C std library headers, wrapped in C++ std namespace */
#include <cstdio>
#include <cstring>

/** Old school Unix headers */
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

const string COL_GREEN = "\x1b[32m";
const string COL_CYAN = "\x1b[36m";
const string COL_RESET = "\x1b[0m";

/**
 * @TLDR
 * system_error is an exception which transports an error_code, it requires the
 * integer and category of the code to wrap
 *
 * @Detailed
 * error_code is a platform-specific error object comprising an int and an
 * error_category; the category defines the string representation of the code
 * and maps multiple error_conditions to it; these error conditions may be
 * checked for in portable code
 *
 * class error_category: represents sources, maps codes to conditions
 * class error_code: platform specific (int, category)
 * class error_condition: platform independent (int, category)
 * class system_error: exception used to transport error codes
 * enum class errc: set of error conditions
 * generic_category(), system_category(): category singletons
 * generic_category identifies conditions corresponding to POSIX errno codes
 * https://en.cppreference.com/w/cpp/error/generic_category
 */
void readFile(const string& path, vector<string>& lines)
{
    ifstream file(path);
    if (file.fail()) {
        throw system_error(errno, generic_category());
    }

    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    if (file.bad()) {
        throw system_error(errno, generic_category());
    }
}

void catFile(const string& path)
{
    vector<string> lines;
    try {
        readFile(path, lines);
    } catch (system_error& e) {
        cerr << "readFile: " << e.what() << endl;
        return;
    }

    int width = 0, numLines = lines.size();
    while (numLines > 0) {
        numLines /= 10;
        ++width;
    }
    cout << string(width + 1, ' ') << COL_GREEN << path << COL_RESET << endl;

    int i=0;
    for (const string& line : lines) {
        string num = to_string(i++);
        cout << string(width - num.size(), ' ');
        cout << COL_CYAN << num << COL_RESET << " ";
        cout << line << endl;
    }
}

void walkDir(const string& curDir)
{
    DIR *dir = opendir(curDir.c_str());
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    struct stat info;

    while ((entry = readdir(dir))) {
        string nextPath = curDir + "/" + entry->d_name;
        if (stat(nextPath.c_str(), &info) == -1) {
            perror("stat");
            return;
        }

        if (entry->d_name[0] == '.')
            continue;

        cout << nextPath << endl;

        if (info.st_mode & S_IFDIR)
            walkDir(nextPath);
    }

    closedir(dir);
}

void printUsage(const string& program)
{
    cerr << "Usage " << program << " (-c|-w) <path>\n";
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printUsage(argv[0]);
        return 1;
    }

    string mode(argv[1]);

    if (mode == "-c")
        catFile(argv[2]);
    else if (mode == "-w")
        walkDir(argv[2]);
    else
        printUsage(argv[0]);
}

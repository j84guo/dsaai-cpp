#include <iostream>
#include <vector>
#include <utility>
#include <list>

using namespace std;

int main(){

    // constructs a vector of capacity and size 50 (elements are initialized)
    vector<int> v(50);
    v.pop_back();

    cout << v.size() << endl;
    cout << v.capacity() << endl;
}

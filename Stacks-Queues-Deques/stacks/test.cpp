// #include "linked_stack.h"
#include "array_stack.h"

#include <iostream>

using namespace std;

int main(){
    // LinkedStack<int> s;
    //
    // s.push(1);
    // s.push(2);
    //
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;

    ArrayStack<int> s2(3);
    s2.push(1);
    s2.push(2);
    s2.push(3);
    // s2.push(4);

    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
}

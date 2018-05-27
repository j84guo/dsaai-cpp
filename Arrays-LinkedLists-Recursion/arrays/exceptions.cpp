#include <iostream>

using std::endl;
using std::cout;
using std::runtime_error;

int main(){
  try{
    throw runtime_error("A runtime error occured!");
  }catch(const runtime_error &e){
    cout << "Caught a runtime error." << endl;
  }
}

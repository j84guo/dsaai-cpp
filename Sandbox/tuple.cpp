#include <iostream>
#include <tuple>

using std::cout;
using std::endl;

using std::get;
using std::tuple;
using std::make_tuple;

int main(){
  tuple<int, char> foo(10, 'a');

  // template types to make_tuple can be inferred from function arguments
  auto bar = make_tuple("test", 3.1, 14, 'y');

  cout << get<0>(foo) << " " << get<1>(foo) << endl;
  cout << get<0>(bar) << " " << get<1>(bar) << endl;
}

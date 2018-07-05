#include "HashMap.h"

struct IntHash{
  int operator()(int x){
    return x;
  }
};

int main(){
  HashMap<int, int, IntHash> m;

  m.put(1, 2);
  cout << m.find(1).key() << " " << m.find(1).value() << endl;
  cout << m.find(1)->first << " " <<  m.find(1)->second << endl;
}

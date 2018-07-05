#include <iostream>
#include "AdaptablePq.h"

using namespace std;

struct IntLessThan{
  bool operator()(int a, int b){
    return a < b;
  }
};

int main(){
  typedef typename AdaptablePq<int, IntLessThan>::Position Position;
  AdaptablePq<int, IntLessThan> pq;

  Position a = pq.insert(5);
  Position b = pq.insert(10);
  Position c = pq.insert(1);
  Position d = pq.insert(3);
  Position e = pq.insert(9);

  pq.remove(c);
  pq.remove(d);

  pq.replace(a, 100);
  pq.replace(a, 200);

  while(pq.size() > 0){
    cout << pq.min() << endl;
    pq.removeMin();
  }
}

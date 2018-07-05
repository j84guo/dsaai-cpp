#include <iostream>

using std::cout;
using std::endl;

int cyclicShiftInt(const char* p, int len);
int cyclicShiftFloat(const float& x);

int main(){
  cout << cyclicShiftInt("abcde", 6) << endl;

  float f = 10.5;
  cyclicShiftFloat(f);
}

int cyclicShiftInt(const char* p, int len){
  // use an unsigned int so right shifts fill with zeros
  unsigned int h = 0;

  for(int i=0; i<len; ++i){
    // cyclic shift left by 5 bits
    h = (h << 5) | (h >> 27);

    h += (unsigned int) p[i];
  }

  return (int) h;
}

int cyclicShiftFloat(const float& x){
  int len = sizeof x;

  // interpret float as sequence of bits
  const char* p = reinterpret_cast<const char*>(&x);

  // hash the integer
  return cyclicShiftInt(p, len);
}

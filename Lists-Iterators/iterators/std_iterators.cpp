#include <list>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::list;
using std::vector;

int vectorSumIterator(vector<int> v){
  int sum = 0;

  for(vector<int>::iterator p = v.begin(); p != v.end(); ++p){
    sum += *p;
  }

  return sum;
}

int vectorSumConstIterator(const vector<int> &v){
  int sum = 0;

  for(vector<int>::const_iterator p = v.begin(); p != v.end(); ++p){
    sum += *p;
  }

  return sum;
}


int main(){

  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);

  /*
  * Every std container defines an associated class caled an iterator.
  * An iterator is an object which points to an element in a container and is endowed with the ability to navigate to other positions.
  * If p is an iterator, *p yields the item at the position and ++p yields the next one.
  * Containers also provide two methods, begin() and end(), which return iterators to the first and one past the last item.
  * Iterators can be bidirectional or random access.
  * A non-const iterator doesn't usually work with a const reference container, so read-only iteration can be achieved using a const iterator.
  */
  cout <<  vectorSumConstIterator(v) << endl;
  cout <<  vectorSumIterator(v) << endl;


}

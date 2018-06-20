#include <iostream>
#include <queue>
#include <vector>

using std::ostream;
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

struct Point{
  int x;
  int y;

  Point(int x, int y):
  x(x), y(y){
  }

  friend ostream& operator<<(ostream& out, const Point& p){
    out << "Point x: " << p.x << ", y: " << p.y << endl;
    return out;
  }
};

struct LeftRight{
  bool operator()(const Point& a, const Point& b) const{
    return a.x < b.x;
  }
};

int main(){
  priority_queue<int> p1;
  p1.push(10);
  p1.push(5);
  p1.push(3);
  p1.push(7);
  p1.push(16);
  p1.push(11);

  cout << p1.size() << endl;
  cout << p1.empty() << endl;

  cout << p1.top() << endl;
  p1.pop();
  cout << p1.top() << endl;
  p1.pop();
  cout << p1.top() << endl;

  Point a(2, 3);
  Point b(4, 1);

  LeftRight lr;
  cout << lr(a, b) << endl;

  priority_queue <Point, vector<Point>, LeftRight> p2;
  p2.push(a);
  p2.push(b);
  p2.push(Point(3, 3));
  p2.push(Point(31, 32));

  cout << p2.top();
  cout << p2.size() << endl;
  p2.pop();

  cout << p2.top();
}

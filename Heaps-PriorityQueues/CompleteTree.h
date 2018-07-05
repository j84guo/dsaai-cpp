#ifndef COMPLETE_TREE_H
#define COMPLETE_TREE_H

#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::ostream;

template <typename E>
class CompleteTree{

public:
  typedef typename vector<E>::iterator Position;

  CompleteTree();
  int size() const;

  Position left(const Position& p);
  Position right(const Position &p);
  Position parent(const Position &p);

  bool hasLeft(const Position& p) const;
  bool hasRight(const Position& p) const;
  bool isRoot(const Position& p) const;

  Position root();
  Position last();

  void addLast(const E& e);
  void removeLast();
  void swap(const Position& a, const Position& b);

protected:
  Position pos(int i);
  int idx(const Position& p) const;

private:
  vector<E> V;

  friend ostream& operator<<(ostream& out, const CompleteTree<E>& t){
    out << "CompleteTree: ";
    for(int i=1; i<t.V.size(); ++i){
      out << t.V[i] << " ";
    }
    out << endl;
    return out;
  }
};

template <typename E>
CompleteTree<E>::CompleteTree():
V(1){
}

/*
* typename keyword is requred when using a type in terms of another type
* see dependent types https://stackoverflow.com/questions/1600464/templates-problem-typename-as-not-template-function-parameter
*/
template <typename E>
typename CompleteTree<E>::Position CompleteTree<E>::pos(int i){
  return V.begin() + i;
}

template <typename E>
int CompleteTree<E>::idx(const Position& p) const{
  return p - V.begin();
}

template <typename E>
int CompleteTree<E>::size() const{
  return V.size() - 1;
}

template <typename E>
typename CompleteTree<E>::Position CompleteTree<E>::left(const Position& p){
  return pos(2 * idx(p));
}

template <typename E>
typename CompleteTree<E>::Position CompleteTree<E>::right(const Position& p){
  return pos(2 * idx(p) + 1);
}

template <typename E>
typename CompleteTree<E>::Position CompleteTree<E>::parent(const Position& p){
  return pos(idx(p) / 2);
}

template <typename E>
bool CompleteTree<E>::hasLeft(const Position& p) const{
  return 2 * idx(p) <= size();
}

template <typename E>
bool CompleteTree<E>::hasRight(const Position& p) const {
  return 2 * idx(p) + 1 <= size();
}

template <typename E>
bool CompleteTree<E>::isRoot(const Position& p) const{
  return idx(p) == 1;
}

template <typename E>
typename CompleteTree<E>::Position CompleteTree<E>::root(){
  return pos(1);
}

template <typename E>
typename CompleteTree<E>::Position CompleteTree<E>::last(){
  return pos(size());
}

template <typename E>
void CompleteTree<E>::addLast(const E& e){
  V.push_back(e);
}

template <typename E>
void CompleteTree<E>::removeLast(){
  V.pop_back();
}

template <typename E>
void CompleteTree<E>::swap(const Position& a, const Position& b){
  E tmp = *a;
  *a = *b;
  *b = tmp;
}

#endif

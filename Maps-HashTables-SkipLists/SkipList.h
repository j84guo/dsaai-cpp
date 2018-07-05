#ifndef SKIPLIST_H
#define SKIPLIST_H

#include "SkipNode.h"

#include <cstdlib>
#include <ctime>

using std::runtime_error;
using std::srand;
using std::rand;
using std::time;

template <typename K, typename V, typename C>
class SkipList
{

public:
  SkipList();
  ~SkipList();

  void put(K key, V value);
  void erase(K key) throw(runtime_error);

  bool containsKey(K key);

  V get(K key) throw(runtime_error);

private:
  bool randomBool() const;
  bool lastNodeOnLevel(SkipNode<K,V>* node) const throw(runtime_error);
  bool lessOrEqual(SkipNode<K,V>* a, K key) const;

  void insertAfterAbove(SkipNode<K,V>* a, SkipNode<K,V>* b, K key, V value, int level);
  void eraseSentinel(SkipNode<K,V>* node) throw(runtime_error);
  void initializeEmptyLevel();
  void initializeBaseLevel() throw(runtime_error);
  void newTopLevel() throw(runtime_error);

  SkipNode<K,V>* skipSearch(K key);

  SkipNode<K,V> *start;
  int height;
  C compare; // compares two objects of type K and returns an integer

  template <typename K2, typename V2, typename C2>
  friend ostream& operator<<(ostream& out, const SkipList<K2,V2,C2>& sl);

};

template <typename K2, typename V2, typename C2>
ostream& operator<<(ostream& out, const SkipList<K2,V2,C2>& sl)
{
  for(SkipNode<K2,V2>* level = sl.start; level != nullptr; level = level->down)
  {
    for(SkipNode<K2,V2>* node = level; node != nullptr; node = node->right)
      out << node->key << " ";
    out << endl;
  }

  return out;
}

/*
* todo :
* erase level if last node on a level is removed
* but keep the top and low levels (invariant)
* free node memory
*/
template <typename K, typename V, typename C>
void SkipList<K,V,C>::erase(K key) throw(runtime_error)
{
  SkipNode<K,V>* node = skipSearch(key);

  if(node->smallest || compare(node->key, key) != 0)
    throw runtime_error("Key does not exist.");

  SkipNode<K,V>* upper = nullptr;
  do
  {
    upper = node->up;
    node->left->right = node->right;
    node->right->left = node->left;

    if(lastNodeOnLevel(node) && node->left->down != nullptr)
    {
      cout << "removing an empty level" << endl;
      eraseSentinel(node->left);
      eraseSentinel(node->right);
    }

    delete node;
    node = upper;
  }
  while(upper != nullptr);
}

template <typename K, typename V, typename C>
bool SkipList<K,V,C>::lastNodeOnLevel(SkipNode<K,V>* node) const throw(runtime_error)
{
  if(node == nullptr)
    throw runtime_error("Node is null.");

  return node->left != nullptr && node->right != nullptr
    && node->left->smallest && node->right->largest;
}

template <typename K, typename V, typename C>
void SkipList<K,V,C>::eraseSentinel(SkipNode<K,V>* node) throw(runtime_error)
{
  cout << "called eraseSentinel" << endl;

  if(node == nullptr)
    throw runtime_error("Node is null.");

  if(!node->smallest && !node->largest)
    throw runtime_error("Node is not a sentinel.");

  if(node->up == nullptr || node->down == nullptr)
    throw runtime_error("Node is not a deletable sentinel.");

  node->up->down = node->down;
  node->down->up = node->up;
  delete node;
}

template <typename K, typename V, typename C>
SkipList<K,V,C>::SkipList():
  height(1),
  compare()
{
  initializeEmptyLevel();
  initializeBaseLevel();
  srand(time(0));
}

template <typename K, typename V, typename C>
void SkipList<K,V,C>::initializeEmptyLevel()
{
  start = SkipNode<K,V>::makeSmallest();
  start->right = SkipNode<K,V>::makeLargest();
  start->right->left = start;
}

template <typename K, typename V, typename C>
void SkipList<K,V,C>::initializeBaseLevel() throw(runtime_error)
{
  if(start == nullptr)
    throw runtime_error("Start is a null pointer.");

  // create sentinels
  start->down = SkipNode<K,V>::makeSmallest();
  start->down->right = SkipNode<K,V>::makeLargest();

  // up/down
  start->down->up = start;
  start->down->right->up = start->right;
  start->right->down = start->down->right;

  // left/right
  start->down->right->left = start->down->right;
}

// join positive infinity sentinels
template <typename K, typename V, typename C>
void SkipList<K,V,C>::newTopLevel() throw(runtime_error)
{
  if(start == nullptr)
    throw runtime_error("Start is a null pointer.");

  // create new sentinels
  start->up = SkipNode<K,V>::makeSmallest();
  start->up->right = SkipNode<K,V>::makeLargest();

  // up/down
  start->up->down = start;
  start->up->right->down = start->right;
  start->right->up = start->up->right;

  //left/right
  start->up->right->left = start->up;

  // update start pointer and height
  start = start->up;
  ++height;
}

/*
* delete nodes layer by layer
*/
template <typename K, typename V, typename C>
SkipList<K,V,C>::~SkipList()
{ }

template <typename K, typename V, typename C>
bool SkipList<K,V,C>::randomBool() const
{
  int i = rand() % 2;
  return i == 0;
}

template <typename K, typename V, typename C>
void SkipList<K,V,C>::put(K key, V value)
{
  SkipNode<K,V> *node = skipSearch(key);

  if(node->smallest || compare(node->key, key) != 0)
    insertAfterAbove(node, nullptr, key, value, 0);
  else
    node->value = value;
}

template <typename K, typename V, typename C>
V SkipList<K,V,C>::get(K key) throw(runtime_error)
{
  SkipNode<K,V>* node = skipSearch(key);

  if(compare(node->key, key) == 0)
    return node->value;
  else
    throw runtime_error("Key does not exist.");
}

template <typename K, typename V, typename C>
void SkipList<K,V,C>::insertAfterAbove(SkipNode<K,V>* a, SkipNode<K,V>* b, K key, V value, int level)
{
  cout << "called insertAfterAbove()" << endl;

  if(level == height)
  {
    cout << "extending top level" << endl;
    newTopLevel();
  }

  // new node
  SkipNode<K,V>* node = new SkipNode<K,V>(key, value);

  // rightwards links
  node->right = a->right;
  a->right = node;

  // leftwards links
  node->right->left = node;
  node->left = a;

  // update down and up pointers if b was not nullptr
  if(b != nullptr)
  {
    node->down = b;
    b->up = node;
  }

  // extend upwards with 1/2 probability
  if(randomBool())
  {
    cout << "continue upwards" << endl;

    while(a->up == nullptr)
      a = a->left;

    insertAfterAbove(a->up, node, key, value, level + 1);
  }
}

template <typename K, typename V, typename C>
bool SkipList<K,V,C>::containsKey(K key)
{
  SkipNode<K,V> *node = skipSearch(key);
  return node->smallest ? false : compare(node->key, key) == 0;
}

template <typename K, typename V, typename C>
SkipNode<K,V>* SkipList<K,V,C>::skipSearch(K key)
{
  /*
  * using the invariant that our skiplist always has at least height 1 (empty
  * layer on top of base layer) we can descend immediately and scan forwards
  */
  SkipNode<K,V>* node = start;
  SkipNode<K,V>* it = nullptr;

  do
  {
    node = node->down;

    /*
    * using the invariant that a level always begins with negative infinity and
    * ends with positive inifinity we check that the next element is not
    * positive infinity or <= before moving right
    */
    while(!node->right->largest && lessOrEqual(node->right, key))
      node = node->right;
  }
  while(node->down != nullptr);

  return node;
}

template <typename K, typename V, typename C>
bool SkipList<K,V,C>::lessOrEqual(SkipNode<K,V>* node, K key) const
{
  if(node->smallest)
    return true;

  if(node->largest)
    return false;

  return compare(node->key, key) <= 0;
}

#endif

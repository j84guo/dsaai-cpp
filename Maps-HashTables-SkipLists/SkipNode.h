#ifndef SKIPNODE_H
#define SKIPNODE_H

#include <stdexcept>
#include <iostream>

using std::runtime_error;
using std::ostream;
using std::cout;
using std::endl;

template <typename K, typename V>
class SkipNode
{

public:
  SkipNode(bool smallest, bool largest);
  SkipNode(K key, V value);

  SkipNode<K,V>* left;
  SkipNode<K,V>* right;
  SkipNode<K,V>* up;
  SkipNode<K,V>* down;

  K key;
  V value;

  bool smallest;
  bool largest;

  static SkipNode* makeSmallest();
  static SkipNode* makeLargest();

private:
  template <typename K2, typename V2>
  friend ostream& operator<<(ostream& out, const SkipNode<K2,V2>& node);

};

/*
* leaves key and value default initialized for class types and uninitialized for
* numeric types
*/
template <typename K, typename V>
SkipNode<K,V>::SkipNode(bool smallest, bool largest):
  left(nullptr),
  right(nullptr),
  up(nullptr),
  down(nullptr),
  key(), // value intialization https://stackoverflow.com/questions/11164394/constructor-initialization-list-with-empty-initialization
  value()
{
  if(smallest && largest)
    throw runtime_error("Node cannot be smallest and largest sentinel.");

  this->smallest = smallest;
  this->largest = largest;
}

template <typename K, typename V>
SkipNode<K,V>::SkipNode(K key, V value):
  left(nullptr),
  right(nullptr),
  up(nullptr),
  down(nullptr),
  key(key),
  value(value),
  smallest(false),
  largest(false)
{ }

template <typename K, typename V>
SkipNode<K,V>* SkipNode<K,V>::makeSmallest()
{
  return new SkipNode<K,V>(true, false);
}

template <typename K, typename V>
SkipNode<K,V>* SkipNode<K,V>::makeLargest()
{
  return new SkipNode<K,V>(false, true);
}

template <typename K2, typename V2>
ostream& operator<<(ostream& out, const SkipNode<K2,V2>& node)
{
  out << "<SkipNode object key: " << node.key << ", value: " << node.value;
  out << ", left: " << node.left << ", right: " << node.right
    << ", up: " << node.up << ", down: " << node.down
    << ", smallest: " << node.smallest << ", largest: " << node.largest
    << ">" << endl;
  return out;
}

#endif

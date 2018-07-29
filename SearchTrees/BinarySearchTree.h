#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryTree.h"

/*
* binary search tree
*/
template <typename K, typename V>
class BinarySearchTree
{

public:
  class Iterator;

public:
  BinarySearchTree();

  int size() const;
  bool empty() const;

  Iterator find(const K& k);
  Iterator insert(const K& k, const V& v);
  void erase(const K& k);
  void erase(const Iterator& p);

  Iterator begin();
  Iterator end();

protected:
  class Entry;
  
  typedef BinarySearchTree<K,V> BinaryTree;
  typedef typename BinarySearchTree::Position BtPos;

protected:
  BtPos root() const;
  BtPos finder(const K& k, const BtPos& p);
  BtPos inserter(const K& k, const V& v);
  BtPos eraser(BtPos& p);
  BtPos restructure(const BtPos& p);

private:
  BinaryTree tree;
  int n;

};

/*
* entry in a BST
*/
template <typename K, typename V>
class BinarySearchTree<K,V>::Entry
{

public:
  Entry(const K& k=K(), const V& v=V());
  const K& getKey();
  const V& getValue();
  void setKey(const K& k);
  void setValue(const V& v);

private:
  K key;
  V value;

};

/*
* iterator for a BST
*/
template <typename K, typename V>
class BinarySearchTree<K,V>::Iterator
{

private:
  BtPos p;

  /*
  * since Iterator is nested, it doesn't need to use template arguments when
  * referring to BinarySearchTree
  */
  friend class BinarySearchTree;

public:
  Iterator(const BtPos& p);
  const Entry<K,V>& operator&() const;
  Entry<K,V>& operator();
  bool operator==(const Iterator& p) const;
  Iterator& operator++();

};

#endif

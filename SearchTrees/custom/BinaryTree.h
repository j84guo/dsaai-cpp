#include <list>

using std::list;

/*
* Tree<K,V>::Node:
* - element
* - parent
* - left
* - right
*
* Tree<K,V>::Position:
* - dereference
* - parent()
* - children() // optional
* - left()
* - right()
* - isRoot()
* - isExternal()
* - node
*
* Tree<K,V>:
* - Position, PositionList
* - getSize()
* - isEmpty()
* - addRoot()
* - getRoot()
* - positions()
* - expandExternal()
* - removeAboveExternal()
* - preorder()
* - root
* - size
*/

/*
* binary tree parameterized with an element type E
*/
template <typename E>
class BinaryTree
{

public:
  class Position;
  typedef list<Position> PositionList;

  BinaryTree();
  ~BinaryTree();

  int getSize() const;
  bool isEmpty() const;

  void addRoot();
  void expandExternal(Position p);
  Position removeAboveExternal(Position p);

protected:
  class Node;

  void preOrder(Node *node, PositionList positions) const;

private:
  Node *root;
  int size;

};

/*
* protected nested class of BinaryTree<E>
*/
template <typename E>
class BinaryTree<E>::Node
{

public:
  Node(): element(), left(nullptr), right(nullptr), parent(nullptr) { }
  E element;
  Node *left;
  Node *right;
  Node *parent;

};

/*
* public nested class of BinaryTree<E>
*/
template <typename E>
class BinaryTree<E>::Position
{

public:
   Position(Node *node): node(node) { }
   E& operator*() { return node->element; }
   Position left() { return Position(node->left); }
   Position right() { return Position(node->right); }
   Position parent() { return Position(node->parent); }
   bool isRoot() const { return node->parent == nullptr; }
   bool isExternal() const { return node->left == nullptr && node->right == nullptr; }

private:
  Node *node;
  friend class BinaryTree;

};

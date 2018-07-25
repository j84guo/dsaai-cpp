#ifndef BST_SIMPLE_H
#define BST_SIMPLE_H

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::logic_error;

/*
* K - key type
* V - value type
* C - comparator type which returns an int < == or > 0 based on the relationship
*     between the first and second parameters of its callable operator
*/
template<typename K, typename V, typename C>
class BstSimple
{

public:
  /*
  * the nested class is defined in terms of the enclosing class
  */
  class Node
  {
  private:
    Node(K key, V value, Node *parent):
      key(key),
      value(value),
      left(nullptr),
      right(nullptr),
      parent(parent)
    { }

    K key;
    V value;

    Node *left;
    Node *right;
    Node *parent;

    friend class BstSimple;
  };

public:
  BstSimple();
  int getSize() const;
  bool isEmpty() const;
  void add(const K& k, const V& v);
  void remove(const K& k);
  void erase(const K& k);
  void printInOrder();
  const V& get(const K& k);

private:
  Node* getNode(const K& k);
  Node* inOrderSuccessor(Node* node);
  void eraseInternal(Node *node);
  void eraseLeaf(Node *parent, Node *node);
  void printInOrder(Node *node);

  Node *root;
  int size;
  C compare;

};

template <typename K, typename V, typename C>
const V& BstSimple<K,V,C>::get(const K& k)
{
  Node* node = getNode(k);
  return node->value;
}

template <typename K, typename V, typename C>
void BstSimple<K,V,C>::add(const K& k, const V& v)
{
  if(size == 0)
  {
    root = new Node(k, v, nullptr);
  }
  else
  {
    Node *node = root;
    while(true)
    {
      int r = compare(k, node->key);

      if(r <= 0)
      {
        if(node->left == nullptr)
        {
          node->left = new Node(k, v, node);
          break;
        }
        else
        {
          node = node->left;
        }
      }
      else
      {
        if(node->right == nullptr)
        {
          node->right = new Node(k, v, node);
          break;
        }
        else
        {
          node = node->right;
        }
      }
    }
  }

  ++size;
}

template <typename K, typename V, typename C>
void BstSimple<K,V,C>::erase(const K& k)
{
  Node *node = getNode(k);

  if(size == 1 && compare(root->key, k) == 0)
  {
    delete root;
    root = nullptr;
  }
  else if(node->left == nullptr && node->right == nullptr)
  {
    eraseLeaf(node->parent, node);
  }
  else
  {
    eraseInternal(node);
  }

  --size;
}

/*
* note that this binary tree is not proper/full, meaning internal nodes may only
* have one child
*/
template <typename K, typename V, typename C>
void BstSimple<K,V,C>::eraseInternal(Node *node)
{
  if(node == nullptr || (node->left == nullptr && node->right == nullptr))
    throw logic_error("BstSimple: not an internal node.");

  if(node->left == nullptr)
  {
    Node *tmp = node->right;
    node->key = tmp->key;
    node->value = tmp->value;
    node->left = tmp->left;
    node->right = tmp->right;
    delete tmp;
  }
  else if(node->right == nullptr)
  {
    Node *tmp = node->left;
    node->key = tmp->key;
    node->value = tmp->value;
    node->left = tmp->left;
    node->right = tmp->right;
    delete tmp;
  }
  else
  {
    Node *next = inOrderSuccessor(node);

    if(next == nullptr)
      next = node;
    else
      node->value = next->value;

    if(next->parent->left == next)
      next->parent->left = nullptr;
    else
      next->parent->right = nullptr;

    delete next;
  }
}

template <typename K, typename V, typename C> typename
BstSimple<K,V,C>::Node* BstSimple<K,V,C>::inOrderSuccessor(Node* node)
{
  if(node == nullptr)
    throw logic_error("BstSimple: invalid node.");

  if(node->right == nullptr)
  {
    while(node->parent != nullptr)
    {
      if(node == node->parent->left)
        return node->parent;
      else
        node = node->parent;
    }

    return nullptr;
  }

  node = node->right;

  while(node->left != nullptr)
    node = node->left;

  return node;
}

template <typename K, typename V, typename C>
void BstSimple<K,V,C>::eraseLeaf(Node *parent, Node *node)
{
  if(parent == nullptr || node == nullptr)
    throw logic_error("BstSimple: node or parent is nullptr.");

  if(node->parent == nullptr || node->parent != parent)
    throw logic_error("BstSimple: node has invalid parent pointer.");

  if(parent->left == node)
    parent->left = nullptr;
  else
    parent->right = nullptr;

  delete node;
}

template <typename K, typename V, typename C> typename
BstSimple<K,V,C>::Node* BstSimple<K,V,C>::getNode(const K& k)
{
  if(size == 0)
    throw logic_error("BstSimple: tree is empty.");

  Node *node = root;
  while(node != nullptr)
  {
    int r = compare(k, node->key);

    if(r < 0)
      node = node->left;
    else if(r > 0)
      node = node->right;
    else
      return node;
  }

  throw logic_error("BstSimple: key does not exist.");
}

template <typename K, typename V, typename C>
BstSimple<K,V,C>::BstSimple():
  root(nullptr),
  size(0),
  compare()
{ }

template <typename K, typename V, typename C>
int BstSimple<K,V,C>::getSize() const
{
  return size;
}

template <typename K, typename V, typename C>
bool BstSimple<K,V,C>::isEmpty() const
{
  return size == 0;
}

template <typename K, typename V, typename C>
void BstSimple<K,V,C>::printInOrder()
{
  printInOrder(root);
}

template <typename K, typename V, typename C>
void BstSimple<K,V,C>::printInOrder(Node *node)
{
  if(node == nullptr)
    return;

  printInOrder(node->left);
  cout << node->value << endl;
  printInOrder(node->right);
}

#endif

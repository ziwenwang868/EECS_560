#ifndef bnode_h
#define bnode_h

#include <iostream>
using namespace std;

template <typename t>
class bnode
{
public:
  t getEntry() const;

  bnode<t> *getLeft() const;
  bnode<t> *getRight() const;

  void setEntry(t entry);

  void setLeft(bnode<t> *left);
  void setRight(bnode<t> *right);
  bnode(t entry);
  bnode();
  //~btnode(){}

private:
  t item;
  bnode<t> *leftptr;
  bnode<t> *rightptr;
};
#include "bnode.cpp"
#endif

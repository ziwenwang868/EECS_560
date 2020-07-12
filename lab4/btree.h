#ifndef btree_h
#define btree_h

#include<iostream>
#include"bnode.h"
#include"data.h"
#include<math.h>

using namespace std;

class btree
{
private:
  bnode<Data*>* root;
  int level;
  int nodecount;
  int nodefordelete;
  bool addscussed;
  bool d_scussed;
  bool infor_mode;
  string output;
  void adding(bnode<Data*>* tree,Data* entry,int levels);
  void removeing(bnode<Data*>*tree,int levels);
  int gethight(bnode<Data*>* tree);
  int chekcnodes(bnode<Data*>*tree,int level);

  void preorder_trv(bnode<Data*>*tree);
  void postorder_trv(bnode<Data*>*tree);
  void inorder_trv(bnode<Data*>*tree);
  void levelorder_trv(bnode<Data*>*tree, int level);
  bool searching(bnode<Data*>*tree,string key);
  void recleaves(bnode<Data*>*tree,int level);
public:
  btree();
  ~btree();
  bool isfull();
  void RemoveMovie();
  void setinfor(bool swith);
  bool isLeaf(string title);
  string printleaves();

  string preorder();
  string postorder();
  string inorder();
  string levelorder();

  int numberofnode();
  int printhight();
  bool Rate_check(float rate);
  int test();
  void AddMovie(string title,float rate);
};
#endif

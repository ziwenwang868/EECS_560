#ifndef exe_h
#define exe_h

#include<iostream>
#include<fstream>
#include<string>
#include "btree.h"
using namespace std;

class exe
{
public:
  exe(string file);
  void run();
private:
  btree m_tree;
};
#endif

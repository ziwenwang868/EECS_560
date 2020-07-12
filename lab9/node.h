#ifndef node_h
#define node_h
#include <iostream>
using namespace std;

class node
{

   

public:
    node();
    node(int data);
    int getdata();

    node *getleft();
    node *getright();
    ~node();
    int data;
    int rank;
    node *left;
    node *right;
};
#endif
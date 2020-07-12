#ifndef minleft_h
#define minleft_h

#include<iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include "node.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

class minleftist
{
    private:
    node *root;
    public:
    minleftist();
    ~minleftist();

    void insert(int entry);
    void deletemin();

    node* merge(node*h1,node*h2);

    void Level(node* h);
    void printlevel();

    void clear();
    void clean(node* h);
    

    void build(vector<int> in);
    float build_test(int size);
    float delete_test(int size);

};
#endif
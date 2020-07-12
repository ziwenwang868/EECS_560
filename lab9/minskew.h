#ifndef minskew_h
#define minskew_h

#include<iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include "node.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

class minskew
{
    private:
    node *root;
    public:
    minskew();
    ~minskew();

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
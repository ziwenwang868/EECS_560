#ifndef dset_h
#define dset_h

#include<iostream>
using namespace std;
#include<vector>
#include"set_node.h"
class dis_jointSet
{
    private:
    set_node** arr;
    int m_size;
    public:
    dis_jointSet();
    void makeSet(vector<int>orig);
    void Union_set(int h1,int h2);
    set_node* found(int x);
    int find_repersent(set_node* x);
    set_node* check_parents(set_node* x);

    void find(int x);

    bool check(int x);
    set_node* get_partentsptr(set_node*x);
    void pathcomp(int x);
    
    void printpath(int x);
    ~dis_jointSet();
};
#endif
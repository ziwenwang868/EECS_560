#ifndef setnode_h
#define setnode_h

#include<iostream>
using namespace std;

class set_node
{
    private:
    int entry;
    int rank;
    set_node* parent_ptr;
    public:
    set_node();
    ~set_node();
    //set_node(int entry);

    void set_rank(int r);
    int get_rank();

    void set_parent(set_node*p);
    set_node* get_parent();

    void set_entry(int x);
    int get_entry();


};
#endif

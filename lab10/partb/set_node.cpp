#include "set_node.h"

set_node::set_node()
{
    rank=0;
    entry=-1;
    parent_ptr=nullptr;
}
set_node::~set_node()
{

}

void set_node::set_rank(int r)
{
    rank=r;
}
int set_node::get_rank()
{
    return rank;
}

void set_node::set_parent(set_node *p)
{
    parent_ptr=p;
}
set_node *set_node::get_parent()
{
    return parent_ptr;
}

void set_node::set_entry(int x)
{
    entry=x;
}
int set_node::get_entry()
{
    return entry;
}

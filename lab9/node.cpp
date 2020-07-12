#include "node.h"
node::node()
{
    data=-1;
    rank=1;
    left=nullptr;
    right=nullptr;
}
node::node(int x)
{
    data=x;
    rank=1;
    left=nullptr;
    right=nullptr;
}

node* node::getleft()
{
    return left;
}
node* node::getright()
{
    return right;
}
node::~node()
{
   
}
int node::getdata()
{
    return data;
}
#ifndef q_hash
#define q_hash
#include "data.h"
#include <iostream>
using namespace std;
class qhash
{
private:
    Data *qtable;
    int t_size;
    int k_value;
    int added;
    int founded;
    int notfind;

public:
    qhash();
    qhash(int size);
    int hash(int inpt);
    void add(int inpt);
    void found(int inpt);
    bool founding(int input);
    int getadded();
    int getfounded();
    int getnotfind();
    void setup(int size);
    ~qhash();
};
#endif
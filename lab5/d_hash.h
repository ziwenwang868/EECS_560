#ifndef d_hash
#define d_hash
#include "data.h"
#include <iostream>
using namespace std;
class dhash
{
private:
    Data *dtable;
    int t_size;
    int k_value;
    int R_value;
    int added;
    int founded;
    int notfind;

public:
    dhash();
    dhash(int size);
    int hash(int inpt);
    void add(int inpt);
    void found(int inpt);
    bool founding(int input);
    int getadded();
    int getfounded();
    void setup(int size);
    int getnotfind();
    ~dhash();
};
#endif
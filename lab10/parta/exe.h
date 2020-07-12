#ifndef exe_h
#define exe_h
#include<iostream>
#include<fstream>
using namespace std;
#include"disjoint.h"
#include<vector>

class exe
{
    private:
    dis_jointSet dset;
    vector<int>orig;

    public:
    exe(string file);
    void run();

};
#endif

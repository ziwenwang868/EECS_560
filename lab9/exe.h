#ifndef exe_h
#define exe_h
#include<iostream>
#include<fstream>
using namespace std;
#include"minleftist.h"
#include"minskew.h"

class exe
{
    private:
    minleftist leftist_tree;
    minskew skew_tree;
    public:
    exe(string file);
    void run();

};
#endif

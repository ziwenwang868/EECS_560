#ifndef exe_h
#define exe_h


#include<iostream>
#include<fstream>
using namespace std;
#include"bst.h"

class exe
{
    private:
        bst tree;
    public:
        exe(string file);
        void run();
        ~exe();
};
#endif
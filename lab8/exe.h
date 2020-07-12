#ifndef exe_h
#define exe_h


#include<iostream>
#include<fstream>
#include"maxmin.h"
#include"data.h"
using namespace std;

class exe
{
    private:
       maxmin m_heap;
    public:
        exe(string filename);
        void run();
        
        ~exe();
};
#endif
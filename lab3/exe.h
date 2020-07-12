#ifndef EXE_H
#define EXE_H

#include<iostream>
#include<fstream>
#include<string>
#include"hash.h"
#include"data.h"
using namespace std;

class exe
{
    private:
        hAsh table;
    public:
    exe();
    ~exe();
    exe(string file);
    void printlist();
    bool name_check(string name);
    bool password_check(string pd);
    void run();
   
};
#endif
#ifndef exe_h
#define exe_h
#include<iostream>
#include<fstream>
using namespace std;
#include"disjoint.h"
#include"graph.h"
#include<sstream>
#include<limits>
#include<vector>

class exe
{
    private:
    graph pic;
    vector<string>island_name;
    int **arr;
    int size;
    public:
    exe();
    ~exe();
    void run();

};
#endif

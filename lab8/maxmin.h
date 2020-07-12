#ifndef maxmin_h
#define maxmin_h
#include<iostream>
#include <cmath>
#include <math.h> 
using namespace std;
#include"data.h"
class maxmin
{
    private:
    app arr[1000];
    int heapsize;
    
    public:
    maxmin();
    //for insert
    void insert(string name, int num);
    int get_parent(int x);
    int get_grandpar(int x);
    void minup(int x);
    void maxup(int x);
    void heapfiy(int index);
    bool max_level_check(int num);
    //end inssert
    void delete_max();
    void down_heap(int index);
    //
    void mindown(int x);
    void maxdown(int x);
    int find_child(int x,int y);
    int find_grand_child(int x,int y);
    int min_lv_child(int x);
    int min_lv_grand(int x);
    int max_lv_child(int x);
    int max_lv_grand(int x);
    //
    void printAtmin();
    void printAtmax();
    //
    int totalmax();
    int totalmin();
    //
    void remove(string name,int num);
    int get_index(string name,int num);

    void test_print();
};
#endif
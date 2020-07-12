#ifndef min_heap
#define min_heap
#include<iostream>
using namespace std;
#include <cmath>
#include"data.h"

class doctor
{
    private:
    people* arr;
    int m_size;
    int m_heapsize;

    public:
    doctor();
    ~doctor();
    void inital_d(people*entry,int size);
    void insert(string first,string last,int num);
    void heapify(int size,int index);
    void remove_d();
    bool search(string first,string last);
    int patient_count(string first,string last);
    bool check_dup(string first,string last);
    bool check_avaliable(string first,string last);
    void change_patient_C(string first,string last,int num);
    int totaldoc();
    int totalavaliable();
    void avaliable_report();
    void busy_report();
    string next_doc();
    void buildheap(int size);
    void downheap(int partents);
    void pritall();
};
#endif
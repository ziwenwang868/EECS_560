#ifndef max_heap_h
#define max_heap_h

#include<iostream>
#include <cmath>
#include"data.h"
using namespace std;

class patient
{
    private:
    people* arr;
    int m_size;
    int m_heapsize;
    public:
    
    patient();
    ~patient();
    void inital_p(people*entery,int size);
    void insert(string first,string last,int num);
    void treat();
    void change_urgency(string first,string last,int num);
    string next_patient();
    string last_patient();
    int patient_token(string first,string last);
    int patient_c();
    void patient_report();
    string search(string first,string last);
    bool check_dup(string first,string last);
    void heapify(int size,int index);
  
    void buildheap(int size);
    void downheap(int partents);

};
#endif
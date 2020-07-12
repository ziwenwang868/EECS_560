#ifndef exe_h
#define exe_h


#include<iostream>
#include<fstream>
using namespace std;
#include"data.h"
#include"patient_max.h"
#include"doctor_min.h"
class exe
{
    private:
       patient p_manage;
       doctor d_manage;
    public:
        exe(string docfile,string patfile);
        void run();
        void doctor_as();
        void patient_as();
        ~exe();
};
#endif
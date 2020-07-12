#ifndef Data_h
#define Data_h
#include<iostream>
using namespace std;

class Data
{
    private:
        int value;
        bool space;
        bool deleted;
    public:
        Data();
        Data(int x);
        ~Data();
        bool isempty();
        void setdata(int val);
        void setdeletion(bool state);
        bool isdeleted();
        void setspace(bool state);
        int getdata()const;
};
#endif
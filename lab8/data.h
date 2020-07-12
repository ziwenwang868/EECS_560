#ifndef app_h
#define app_h
#include<iostream>
using namespace std;
class app
{
    private:
        string app_name;
        int down_num;
    public:
        app();
        void setup(string name,int num);
        void setEmpty();
        string getname();
        int getnum();
        void operator ==(app &other);
};
#endif
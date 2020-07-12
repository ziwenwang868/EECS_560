#ifndef data_h
#define data_h
#include<iostream>
using namespace std;

class people
{
    private:
    string firstname;
    string lastname;
    int priority;
    public:
    people();
    people(string first,string last,int num);
    int getpriority();
    void setpriority(int num);

    string getfirst();
    void setfirst(string name);

    string getlast();
    void setlast(string name);

};
#endif
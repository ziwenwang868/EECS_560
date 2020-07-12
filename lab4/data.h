#ifndef Data_h
#define Data_h
#include<iostream>
using namespace std;

class Data
{
    private:
        string movie;
        float rate;
    public:
        Data();
        Data(string m_movie,float m_rate);
        ~Data();
        string getname()const;
        float getrate()const;

};
#endif

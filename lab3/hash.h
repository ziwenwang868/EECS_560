#ifndef hAsh_h
#define hAsh_h
#include<iostream>
#include"data.h"
using namespace std;

class hAsh
{
    private:
        Data *LinearP;
        Data *QuadP;
        int t_size;
        int num_elemt_L;
        int num_elemt_Q;
        int k_value;
    public:
        hAsh();
        ~hAsh();
        void adduser(Data x,bool mode);
        void print();
        int translator(string x);
        void rehash();
        bool isprime(int a);
        void forgetname(string password);
        void forgetpswd(string username);
        bool checknameDuo(string name);
        void remove(Data x);
        int Q_hash(int x);
        int L_hash(int x);
       
};
#endif
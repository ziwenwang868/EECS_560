#ifndef Data_h
#define Data_h
#include<iostream>
using namespace std;

class Data
{
    private:
        string name;
        string password;
        bool space;
        bool deleted;
    public:
        Data();
        Data(string name,string paswd);
        ~Data();
        bool isempty();
        void setdeletion(bool state);
        bool isdeleted();
        void setspace(bool state);
        string getname()const;
        string getpassword()const;
        void operator==(Data x);
};
#endif
#include"exe.h"
#include<string>
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    string func;
    if(argc==3)
    {
        exe t(argv[1],argv[2]);
        t.run();
    }
    else
    {
        cout<<"Please enter a correct file name!"<<'\n';
    }

    return 0;
}

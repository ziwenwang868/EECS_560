#include"exe.h"
#include<string>
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    string func;
    if(argc==2)
    {
        exe test(argv[1]);
        test.run();
    }
    else
    {
        cout<<"Please enter a correct file name!"<<'\n';
    }

    return 0;
}

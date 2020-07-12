#include"exe.h"
#include<string>
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    string func;
    if(argc==2)
    {
       
        exe t(argv[1]);
        //exe t;
        t.run();
        
    }
    else
    {
        cout<<"Please enter a correct function name!"<<'\n';
    }
    
    return 0;
}
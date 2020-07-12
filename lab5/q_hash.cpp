#include "q_hash.h"
qhash::qhash()
{
    added=0;
    founded=0;
    k_value=25;
    notfind=0;
}
qhash::qhash(int size)
{
    
    t_size=size;
    k_value=25;
    qtable=new Data[t_size];
    added=0;
    founded=0;
}
int qhash::getnotfind()
{
    return notfind;
}
void qhash::setup(int size)
{
    t_size=size;
    k_value=25;
    qtable=new Data[t_size];
    added=0;
    founded=0;
}
int qhash::hash(int inpt)
{
    int out=-1;
    for(int i=0;i<k_value;i++)
    {
        int value=0;
        if(i==0)
        {
            value=inpt%t_size;
        }
        else
        {
            value=(inpt%t_size+i*i)%t_size;
        }
    
        if(qtable[value].isempty())
        {
            out=value;
        }
    }
    return out;
}
void qhash::add(int inpt)
{
    int keyq=hash(inpt);
    if(keyq!=-1)
    {
        qtable[keyq].setdata(inpt);
        qtable[keyq].setspace(false);
        qtable[keyq].setdeletion(false);
        added++;
    }
}
void qhash::found(int input)
{
    if(founding(input))
    {
        founded++;
    }
    else
    {
        notfind++;
    }
    
}
bool qhash::founding(int inpt)
{
    bool re=false;
    for(int i=0;i<k_value;i++)
    {   
        int value=0;
        if(i==0)
        {
            value =inpt%t_size;
        }
        else
        {
            value=(inpt%t_size+i*i)%t_size;
        }

        if(qtable[value].getdata()==inpt)
        {
            
            re=true;
            break;
        } 
    }
    return re;
}

int qhash::getadded()
{
    return added;
}
int qhash::getfounded()
{
    return founded;
}
qhash::~qhash()
{
    delete []qtable;
}
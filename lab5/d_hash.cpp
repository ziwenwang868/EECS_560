#include "d_hash.h"
dhash::dhash()
{
    k_value=25;
    added=0;
   founded=0;
   R_value=773;
   notfind=0;
}
dhash::dhash(int size)
{
   t_size=size;
   k_value=25;
   dtable=new Data[t_size];
   added=0;
   founded=0;
   R_value=773;
}
void dhash::setup(int size)
{
t_size=size;
   k_value=25;
   dtable=new Data[t_size];
   added=0;
   founded=0;
   R_value=773;
}
int dhash::getnotfind()
{
    return notfind;
}
int dhash::hash(int inpt)
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
            value=(value+i*(R_value-value))%t_size;
        }
        if(dtable[value].isempty())
        {
            out=value;
        }
        
    }
    return out;
}
void dhash::add(int inpt)
{
    int keyd=hash(inpt);
    if(keyd!=-1)
    {
        dtable[keyd].setdata(inpt);
        dtable[keyd].setspace(false);
        dtable[keyd].setdeletion(false);
        added++;
    }
}
void dhash::found(int input)
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
bool dhash::founding(int inpt)
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
           
            value=(value+i*(R_value-value))%t_size;
        }

        if(dtable[value].getdata()==inpt)
        {
            re=true;
            break;
        } 
    }
    return re;
}
int dhash::getadded()
{
    return added;
}
int dhash::getfounded()
{
    return founded;
}
dhash::~dhash()
{
    delete []dtable;
}
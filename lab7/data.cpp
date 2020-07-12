#include "data.h"
people::people()
{
    firstname="";
    lastname="";
    priority=0;
}
people::people(string first, string last, int num)
{
    firstname=first;
    lastname=last;
    priority=num;
}
int people::getpriority()
{
    return priority;
}
void people::setpriority(int num)
{
    priority=num;
}

string people::getfirst()
{
    return firstname;
}
void people::setfirst(string name)
{
    firstname=name;
}

string people::getlast()
{
    return lastname;
}
void people::setlast(string name)
{
    lastname=name;
}
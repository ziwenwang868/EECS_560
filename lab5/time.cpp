#include"time.h"
timer::timer()
{
    start=0;
    end=0;
    output=0;
}
void timer::finish()
{
    end=clock()-start;
    output= (float)end/CLOCKS_PER_SEC;
}
void timer::begin()
{
    start=0;
    end=0;
    output=0;
    start=clock();
}
float timer::gettime()
{
    return output;
}
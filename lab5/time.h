#ifndef time_h
#define time_h
#include<iostream>

#include<time.h>

using namespace std;

class timer
{
    private:
        clock_t start;
        clock_t end;
        float output;
    public:
        timer();
        void begin();
        void finish();
        float gettime();
        
};
#endif
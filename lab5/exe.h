#ifndef EXE_H
#define EXE_H

#include <iostream>

#include <string>
#include "q_hash.h"
#include "d_hash.h"
#include "time.h"
#include <math.h>
#include <iomanip>
using namespace std;

class exe
{
private:
    
    
    int tablesize;

public:
    exe();
    ~exe();
    void printlist();
    void quadhash();
    void doublehash();
    void run();
};
#endif
#include "data.h"

Data::Data()
{
    movie="";
    rate=0.0;
}
Data::Data(string name,float num)
{
    movie=name;
    rate=num;
}
Data::~Data()
{

}
string Data::getname()const
{
    return movie;
}
float Data::getrate()const
{
    return rate;
}

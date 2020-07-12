#include "data.h"

Data::Data()
{
    space = true;
    value=-1;
    deleted = false;
}
Data::~Data()
{
}
bool Data::isdeleted()
{
    return deleted;
}
void Data::setdeletion(bool state)
{
    deleted=state;
}
void Data::setdata(int va)
{
    value=va;
}
Data::Data(int x)
{
    value =x;
}
bool Data::isempty()
{
    return space;
}
void Data::setspace(bool state)
{
    space = state;
}
int Data::getdata()const
{
    return value;
}
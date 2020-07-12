#include "data.h"

Data::Data()
{
    space = true;
    name = "";
    password = "";
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
Data::Data(string ne, string paswd)
{
    name = ne;
    password = paswd;
}
void Data::operator==(Data x)
{
    name = x.getname();
    password = x.getpassword();
}
bool Data::isempty()
{
    return space;
}
void Data::setspace(bool state)
{
    space = state;
}
string Data::getname() const
{
    return name;
}
string Data::getpassword() const
{
    return password;
}
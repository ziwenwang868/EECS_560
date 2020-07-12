#include "data.h"
app::app()
{
    down_num=-1;
    app_name="";
}
void app::setup(string name, int num)
{
    down_num=num;
    app_name=name;
}
void app::setEmpty()
{
    app_name="";
    down_num=-1;
}
string app::getname()
{
    return app_name;
}
int app::getnum()
{
    return down_num;
}
void app::operator==(app &other)
{
    string name=this->app_name;
    int num=this->down_num;
    this->app_name=other.getname();
    this->down_num=other.getnum();
    other.app_name=name;
    other.down_num=num;
}
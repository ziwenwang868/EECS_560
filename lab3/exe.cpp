#include "exe.h"

exe::exe(string name)
{
    ifstream infile;
    string name_srting;
    string hash_string;
    
    infile.open(name);
    while (!infile.is_open())
    {
        string file;
        cout << "wrong filename try again: ";
        cin >> file;
        infile.open(file);
    }
    if (!(infile.peek() == EOF))
    {
        while (infile >> name_srting>>hash_string)
        {
            name_srting.resize(name_srting.size()-1);
            if(name_check(name_srting)&&password_check(hash_string))
            {
                table.rehash();
                Data x(name_srting,hash_string);
                table.adduser(x,false);
                //cout<<"name: "<<x.getname()<<" pasw: "<<x.getpassword()<<endl;
            }
            //cout<<"name "<<name_srting<<" size:"<<name_srting.length()<<" hash: "<<hash_string<<endl;
        }
    }
    infile.close();
}

bool exe::name_check(string x)
{
    
    bool flag=false;
    if(x.size()>1 && x.size()<=7)
    {
        flag=true;
        int max=x.size();
        for (int i=0;i<max;i++)
        {
            if(!islower(x.at(i)))
            {
                cout<<"Warning, username "<<x<<" is invalid_capital_letter"<<endl;
                flag=false;
                break;
            }
        }
    }
    else
    {
         cout<<"Warning, username "<<x<<" invalid_size"<<endl;
    }
     return flag;
     
}

bool exe::password_check(string x)
{
    bool flag=false;
    int letter_count=3;
    int num_count=2;
    int max=x.length();
    if(max<=7)
    {
        for(int i=0;i<max;i++)
        {
            if(isdigit(x.at(i)))
            {
                num_count--;
            }
            else if(islower(x.at(i)))
            {
                letter_count--;
            }
            else
            {
                cout<<"Invalid password"<<endl;
                flag=false;
                break;
            }
            
        }
        if(letter_count<=0&&num_count<=0)
        {
            flag=true;
        }
    }
    else
    {
        cout<<"Invalid size of password"<<endl;
    }
    if(!flag)
    {
        cout<<"Invalid password"<<endl;
    }
    
    return flag;
}

exe::~exe()
{
}

void exe::run()
{
    bool flag=true;
    int choice;
    
    while(flag)
    {
        cout<<endl;
        cout<<"Please choose one of the following commands:"<<endl;
        cout<<"  1- Add User"<<endl;
        cout<<"  2- Remove User"<<endl;
        cout<<"  3- Forgot Password"<<endl;
        cout<<"  4- Forgot Username"<<endl;
        cout<<"  5- Print Users"<<endl;
        cout<<"  6- Exit"<<endl;
        cin>>choice;
        if(choice==6)
        {
            cout<<"Bye Bye!"<<endl;
            flag=false;
        }
        if(choice==2)
        {
            string inser_name;
            string inser_pawd;   
            cout<<"Enter user and password to be removed:"<<endl;
            cout<<"User name: ";
            cin>>inser_name;
            cout<<"User password: ";
            cin>>inser_pawd;
            if(name_check(inser_name)&&password_check(inser_pawd))
            {
                Data y(inser_name,inser_pawd);
                table.remove(y);
            }
            
        }
        if(choice==3)
        {
            string in_name;
            cout<<"Enter username"<<endl;
            cin>>in_name;
            if(name_check(in_name))
            {
                table.forgetpswd(in_name);
            }
        }
        if(choice==4)
        {
            string in_pswd;
            cout<<"Enter Password"<<endl;
            cin>>in_pswd;
            if(password_check(in_pswd))
            {
                table.forgetname(in_pswd);
            }
        }
        if(choice==1)
        {   
            string inser_name;
            string inser_pawd;   
            cout<<"Enter user details to be added:"<<endl;
            cout<<"User name: ";
            cin>>inser_name;
            cout<<"User password: ";
            cin>>inser_pawd;
            
            if(name_check(inser_name)&&password_check(inser_pawd))
            {
                table.rehash();
                Data y(inser_name,inser_pawd);
                table.adduser(y,true);
            }
            
            
           
        }
        if (choice==5)
        {
            table.print();
        }
        
    }
}
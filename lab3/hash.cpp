#include "hash.h"

hAsh::hAsh()
{
    t_size = 11;
    k_value = 11;
    num_elemt_L=1;
    num_elemt_Q=1;
    QuadP = new Data[t_size];
    LinearP = new Data[t_size];
}
void hAsh::forgetname(string paswd)
{
    bool flag=false;
    bool flag2=false;
    cout << endl;
    cout << "Output for Linear Probing" << endl;
    for (int i = 0; i < t_size; i++)
    {
        if (LinearP[i].getpassword() == paswd)
        {
            cout << LinearP[i].getname() << ": " << LinearP[i].getpassword() << endl;
            flag=true;
        }
    }
    if(!flag)
    {
        cout<<"Record does not exist"<<endl;
    }
    cout << endl;
    cout << "Output for Quadratic Probing" << endl;
    for (int i = 0; i < t_size; i++)
    {
        if (QuadP[i].getpassword() == paswd)
        {
            cout << QuadP[i].getname() << ": " << QuadP[i].getpassword() << endl;
            flag2=true;
        }
    }
    if(!flag2)
    {
        cout<<"Record does not exist"<<endl;
    }
}
void hAsh::forgetpswd(string name)
{
    bool flag=false;
    bool flag2=false;
    cout << endl;
    cout << "Output for Linear Probing" << endl;
    for (int i = 0; i < t_size; i++)
    {
        if (LinearP[i].getname() == name)
        {
            cout << LinearP[i].getname() << ": " << LinearP[i].getpassword() << endl;
            flag=true;
        }
    }
    if(!flag)
    {
        cout<<"Record does not exist"<<endl;
    }
    cout << endl;
    cout << "Output for Quadratic Probing" << endl;
    for (int i = 0; i < t_size; i++)
    {
        if (QuadP[i].getname() == name)
        {
            cout << QuadP[i].getname() << ": " << QuadP[i].getpassword() << endl;
            flag2=true;
        }
    }
    if(!flag2)
    {
        cout<<"Record does not exist"<<endl;
    }
}
int hAsh::translator(string x)
{
    int total = 0;
    int max=x.length();
    for (int i = 0; i < max; i++)
    {
        if (isdigit(x.at(i)))
        {
            int t = x.at(i) - '0';
            total = total + t;
        }
        else
        {
            total = total + static_cast<int>(x.at(i));
        }
    }
    return total;
}
int hAsh::L_hash(int x)
{
    int out = -1;
    for (int i = 0; i < k_value; i++)
    {
        int value =0;
        if(i==0)
        {
            value=x%t_size;
        }
        else
        {
            value=(x%t_size+i)%t_size;
        }
        
        if (LinearP[value].isempty())
        {
            out = value;
            break;
        }
    }
    return out;
}
int hAsh::Q_hash(int x)
{
    int out = -1;
    for (int i = 0; i < k_value; i++)
    {
        int value = 0;
        if(i==0)
        {
            value=x%t_size;
        }
        else
        {
            value=(x%t_size+i*i)%t_size;
        }
        
        
        if (QuadP[value].isempty())
        {
            out = value;
            break;
        }
    }
    return out;
}
void hAsh::remove(Data user)
{
    int allK = translator(user.getpassword());
    int keyL = 0;
    int keyQ = 0;
    bool flag = false;
    bool flag2 = false;
    Data empty;
    for (int i = 0; i < k_value; i++)
    {
        keyL = (allK + i) % t_size;
        if (!LinearP[keyL].isdeleted() && LinearP[keyL].getname() == user.getname())
        {
            LinearP[keyL] == empty;
            LinearP[keyL].setspace(true);
            LinearP[keyL].setdeletion(true);
            flag = true;
            break;
        }
    }
    cout << endl;
    cout << "Linear Probing:" << endl;
    if (flag)
    {
        cout << "Record removed" << endl;
    }
    else
    {
        cout << "Record does not exist" << endl;
    }

    for (int i = 0; i < k_value; i++)
    {
        keyQ = (allK + i * i) % t_size;
        if (!QuadP[keyQ].isdeleted() && QuadP[keyQ].getname() == user.getname())
        {
            QuadP[keyQ] == empty;
            QuadP[keyQ].setspace(true);
            QuadP[keyQ].setdeletion(true);
            flag2 = true;
            break;
        }
    }
    cout << endl;
    cout << "Quadratic Probing:" << endl;
    if (flag2)
    {
        cout << "Record removed" << endl;
    }
    else
    {
        cout << "Record does not exist" << endl;
    }
}
void hAsh::adduser(Data x, bool mode)
{
    int glop = translator(x.getpassword());
    int key = L_hash(glop);
    int key2 = Q_hash(glop);
    if (!checknameDuo(x.getname()))
    {
        if (key == -1)
        {
            cout << "[" << x.getname() << "]"
                 << " fail to add into any location using Linear probing" << endl;
        }
        else
        {
            LinearP[key] == x;
            LinearP[key].setspace(false);
            LinearP[key].setdeletion(false);
            num_elemt_L++;
            if (mode)
            {
                cout << "[" << x.getname() << "]"
                     << " has been succeffully added at location [" << key << "] using Linear probing" << endl;
            }
        }

        if (key2 == -1)
        {
            cout << "[" << x.getname() << "]"
                 << " fail to add into any location using Quadratic probing" << endl;
        }
        else
        {
            QuadP[key2] == x;
            QuadP[key2].setspace(false);
            QuadP[key2].setdeletion(false);
            num_elemt_Q++;
            if (mode)
            {
                cout << "[" << x.getname() << "]"
                     << " has been succeffully added at location [" << key2 << "] using Quadratic probing" << endl;
            }
        }
    }
    else
    {
        cout << "Duplicated detected at user [" << x.getname() << "] insertion failed" << endl;
    }

    
}
bool hAsh::checknameDuo(string name)
{
    bool out = false;
    for (int i = 0; i < t_size; i++)
    {
        if (LinearP[i].getname() == name || QuadP[i].getname() == name)
        {
            out = true;
            break;
        }
    }
    return out;
}

void hAsh::print()
{
    cout << "---------------------------" << endl;
    cout << "Linear Probing:" << endl;
    for (int i = 0; i < t_size; i++)
    {
        cout << i << ": ";
        if (!LinearP[i].isempty())
        {
            cout << LinearP[i].getname() << ":" << LinearP[i].getpassword() << endl;
        }
        else
        {
            cout << endl;
        }
    }
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Quadratic Probing:" << endl;
    for (int i = 0; i < t_size; i++)
    {
        cout << i << ": ";
        if (!QuadP[i].isempty())
        {
            cout << QuadP[i].getname() << ":" << QuadP[i].getpassword() << endl;
        }
        else
        {
            cout << endl;
        }
    }

    cout << endl;
}
void hAsh::rehash()
{
    int ld_fac_L=num_elemt_L/t_size;
    int ld_fac_Q=num_elemt_Q/t_size;
    if(ld_fac_L>0.5||ld_fac_Q>0.5)
    {
        //cout<<"rehash called"<<endl;
        num_elemt_L=1;
        num_elemt_Q=1;
        int i;
        for( i=t_size*2;!isprime(i);i++);
        int orign_size=t_size;
        t_size=i;
        k_value=i;
        Data *tempP=new Data[t_size];
        Data *tempQ=new Data[t_size];
        Data *oldP=LinearP;
        Data *oldQ=QuadP;
        LinearP=tempP;
        QuadP=tempQ;
        for(int j=0;j<orign_size;j++)
        {
            if(!oldP[j].isempty())
            {
                int key_l=L_hash(translator(oldP[j].getpassword()));
                LinearP[key_l]==oldP[j];
                LinearP[key_l].setdeletion(false);
                LinearP[key_l].setspace(false);
                num_elemt_L++;
            }
            
        }
        for(int j=0;j<orign_size;j++)
        {
            if(!oldQ[j].isempty())
            {
                int key_Q=Q_hash(translator(oldQ[j].getpassword()));
                QuadP[key_Q]==oldQ[j];
                QuadP[key_Q].setdeletion(false);
                QuadP[key_Q].setspace(false);
                num_elemt_Q++;
            }
        }
        delete []oldP;
        delete []oldQ;
    }
}
bool hAsh::isprime(int x)
{
    int count=0;
    for(int i=2;i<=x/2;i++)
    {
        if(x%i==0)
        {
            count++;
        }
    }
    if(count==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
hAsh::~hAsh()
{
    delete[] QuadP;
    delete[] LinearP;
}
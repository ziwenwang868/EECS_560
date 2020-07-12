#include "patient_max.h"

patient::patient()
{
    m_heapsize = 0;
    m_size = 1000; //size the max heap
    arr = new people[m_size];
}
void patient::inital_p(people *entery, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i].setfirst(entery[i].getfirst());
        arr[i].setlast(entery[i].getlast());
        arr[i].setpriority(entery[i].getpriority());
        m_heapsize++;
    }
   
    buildheap(m_heapsize);
}

bool patient::check_dup(string first, string last)
{
    bool flag = false;
    for (int i = 0; i < m_heapsize; i++)
    {
        if (arr[i].getfirst() == first && arr[i].getlast() == last)
        {
            flag = true;
        }
    }
    return flag;
}
void patient::insert(string first, string last, int num)
{
    int x = m_heapsize + 1;
    if (m_size < x)
    {
        throw(runtime_error("failed to insert, surpass the large size"));
    }
    else
    {

        arr[m_heapsize].setfirst(first);
        arr[m_heapsize].setlast(last);
        arr[m_heapsize].setpriority(num);
        m_heapsize++;
        buildheap(m_heapsize);
    }
}
void patient::downheap(int index)
{

    int partent = index;
    int one_c = 3 * index + 1;
    int two_c = 3 * index + 2;
    int three_c = 3 * index + 3;
    if (three_c < m_heapsize && arr[three_c].getpriority() > arr[partent].getpriority())
    {
        partent = three_c;
    }

    if (two_c < m_heapsize && arr[two_c].getpriority() > arr[partent].getpriority())
    {
        partent = two_c;
    }

    if (one_c < m_heapsize && arr[one_c].getpriority() > arr[partent].getpriority())
    {
        partent = one_c;
    }
    if (partent != index)
    {
        string first = arr[partent].getfirst();
        string last = arr[partent].getlast();
        int num = arr[partent].getpriority();
        arr[partent].setfirst(arr[index].getfirst());
        arr[partent].setlast(arr[index].getlast());
        arr[partent].setpriority(arr[index].getpriority());
        arr[index].setfirst(first);
        arr[index].setlast(last);
        arr[index].setpriority(num);

        downheap(partent);
    }
}
void patient::treat()
{
    if (m_heapsize == 0)
    {
        throw(runtime_error("failed to treat, empty patients in heap"));
    }
    else
    {
        arr[0].setfirst(arr[m_heapsize - 1].getfirst());
        arr[0].setlast(arr[m_heapsize - 1].getlast());
        arr[0].setpriority(arr[m_heapsize - 1].getpriority());
        arr[m_heapsize - 1].setfirst("");
        arr[m_heapsize - 1].setlast("");
        arr[m_heapsize - 1].setpriority(0);
        m_heapsize--;
        downheap(0);
    }
}
void patient::change_urgency(string first, string last, int num)
{
    bool flag = false;
    int index;
    if (m_heapsize == 0)
    {
        throw(runtime_error("faild,heap is empty"));
    }
    else
    {
        for (int i = 0; i < m_heapsize; i++)
        {
            if (arr[i].getfirst() == first && arr[i].getlast() == last)
            {
                flag = true;
                index = i;
            }
        }
    }
    if (!flag)
    {
        throw(runtime_error("patient not found!"));
    }
    else
    {
        arr[index].setfirst(arr[m_heapsize - 1].getfirst());
        arr[index].setlast(arr[m_heapsize - 1].getlast());
        arr[index].setpriority(arr[m_heapsize - 1].getpriority());
        arr[m_heapsize - 1].setfirst("");
        arr[m_heapsize - 1].setlast("");
        arr[m_heapsize - 1].setpriority(0);

        m_heapsize--;
        insert(first, last, num);
    }
}
string patient::next_patient()
{
    if (m_heapsize == 0)
    {
        throw(runtime_error("faild,heap is empty"));
    }
    string output = arr[0].getfirst() + ", ";
    output = output + arr[0].getlast() + ", ";
    output = output + to_string(arr[0].getpriority());
    return output;
}
string patient::last_patient()
{
    int lower = arr[0].getpriority();
    int index = 0;
    if (m_heapsize == 0)
    {
        throw(runtime_error("faild,heap is empty"));
    }
    for (int i = 0; i < m_heapsize; i++)
    {
        if (arr[i].getpriority() < lower)
        {
            lower = arr[i].getpriority();
            index = i;
        }
    }
    string output = arr[index].getfirst() + ", ";
    output = output + arr[index].getlast() + ", ";
    output = output + to_string(arr[index].getpriority());
    return output;
}
void patient::patient_report()
{
    if (m_heapsize == 0)
    {
        throw(runtime_error("faild,heap is empty"));
    }
    else
    {
        for (int i = 0; i < m_heapsize; i++)
        {
            string output = "";
            output = arr[i].getlast() + ", ";
            output = output + arr[i].getfirst() + ", ";
            output = output + to_string(arr[i].getpriority());
            cout << output << endl;
        }
    }
}
int patient::patient_token(string first, string last)
{
    bool flag = false;
    int out = -1;
    for (int i = 0; i < m_heapsize; i++)
    {
        if (arr[i].getfirst() == first && arr[i].getlast() == last)
        {
            flag = true;
            out = i;
            break;
        }
    }
    if (!flag)
    {
        throw(runtime_error("patient not found!"));
    }
    return out + 1;
}
string patient::search(string first, string last)
{
    bool flag = false;
    string output = "";
    for (int i = 0; i < m_heapsize; i++)
    {
        if (arr[i].getfirst() == first && arr[i].getlast() == last)
        {

            output = arr[i].getfirst() + ", ";
            output = output + arr[i].getlast() + ", ";
            output = output + to_string(arr[i].getpriority());
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        throw(runtime_error("patient not found!"));
    }
    return output;
}
int patient::patient_c()
{
    return m_heapsize;
}
void patient::heapify(int size, int index)
{
    //entry not nessary
    int partent = index;
    int one_c = 3 * index + 1;
    int two_c = 3 * index + 2;
    int three_c = 3 * index + 3;

    if (three_c < size && arr[three_c].getpriority() > arr[partent].getpriority())
    {
        partent = three_c;
    }
    if (two_c < size && arr[two_c].getpriority() > arr[partent].getpriority())
    {
        partent = two_c;
    }

    if (one_c < size && arr[one_c].getpriority() > arr[partent].getpriority())
    {
        partent = one_c;
    }
    if (partent != index)
    {
        string first = arr[partent].getfirst();
        string last = arr[partent].getlast();
        int num = arr[partent].getpriority();
        arr[partent].setfirst(arr[index].getfirst());
        arr[partent].setlast(arr[index].getlast());
        arr[partent].setpriority(arr[index].getpriority());
        arr[index].setfirst(first);
        arr[index].setlast(last);
        arr[index].setpriority(num);

        heapify(size, partent);
    }
}
void patient::buildheap(int size)
{
    int index = floor((size / 3) - 1);
    //cout<<index<<" i ma mheare"<<arr[index].getpriority()<<endl;
    for (int i = index; i >= 0; i--)
    {
        heapify(size, i);
    }
}

patient::~patient()
{
    delete[] arr;
}
#include "doctor_min.h"
doctor::doctor()
{
    m_heapsize = 0;
    m_size = 1000; //size the max heap
    arr = new people[m_size];
}
doctor::~doctor()
{
    delete[] arr;
}
void doctor::inital_d(people *entery, int size)
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
void doctor::remove_d()
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
void doctor::insert(string first, string last, int num)
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
void doctor::heapify(int size, int index)
{
    int partent = index;
    int one_c = 3 * index + 1;
    int two_c = 3 * index + 2;
    int three_c = 3 * index + 3;

    if (three_c < size && arr[three_c].getpriority() < arr[partent].getpriority())
    {
        partent = three_c;
    }
    if (two_c < size && arr[two_c].getpriority() < arr[partent].getpriority())
    {
        partent = two_c;
    }

    if (one_c < size && arr[one_c].getpriority() < arr[partent].getpriority())
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
void doctor::buildheap(int size)
{
    int index = floor((size / 3));
    //cout<<"index in build heap "<<index<<" and size pass in"<<size<<endl;
    //cout<<index<<" i ma mheare"<<arr[index].getpriority()<<endl;
    for (int i = index; i >= 0; i--)
    {
        heapify(size, i);
    }
}
string doctor::next_doc()
{
    if (m_heapsize == 0)
    {
        throw(runtime_error("faild,heap is empty"));
    }
    string output = arr[0].getfirst() + ", ";
    output = output + arr[0].getlast() + ", ";

    return output;
}
bool doctor::check_dup(string first, string last)
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
void doctor::downheap(int index)
{
    int partent = index;
    int one_c = 3 * index + 1;
    int two_c = 3 * index + 2;
    int three_c = 3 * index + 3;
    if (three_c < m_heapsize && arr[three_c].getpriority() < arr[partent].getpriority())
    {
        partent = three_c;
    }

    if (two_c < m_heapsize && arr[two_c].getpriority() < arr[partent].getpriority())
    {
        partent = two_c;
    }

    if (one_c < m_heapsize && arr[one_c].getpriority() < arr[partent].getpriority())
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
void doctor::pritall()
{
    cout << "heap_size" << m_heapsize << endl;
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
bool doctor::check_avaliable(string first, string last)
{
    bool flag = false;
    bool flag2 = false;
    if (m_heapsize == 0)
    {
        throw(runtime_error("faild,heap is empty"));
    }
    else
    {
        for (int i = 0; i < m_heapsize; i++)
        {
            string output = "";
            if (arr[i].getfirst() == first && arr[i].getlast() == last)
            {
                flag2 = true;
                if (arr[i].getpriority() < 22)
                {
                    flag = true;
                }
            }
        }
        if (!flag2)
        {
            throw(runtime_error("doctor record not found!"));
        }
    }
    return flag;
}
int doctor::totaldoc()
{
    return m_heapsize;
}
int doctor::totalavaliable()
{
    int out = 0;
    for (int i = 0; i < m_heapsize; i++)
    {
        string output = "";

        if (arr[i].getpriority() < 22)
        {
            out++;
        }
    }
    return out;
}
void doctor::avaliable_report()
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
            if (arr[i].getpriority() < 22)
            {
                output = arr[i].getfirst() + ", ";
                output = output + arr[i].getlast() + ", ";
                output = output + to_string(arr[i].getpriority());
                cout << output << endl;
            }
        }
    }
}
void doctor::busy_report()
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
            if (arr[i].getpriority() >= 22)
            {
                output = arr[i].getfirst() + ", ";
                output = output + arr[i].getlast() + ", ";
                output = output + to_string(arr[i].getpriority());
                cout << output << endl;
            }
        }
    }
}
bool doctor::search(string first, string last)
{
    bool flag = false;
    for (int i = 0; i < m_heapsize; i++)
    {
        if (arr[i].getfirst() == first && arr[i].getlast() == last)
        {
            flag = true;
        }
    }
    if (!flag)
    {
        throw(runtime_error("doctor record not found!"));
    }
    return flag;
}
int doctor::patient_count(string first, string last)
{
    bool flag = false;
    int output = 0;
    for (int i = 0; i < m_heapsize; i++)
    {
        if (arr[i].getfirst() == first && arr[i].getlast() == last)
        {

            output = arr[i].getpriority();
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        throw(runtime_error("doctor record not found!"));
    }
    return output;
}
void doctor::change_patient_C(string first, string last, int num)
{
    if (search(first, last))
    {
        int index;
        for (int i = 0; i < m_heapsize; i++)
        {
            if (arr[i].getfirst() == first && arr[i].getlast() == last)
            {
                index = i;
            }
        }
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
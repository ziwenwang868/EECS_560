#include "disjoint.h"
dis_jointSet::dis_jointSet()
{
    arr = new set_node *[100];
    m_size = 0;
}
void dis_jointSet::makeSet(vector<int> orig)
{

    for (int i = 0; i < (int)orig.size(); i++)
    {
        arr[i] = new set_node();
        arr[i]->set_entry(orig[i]);
        m_size++;
        //cout<<arr[i]->get_entry()<<endl;
    }
}
set_node *dis_jointSet::found(int x)
{
    set_node *re = nullptr;
    for (int i = 0; i < m_size; i++)
    {
        if (arr[i]->get_entry() == x)
        {
            re = arr[i];
            break;
        }
    }
    return re;
}
set_node *dis_jointSet::check_parents(set_node *x)
{
    if (x != nullptr)
    {
        if (x->get_parent() == nullptr)
        {
            return x;
        }
        else
        {
            return check_parents(x->get_parent());
        }
    }
    else
    {
        return nullptr;
    }
}
int dis_jointSet::find_repersent(set_node *x)
{
    if (x->get_parent() == nullptr)
    {
        return x->get_entry();
    }
    else
    {
        return find_repersent(x->get_parent());
    }
}
void dis_jointSet::Union_set(int h1, int h2)
{

    set_node *i = check_parents(found(h1));
    set_node *j = check_parents(found(h2));
    bool ok = false;
    bool flag = false;

    if (i != nullptr && j != nullptr)
    {
        ok = true;
        if (i->get_rank() <= j->get_rank())
        {
            i->set_parent(j);
            flag = true;
            if (i->get_rank() == j->get_rank())
            {
                j->set_rank(j->get_rank() + 1);
            }
        }
        else
        {
            j->set_parent(i);
        }
    }
    if (ok)
    {
        cout << h1 << " and " << h2 << " have been merged. The representative element is ";
        if (flag)
        {
            cout << find_repersent(i) << endl;
        }
        else
        {
            cout << find_repersent(j) << endl;
        }
    }
    else
    {
        cout << "unable to merge due to unfound entry in the set" << endl;
    }
}
void dis_jointSet::find(int x)
{
    set_node *to_go = found(x);
    if (to_go != nullptr)
    {
        cout << "Element " << x << " has been found successfully. The representative element is " << find_repersent(to_go) << " ." << endl;
    }
    else
    {
        cout << " Sorry! " << x << " is not found!" << endl;
    }
}
set_node *dis_jointSet::get_partentsptr(set_node *x)
{
    if (x->get_parent() == nullptr)
    {
        return x;
    }
    else
    {
        return get_partentsptr(x->get_parent());
    }
}
bool dis_jointSet::check(int x)
{
    bool flag = false;
    for (int i = 0; i < m_size; i++)
    {
        if (arr[i]->get_entry() == x)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
void dis_jointSet::pathcomp(int x)
{
    set_node *item = found(x);
    if (item != nullptr)
    {
        if (find_repersent(item) != x)
        {
            set_node *temp = get_partentsptr(item);
            set_node *temp_call = item->get_parent();
            item->set_parent(temp);
            pathcomp(temp_call->get_entry());
        }
    }
}
void dis_jointSet::printpath(int x)
{
    set_node *path = nullptr;
    if (x > 0 && x <= m_size)
    {
        for (int i = 0; i < x; i++)
        {
            path = arr[i];
        }
    }
    else
    {
        throw(runtime_error("index number is incorrect"));
    }

    cout << "The path for the element " << x << " is : ";
    cout << path->get_entry();
    while (path->get_entry() != find_repersent(path))
    {
        path = path->get_parent();
        cout << " -> " << path->get_entry();
    }
    cout << endl;
}
dis_jointSet::~dis_jointSet()
{
    for (int i = 0; i < m_size; i++)
    {
        delete arr[i];
    }
    delete[] arr;
}
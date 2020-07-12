#include "maxmin.h"
maxmin::maxmin()
{
    heapsize = 0;
}
void maxmin::insert(string name, int num)
{
    int test_size = heapsize + 1;
    if (test_size > 1000)
    {
        throw(runtime_error("Insertion failed, surpass the max size"));
    }
    else
    {
        arr[heapsize].setup(name, num);

        //cout<<"level: "<<floor(heapsize/2)<<endl;
        heapfiy(heapsize);
        heapsize++;
        //heapfiy(floor(heapsize));
    }
}
int maxmin::get_parent(int x)
{
    if (x <= 0)
    {
        return -1;
    }
    else
    {
        return floor((x - 1) / 2);
    }
}
int maxmin::get_grandpar(int x)
{
    return get_parent(get_parent(x));
}
bool maxmin::max_level_check(int num)
{
    //cout<<"level: "<<floor(log(num))<<endl;
    if ((int)ceil(log2(num + 2) - 1) % 2 == 0 || num == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void maxmin::minup(int x)
{
    if (get_grandpar(x) != -1)
    {
        if (arr[x].getnum() < arr[get_grandpar(x)].getnum())
        {
            arr[x] == arr[get_grandpar(x)];
            minup(get_grandpar(x));
        }
    }
}
void maxmin::maxup(int x)
{
    if (get_grandpar(x) != -1)
    {
        if (arr[x].getnum() > arr[get_grandpar(x)].getnum())
        {
            arr[x] == arr[get_grandpar(x)];
            maxup(get_grandpar(x));
        }
    }
}
void maxmin::heapfiy(int num)
{
    if (get_parent(num) != -1)
    {
        if (max_level_check(num))
        {
            if (arr[num].getnum() < arr[get_parent(num)].getnum())
            {
                arr[num] == arr[get_parent(num)];
                minup(get_parent(num));
            }
        }
        else
        {
            if (arr[num].getnum() > arr[get_parent(num)].getnum())
            {
                arr[num] == arr[get_parent(num)];
                maxup(get_parent(num));
            }
        }
    }
}
void maxmin::delete_max()
{
    if (heapsize > 0)
    {
        arr[0] == arr[heapsize - 1];
        cout << arr[heapsize - 1].getname() << " game with " << arr[heapsize - 1].getnum() << "k downloads has been deleted successfully." << endl;
        arr[heapsize - 1].setEmpty();
        heapsize--;
        down_heap(0);
    }
    else
    {
        throw(runtime_error("delete Max failed, heap empty!"));
    }
}
int maxmin::get_index(string name, int num)
{
    int re = -1;
    for (int i = 0; i < heapsize; i++)
    {
        if (arr[i].getname() == name && arr[i].getnum() == num)
        {
            re = i;
            break;
        }
    }
    return re;
}
void maxmin::remove(string name, int num)
{
    int index = get_index(name, num);
    if (index != -1)
    {
        if (index == 0)
        {
            delete_max();
        }
        else
        {
            arr[index] == arr[heapsize - 1];
            cout << arr[heapsize - 1].getname() << " game with " << arr[heapsize - 1].getnum() << "k downloads has been deleted successfully." << endl;
            arr[heapsize - 1].setEmpty();
            heapsize--;
            down_heap(index);
        }
    }
    else
    {
        throw(runtime_error("failed remove, no iteam found in heap!"));
    }
}
void maxmin::down_heap(int index)
{
    //int parenet = index;
    //int left = 2 * index + 1;
    //int right = 2 * index + 2;
    if (max_level_check(index))
    {
        maxdown(index);
    }
    else
    {
        mindown(index);
    }
}
void maxmin::mindown(int x)
{
    int min_child = min_lv_child(x);
    if (min_child != -1)
    {
        int min_grand = min_lv_grand(x);
        if (min_grand != -1 && arr[min_grand].getnum() < arr[min_child].getnum())
        {
            if (arr[min_grand].getnum() < arr[x].getnum())
            {
                arr[min_grand] == arr[x];
                if (arr[min_grand].getnum() > arr[get_parent(min_grand)].getnum())
                {
                    arr[min_grand] == arr[get_parent(min_grand)];
                }
                mindown(min_grand);
            }
        }
        else
        {
            if (arr[min_child].getnum() < arr[x].getnum())
            {
                arr[min_child] == arr[x];
            }
        }
    }
}
void maxmin::maxdown(int x)
{
    int max_child = max_lv_child(x);
    if (max_child != -1)
    {
        int max_grand = max_lv_grand(x);
        if (max_grand != -1 && arr[max_grand].getnum() > arr[max_child].getnum())
        {
            if (arr[max_grand].getnum() > arr[x].getnum())
            {
                arr[max_grand] == arr[x];
                if (arr[max_grand].getnum() < arr[get_parent(max_grand)].getnum())
                {
                    arr[max_grand] == arr[get_parent(max_grand)];
                }
                maxdown(max_grand);
            }
        }
        else
        {
            if (arr[max_child].getnum() > arr[x].getnum())
            {
                arr[max_child] == arr[x];
            }
        }
    }
}
int maxmin::min_lv_child(int x)
{
    if (arr[find_child(x, 1)].getnum() != -1)
    {
        int min_lv_lc = find_child(x, 1);
        if (arr[find_child(x, 2)].getnum() != -1 && arr[find_child(x, 2)].getnum() < arr[min_lv_lc].getnum())
        {
            min_lv_lc = find_child(x, 2);
        }
        return min_lv_lc;
    }
    else
    {
        return -1;
    }
}
int maxmin::min_lv_grand(int x)
{
    if (arr[find_grand_child(x, 1)].getnum() != -1)
    {
        int min_lv_gr = find_grand_child(x, 1);
        for (int i = 2; i <= 4; i++)
        {
            if (arr[find_grand_child(x, i)].getnum() != -1 && arr[find_grand_child(x, i)].getnum() < arr[min_lv_gr].getnum())
            {
                min_lv_gr = find_grand_child(x, i);
            }
        }
        return min_lv_gr;
    }
    else
    {
        return -1;
    }
}
int maxmin::max_lv_child(int x)
{
    if (arr[find_child(x, 1)].getnum() != -1)
    {
        int max_lv_lc = find_child(x, 1);
        if (arr[find_child(x, 2)].getnum() != -1 && arr[find_child(x, 2)].getnum() > arr[max_lv_lc].getnum())
        {
            max_lv_lc = find_child(x, 2);
        }
        return max_lv_lc;
    }
    else
    {
        return -1;
    }
}
int maxmin::max_lv_grand(int x)
{
    if (arr[find_grand_child(x, 1)].getnum() != -1)
    {
        int max_lv_gr = find_grand_child(x, 1);
        for (int i = 2; i <= 4; i++)
        {
            if (arr[find_grand_child(x, i)].getnum() != -1 && arr[find_grand_child(x, i)].getnum() > arr[max_lv_gr].getnum())
            {
                max_lv_gr = find_grand_child(x, i);
            }
        }
        return max_lv_gr;
    }
    else
    {
        return -1;
    }
}
int maxmin::find_child(int i, int j)
{
    return 2 * i + j;
}
int maxmin::find_grand_child(int i, int j)
{
    return 4 * i + 2 + j;
}
int maxmin::totalmax()
{
    int sum = 0;
    for (int i = 0; i < heapsize; i++)
    {
        if (max_level_check(i))
        {
            sum = sum + arr[i].getnum();
        }
    }
    return sum;
}
int maxmin::totalmin()
{
    int sum = 0;
    for (int i = 0; i < heapsize; i++)
    {
        if (!max_level_check(i))
        {
            sum = sum + arr[i].getnum();
        }
    }
    return sum;
}
void maxmin::printAtmax()
{
    string output = "";
    for (int i = 0; i < heapsize; i++)
    {
        if (max_level_check(i))
        {
            output = output + arr[i].getname() + ",";
        }
    }
    output.resize(output.size() - 1);
    cout << output << endl;
}
void maxmin::printAtmin()
{
    string output = "";
    for (int i = 0; i < heapsize; i++)
    {
        if (!max_level_check(i))
        {
            output = output + arr[i].getname() + ",";
        }
    }
    output.resize(output.size() - 1);
    cout << output << endl;
}
void maxmin::test_print()
{
    for (int i = 0; i < heapsize; i++)
    {
        //cout << " name " << arr[i].getname() << " num " << arr[i].getnum() << endl;
        cout << "parent " << arr[i].getnum() << " left " << arr[2 * i + 1].getnum() << " right " << arr[2 * i + 2].getnum() << endl;
    }
}
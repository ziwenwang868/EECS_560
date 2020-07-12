#include "minskew.h"
minskew::minskew()
{
    root = nullptr;
}
minskew::~minskew()
{
    clear();
}

void minskew::insert(int entry)
{
    node *temp = new node(entry);
    if (root != nullptr)
    {
        root = merge(temp, root);
    }
    else
    {
        root = temp;
    }
}
void minskew::deletemin()
{
    if (root == nullptr)
    {
        throw(runtime_error("failed in delete min, three is empty"));
    }
    else
    {
        node *left = root->getleft();
        node *right = root->getright();
        delete root;
        root = merge(left, right);
    }
}

node *minskew::merge(node *h1, node *h2)
{
    if (h1 == nullptr)
    {
        return h2;
    }
    else if (h2 == nullptr)
    {
        return h1;
    }
    else if (h1->data > h2->data)
    {
        std::swap(h1, h2);
    }
    node *temp = h1->right;
    h1->right = h1->left;
    h1->left = merge(temp, h2);
    return h1;
}

void minskew::Level(node *h)
{
    if (h == nullptr)
    {
        throw(runtime_error("failed in print,empty heap already!"));
    }
    std::queue<node *> temp;
    temp.push(h);
    while (!temp.empty())
    {
        node *n = temp.front();
        std::cout << n->data << " ";
        temp.pop();

        if (n->left != nullptr)
        {
            temp.push(n->left);
        }
        if (n->right != nullptr)
        {
            temp.push(n->right);
        }
    }
}
void minskew::printlevel()
{
    Level(root);
}

void minskew::clear()
{
    clean(root);
}
void minskew::clean(node *h)
{
    if (h != nullptr)
    {
        clean(h->left);
        clean(h->right);
        delete h;
    }
}

void minskew::build(vector<int> in)
{
    for (int i = 0; i < in.size(); i++)
    {
        insert(in[i]);
    }
}
float minskew::build_test(int size)
{
    clock_t start = clock();
    int random_number;
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        random_number = rand() % 5000000 + 1;
        insert(random_number);
    }
    clock_t end = clock();
    float totalTime = (end - start) / (float)CLOCKS_PER_SEC;
    return totalTime;
}
float minskew::delete_test(int size)
{
    clock_t start = clock();
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        deletemin();
    }
    clock_t end = clock();
    float totalTime = (end - start) / (float)CLOCKS_PER_SEC;
    return totalTime;
}
#include "minleftist.h"
minleftist::minleftist()
{
    root = nullptr;
}
minleftist::~minleftist()
{
    clear();
}

void minleftist::insert(int entry)
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
void minleftist::deletemin()
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

node *minleftist::merge(node *h1, node *h2)
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
    h1->right = merge(h1->right, h2);
    if (h1->left == nullptr && h1->right != nullptr)
    {

        h1->left = h1->right;
        h1->right = nullptr;
    }
    else
    {

        if (h1->left->rank < h1->right->rank)
        {
            std::swap(h1->left, h1->right);
        }

        h1->rank = h1->right->rank + 1;
    }
    return h1;
}

void minleftist::Level(node *h)
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
void minleftist::printlevel()
{
    Level(root);
}

void minleftist::clear()
{
    clean(root);
}
void minleftist::clean(node *h)
{
    if (h != nullptr)
    {
        clean(h->left);
        clean(h->right);
        delete h;
    }
}


void minleftist::build(vector<int> in)
{
    for (int i = 0; i < in.size(); i++)
    {
        insert(in[i]);
    }
}

float minleftist::build_test(int size)
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
float minleftist::delete_test(int size)
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
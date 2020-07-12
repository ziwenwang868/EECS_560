#include "bst.h"
bst::bst()
{
    root = nullptr;
    key = -1;

    output_storage = "";
    Nodecopy = nullptr;
    count = 0;
}
bst::~bst()
{
    clear();
}
void bst::addItem(int entry)
{
    RecAdd(entry, root);
}
bnode<int> *bst::InorderSccu(int item, bnode<int> *current)
{
    bnode<int> *temp = nullptr;

    if (!current)
    {
        return nullptr;
    }

    while (current->getEntry() != item)
    {
        if (current->getEntry() > item)
        {
            temp = current;
            current = current->getLeft();
        }
        else
        {
            current = current->getRight();
        }
    }
    if (current && current->getRight())
    {
        temp = minValuenode(current->getRight());
    }

    return temp;
}

int bst::InorderSuccessor(int item)
{
    if (Search(item))
    {
        Nodecopy = InorderSccu(item, root);
    }
    else
    {
        throw(runtime_error("Value not found InorderSuccessor() Failed"));
    }
    return Nodecopy->getEntry();
}
bnode<int> *bst::minValuenode(bnode<int> *current)
{
    if (!current)
    {
        return nullptr;
    }
    while (current->getLeft())
    {
        current = current->getLeft();
    }
    return current;
}
void bst::RecAdd(int entry, bnode<int> *current)
{
    if (root == nullptr)
    {
        root = new bnode<int>();
        root->setEntry(entry);
    }
    else if (entry < current->getEntry())
    {
        if (current->getLeft() == nullptr)
        {
            bnode<int> *temp = new bnode<int>();
            temp->setEntry(entry);
            current->setLeft(temp);
        }
        else
        {
            RecAdd(entry, current->getLeft());
        }
    }
    else if (current->getEntry() <= entry)
    {
        if (current->getRight() == nullptr)
        {
            bnode<int> *temp = new bnode<int>();
            temp->setEntry(entry);
            current->setRight(temp);
        }
        else
        {
            RecAdd(entry, current->getRight());
        }
    }
}

int bst::getheight(bnode<int> *current)
{
    if (current == nullptr)
    {
        return 0;
    }
    else
    {
        int left = getheight(current->getLeft());
        int right = getheight(current->getRight());
        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
}
void bst::deleteAll(bnode<int> *current)
{
    if (current != nullptr)
    {
        deleteAll(current->getLeft());
        deleteAll(current->getRight());
        delete current;
    }
}
void bst::clear()
{
    if (root != nullptr)
    {
        deleteAll(root);
    }
}
string bst::Level_trv()
{
    output_storage = "";
    for (int i = 1; i <= getheight(root); i++)
    {
        LevelOrder(i, root);
    }
    if (root != nullptr && output_storage.size() != 0)
    {
        output_storage.resize(output_storage.size() - 1);
    }
    return output_storage;
}

string bst::spiral_trv()
{
    output_storage = "";
    for (int i = 1; i <= getheight(root); i++)
    {
        if (i % 2 == 0)
        {
            spiralevel(i, root);
        }
        else
        {
            LevelOrder(i, root);
        }
    }
    if (root != nullptr && output_storage.size() != 0)
    {
        output_storage.resize(output_storage.size() - 1);
    }
    return output_storage;
}

void bst::LevelOrder(int level, bnode<int> *current)
{
    if (current != nullptr)
    {
        if (level == 1)
        {
            output_storage = output_storage + to_string(current->getEntry()) + ",";
        }
        else if (level > 1)
        {
            LevelOrder(level - 1, current->getLeft());
            LevelOrder(level - 1, current->getRight());
        }
    }
}

void bst::spiralevel(int level, bnode<int> *current)
{
    if (current != nullptr)
    {
        if (level == 1)
        {
            output_storage = output_storage + to_string(current->getEntry()) + ",";
        }
        else if (level > 1)
        {
            spiralevel(level - 1, current->getRight());
            spiralevel(level - 1, current->getLeft());
        }
    }
}

bnode<int> *bst::RecRemove(bnode<int> *current, int key)
{
    if (current == nullptr)
    {
        return current;
    }
    if (current->getEntry() > key)
    {
        current->setLeft(RecRemove(current->getLeft(), key));
    }
    else if (current->getEntry() < key)
    {
        current->setRight(RecRemove(current->getRight(), key));
    }
    else
    {
        if (current->getLeft() == nullptr)
        {
            bnode<int> *temp = current->getRight();
            delete current;
            return temp;
        }
        else if (current->getRight() == nullptr)
        {
            bnode<int> *temp = current->getLeft();
            delete current;
            return temp;
        }
        bnode<int> *min = Removenode(current->getRight());
        int successor = min->getEntry();

        current->setEntry(min->getEntry());
        current->setRight(RecRemove(current->getRight(), successor));
    }
    return current;
}
bnode<int> *bst::Removenode(bnode<int> *current)
{
    bnode<int> *temp = current;
    while (temp && temp->getLeft() != nullptr)
    {
        temp = temp->getLeft();
    }
    return temp;
}
void bst::remove(int item)
{
    if (Search(item))
    {
        root = RecRemove(root, item);
    }
    else
    {
        throw(runtime_error("Value not found Deletion failed"));
    }
}
//

//test only
void bst::inordertr(bnode<int> *current)
{
    if (current != nullptr)
    {
        inordertr(current->getLeft());
        if (count <= key)
        {
            output_storage = to_string(current->getEntry());
            count++;
        }
        inordertr(current->getRight());
    }
}
string bst::kthSmall(int entry)
{
    count = 0;
    output_storage = "";
    entry--;
    if (entry < 0)
    {
        throw(runtime_error("Invailed input KthSmallestitem() Failed"));
    }
    key = entry;
    inordertr(root);

    return output_storage;
}

string bst::leftsideview()
{
    output_storage = "";
    bnode<int> *temp = root;
    while (temp)
    {
        output_storage = output_storage + to_string(temp->getEntry()) + ",";
        temp = temp->getLeft();
    }
    if (root != nullptr && output_storage.size() != 0)
    {
        output_storage.resize(output_storage.size() - 1);
    }
    return output_storage;
}

string bst::rightsideview()
{
    output_storage = "";
    bnode<int> *temp = root;
    while (temp)
    {
        output_storage = output_storage + to_string(temp->getEntry()) + ",";
        temp = temp->getRight();
    }
    if (root != nullptr && output_storage.size() != 0)
    {
        output_storage.resize(output_storage.size() - 1);
    }
    return output_storage;
}

int bst::RecSearch(bnode<int> *current, int key)
{
    if (current->getEntry() == key)
    {
        return current->getEntry();
    }
    else if (current->getEntry() > key)
    {
        if (current->getLeft() != nullptr)
        {
            return RecSearch(current->getLeft(), key);
        }
    }
    else if (current->getEntry() < key)
    {
        if (current->getRight() != nullptr)
        {
            return RecSearch(current->getRight(), key);
        }
    }

    throw(runtime_error("no marching"));
}

bool bst::Search(int key)
{
    bool re = false;
    try
    {
        if (key == RecSearch(root, key))
        {
            re = true;
        }
    }
    catch (runtime_error &e)
    {
    }
    return re;
}
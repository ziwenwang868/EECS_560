#include "btree.h"

btree::btree()
{
  level = 1;
  nodecount = 0;
  nodefordelete = 0;
  infor_mode = true;
  addscussed = false;
  root = nullptr;
}
btree::~btree()
{
  setinfor(false);
  while (root != nullptr)
  {
    RemoveMovie();
  }
}
void btree::setinfor(bool sw)
{
  infor_mode = sw;
}
void btree::AddMovie(string title, float rate)
{
  if (Rate_check(rate))
  {
    addscussed = false;
    adding(root, new Data(title, rate), 1);
  }
  else
  {
    throw(runtime_error("Invalid rate, add movie failed !"));
  }
}

int btree::gethight(bnode<Data *> *tree)
{
  if (tree == nullptr)
  {
    return 0;
  }
  else
  {
    int left = gethight(tree->getLeft());
    int right = gethight(tree->getRight());
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

int btree::test()
{
  return numberofnode();
}

void btree::adding(bnode<Data *> *tree, Data *entry, int m_level)
{
  if (nodecount == (int)pow(2, level))
  {
    nodecount = 0;
    level++;
  }

  if (root == nullptr)
  {
    root = new bnode<Data *>(entry);
  }
  else if (tree->getLeft() == nullptr || tree->getRight() == nullptr)
  {
    if (tree->getLeft() == nullptr)
    {
      //cout << "parent: " << tree->getEntry()->getname() << " on left : " << entry->getname() << endl;
      tree->setLeft(new bnode<Data *>(entry));
      nodecount++;
      addscussed = true;
    }

    else if (tree->getRight() == nullptr)
    {
      //cout << "parent: " << tree->getEntry()->getname() << " on right: " << entry->getname() << endl;
      tree->setRight(new bnode<Data *>(entry));
      nodecount++;
      addscussed = true;
    }
  }
  else
  {
    int down = m_level + 1;
    if (down <= level)
    {
      if (tree->getLeft() != nullptr && !addscussed)
      {
        adding(tree->getLeft(), entry, down);
      }
      if (tree->getRight() != nullptr && !addscussed)
      {
        adding(tree->getRight(), entry, down);
      }
    }
  }
}

bool btree::isfull()
{
  bool r = false;
  if (numberofnode() == (int)pow(2, level))
  {
    r = true;
  }
  return r;
}

int btree::numberofnode()
{
  if (root != nullptr)
  {
    return chekcnodes(root, gethight(root));
  }
  else
  {
    return 0;
  }
}
int btree::printhight()
{
  if (root == nullptr)
  {
    return 1;
  }
  else
  {
    return gethight(root);
  }
}
void btree::RemoveMovie()
{
  if (root != nullptr)
  {
    d_scussed = false;
    nodefordelete = 0;
    removeing(root, gethight(root));
  }
  else
  {
    throw(runtime_error("Delete failed, empty tree!"));
  }
}
int btree::chekcnodes(bnode<Data *> *tree, int lev)
{
  if (lev == 2)
  {
    int count = 0;
    if (tree->getLeft() != nullptr)
    {
      count++;
    }
    if (tree->getRight() != nullptr)
    {
      count++;
    }
    return count;
  }
  else if (lev == 1)
  {
    return 0;
  }
  else
  {
    return chekcnodes(tree->getLeft(), lev - 1) + chekcnodes(tree->getRight(), lev - 1);
  }
}

void btree::removeing(bnode<Data *> *tree, int m_level)
{
  if (m_level == 2 && !d_scussed)
  {

    if (tree->getLeft() != nullptr && tree->getRight() == nullptr)
    {
      //cout<<"called when only left"<<endl;
      bnode<Data *> *temp = tree->getLeft();
      if (infor_mode)
      {
        cout << "The last movie with title " << temp->getEntry()->getname() << " and rating " << temp->getEntry()->getrate()
             << " has been deleted" << endl;
      }
      delete temp->getEntry();
      tree->setLeft(nullptr);
      delete temp;
      nodecount--;
      d_scussed = true;
    }
    else if (tree->getLeft() != nullptr && tree->getRight() != nullptr)
    {
      //cout<<"callled"<<endl;
      nodefordelete = nodefordelete + 2;
      //cout<<"parents "<<tree->getEntry()->getname()<<" node have not de "<<nodefordelete<<" node count "<<nodecount<<endl;
      if (nodefordelete == nodecount)
      {
        bnode<Data *> *temp = tree->getRight();
        if (infor_mode)
        {
          cout << "The last movie with title " << temp->getEntry()->getname() << " and rating " << temp->getEntry()->getrate()
               << " has been deleted" << endl;
        }
        delete temp->getEntry();
        tree->setRight(nullptr);
        delete temp;
        nodecount--;
        d_scussed = true;
      }
    }
  }
  else if (root == tree && root->getLeft() == nullptr)
  {
    if (infor_mode)
    {
      cout << "The last movie with title " << root->getEntry()->getname() << " and rating " << root->getEntry()->getrate()
           << " has been deleted" << endl;
    }
    delete root->getEntry();
    delete root;
    root = nullptr;
    nodecount--;
    d_scussed = true;
  }
  if (nodecount == 0)
  {
    level = gethight(root) - 1;
    //cout<<"level: "<<level<<endl;
    nodecount = numberofnode();
    //cout<<"node: "<<nodecount<<endl;
  }
  if (!d_scussed && m_level > 1)
  {
    //cout<<"go down!"<<endl;
    removeing(tree->getLeft(), m_level - 1);
    removeing(tree->getRight(), m_level - 1);
  }
}

bool btree::Rate_check(float rate)
{
  if (rate < 0.0 || rate > 5.0)
  {
    return false;
  }
  else
  {
    return true;
  }
}

string btree::preorder()
{
  output = "";
  preorder_trv(root);
  if (output.size() != 0)
  {
    output.resize(output.size() - 1);
  }
  else
  {
    output = "Tree is empty";
  }
  return output;
}

void btree::preorder_trv(bnode<Data *> *tree)
{
  if (tree != nullptr)
  {
    output = output + to_string((float)tree->getEntry()->getrate()) + " ,";
    preorder_trv(tree->getLeft());
    preorder_trv(tree->getRight());
  }
}

string btree::postorder()
{
  output = "";
  postorder_trv(root);
  if (output.size() != 0)
  {
    output.resize(output.size() - 1);
  }
  else
  {
    output = "Tree is empty";
  }
  return output;
}

void btree::postorder_trv(bnode<Data*>* tree)
{
  if (tree != nullptr)
  {
    postorder_trv(tree->getLeft());
    postorder_trv(tree->getRight());
    output = output + to_string((float)tree->getEntry()->getrate()) + " ,";
  }
}

string btree::inorder()
{
  output = "";
  inorder_trv(root);
  if (output.size() != 0)
  {
    output.resize(output.size() - 1);
  }
  else
  {
    output = "Tree is empty";
  }
  return output;
}
void btree::inorder_trv(bnode<Data*>*tree)
{
  if (tree != nullptr)
  {
    inorder_trv(tree->getLeft());
    output = output + to_string((float)tree->getEntry()->getrate()) + " ,";
    inorder_trv(tree->getRight());
  }
}

string btree::levelorder()
{
  output="";
  for(int i=1;i<=printhight();i++)
  {
    levelorder_trv(root,i);
  }
  if(root!=nullptr&&output.size()!=0)
  {
    output.resize(output.size() - 1);
  }
  else
  {
    output = "Tree is empty";
  }
  return output;
}
void btree::levelorder_trv(bnode<Data*>*tree, int m_level)
{
  if(tree!=nullptr)
  {
    if(m_level==1)
    {
      output = output + tree->getEntry()->getname() + ",";
    }
    else if(m_level>1)
    {
      levelorder_trv(tree->getLeft(),m_level-1);
      levelorder_trv(tree->getRight(),m_level-1);
    }
  }
}

bool btree::isLeaf(string name)
{
  bool out=false;
  if(searching(root,name))
  {
    out=true;
  }
  return out;
}

bool btree::searching(bnode<Data*>*tree,string key)
{
  
  if(tree!=nullptr)
  {
    if(tree->getEntry()->getname()==key)
    {
      if(tree->getLeft()==nullptr&&tree->getRight()==nullptr)
      {
        //cout<<"callled"<<endl;
        return true;
      }
    }
    return searching(tree->getLeft(),key)||searching(tree->getRight(),key);
  }
  return false;  
}

string btree::printleaves()
{
  output="";
  for(int i=1;i<=printhight();i++)
  {
    recleaves(root,i);
  }
  if(root!=nullptr&&output.size()!=0)
  {
    output.resize(output.size() - 1);
  }
  else
  {
    output = "Tree is empty";
  }
  return output;
}
void btree::recleaves(bnode<Data*>*tree,int m_level)
{
  if(tree!=nullptr)
  {
    if(m_level==1)
    {
      if(tree->getLeft()==nullptr&&tree->getRight()==nullptr)
      {
        output = output + tree->getEntry()->getname() + ",";
      }
      
    }
    else if(m_level>1)
    {
      recleaves(tree->getLeft(),m_level-1);
      recleaves(tree->getRight(),m_level-1);
    }
  }
}
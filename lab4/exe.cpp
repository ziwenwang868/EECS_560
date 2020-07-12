#include "exe.h"
exe::exe(string name)
{
  ifstream infile;
  string name_srting;
  float rating;

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
    while (infile >> name_srting >> rating)
    {
      name_srting.resize(name_srting.size() - 1);
      m_tree.AddMovie(name_srting, rating);
      //cout<<m_tree.possible_h()<<endl;
      //cout << "name " << name_srting << " size:" << name_srting.length() << " rate " << rating << endl;
    }
  }
  infile.close();
}
void exe::run()
{
  bool flag = true;
  int choice;
  float out_rate;
  string input;

  while (flag)
  {

    cout << endl;
    cout << "Please choose one of the following commands:" << endl;
    cout << "  1- Isfull" << endl;
    cout << "  2- AddMovie" << endl;
    cout << "  3- RemoveMovie" << endl;
    cout << "  4- Leaf" << endl;
    cout << "  5- PrintLeaves" << endl;
    cout << "  6- PrintTreeHeight" << endl;
    cout << "  7- Preorder" << endl;
    cout << "  8- Postorfer" << endl;
    cout << "  9- Inorder" << endl;
    cout << "  10-Levelorder" << endl;
    cout << "  11-Exit" << endl;
    cin >> choice;
    cout << "Output: ";
    if (choice == 11)
    {
      cout << "Goodbye!" << endl;
      flag = false;
    }
    if (choice == 1)
    {
      if (m_tree.isfull())
      {
        cout << " True " << endl;
      }
      else
      {
        cout << " False " << endl;
      }
    }
    if (choice == 2)
    {
      cout << "Please enter the movie title which you want to enter into the tree." << endl;
      cin >> input;
      cout << "Please enter the rating of your movie." << endl;
      cin >> out_rate;
      try
      {
        m_tree.AddMovie(input, out_rate);
        cout << "Record has been added successfully !" << endl;
      }
      catch (runtime_error &e)
      {
        cout << e.what() << endl;
      }
    }
    if (choice == 3)
    {
      try
      {
        m_tree.RemoveMovie();
      }
      catch (runtime_error &e)
      {
        cout << e.what() << endl;
      }
    }
    if (choice == 4)
    {
      cout << "Please enter the name of your movie which you want to test as a leaf node." << endl;
      cin >> input;

      if (m_tree.isLeaf(input))
      {
        cout << "The record with movie title " << input << " is a leaf node" << endl;
      }
      else
      {
        cout << "The record with movie title " << input << " is not a leaf node" << endl;
      }
    }
    if (choice == 5)
    {
      cout<<" The leaf nodes are: "<<m_tree.printleaves()<<endl;
    }
    if (choice == 6)
    {
      cout << " The hight of the tree is " << m_tree.printhight() - 1 << endl;
    }
    if (choice == 7)
    {
      cout << "Printing in Pre-Order: " << m_tree.preorder() << endl;
    }
    if (choice == 8)
    {
      cout << "Pinting in Post-Order: " << m_tree.postorder() << endl;
    }
    if (choice == 9)
    {
      cout << "Pinting in In-Order: " << m_tree.inorder() << endl;
    }
    if (choice == 10)
    {
      cout << "Pinting in Level-Order: " << m_tree.levelorder() << endl;
    }
  }
}

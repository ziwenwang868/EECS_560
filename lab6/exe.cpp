#include "exe.h"
exe::exe(string file)
{
    ifstream infile;
    int reading;

    infile.open(file);
    while (!infile.is_open())
    {
        string temp;
        cout << "Wrong file_Name try again: ";
        cin >> temp;
        infile.open(temp);
    }
    if (!(infile.peek() == EOF))
    {
        while (infile >> reading)
        {
            tree.addItem(reading);
        }
    }
    infile.close();
}

void exe::run()
{
    bool flag = true;
    int choice;

    while (flag)
    {
        cout << endl;
        cout << "Please choose one of the following commands:" << endl;
        cout << "  1- AddItem" << endl;
        cout << "  2- DeleteItem" << endl;
        cout << "  3- InorderSuccessor" << endl;
        cout << "  4- LevelOrder" << endl;
        cout << "  5- SpiralLevelOrder" << endl;
        cout << "  6- LeftSideView" << endl;
        cout << "  7- RightSideView" << endl;
        cout << "  8- KthSmallestltem" << endl;
        cout << "  9- Exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            int input;
            cout << "Enter the element to be added: ";
            cin >> input;
            tree.addItem(input);
            cout << "Element " << input << " was sccessfully added" << endl;
        }
        if (choice == 2)
        {
            int input;
            cout << "Enter the element tobe deleted: ";
            cin >> input;
            try
            {
                tree.remove(input);
                cout << "Element " << input << " was sccessfully deleted" << endl;
            }
            catch (runtime_error &e)
            {
                cout << e.what() << endl;
            }
        }
        if (choice == 3)
        {
            int input;
            cout << "Enter the element to which you want to know the inorder successor: ";
            cin >> input;
            try
            {
                int o = tree.InorderSuccessor(input);
                cout << "The inorder successor of " << input << " is " << o << endl;
            }
            catch (runtime_error &e)
            {
                cout << e.what() << endl;
            }
        }
        if (choice == 4)
        {
            cout << "Level order: " << tree.Level_trv() << endl;
        }
        if (choice == 5)
        {
            cout << "Spiral Level Order: " << tree.spiral_trv() << endl;
        }
        if (choice == 6)
        {
            cout << "Left Side View: " << tree.leftsideview() << endl;
        }
        if (choice == 7)
        {
            cout << "Right Side View: " << tree.rightsideview() << endl;
        }
        if (choice == 8)
        {
            int input;
            cout << "Enter the value of k: ";
            cin >> input;
            try
            {
                cout << tree.kthSmall(input) << endl;
            }
            catch(runtime_error& e)
            {
                cout<<e.what()<<endl;
            }
        }
        if (choice == 9)
        {
            cout<<"Done"<<endl;
            flag = false;
        }
    }
}
exe::~exe()
{
}

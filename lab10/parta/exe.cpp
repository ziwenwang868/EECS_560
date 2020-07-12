#include "exe.h"

exe::exe(string name)
{
    ifstream infile;
    int input;
    infile.open(name);
    while (!infile.is_open())
    {
        string temp;
        cout << "Wrong file_Name for patient try again: ";
        cin >> temp;
        infile.open(temp);
    }
    if (!(infile.peek() == EOF))
    {

        while (infile >> input)
        {
            orig.push_back(input);
        }
    }
    infile.close();
}

void exe::run()
{
    bool flag = true;
    while (flag)
    {
        int choice;
        cout << "-----------------------------------------------" << endl;
        cout << "\nPlease choose one of the following commands:\n";
        cout << "  1- MakeSet\n";
        cout << "  2- Union\n";
        cout << "  3- Find\n";
        cout << "  4- PathCompression\n";
        cout << "  5- PrintPath\n";
        cout << "  6. Exit\n\n";
        cout << "Please choose an option: ";
        cin >> choice;
        if (choice == 1)
        {
            dset.makeSet(orig);
            cout<<"The disjoint sets have been constructed."<<endl;
        }
        if (choice == 2)
        {
            int h1, h2;
            cout << "Enter the representative elements for the two sets which you wish to union:" << endl;
            cin >> h1;
            cin >> h2;
           
            dset.Union_set(h1, h2);
            
           
        }
        if (choice == 3)
        {
            int h;
            cout<<"Enter the element you want to search:"<<endl;
            cin>>h;
            dset.find(h);
        }
        if (choice == 4)
        {
            int h;
            cout<<"Enter the element on whose set you would want to perform path compression"<<endl;
            cin>>h;
            if(dset.check(h))
            {
                dset.pathcomp(h);
                cout<<"Path compression has been done successfully."<<endl;
            }
            else
            {
                cout<<"ath compression unsuccessfull."<<endl;
            }
            
        }
        if (choice == 5)
        {
            int h;
            cout<<"Enter the element you want to find the path for:"<<endl;
            cin>>h;
            try
            {
                dset.printpath(h);
            }
            catch(runtime_error& e)
            {
                cout<< e.what() << '\n';
            }
            
        }
        if (choice == 6)
        {
            flag = false;
        }
    }
}
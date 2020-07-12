#include "exe.h"
exe::exe(string filename)
{
    ifstream infile;
    string input;
    infile.open(filename);
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
            size_t one = input.find(",");
            string first = input.substr(0, one);
            input.erase(0, first.size() + 1);
            //size_t two = input.find(",");
            //string last = input.substr(0, two);
            //input.erase(0, last.size() + 1);
            int num = stoi(input);
            //cout<<"name "<<first<<" num "<<num<<endl;
            m_heap.insert(first, num);
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
        cout << "Please choose one of the following commands:" << endl;
        cout << " 1. AddGame" << endl;
        cout << " 2. DeleteMaxDownloadedGame" << endl;
        cout << " 3. DeleteGame" << endl;
        cout << " 4. PrintGamesAtMinimumLevels" << endl;
        cout << " 5. PrintGamesAtMaximumLevels" << endl;
        cout << " 6. TotalMinimumDownloadedGames" << endl;
        cout << " 7. TotalMaximumDownloadedGames" << endl;
        cout << " 8. Exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            string name;
            int num;
            cout << "Enter the name of the game you want to insert into the play store:" << endl;
            cin >> name;
            cout << "Enter the number of downloads for the game in thousands:" << endl;
            cin >> num;
            try
            {
                m_heap.insert(name, num);
                cout << " Output: A new game was successfully added to the playstore." << endl;
            }
            catch (runtime_error &e)
            {
                cout << e.what() << '\n';
            }
        }
        if (choice == 2)
        {
            try
            {
                m_heap.delete_max();
            }
            catch (runtime_error &e)
            {
                cout << e.what() << '\n';
            }
        }
        if (choice == 3)
        {
            string name;
            int num;
            cout << "Enter the name of the game you want to delete:" << endl;
            cin >> name;
            cout << "Enter the number of downloads of the game you want to delete:" << endl;
            cin >> num;
            try
            {
                cout << " Output: " << endl;
                m_heap.remove(name, num);
            }
            catch (runtime_error &e)
            {
                cout << e.what() << '\n';
            }
            //m_heap.test_print();
        }
        if (choice == 4)
        {
            cout << "Output: ";
            m_heap.printAtmin();
        }
        if (choice == 5)
        {
            cout << "Output: ";
            m_heap.printAtmax();
        }
        if (choice == 6)
        {
            cout << "Total number of TotalMinimumDownloadedGames: " << m_heap.totalmin() << " k." << endl;
        }
        if (choice == 7)
        {
            cout << "Total number of MaximumDownloadedGames: " << m_heap.totalmax() << " k." << endl;
        }
        if (choice == 8)
        {
            flag = false;
            cout << "Output: Bye!!!" << endl;
        }
        cout << endl;
    }
}
exe::~exe()
{
}
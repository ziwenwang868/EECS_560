#include "exe.h"
exe::exe()
{
    string input_name;
    //int matrix_in;
    ifstream input;
    input.open("data1.txt");
    while (!input.is_open())
    {
        string temp;
        cout << "Wrong file_Name try again: ";
        cin >> temp;
        input.open(temp);
    }
    string firstline;
    getline(input, firstline);
    size_t pos = firstline.find(",");
    size = stoi(firstline.substr(pos + 1, '\n'));

    arr = new int *[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            input >> arr[i][j];
        }
    }

    getline(input, input_name);
    getline(input, input_name);
    while (getline(input, input_name))
    {
        size_t pos = input_name.find(",");
        string island = input_name.substr(0, pos);
        //cout<<island<<endl;
        island_name.push_back(island);
    }

    pic.build(arr, size, island_name);
    input.close();
}
void exe::run()
{
    bool flag = true;
    while (flag)
    {
        int choice;
        cout << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "\nPlease choose one of the following commands:\n";
        cout << "  6. BFS\n";
        cout << "  7. DFS\n";
        cout << "  8. Kruskal MST\n";
        cout << "  9. Prim MST\n";
        cout << "  10. Exit\n\n";
        cout << "Enter your choice:\n";
        cin >> choice;
        if (choice == 6)
        {
            pic.BFS(0);
        }
        if (choice == 7)
        {
            pic.DFS(0);
        }
        if (choice == 8)
        {
            pic.KruskalMST();
        }
        if (choice == 9)
        {
            pic.PrimMST();
        }
        if (choice == 10)
        {
            pic.setfree();
            flag = false;
        }
    }
}
exe::~exe()
{
    for (int i = 0; i < size; i++)
    {
        delete []arr[i];
    }
    delete []arr;
}
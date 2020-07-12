#include "exe.h"
#include <vector>
exe::exe(string name)
{
    vector<int> in;
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
            cout << input << endl;
            in.push_back(input);
        }
    }
    leftist_tree.build(in);
    skew_tree.build(in);
    infile.close();
}
void exe::run()
{
    bool flag = true;
    while (flag)
    {
        int choice;
        cout << "\n-----Experimental profiling (Min leftist and Min skew heaps)-------\n\n";
        cout << "  1. Test build - min leftist heap\n";
        cout << "  2. Test delete min - min leftist heap\n";
        cout << "  3. Test build - min skew heap\n";
        cout << "  4. Test delete min - min skew heap\n";
        cout << "  5. Test performance of heaps\n";
        cout << "  6. Exit\n\n";
        cout << "Please choose an option: ";
        cin >> choice;
        if (choice == 1)
        {
            try
            {
                leftist_tree.printlevel();
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
                leftist_tree.deletemin();
                leftist_tree.printlevel();
            }
            catch (runtime_error &e)
            {
                cout << e.what() << '\n';
            }
        }
        if (choice == 3)
        {
            try
            {
                skew_tree.printlevel();
            }
            catch (runtime_error &e)
            {
                cout << e.what() << '\n';
            }
        }
        if (choice == 4)
        {
            try
            {
                skew_tree.deletemin();
                skew_tree.printlevel();
            }
            catch (runtime_error &e)
            {
                cout << e.what() << '\n';
            }
        }
        if (choice == 5)
        {
            minleftist test_t[5];
            float l_building[5];
            float l_delete[5];
            minskew test_sk[5];
            float sk_building[5];
            float sk_delete[5];
            int count1 = 100000;
            int count2 = 100000;
            for (int i = 0; i < 5; i++)
            {
                l_building[i] = test_t[i].build_test(count1);
                sk_building[i] = test_sk[i].build_test(count1);
                count1 = count1 + 100000;
            }
            for (int j = 0; j < 5; j++)
            {
                l_delete[j] = test_t[j].delete_test(count2);
                sk_delete[j] = test_sk[j].delete_test(count2);
                count2 = count2 + 100000;
            }
            cout << "\n\n_____________Performance (Min Leftist Heap)______________";
            cout << "\n_______________________________________________________________________________";
            cout << "\n| Input size          | 100,000  | 200,000  | 300,000  | 400,000  | 500,000  | ";
            cout << "\n_______________________________________________________________________________";
            cout << "\n| Build (s)           | " << l_building[0] << " | " << l_building[1] << " | " << l_building[2] << " | " << l_building[3] << " | " << l_building[4] << " | ";
            cout << "\n_______________________________________________________________________________";
            cout << "\n| Delete min (s)      | " << l_delete[0] << " | " << l_delete[1] << " | " << l_delete[2] << " | " << l_delete[3] << " | " << l_delete[4] << " | ";
            cout << "\n_______________________________________________________________________________";
            cout << "\n\n";
            cout << "\n\n______________Performance (Min Skew Heap)________________";
            cout << "\n_______________________________________________________________________________";
            cout << "\n| Input size          | 100,000  | 200,000  | 300,000  | 400,000  | 500,000  | ";
            cout << "\n_______________________________________________________________________________";
            cout << "\n| Build (s)           | " << sk_building[0] << " | " << sk_building[1] << " | " << sk_building[2] << " | " << sk_building[3] << " | " << sk_building[4] << " | ";
            cout << "\n_______________________________________________________________________________";
            cout << "\n| Delete min (s)      | " << sk_delete[0] << " | " << sk_delete[1] << " | " << sk_delete[2] << " | " << sk_delete[3] << " | " << sk_delete[4] << " | ";
            cout << "\n_______________________________________________________________________________";
            cout << "\n\n";
        }
        if (choice == 6)
        {
            flag = false;
        }
    }
}
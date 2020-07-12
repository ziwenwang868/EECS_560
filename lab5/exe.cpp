#include "exe.h"

exe::exe()
{
    tablesize = 1000003;
}
void exe::run()
{
    int size = 1000003;
    int random_num;
    int input_size = floor(size * 0.1);
    dhash h(size);
    srand(time(NULL));
    timer be;
    be.begin();
    for (int i = 0; i < input_size; i++)
    {
        random_num = rand() % 5000000 + 1;
        h.add(random_num);
    }
    be.finish();
    cout << "time to add: " << be.gettime() << endl;

    timer en;
    en.begin();
    for (int i = 0; i < floor(size * 0.01); i++)
    {
        random_num = rand() % 5000000 + 1;
        h.found(random_num);
    }
    en.finish();
    cout << "time to found: " << en.gettime() << endl;
    cout << " # of not found " << floor(size * 0.01) - h.getfounded() << " #of founded " << h.getfounded() << endl;
}
void exe::quadhash()
{
    double startseed = 0.1;
    double startsearchseed = 0.01;
    int input_size = 0;
    int random_num;
    float time_container[5];
    int inputsize_container[5];
    int found_container[5];
    int notfound_container[5];
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        timer d_ing;
        qhash table1;
        input_size = floor(tablesize * startseed);
        table1.setup(input_size);
        inputsize_container[i] = input_size;
        d_ing.begin();
        for (int i = 0; i < input_size; i++)
        {
            random_num = rand() % 5000000 + 1;
            table1.add(random_num);
        }
        d_ing.finish();

        time_container[i] = d_ing.gettime();

        for (int i = 0; i < floor(tablesize * startsearchseed); i++)
        {
            random_num = rand() % 5000000 + 1;
            table1.found(random_num);
        }

        found_container[i] = table1.getfounded();
        notfound_container[i] = table1.getnotfind();
        startseed = startseed + 0.1;
        startsearchseed = startsearchseed + 0.01;
    }
    cout << endl;
    cout << "______________________Performance (Quadratic Probing) _________________________" << endl;
    cout << "_______________________________________________________________________________" << endl;
    cout << "| Input size         | " << setw(8) << inputsize_container[0] << " | " << setw(8) << inputsize_container[1] << " | " << setw(8) << inputsize_container[2] << " | " << setw(8) << inputsize_container[3] << " | " << setw(8) << inputsize_container[4] << " |" << endl;
    cout << "_______________________________________________________________________________" << endl;
    cout << "| Build (s)          | " << setw(8) << time_container[0] << " | " << setw(8) << time_container[1] << " | " << setw(8) << time_container[2] << " | " << setw(8) << time_container[3] << " | " << setw(8) << time_container[4] << " |" << endl;
    cout << "_______________________________________________________________________________" << endl;
    cout << "| Number of items" << endl;
    cout << "| successfully found | " << setw(8) << found_container[0] << " | " << setw(8) << found_container[1] << " | " << setw(8) << found_container[2] << " | " << setw(8) << found_container[3] << " | " << setw(8) << found_container[4] << " |" << endl;
    cout << "_______________________________________________________________________________" << endl;
    cout << "| Number of items" << endl;
    cout << "| not found          | " << setw(8) << notfound_container[0] << " | " << setw(8) << notfound_container[1] << " | " << setw(8) << notfound_container[2] << " | " << setw(8) << notfound_container[3] << " | " << setw(8) << notfound_container[4] << " |" << endl;
    cout << "_______________________________________________________________________________" << endl;
    cout << endl;
}
void exe::doublehash()
{
    double startseed = 0.1;
    double startsearchseed = 0.01;
    int input_size = 0;
    int random_num;
    float time_container[5];
    int inputsize_container[5];
    int found_container[5];
    int notfound_container[5];
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        timer d_ing;
        dhash table1;
        input_size = floor(tablesize * startseed);
        table1.setup(input_size);
        inputsize_container[i] = input_size;
        d_ing.begin();
        for (int i = 0; i < input_size; i++)
        {
            random_num = rand() % 5000000 + 1;
            table1.add(random_num);
        }
        d_ing.finish();

        time_container[i] = d_ing.gettime();

        for (int i = 0; i < floor(tablesize * startsearchseed); i++)
        {
            random_num = rand() % 5000000 + 1;
            table1.found(random_num);
        }

        found_container[i] = table1.getfounded();
        notfound_container[i] = table1.getnotfind();
        startseed = startseed + 0.1;
        startsearchseed = startsearchseed + 0.01;
    }
    cout << endl;
    cout << "______________________Performance (Double Hashing) _________________________" << endl;
    cout << "_______________________________________________________________________________" << endl;
    cout << "| Input size         | " << setw(8) << inputsize_container[0] << " | " << setw(8) << inputsize_container[1] << " | " << setw(8) << inputsize_container[2] << " | " << setw(8) << inputsize_container[3] << " | " << setw(8) << inputsize_container[4] << " |" << endl;
    cout << "_______________________________________________________________________________" << endl;
    cout << "| Build (s)          | " << setw(8) << time_container[0] << " | " << setw(8) << time_container[1] << " | " << setw(8) << time_container[2] << " | " << setw(8) << time_container[3] << " | " << setw(8) << time_container[4] << " |" << endl;
    cout << "_______________________________________________________________________________" << endl;
    cout << "| Number of items" << endl;
    cout << "| successfully found | " << setw(8) << found_container[0] << " | " << setw(8) << found_container[1] << " | " << setw(8) << found_container[2] << " | " << setw(8) << found_container[3] << " | " << setw(8) << found_container[4] << " |" << endl;
    cout << "_______________________________________________________________________________" << endl;
    cout << "| Number of items" << endl;
    cout << "| not found          | " << setw(8) << notfound_container[0] << " | " << setw(8) << notfound_container[1] << " | " << setw(8) << notfound_container[2] << " | " << setw(8) << notfound_container[3] << " | " << setw(8) << notfound_container[4] << " |" << endl;
    cout << "_______________________________________________________________________________" << endl;
    cout << endl;
}
exe::~exe()
{
}
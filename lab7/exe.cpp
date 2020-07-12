#include "exe.h"

exe::exe(string docfile, string patfile)
{
    ifstream infile;
    string input;
    infile.open(patfile);
    while (!infile.is_open())
    {
        string temp;
        cout << "Wrong file_Name for patient try again: ";
        cin >> temp;
        infile.open(temp);
    }
    if (!(infile.peek() == EOF))
    {
        int count = 0;
        people *arr;
        while (infile >> input)
        {
            size_t one = input.find(",");
            string first = input.substr(0, one);
            input.erase(0, first.size() + 1);
            size_t two = input.find(",");
            string last = input.substr(0, two);
            input.erase(0, last.size() + 1);
            int num = stoi(input);
            count++;
            people *temp = new people[count];
            for (int i = 0; i < count - 1; i++)
            {
                temp[i].setfirst(arr[i].getfirst());
                temp[i].setlast(arr[i].getlast());
                temp[i].setpriority(arr[i].getpriority());
            }
            temp[count - 1].setfirst(first);
            temp[count - 1].setlast(last);
            temp[count - 1].setpriority(num);

            if (count > 1)
            {
                delete[] arr;
            }
            arr = temp;
        }
        p_manage.inital_p(arr, count);
        
        delete[] arr;
       
    }
    infile.close();



    //nnna

    ifstream infile_d;
    input="";
    infile_d.open(docfile);
    while (!infile_d.is_open())
    {
        string temp;
        cout << "Wrong file_Name for patient try again: ";
        cin >> temp;
        infile_d.open(temp);
    }
    if (!(infile_d.peek() == EOF))
    {
        int count = 0;
        people *arr;
        while (infile_d >> input)
        {
            size_t one = input.find(",");
            string first = input.substr(0, one);
            input.erase(0, first.size() + 1);
            size_t two = input.find(",");
            string last = input.substr(0, two);
            input.erase(0, last.size() + 1);
            int num = stoi(input);
            if(num<0&&num>25)
            {
                cout<<"unable to creat list due to doctor surpass patient limit!"<<endl;
                throw(runtime_error("failed"));
            }
            count++;
            people *temp = new people[count];
            for (int i = 0; i < count - 1; i++)
            {
                temp[i].setfirst(arr[i].getfirst());
                temp[i].setlast(arr[i].getlast());
                temp[i].setpriority(arr[i].getpriority());
            }
            temp[count - 1].setfirst(first);
            temp[count - 1].setlast(last);
            temp[count - 1].setpriority(num);

            if (count > 1)
            {
                delete[] arr;
            }
            arr = temp;
        }
        d_manage.inital_d(arr, count);
        
        delete[] arr;
       
    }
    infile_d.close();

   
}
void exe::run()
{
    bool flag = true;
    while (flag)
    {
        int choice;
        cout << "-------------------------------Hospital Patient & Doctor Management System---------------------" << endl;
        cout << "1. Patient Management" << endl;
        cout << "2. Doctor Assignment" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        if (choice == 2)
        {
            doctor_as();
        }
        if (choice == 1)
        {
            patient_as();
        }
        if (choice == 3)
        {
            flag = false;
        }
    }
}
void exe::doctor_as()
{
    bool flag = true;
    while (flag)
    {
        int choice;
        cout << "------------------------------------------ Doctor Assignment System -------------------------------------" << endl;
        cout << "1. New Doctor" << endl;
        cout << "2. Update Patients" << endl;
        cout << "3. Remove Doctor" << endl;
        cout << "4. Next Available Doctor" << endl;
        cout << "5. Check Availability" << endl;
        cout << "6. Total Doctor Count" << endl;
        cout << "7. Available Doctor Count" << endl;
        cout << "8. Available Doctors Report" << endl;
        cout << "9. Busy Doctors List" << endl;
        cout << "10. Go Back to Menu" << endl;
        cout<<"Please choose your option"<<endl;
        cin >> choice;
        if(choice==1)
        {
            string first;
            string last;
           
            cout<<"Enter doctor details:"<<endl;
            cout << "First name: " ;
            cin >> first;
            cout << "Last name: ";
            cin >> last;
            
            if (!d_manage.check_dup(first, last))
            {
                try
                {
                    d_manage.insert(first, last, 0);
                    cout << "A new doctor is added and available." << endl;
                }
                catch (runtime_error &e)
                {
                    cout << e.what() << endl;
                }
            }
            else
            {
                cout << "Duplicate detected, add patient failed" << endl;
            }
        }
        if(choice==2)
        {
            string first;
            string last;
            int op;
            cout<<"Enter the doctor’s details to update the patient count:"<<endl;
            cout << "First name: " ;
            cin >> first;
            cout << "Last name: ";
            cin >> last;
            try
            {
                //string o=d_manage.search(first,last);
                int x=d_manage.patient_count(first,last);
                cout<<"Current patient count:  "<<x<<endl;
                cout<<"Select 1 to add patients or 0 to reduce patients: ";
                cin>>op;
                while(op>1||op<0)
                {
                    cout<<"selection failed try again !";
                    cout<<"Select 1 to add patients or 0 to reduce patients: ";
                    cin>>op;
                }
                if(op==0)
                {
                    cout<<"Enter the updated count: "<<endl;
                    cin>>op;
                    if(op<x)
                    {
                        d_manage.change_patient_C(first,last,op);
                        cout<<"The doctor’s record is updated."<<endl;
                    }
                    else
                    {
                        cout<<"Failed, value surpass the original patient count"<<endl;
                    }
                    
                }
                else
                {
                    cout<<"Enter the updated count: "<<endl;
                    cin>>op;
                    if(op>x)
                    {
                        d_manage.change_patient_C(first,last,op);
                        cout<<"The doctor’s record is updated."<<endl;
                    }
                    else
                    {
                        cout<<"Failed, value less than the original patient count"<<endl;
                    }
                    
                }

            }
            catch(runtime_error& e)
            {
                cout<< e.what() << '\n';
            }
            
        }
        if(choice==3)
        {
            try
            {
               d_manage.remove_d();
               cout<<"The doctor with the lowest patient count has been removed."<<endl; 
            }
            catch(runtime_error& e)
            {
                cout<< e.what() << '\n';
            }
            
        }
        if(choice==4)
        {
            cout<<"Next Doctor available: "<<d_manage.next_doc()<<endl;
        }
        if(choice==5)
        {
            string first;
            string last;
           
            cout<<"Enter doctor details to check availability:"<<endl;
            cout << "First name: " ;
            cin >> first;
            cout << "Last name: ";
            cin >> last;
            try
            {
                if(d_manage.check_avaliable(first,last))
                {
                    cout<<"This doctor is avaliable"<<endl;
                }
                else
                {
                    cout<<"This doctor is not avaliable"<<endl;
                }
                
            }
            catch(runtime_error& e)
            {
                cout<< e.what() << '\n';
            }
            
        }
        if(choice==6)
        {
            cout<<"There are "<<d_manage.totaldoc()<<" total doctors"<<endl;
        }
        if(choice==7)
        {
            cout<<"There are "<<d_manage.totalavaliable()<<" doctors available"<<endl;
        }
        if(choice==8)
        {
            d_manage.avaliable_report();
        }
        if(choice==9)
        {
            d_manage.busy_report();
        }
        if (choice == 10)
        {
            flag = false;
        }
    }
}
void exe::patient_as()
{
    bool flag = true;
    while (flag)
    {
        int choice;
        cout << "------------------------------------------ Patient Management System ------------------------------------" << endl;
        cout << "1. New Patient" << endl;   //finished
        cout << "2. Treat Patient" << endl; //finished
        cout << "3. Change Urgency" << endl;
        cout << "4. Next Patient" << endl; //finished
        cout << "5. Last Patient" << endl;
        cout << "6. Patient Token" << endl;
        cout << "7. Patient Count" << endl; //finished
        cout << "8. Patient Report" << endl;
        cout << "9. Go Back to Menu" << endl; //finished
        cout << endl;
        cout << "Please choose your option:" << endl;
        cin >> choice;
        if (choice == 1)
        {
            string first;
            string last;
            int num;
            cout << "Enter Patient’s First name:" << endl;
            cin >> first;
            cout << "Enter Patient’s Last name:" << endl;
            cin >> last;
            cout << "Enter Patient’s Urgency:" << endl;
            cin >> num;
            if (!p_manage.check_dup(first, last))
            {
                try
                {
                    p_manage.insert(first, last, num);
                    cout << "New Patient record added" << endl;
                }
                catch (runtime_error &e)
                {
                    cout << e.what() << endl;
                }
            }
            else
            {
                cout << "Duplicate detected, add patient failed" << endl;
            }
        }
        if (choice == 2)
        {
            try
            {
                string p = p_manage.next_patient();
                p_manage.treat();
                cout << "High priority patient successfully treated. Below are the details:" << endl;
                cout << p << endl;
            }
            catch (runtime_error &e)
            {
                cout << e.what() << endl;
            }
        }
        if (choice == 3)
        {
            string first;
            string last;
            int num;
            cout << "Enter the patient details to change the urgency:" << endl;
            cout << "First name: ";
            cin >> first;
            cout << "Last name: ";
            cin >> last;
            try
            {
                cout << "Current details of this patient are: " << p_manage.search(first, last) << endl;
                cout << "Enter new urgency level: ";
                cin >> num;
                p_manage.change_urgency(first, last, num);
                cout << "The patient record is updated." << endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (choice == 4)
        {
            cout << "Next patient: " << p_manage.next_patient() << endl;
        }
        if (choice == 5)
        {
            cout << "Last patient details: " << p_manage.last_patient() << endl;
        }
        if (choice == 6)
        {
            string first;
            string last;
            cout << "Enter details of patient:" << endl;
            cout << "First name:" ;
            cin >> first;
            cout << "Last name:" ;
            cin >> last;

            try
            {
                int token = p_manage.patient_token(first, last);
                cout << "Patient token: " << token << endl;
            }
            catch (runtime_error &e)
            {
                cout << e.what() << endl;
            }
        }
        if (choice == 7)
        {
            cout << "Current patient count is: " << p_manage.patient_c() << endl;
        }
        if (choice == 8)
        {
            cout << "Current Patients report:" << endl;
            try
            {
                p_manage.patient_report();
            }
            catch (runtime_error &e)
            {
                cout << e.what() << endl;
            }
        }
        if (choice == 9)
        {
            flag = false;
        }
    }
}
exe::~exe()
{
}

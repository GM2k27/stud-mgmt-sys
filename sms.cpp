#include<iostream>
#include "STD_tree.hh"
using namespace std;
int main()
{
    int choice;
    Student_info stud;
    cout << "WELCOME\n";
    
    while (true)
    {
        cout << "\nEnter your choice\n";
        cout << "1. Add student\n2. Search student\n3. Remove student\n4. Modify data\n";
        cout << "5. Display students\n6. Count number of students\n";
        cout << "7. K number of students with maximum CGPA\n8. K number of students with minimum CGPA\n9. Exit\n";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
        {
            string name, usn;
            long long int phone;
            float cgpa;
            cout << "Please enter the details\n";
            cout << "Name: ";
            cin >> name;
            cout << "USN: ";
            cin >> usn;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            cout << "Contact No: ";
            cin >> phone;
            stud.Insert_student(name, usn, phone, cgpa);
            cout << endl;
            break;
        }
        case 2:
        {
            string usn;
            cout << "~~~~~~~~~~~~~~~~~~~~\n";
            cout << "Enter USN of the student to search: ";
            cin >> usn;
            if (stud.search_student(usn))
                stud.Student_display(usn);
            else
                cout << "Student is not present\n";
            cout << "~~~~~~~~~~~~~~~~~~~~\n";
            break;
        }
        case 3:
        {
            string usn;
            cout << "~~~~~~~~~~~~~~~~~~~~\n";
            cout << "Enter USN: ";
            cin >> usn;
            if (stud.search_student(usn))
                stud.remove_stud(usn);
            else
                cout << "Student is not present :( \n";
            cout << "~~~~~~~~~~~~~~~~~~~~\n";
            break;
        }
        case 4:
        {
            string name, usn;
            long int phone;
            float cgpa;
            cout << "Enter USN: ";
            cin >> usn;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone: ";
            cin >> phone;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            stud.modify_data(name, usn, phone, cgpa);
            break;
        }
        case 5:
        {
            cout << "~~~~~~~~~~~~~~~~~~~~\n";
            stud.Display();
            cout << "~~~~~~~~~~~~~~~~~~~~\n";
            break;
        }
        case 6:
        {
            cout << "Total number of students: " << stud.count_students() << endl;
            break;
        }
        case 7:
        {
            int k;
            cout << "Enter value of k: ";
            cin >> k;
            stud.maxmin_stud(k, 1);
            break;
        }
        case 8:
        {
            int k;
            cout << "Enter value of k: ";
            cin >> k;
            stud.maxmin_stud(k, 0);
            break;
        }
        case 9:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
}
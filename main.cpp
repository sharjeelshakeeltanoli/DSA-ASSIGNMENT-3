#include "StudentList.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    StudentList stud;
    int choice;
    do
    {
        system("cls");
        cout << "====== Student List Menu ======";
        cout << "\n1. Insert Student";
        cout << "\n2. Delete Student by Roll No";
        cout << "\n3. Search Student by Roll No";
        cout << "\n4. Display All Students";
        cout << "\n5. Count Students";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            int rollNo;
            string name;
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            stud.insertAtEnd(rollNo, name);
            cout << "\nStudent inserted successfully.";
            break;
        }
        case 2:
        {
            system("cls");
            int rollNo;
            cout << "Enter Roll No to delete: ";
            cin >> rollNo;
            stud.deleteByRollNo(rollNo);
            break;
        }
        case 3:
        {
            system("cls");
            int rollNo;
            cout << "Enter Roll No to search: ";
            cin >> rollNo;
            stud.searchStudent(rollNo);
            break;
        }
        case 4:
            system("cls");
            stud.displayList();
            break;
        case 5:
            system("cls");
            stud.countStudents();
            break;
        case 6:
            system("cls");
            cout << "\nExiting program. Goodbye!";
            break;
        default:
            cout << "\nInvalid choice. Please try again.";
        }
    } while (choice != 6);

    return 0;
}

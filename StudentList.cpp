#include <iostream>
#include <string>
#include "StudentList.h"
using namespace std;



StudentList::StudentList()
{
    listptr = NULL;
    count = 0;
}

StudentList::~StudentList()
{
    NODEPTR p = listptr;
    while (p != NULL)
    {
        NODEPTR temp = p;
        p = p->next;
        delete temp;
    }
}

bool StudentList::isEmpty()
{
    return (listptr == NULL);
}

void StudentList::insertAtEnd(int rollNo, string name)
{
    NODEPTR newnode = new node();
    newnode->Name = name;
    newnode->rollNo = rollNo;
    newnode->next = NULL;
    if (isEmpty())
    {
        listptr = newnode;
    }
    else
    {
        NODEPTR p = listptr;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newnode;
    }
    count++;
}

void StudentList::deleteByRollNo(int rollNo)
{
    if (isEmpty())
    {
        cout << "\nThe list is empty.";
        return;
    }

    NODEPTR p = listptr;
    NODEPTR prev = NULL;

    while (p != NULL && p->rollNo != rollNo)
    {
        prev = p;
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "\nThe sought student is not found in the list";
        return;
    }

    if (prev == NULL)
    {
        listptr = p->next;
    }
    else
    {
        prev->next = p->next;
    }

    delete p;
    count--;
    cout << "\nStudent with roll number " << rollNo << " deleted.";
}

void StudentList::searchStudent(int rollNo)
{
    if (isEmpty())
    {
        cout << "\nThe list is empty";
        return;
    }
    NODEPTR p = listptr;

    while (p != NULL && p->rollNo != rollNo)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "\nThe sought student not found in the list";
        return;
    }
    else
    {
        cout << "\nStudent found:";
        cout << "\nRoll No: " << p->rollNo;
        cout << "\nName: " << p->Name;
    }
    cout << endl;
    system("pause");
}

void StudentList::displayList()
{
    if (isEmpty())
    {
        cout << "\nThe list is empty.";
        return;
    }
    NODEPTR p = listptr;
    cout << "\nStudent List:";
    cout << "\n-----------------------------";
    cout << "\nRoll No\t\tName";
    cout << "\n-----------------------------";
    while (p != NULL)
    {
        cout << "\n" << p->rollNo << "\t\t" << p->Name;
        p = p->next;
    }
    cout << "\n-----------------------------";
    cout << endl;
    system("pause");
}

void StudentList::countStudents()
{
    cout << "\nTotal number of waiting students : " << count;
    cout << endl;
    system("pause");
}


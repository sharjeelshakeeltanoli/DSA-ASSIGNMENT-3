#pragma once
#include <string>
using namespace std;

class StudentList
{
private:
    int count;
    struct node
    {
        node* next;
        int rollNo;
        string Name;
    };
    typedef struct node* NODEPTR;
    NODEPTR listptr; //first node
public:

    StudentList();
    ~StudentList();
    bool isEmpty();
    void insertAtEnd(int rollNo, string name);
    void deleteByRollNo(int rollNo);
    void searchStudent(int rollNo);
    void displayList();
    void countStudents();
};
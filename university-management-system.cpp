#include<iostream>
using namespace std;
struct University {
    int universityID;
    string universityName;
    string universityLocation;
    int startYear;
};
struct Branch {
    int universityID;
    string universityName;
    string branchID;
};
struct Student {
    int rollNumber;
    string name;
    string branchID;
    int cgpa;
    struct Student *next;
    struct Student *prev;
};
void create(struct Student **start, struct Student **last) {
    Student *newPtr = new Student;
    cout<<"Enter Name: ";
    cin>>newPtr->name;
    cout<<"Enter Roll Number: ";
    cin>>newPtr->rollNumber;
    cout<<"Enter Branch ID: ";
    cin>>newPtr->branchID;
    cout<<"Enter CGPA: ";
    cin>>newPtr->cgpa;
    newPtr->next = NULL;
    newPtr->prev = NULL;
    if (*start == NULL) {
        *start = newPtr;
        *last = newPtr;  
    }
    else {
        (*last)->next = newPtr;
        newPtr->prev = *last;
        *last = newPtr;
    }
}
void display(struct Student **start, struct Student **last) {
    struct Student *ptr;
    ptr = *start;
    while (ptr! = NULL) {
        cout<<"\nRoll Number: "<<ptr->rollNumber;
        cout<<"\nName: "<<ptr->name;
        cout<<"\nBranch ID: "<<ptr->branchID;
        cout<<"\nCGPA: "<<ptr->cgpa;
        cout<<"\n\n";
        ptr = ptr->next;
    }
}
int main()
{
    struct Student *st = NULL;
    struct Student *last = NULL;
    char ch = 'Y';
    while (ch == 'Y') {
        create(&st, &last);
        cout<<"\nDo You Want to Continue (Y/N)?";
        cout<<"\nEnter Your Choice: ";
        cin>>ch;
        cout<<"\n";
    }
    display(&st, &last);
    return 0;
}

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
    Student *ptr = new Student;
    cout<<"Enter Name: ";
    cin>>ptr->name;
    cout<<"Enter Roll Number: ";
    cin>>ptr->rollNumber;
    cout<<"Enter Branch ID: ";
    cin>>ptr->branchID;
    cout<<"Enter CGPA: ";
    cin>>ptr->cgpa;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (*start == NULL) {
        *start = ptr;
        *last = ptr;  
    }
    else {
        *last->next = ptr;
        ptr->prev = *last;
        *last = ptr;
    }
}
void display(struct Student **start, struct Student **last) {
    struct Student *ptr;
    ptr = *start;
    while (ptr != NULL) {
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
    struct Branch b1;
    b1.branch_id="B001";
    b1.university_id=1;
    b1.Universitt_name="KIIT";
    struct Branch b2;
    b2.branch_id="B002";
    b2.university_id=2;
    b2.Universitt_name="MIT Manipal";
    struct Branch b3;
    b3.branch_id="B003";
    b3.university_id=3;
    b3.Universitt_name="VIT Vellore";
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

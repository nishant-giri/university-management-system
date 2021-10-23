#include<iostream>
using namespace std;

// University Structure
struct University {
    string universityID;
    string universityName;
    string universityLocation;
    int startYear;
    struct University *next;
    struct University *prev;
};

// Branch Structure
struct Branch {
    string universityID;
    string universityName;
    string branchName;
    string branchID;
    struct Branch *next;
    struct Branch *prev;
};

// Student Structure
struct Student {
    string name;
    int rollNumber;
    string branchID;
    float cgpa;
    struct Student *next;
    struct Student *prev;
};

void create(struct Student **start, struct Student **last) {
    Student *ptr = new Student;
    cout<<"Enter Name: ";
    getline(cin, ptr->name);
    cout<<"Enter Roll Number: ";
    cin>>ptr->rollNumber;
    getchar();
    cout<<"Enter Branch ID: ";
    getline(cin, ptr->branchID);
    cout<<"Enter CGPA: ";
    cin>>ptr->cgpa;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (*start == NULL) {
        *start = ptr;
        *last = ptr;  
    }
    else {
        (*last)->next = ptr;
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

void display(struct Branch** start)
{
    struct Branch* temp = *start;
    while (temp != NULL)
    {
        cout<<"\n\nBranch ID: "<<temp->branchID;
        cout<<"\nBranch name: "<<temp->branch_name;
        cout<<"\nUniversity ID: "<<temp->universityID;
        temp = temp->next;
    }
}

int main()
{
    struct Student *st = NULL;
    struct Student *last = NULL;
    struct Branch* BRstart = NULL;
    struct Branch* BRlast = NULL;
    char ch;
    struct Branch* b1 = new struct Branch;
    b1->branchID = "B001";
    b1->universityID = "U001";
    b1->universityName = "KIIT Bhubaneswar";
    b1->prev = NULL;
    struct Branch* b2 = new struct Branch;
    b2->branchID = "B002";
    b2->universityID = "U002";
    b2->universityName = "MIT Manipal";
    b2->prev = b1;
    b1->next = b2;
    struct Branch* b3 = new struct Branch;
    b3->branchID = "B003";
    b3->universityID = "U003";
    b3->universityName = "VIT Vellore";
    b3->prev = b2;
    b2->next = b3;
    b3->next = NULL;
    do {
        create(&st, &last);
        cout<<"\nDo You Want to Continue (Y/N)?";
        cout<<"\nEnter Your Choice: ";
        cin>>ch;
        getchar();
        cout<<"\n";
    } while ((ch == 'y') || (ch == 'Y'));
    ch = '0';
    cout<<"Enter 'Y' to create a branch or any other alpahabet to continue: ";
    cin>>ch;
    while (ch == 'y' || ch == 'Y')
    {
        create(&BRstart, &BRlast);
        cout<<"\nDo You Want to Continue (Y/N)? ";
        cin>>ch;
    }
    display(&st, &last);
    display(&BRstart);
    return 0;
}

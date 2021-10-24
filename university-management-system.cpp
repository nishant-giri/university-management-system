#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

// University Structure
struct University {
    string universityName;
    string universityID;
    string universityLocation;
    int startYear;
    struct University *next;
    struct University *prev;
};

// Branch Structure
struct Branch {
    //string universityName;
    string universityID;
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

// void capital(string &name)
// {
//     int l = name.length();
//     for(int i=0;i<l;i++)
//     {
//         char c=name[i];
//         if (islower(c))
//         {
//             name[i]=toupper(c);
//         }
//         else
//           continue;

//     }
// }

void create(struct Branch** start, struct Branch** last) {
    struct Branch* p = *last;
    Branch* ptr = new Branch;
    ptr->next = NULL;
    ptr->prev = NULL;
    getchar();
    cout<<"\nEnter Branch Name: ";
    getline(cin, ptr->branchName);
    string bname=ptr->branchName;
    int l= bname.length();
    for(int i=0;i<l;i++)
    {
        char c=bname[i];
        if (islower(c))
        {
            bname[i]=toupper(c);
        }
        else
          continue;

    }
    ptr->branchName=bname;
    cout<<"Enter University ID: ";
    getline(cin, ptr->universityID);
    cout<<"Enter Branch ID: ";
    getline(cin, ptr->branchID);
    if (*start == NULL) {
        *start = ptr;
        *last = ptr;
    }
    else {
        ptr->prev = p;
        p->next = ptr;
    }
}

void create(struct Student **start, struct Student **last) {
    Student *ptr = new Student;
    cout<<"Enter Name: ";
    getline(cin, ptr->name);
    string sname=ptr->name;
    int l= sname.length();
    for(int i=0;i<l;i++)
    {
        char c=sname[i];
        if (islower(c))
        {
            sname[i]=toupper(c);
        }
        else
          continue;

    }
    ptr->name=sname;
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
        cout<<"\nName: "<<ptr->name;
        cout<<"\nRoll Number: "<<ptr->rollNumber;
        cout<<"\nBranch ID: "<<ptr->branchID;
        cout<<"\nCGPA: "<<ptr->cgpa;
        cout<<"\n\n";
        ptr = ptr->next;
    }
}

void display(struct Branch** start)
{
    struct Branch* ptr = *start;
    while (ptr != NULL)
    {
        cout<<"Branch Name: "<<ptr->branchName;
        cout<<"\nBranch ID: "<<ptr->branchID;
        cout<<"\nUniversity ID: "<<ptr->universityID;
        cout<<"\n";
        ptr = ptr->next;
    }
}

void display(struct University** start)
{
    struct University* ptr = *start;
    while (ptr != NULL)
    {
        cout<<"University Name: "<<ptr->universityName;
        cout<<"\nUniversity ID: "<<ptr->universityID;
        cout<<"\nUniversity Location: "<<ptr->universityLocation;
        cout<<"\nStart Year: "<<ptr->startYear;
        cout<<"\n";
        ptr = ptr->next;
    }
}

int main()
{
    struct Student *st = NULL;
    struct Student *last = NULL;
    struct Branch* BRstart = NULL;
    struct Branch* BRlast = NULL;
    struct University* u_start=NULL;
    struct University* u_last=NULL;
    char ch;
    struct Branch* b1 = new struct Branch;
    b1->branchID = "CS1";
    b1->universityID = "U001";
    b1->branchName = "COMPUTER SCIENCE";
    b1->prev = NULL;
    struct Branch* b2 = new struct Branch;
    b2->branchID = "EE1";
    b2->universityID = "U002";
    b2->branchName = "ELECTRONICS";
    b2->prev = b1;
    b1->next = b2;
    struct Branch* b3 = new struct Branch;
    b3->branchID = "ME1";
    b3->universityID = "U003";
    b3->branchName = "MECHANICAL";
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
    cout<<"Do You Want to Create a Branch (Y/N)?";
    cout<<"\nEnter Your Choice: ";
    cin>>ch;
    while (ch == 'y' || ch == 'Y')
    {
        create(&BRstart, &BRlast);
        cout<<"\nDo You Want to Continue (Y/N)?";
        cout<<"\nEnter Your Choice: ";
        cin>>ch;
    }
    display(&st, &last);
    display(&BRstart);
    display(&u_start);
    return 0;
}

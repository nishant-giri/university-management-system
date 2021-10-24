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

//creation of branch list
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

//craetion of student list
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

//student list display 
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

//branch list display
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

//university list display
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

    //total 4 branches- 3 same ,1 unique
    //1.1
    struct Branch* b1 = new struct Branch;
    b1->branchID = "CS1";
    b1->universityID = "U001";
    b1->branchName = "COMPUTER SCIENCE";
    b1->prev = NULL;

    //1.2
    struct Branch* b2 = new struct Branch;
    b2->branchID = "EE1";
    b2->universityID = "U001";
    b2->branchName = "ELECTRONICS";
    b2->prev = b1;
    b1->next = b2;

    //1.3
    struct Branch* b3 = new struct Branch;
    b3->branchID = "ME1";
    b3->universityID = "U001";
    b3->branchName = "MECHANICAL";
    b3->prev = b2;
    b2->next = b3;

    //1.4
    struct Branch* b4 = new struct Branch;
    b4->branchID = "BT1";
    b4->universityID = "U001";
    b4->branchName = "BIOTECHNOLOGY";
    b4->prev = b3;
    b3->next = b4;
 
    //2.1
    struct Branch* b5 = new struct Branch;
    b5->branchID = "CS1";
    b5->universityID = "U002";
    b5->branchName = "COMPUTER SCIENCE";
    b5->prev = b4;
    b4->next = b5;

    //2.2
    struct Branch* b6 = new struct Branch;
    b6->branchID = "EE1";
    b6->universityID = "U002";
    b6->branchName = "ELECTRONICS";
    b6->prev = b5;
    b5->next = b6;

    //2.3
    struct Branch* b7 = new struct Branch;
    b7->branchID = "ME1";
    b7->universityID = "U002";
    b7->branchName = "MECHANICAL";
    b7->prev = b6;
    b6->next = b7;
    
    //2.4
    struct Branch* b8 = new struct Branch;
    b8->branchID = "LAW1";
    b8->universityID = "U002";
    b8->branchName = "LAW";
    b8->prev = b7;
    b7->next = b8;

    //3.1
    struct Branch* b9 = new struct Branch;
    b9->branchID = "CS1";
    b9->universityID = "U003";
    b9->branchName = "COMPUTER SCIENCE";
    b9->prev = b8;
    b8->next = b9;

    //3.2
    struct Branch* b10 = new struct Branch;
    b10->branchID = "EE1";
    b10->universityID = "U003";
    b10->branchName = "ELECTRONICS";
    b10->prev = b9;
    b9->next = b10;

    //3.3
    struct Branch* b11 = new struct Branch;
    b11->branchID = "ME1";
    b11->universityID = "U003";
    b11->branchName = "MECHANICAL";
    b11->prev = b10;
    b10->next = b11;
    
    //3.4
    struct Branch* b12 = new struct Branch;
    b12->branchID = "MRE1";
    b12->universityID = "U003";
    b12->branchName = "MARINE";
    b12->prev = b11;
    b11->next = b12;

    //4.1
    struct Branch* b13 = new struct Branch;
    b13->branchID = "CS1";
    b13->universityID = "U004";
    b13->branchName = "COMPUTER SCIENCE";
    b13->prev = b12;
    b12->next = b13;

    //4.2
    struct Branch* b14 = new struct Branch;
    b14->branchID = "EE1";
    b14->universityID = "U004";
    b14->branchName = "ELECTRONICS";
    b14->prev = b13;
    b13->next = b14;

    //4.3
    struct Branch* b15 = new struct Branch;
    b15->branchID = "ME1";
    b15->universityID = "U004";
    b15->branchName = "MECHANICAL";
    b15->prev = b14;
    b14->next = b15;
    
    //4.4
    struct Branch* b16 = new struct Branch;
    b16->branchID = "AGR1";
    b16->universityID = "U004";
    b16->branchName = "AGRICULTURE";
    b16->prev = b15;
    b15->next = b16;

    //5.1
    struct Branch* b17 = new struct Branch;
    b17->branchID = "CS1";
    b17->universityID = "U005";
    b17->branchName = "COMPUTER SCIENCE";
    b17->prev = b16;
    b16->next = b17;

    //5.2
    struct Branch* b18 = new struct Branch;
    b18->branchID = "EE1";
    b18->universityID = "U005";
    b18->branchName = "ELECTRONICS";
    b18->prev = b17;
    b17->next = b18;

    //5.3
    struct Branch* b19 = new struct Branch;
    b19->branchID = "ME1";
    b19->universityID = "U005";
    b19->branchName = "MECHANICAL";
    b19->prev = b18;
    b18->next = b19;
    
    //5.4
    struct Branch* b20 = new struct Branch;
    b20->branchID = "AE1";
    b20->universityID = "U005";
    b20->branchName = "AEROSPACE";
    b20->prev = b19;
    b19->next = b20;
    b20->next = NULL;

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

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

// Creation of University List
void create(struct University** start, struct Branch** last) {
    struct University* p = *last;
    University* ptr = new University;
    ptr->next = NULL;
    ptr->prev = NULL;
    getchar();
    cout<<"\nEnter University Name: ";
    getline(cin, ptr->universityName);
    string tempUniversityName = ptr->universityName;
    int l = tempUniversityName.length();
    for (int i = 0; i < l; i++)
    {
        char c = tempUniversityName[i];
        if (islower(c))
            tempUniversityName[i] = toupper(c);
        else
            continue;
    }
    ptr->universityName = tempUniversityName;
    cout<<"Enter University ID: ";
    getline(cin, ptr->universityID);
    tempUniversityID = ptr->universityID;
    l = tempUniversityID.length();
    for (int i = 0; i < l; i++)
    {
        char c = tempUniversityID[i];
        if (islower(c))
            tempUniversityID[i] = toupper(c);
        else
            continue;
    }
    ptr->universityID = tempUniversityID;
    cout<<"Enter University Location: ";
    getline(cin, ptr->universityLocation);
    tempUniversityLocation = ptr->universityLocation;
    l = tempUniversityLocation.length();
    for (int i = 0; i < l; i++)
    {
        char c = tempUniversityLocation[i];
        if (islower(c))
            tempUniversityLocation[i] = toupper(c);
        else
            continue;
    }
    ptr->universityLocation = tempUniversityLocation;
    cout<<"Enter Start Year of University: ";
    cin>>ptr->universityLocation;
    if (*start == NULL) {
        *start = ptr;
        *last = ptr;
    }
    else {
        ptr->prev = p;
        p->next = ptr;
    }
}

// Creation of Branch List
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
    bname=ptr->universityID;
    l= bname.length();
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
    ptr->universityID=bname;
    cout<<"Enter Branch ID: ";
    getline(cin, ptr->branchID);
    bname=ptr->branchID;
    l= bname.length();
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
    ptr->branchID=bname;
    if (*start == NULL) {
        *start = ptr;
        *last = ptr;
    }
    else {
        ptr->prev = p;
        p->next = ptr;
    }
}

// Creation of Student List
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
    sname=ptr->branchID;
    l= sname.length();
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
    ptr->branchID=sname;
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

// Display Student List 
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

// Display Branch List
void display(struct Branch** start)
{
    struct Branch* ptr = *start;
    while (ptr != NULL)
    {
        cout<<"Branch Name: "<<ptr->branchName;
        cout<<"\nBranch ID: "<<ptr->branchID;
        cout<<"\nUniversity ID: "<<ptr->universityID;
        cout<<"\n\n";
        ptr = ptr->next;
    }
}

// Display University List
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

// Student Modification
void modify(Student** start)
{
    int key;
    cout<<"Enter roll number of student: ";
    cin>>key;
    Student* p = *start;
    while (p != NULL)
    {
        if (p->rollNumber == key)
        {
            cout<<"Enter Name: ";
            getchar();
            getline(cin, p->name);
            string sname=p->name;
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
            p->name=sname;
            cout<<"Enter Roll Number: ";
            cin>>p->rollNumber;
            cout<<"Enter Branch ID: ";
            getchar();
            getline(cin, p->branchID);
            sname=p->branchID;
            l= sname.length();
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
            p->branchID=sname;
            cout<<"Enter CGPA: ";
            cin>>p->cgpa;
            break;
        }
        p = p->next;
    }
    if(p == NULL)
        cout<<"\n\nInvalid roll number entered!\n\n";
}

// Branch Modification
void modify(Branch** start)
{
    string key1, key2;
    cout<<"Enter branch ID to be modified: ";
    cin>>key1;
    string bname=key1;
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
        key1=bname;
    cout<<"Enter ID of university that branch is present in: ";
    cin>>key2;
    bname=key2;
    l= bname.length();
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
        key2=bname;
        l = 1;
    Branch* p = *start;
    while (p != NULL)
    {
        if (p->branchID == key1 && p->universityID == key2)
        {
            l = 0;
            getchar();
        string BN, BID, UID;
            cout<<"\nEnter Branch Name: ";
            getline(cin, BN);
            bname=BN;
            l= bname.length();
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
            BN=bname;
            cout<<"Enter University ID: ";
            getline(cin, UID);
            bname=UID;
            l= bname.length();
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
            UID=bname;
            cout<<"Enter Branch ID: ";
            getline(cin, BID);
            bname=BID;
            l= bname.length();
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
            BID=bname;
            p->branchName = BN;
            p->universityID = UID;
            p->branchID = BID;
        }
        p = p->next;
    }
    if (l == 1)
        cout<<"\n\nInvalid branch ID or university ID entered!\n\n";
}

// Display List of Branches of a Particular University
void DispBranch(struct Branch** start,struct University**start1)
{   string uc;
    cout<<"UNIVERSITIES AND CODES"<<endl;
// Display Universities and Their Respective IDs
struct University* ptr1 = *start1;
    while (ptr1!= NULL)
    {
        cout<<"University Name: "<<ptr1->universityName;
        cout<<"\tUniversity ID: "<<ptr1->universityID;
        cout<<"\n";
        ptr1 = ptr1->next;

    }
  
    cout<<"\n\nEnter the University code:";
    cin>>uc;
    cout<<"\nBranches available:\n";
     struct Branch *ptr = *start;
    while (ptr != NULL)
    { 
        if((ptr->universityID)!=uc)
        {}
        else
        {
        cout<<ptr->branchName<<endl;
        }
        
        ptr = ptr->next;
    }
}
int main()
{
    struct Student *st = NULL;
    struct Student *last = NULL;
    struct Branch* BRstart = NULL;
    struct Branch* BRlast = NULL;
    struct University* universityStart = NULL;
    struct University* universityLast = NULL;
    char ch;

    // Total 5 Universities
     
    // University 1
    struct University* u1 = new struct University;
    u1->universityName = "KIIT";
    u1->universityID = "U001";
    u1->universityLocation = "Bhubaneswar";
    u1->startYear = 1992;
    u1->prev = NULL;

    // University 2
    struct University* u2 = new struct University;
    u2->universityName = "VIT";
    u2->universityID = "U002";
    u2->universityLocation = "Vellore";
    u2->startYear = 1984;
    u2->prev = u1;
    u1->next = u2;

    // University 3
    struct University* u3 = new struct University;
    u3->universityName = "MAHE";
    u3->universityID = "U003";
    u3->universityLocation = "Manipal";
    u3->startYear = 1953;
    u3->prev = u2;
    u2->next = u3;

    // University 4
    struct University* u4 = new struct University;
    u4->universityName = "BITS";
    u4->universityID = "U004";
    u4->universityLocation = "Pilani";
    u4->startYear = 1964;
    u4->prev = u3;
    u3->next = u4;

    // University 5
    struct University* u5 = new struct University;
    u5->universityName = "TIET";
    u5->universityID = "U005";
    u5->universityLocation = "Thapar";
    u5->startYear = 1956;
    u5->prev = u4;
    u4->next = u5;
    
    universityStart = u1;
    universityLast = u5;
    
    // Total 4 Branches - ALL Unique
    
    // 1.1
    struct Branch* b1 = new struct Branch;
    b1->branchID = "CS1";
    b1->universityID = "U001";
    b1->branchName = "COMPUTER SCIENCE";
    b1->prev = NULL;

    // 1.2
    struct Branch* b2 = new struct Branch;
    b2->branchID = "EE1";
    b2->universityID = "U001";
    b2->branchName = "ELECTRONICS";
    b2->prev = b1;
    b1->next = b2;

    // 1.3
    struct Branch* b3 = new struct Branch;
    b3->branchID = "ME1";
    b3->universityID = "U001";
    b3->branchName = "MECHANICAL";
    b3->prev = b2;
    b2->next = b3;

    // 1.4
    struct Branch* b4 = new struct Branch;
    b4->branchID = "BT1";
    b4->universityID = "U001";
    b4->branchName = "BIOTECHNOLOGY";
    b4->prev = b3;
    b3->next = b4;
 
    // 2.1
    struct Branch* b5 = new struct Branch;
    b5->branchID = "CS2";
    b5->universityID = "U002";
    b5->branchName = "COMPUTER SCIENCE";
    b5->prev = b4;
    b4->next = b5;

    // 2.2
    struct Branch* b6 = new struct Branch;
    b6->branchID = "EE2";
    b6->universityID = "U002";
    b6->branchName = "ELECTRONICS";
    b6->prev = b5;
    b5->next = b6;

    // 2.3
    struct Branch* b7 = new struct Branch;
    b7->branchID = "ME2";
    b7->universityID = "U002";
    b7->branchName = "MECHANICAL";
    b7->prev = b6;
    b6->next = b7;
    
    // 2.4
    struct Branch* b8 = new struct Branch;
    b8->branchID = "LAW1";
    b8->universityID = "U002";
    b8->branchName = "LAW";
    b8->prev = b7;
    b7->next = b8;

    // 3.1
    struct Branch* b9 = new struct Branch;
    b9->branchID = "CS3";
    b9->universityID = "U003";
    b9->branchName = "COMPUTER SCIENCE";
    b9->prev = b8;
    b8->next = b9;

    // 3.2
    struct Branch* b10 = new struct Branch;
    b10->branchID = "EE3";
    b10->universityID = "U003";
    b10->branchName = "ELECTRONICS";
    b10->prev = b9;
    b9->next = b10;

    // 3.3
    struct Branch* b11 = new struct Branch;
    b11->branchID = "ME3";
    b11->universityID = "U003";
    b11->branchName = "MECHANICAL";
    b11->prev = b10;
    b10->next = b11;
    
    // 3.4
    struct Branch* b12 = new struct Branch;
    b12->branchID = "MRE1";
    b12->universityID = "U003";
    b12->branchName = "MARINE";
    b12->prev = b11;
    b11->next = b12;

    // 4.1
    struct Branch* b13 = new struct Branch;
    b13->branchID = "CS4";
    b13->universityID = "U004";
    b13->branchName = "COMPUTER SCIENCE";
    b13->prev = b12;
    b12->next = b13;

    // 4.2
    struct Branch* b14 = new struct Branch;
    b14->branchID = "EE4";
    b14->universityID = "U004";
    b14->branchName = "ELECTRONICS";
    b14->prev = b13;
    b13->next = b14;

    // 4.3
    struct Branch* b15 = new struct Branch;
    b15->branchID = "ME4";
    b15->universityID = "U004";
    b15->branchName = "MECHANICAL";
    b15->prev = b14;
    b14->next = b15;
    
    // 4.4
    struct Branch* b16 = new struct Branch;
    b16->branchID = "AGR1";
    b16->universityID = "U004";
    b16->branchName = "AGRICULTURE";
    b16->prev = b15;
    b15->next = b16;

    // 5.1
    struct Branch* b17 = new struct Branch;
    b17->branchID = "CS5";
    b17->universityID = "U005";
    b17->branchName = "COMPUTER SCIENCE";
    b17->prev = b16;
    b16->next = b17;

    // 5.2
    struct Branch* b18 = new struct Branch;
    b18->branchID = "EE5";
    b18->universityID = "U005";
    b18->branchName = "ELECTRONICS";
    b18->prev = b17;
    b17->next = b18;

    // 5.3
    struct Branch* b19 = new struct Branch;
    b19->branchID = "ME5";
    b19->universityID = "U005";
    b19->branchName = "MECHANICAL";
    b19->prev = b18;
    b18->next = b19;
    
    // 5.4
    struct Branch* b20 = new struct Branch;
    b20->branchID = "AE1";
    b20->universityID = "U005";
    b20->branchName = "AEROSPACE";
    b20->prev = b19;
    b19->next = b20;
    b20->next = NULL;

    BRstart = b1;
    BRlast = b20;
    
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
    DispBranch(&BRstart,&u_start);
    return 0;
}

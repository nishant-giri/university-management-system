#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

// University Header Structure 
struct Uni_head {
    int count_uni ;
    struct University *next;
} uh;

// Branch Header Structure
struct Branch_head {
    int count_branch ;
    struct Branch *next;
} bh;

// Student Header Structure 
struct Student_head {
    int count_stu ;
    struct Student *next;
}sh;

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

int CheckAvailableU(struct University**,string);
int CheckAvailableB(struct Branch**,string);
int CheckRoll(struct Student**,int);

// Creation of University List
void create(struct University** start, struct University** last) {
    struct University* p = *last;
    struct University *t=*start;
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
    string tempUniversityID = ptr->universityID;
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
    int temp = CheckAvailableU(&t,ptr->universityID);
    if(temp==0)
    {
        uh.count_uni++;
        cout<<"Enter University Location: ";
        getline(cin, ptr->universityLocation);
        string tempUniversityLocation = ptr->universityLocation;
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
    else
    {
        cout<<"University ID is not unique.";
    }
}

// Creation of Branch List
void create(struct Branch** start, struct Branch** last) {
    struct Branch* p = *last;
    Branch* ptr = new Branch;
    struct Branch *ptr1=*start; 
    ptr->next = NULL;
    ptr->prev = NULL;
    getchar();
    cout<<"\nEnter Branch Name: ";
    getline(cin, ptr->branchName);
    string bname = ptr->branchName;
    int l = bname.length();
    for (int i = 0; i < l; i++) {
        char c = bname[i];
        if (islower(c)) {
            bname[i] = toupper(c);
        }
        else
            continue;
    }
    ptr->branchName = bname;
    cout<<"Enter University ID: ";
    getline(cin, ptr->universityID);
    bname = ptr->universityID;
    l = bname.length();
    for(int i = 0; i < l; i++) {
        char c = bname[i];
        if (islower(c)) {
            bname[i] = toupper(c);
        }
        else
            continue;
    }
    ptr->universityID = bname;
    cout<<"Enter Branch ID: ";
    getline(cin, ptr->branchID);
    bname = ptr->branchID;
    l = bname.length();
    for(int i = 0; i < l; i++) {
        char c = bname[i];
        if (islower(c)) {
            bname[i] = toupper(c);
        }
        else
            continue;
    }
    ptr->branchID = bname;
    int temp = CheckAvailableB(&ptr1, ptr->branchID);
    if (temp == 0) {
        bh.count_branch++;
        if (*start == NULL) {
            *start = ptr;
            *last = ptr;
        }
        else {
            ptr->prev = p;
            p->next = ptr;
        }
    }
    else {
     cout<<"Branch ID is not unique";
    }
}

// Creation of Student List
void create(struct Student **start, struct Student **last, struct Branch **st) {
    Student *ptr = new Student;
    struct Branch *ptr1 = *st;
    struct Student *p = *start;
    cout<<"Enter Name: ";
    getline(cin, ptr->name);
    string sname = ptr->name;
    int l = sname.length();
    for (int i = 0; i < l; i++) {
        char c = sname[i];
        if (islower(c)) {
            sname[i] = toupper(c);
        }
        else
            continue;

    }
    ptr->name = sname;
    cout<<"Enter Roll Number: ";
    cin>>ptr->rollNumber;
    int t = CheckRoll(&p, ptr->rollNumber);
    if (t == 0) {
        sh.count_stu++;
        getchar();
        cout<<"Enter Branch ID: ";
        getline(cin, ptr->branchID);
        sname = ptr->branchID;
        l = sname.length();
        for (int i = 0; i < l; i++) {
            char c = sname[i];
            if (islower(c)) {
                sname[i]=toupper(c);
            }
            else
                continue;
        }
        ptr->branchID = sname;
        int temp = CheckAvailableB(&ptr1,ptr->branchID);
        if (temp == 1) {
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
        else {
            cout<<"Branch ID not available";
        }
    }
    else {
        cout<<"Roll Number is not unique";
    }
}

// Display Student List
void display(struct Student **start, struct Student **last) {
    cout<<"\nSTUDENT LIST ->\n\n";
    struct Student *ptr;
    ptr = *start;
    if (ptr == NULL) {
        cout<<"No Nodes Present\n";
    }
    else {
        while (ptr != NULL) {
            cout<<"Name: "<<ptr->name;
            cout<<"\nRoll Number: "<<ptr->rollNumber;
            cout<<"\nBranch ID: "<<ptr->branchID;
            cout<<"\nCGPA: "<<ptr->cgpa;
            cout<<"\n\n";
            ptr = ptr->next;
        }
    }
}

// Display Branch List
void display(struct Branch** start) {
    cout<<"\nBRANCH LIST ->\n\n";
    struct Branch* ptr = *start;
    if (ptr == NULL) {
        cout<<"No Nodes Present\n";
    }
    else {
        while (ptr != NULL) {
            cout<<"Branch Name: "<<ptr->branchName;
            cout<<"\nBranch ID: "<<ptr->branchID;
            cout<<"\nUniversity ID: "<<ptr->universityID;
            cout<<"\n\n";
            ptr = ptr->next;
        }
    }
}

// Display University List
void display(struct University** start) {
    cout<<"\nUNIVERSITY LIST ->\n\n";
    struct University* ptr = *start;
    if (ptr == NULL) {
        cout<<"no nodes present\n";
    }
    else {
        while (ptr != NULL) {
            cout<<"University Name: "<<ptr->universityName;
            cout<<"\nUniversity ID: "<<ptr->universityID;
            cout<<"\nUniversity Location: "<<ptr->universityLocation;
            cout<<"\nStart Year: "<<ptr->startYear;
            cout<<"\n";
            ptr = ptr->next;
        }
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

// University Modification
void modify(University** start, Branch** BRstart)
{
    string key;
    cout<<"Enter university ID to be modified: ";
    cin>>key;
    string bname=key;
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
        key=bname;
        l = 1;
    University* p = *start;
    while (p != NULL)
    {
        if (p->universityID == key)
        {
            l = 0;
            getchar();
            string temp_sto = p->universityID;
        string BN, BID, UID;
            cout<<"\nEnter University Name: ";
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
            cout<<"Enter University location: ";
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
            cout<<"Enter University's year of commencement: ";
            cin>>p->startYear;
            p->universityName = BN;
            p->universityID = UID;
            p->universityLocation = BID;
            Branch* tempo = *BRstart;
            while (tempo != NULL)
            {
                if (tempo->universityID == temp_sto)
                {
                    tempo->universityID = p->universityID;
                }
                tempo = tempo->next;
            }
            break;
        }
        p = p->next;
    }
    if (l == 1)
        cout<<"\n\nUniversity ID entered!\n\n";
}

// Student Deletion
void remove(Student** start)
{
    int key;
    cout<<"Enter roll number of student: ";
    cin>>key;
    Student* p = *start;
    if (p->rollNumber == key && p->next != NULL)
    {
        *start = p->next;
        p->next->prev = NULL;
        free(p);
        printf("\n\nStudent data successfully deleted\n\n");
        return;
    }
    while (p->next != NULL)
    {
        if (p->rollNumber == key)
        {
            sh.count_stu--;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            printf("\n\nStudent data successfully deleted\n\n");
            return;
        }
        p = p->next;
    }
    if (p->rollNumber == key && p->prev != NULL)
    {
        sh.count_stu--;
        p->prev->next = NULL;
        free(p);
        printf("\n\nStudent data successfully deleted\n\n");
        return;
    }
    else if (p->rollNumber == key && p->prev == NULL)
    {
        sh.count_stu--;
        *start = NULL;
        free(p);
        printf("\n\nStudent data successfully deleted\n\n");
        return;
    }
        cout<<"\n\nInvalid roll number entered!\n\n";
}

// Branch Deletion
void remove(Branch** start)
{
    string key;
    cout<<"Enter branch ID to be deleted: ";
    cin>>key;
    string bname=key;
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
        key=bname;
        l = 1;
    Branch* p = *start;
    if (p->branchID == key && p->next != NULL)
    {
        bh.count_branch--;
        *start = p->next;
        p->next->prev = NULL;
        free(p);
        printf("\n\nBranch successfully deleted\n\n");
        return;
    }
    while (p->next != NULL)
    {
        if (p->branchID == key)
        {
            bh.count_branch--;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            printf("\n\nBranch successfully deleted\n\n");
            return;
        }
        p = p->next;
    }
    if (p->branchID == key && p->prev != NULL)
    {
        bh.count_branch--;
        p->prev->next = NULL;
        free(p);
        printf("\n\nBranch successfully deleted\n\n");
        return;
    }
    if (p->branchID == key && p->prev == NULL)
    {
        bh.count_branch--;
        *start = NULL;
        free(p);
        printf("\n\nBranch successfully deleted\n\n");
        return;
    }
        cout<<"\n\nInvalid branch ID!\n\n";
}

// Branch Deletion for university deletion
void remove(Branch** BRstart, string key)
{
    Branch* p = *BRstart;
    while (p->universityID == key && p->next != NULL)
    {
        bh.count_branch--;
        *BRstart = p->next;
        cout<<"\n\nPASS\n\n";
        p->next->prev = NULL;
        Branch* temp = p;
        p = p->next;
        free(temp);
    }
    while (p->next != NULL)
    {
        if (p->universityID == key)
        {
            bh.count_branch--;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
        }
        p = p->next;
    }
    if (p->universityID == key && p->prev != NULL)
    {
        bh.count_branch--;
        p->prev->next = NULL;
        free(p);
    }
    else if (p->universityID == key && p->prev == NULL)
    {
        bh.count_branch--;
        *BRstart = NULL;
        free(p);
    }
}

// University Deletion
void remove(University** start, Branch** BRstart)
{
    string key;
    cout<<"Enter university ID to be deleted: ";
    cin>>key;
    string bname=key;
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
        key=bname;
        l = 1;
    University* p = *start;
    if (p->universityID == key && p->next != NULL)
    {
        uh.count_uni--;
        *start = p->next;
        string temp = p->universityID;
        remove(BRstart, temp);
        p->next->prev = NULL;
        free(p);
        printf("\n\nUniversity data successfully deleted\n\n");
        return;
    }
    while (p->next != NULL)
    {
        if (p->universityID == key)
        {
            uh.count_uni--;
            string temp = p->universityID;
            remove(BRstart, temp);
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            printf("\n\nUniversity data successfully deleted\n\n");
            return;
        }
        p = p->next;
    }
    if (p->universityID == key && p->prev != NULL)
    {
        uh.count_uni--;
        string temp = p->universityID;
        remove(BRstart, temp);
        p->prev->next = NULL;
        free(p);
        printf("\n\nUniversity data successfully deleted\n\n");
        return;
    }
    else if (p->universityID == key && p->prev == NULL)
    {
        uh.count_uni--;
        *start = NULL;
        string temp = p->universityID;
        remove(BRstart, temp);
        free(p);
        printf("\n\nUniversity data successfully deleted\n\n");
        return;
    }
        cout<<"\n\nInvalid University ID entered!\n\n";
}

// Display of students in KIIT's CSE
void KIIT_CSE_DISP(Student** start)
{
    Student* p = *start;
    while (p != NULL)
    {
        if (p->branchID == "CS1")
        {
            cout<<"\nName: "<<p->name;
            cout<<"\nRoll Number: "<<p->rollNumber;
            cout<<"\nBranch ID: "<<p->branchID;
            cout<<"\nCGPA: "<<p->cgpa;
            cout<<"\n\n";
        }
        p = p->next;
    }
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
    string ucmod = uc;
    int l = ucmod.length();
    for (int i = 0; i < l; i++)
    {
            char c = ucmod[i];
            if (islower(c))
            {
                ucmod[i]=toupper(c);
            }
            else
            continue;
    }
    uc = ucmod;
 
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
void UniYear(struct University** start)
{
    int c=0;
    int a[100];
    struct University* ptr = *start;


    while (ptr != NULL)
    {
        a[c]=ptr->startYear;
        c++;
        ptr=ptr->next;
    }
    //sorting
        int i,j,temp;
        for(i=0;i<c-1;i++)
        {
            for(j=0;j<(c-1)-i;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
    cout<<"\n\nUniversity details sorted on the basis of their start year\n\n";
        int *p=a;
    for(int i=0;i<c;i++)
    {
        int t=*p;
        struct University* ptr1 = *start;
        while (ptr1!= NULL)
        {
            if(ptr1->startYear==t)
            {   
                cout<<"University Name: "<<ptr1->universityName;
                cout<<"\nUniversity ID: "<<ptr1->universityID;
                cout<<"\nUniversity Location: "<<ptr1->universityLocation;
                cout<<"\nStart Year: "<<ptr1->startYear;
                cout<<"\n\n\n";  
            }
            ptr1=ptr1->next;
        }
        p++;
    }

}
int CheckAvailableU(struct University** start,string ID)
{
   
    struct University* ptr = *start;
    while (ptr != NULL)
    {
        int sid=ID.compare(ptr->universityID);
       if(sid==0)
       {
         return 1;
       }
        ptr=ptr->next;
    }
     
   return 0;
} 

int CheckAvailableB(struct Branch** start,string ID)
{
struct Branch *ptr1=*start;
while (ptr1!= NULL)
    {
        int sid=ID.compare(ptr1->branchID);
        if(sid==0)
            {
             return 1;
            }
        
        ptr1=ptr1->next;
    }
    return 0;
}
int CheckRoll(struct Student** start,int rn)
{
struct Student *ptr1=*start;
while (ptr1!= NULL)
    {
        if(rn==ptr1->rollNumber)
            {
             return 1;
            }
        
        ptr1=ptr1->next;
    }
    return 0;
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
    int choice;

    // Total 5 Universities
     
    // University 1
    struct University* u1 = new struct University;
    u1->universityName = "KIIT";
    u1->universityID = "U001";
    u1->universityLocation = "BHUBANESWAR";
    u1->startYear = 1992;
    u1->prev = NULL;

    // University 2
    struct University* u2 = new struct University;
    u2->universityName = "VIT";
    u2->universityID = "U002";
    u2->universityLocation = "VELLORE";
    u2->startYear = 1984;
    u2->prev = u1;
    u1->next = u2;

    // University 3
    struct University* u3 = new struct University;
    u3->universityName = "MAHE";
    u3->universityID = "U003";
    u3->universityLocation = "MANIPAL";
    u3->startYear = 1953;
    u3->prev = u2;
    u2->next = u3;

    // University 4
    struct University* u4 = new struct University;
    u4->universityName = "BITS";
    u4->universityID = "U004";
    u4->universityLocation = "PILANI";
    u4->startYear = 1964;
    u4->prev = u3;
    u3->next = u4;

    // University 5
    struct University* u5 = new struct University;
    u5->universityName = "TIET";
    u5->universityID = "U005";
    u5->universityLocation = "PATIALA";
    u5->startYear = 1956;
    u5->prev = u4;
    u4->next = u5;
    
    universityStart = u1;
    universityLast = u5;
    uh.next = universityStart;    
    
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

    //struct Uni_head uh;
    uh.count_uni = 5;
    //struct Branch_head bh;
    bh.count_branch = 20;
    //struct Student_head sh;
    sh.count_stu = 0;

    BRstart = b1;
    BRlast = b20;
    bh.next = BRstart;

    do {
        cout<<"1. Add Student Details\n";
        cout<<"2. Modify Student Details\n";
        cout<<"3. Delete Student Details\n";
        cout<<"4. Update Student Details\n";
        cout<<"5. Display Students' Details\n";
        cout<<"6. Display KiiTians' Details\n";
        cout<<"7. Display CSE KiiTians' Details\n";
        cout<<"8. Add Branch Details\n";
        cout<<"9. Modify Branch Details\n";
        cout<<"10. Delete Branch Details\n";
        cout<<"11. Display Branches' Details\n";
        cout<<"12. Display Branches of a Given University\n";
        cout<<"13. Add University Details\n";
        cout<<"14. Modify University Details\n";
        cout<<"15. Delete University Details\n";
        cout<<"16. Display Universities' Details\n";
        cout<<"17. Display Universities' Details in Ascending Order of Start Year\n";
        cout<<"18. Display Student Name for a Given Substring\n";
        cout<<"19. Display University Name for a Given Substring\n";
        cout<<"20. Exit\n\n";
        cout<<"Enter Your Choice: ";
        cin>>choice;
        cout<<"\n";
        getchar();
        switch(choice) {
            case 1: 
                do {
                    create(&st, &last, &BRstart);
                    cout<<"\nDo You Want to Continue (Y/N)?";
                    cout<<"\nEnter Your Choice: ";
                    cin>>ch;
                    getchar();
                    cout<<"\n";
                } while ((ch == 'y') || (ch == 'Y'));
                 sh.next = st;
                 break;
            
            case 5:
                display(&st, &last);
                break;

            case 8: 
                cout<<"Do You Want to Create a Branch (Y/N)?";
                cout<<"\nEnter Your Choice: ";
                cin>>ch;
                while (ch == 'y' || ch == 'Y') {
                    create(&BRstart, &BRlast);
                    cout<<"\nDo You Want to Continue (Y/N)?";
                    cout<<"\nEnter Your Choice: ";
                    cin>>ch;
                }
                break;
            
            case 11: 
                display(&BRstart);
                break;

            case 12:
                DispBranch(&BRstart,&universityStart);
                break;

            case 16:
                display(&universityStart);
                break;

            case 17:
                UniYear(&universityStart);
                break;

            case 20:
                exit(0);
        } 
    } while(choice);
    return 0;
}

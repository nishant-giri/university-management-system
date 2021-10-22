#include<iostream>
using namespace std;
struct Student
{
    int roll;
    string name;
    string branch_id;
    int cgpa;
    struct Student *next;
    struct Student *prev;
};
struct branch 
{
  string branch_id;
  int university_id;
  string university_name;
}; 
void create(struct Student **start,struct Student **last)
{
  Student *nw=new Student;
 cout<<"\nEnter Name:-";
 cin>>nw->name;
 cout<<"\nEnter Rollno:";
 cin>>nw->roll;
 cout<<"\nEnter Branch ID:-";
 cin>>nw->branch_id;
 cout<<"\nEnter CGPA:-";
 cin>>nw->cgpa;
 nw->next=NULL;
 nw->prev=NULL;
 
 if(*start==NULL)
 {
     *start=nw;
     *last=nw;  
 }
 else
 {
     (*last)->next=nw;
     nw->prev=*last;
     *last=nw;

 }
}
void display(struct Student **start,struct Student **last )
{
    struct Student *t;
    t=*start;
    while(t!=NULL)
    {
        cout<<"Roll no: "<<t->roll<<endl;
        cout<<"NAME: "<<t->name<<endl;
        cout<<"Branch ID: "<<t->branch_id<<endl;
        cout<<"CGPA: "<<t->cgpa<<endl;
       t=t->next;
       cout<<endl;
 
    }
}
int main()
{
    struct Student *st=NULL;
    struct Student *l=NULL;
    char ch='y';
    while(ch=='y')
    {
        create(&st,&l);
        cout<<"Add more(y/n)?"<<endl;
        cin>>ch;
    }
    display(&st,&l);
    return 0;
}

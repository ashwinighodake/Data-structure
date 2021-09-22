#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};
class Stack
{
    struct node *head;
    int iCnt;

   public:
   Stack()
   {
       head=NULL;
       iCnt=0;
   }
   void Push(int); //InsertFist
   int Pop();//DeleteFirst
   void Display();
   int Count();

};
void Stack::Push(int no)
{
    struct node *newn=NULL;
    newn=new struct node;
    newn->data=no;
    newn->next=NULL;

    if(head==NULL)
    {
       head=newn;   
    }
    else
    {
        newn->next=head;
        head=newn;
    }
    iCnt++;
}
int Stack::Pop()
{
    int no=0;
    if(head==NULL)
    {
        cout<<"Stack is empty";
        return 0;
    }
    else
    {
        no=head->data;
        struct node *temp=head;
        head=head->next;
        delete(temp);
        return no;
    }
    iCnt--;
    
}
void Stack::Display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        return;
    }
    while(temp!=NULL)
    {
       cout<<temp->data<<"\t";
       temp=temp->next;
    }
}
int Stack::Count()
{
    return iCnt;
}
int main()
{   
    Stack s;
    int no=0,choice=0,iRet=0;
    char ans='\0';

    do
    {
        cout<<"\n1.Push element in stack";
        cout<<"\n2.Pop element from stack";
        cout<<"\n3.Count the no.of elements in stack";
        cout<<"\n4.Display all elements in stack";
        cout<<"\nEnter your choice:";
        cin>>choice;

        switch(choice)
        {
           case 1:cout<<"\nEnter the element:";
                  cin>>no;
                  s.Push(no);
                  break;

           case 2:iRet=s.Pop();
                  cout<<iRet<<"\t";
                  break;

           case 3:iRet=s.Count();
                  cout<<"\nNo. of Elements in stack:"<<iRet;
                   break;

           case 4:s.Display();
                  break;

           default:cout<<"\nInvalid choice!!";
                   break;
        }
        cout<<"\nDo you want to perform other operation(y/n):";
        cin>>ans;

    } while ((ans=='y')||(ans=='Y'));
    
    return 0;
}
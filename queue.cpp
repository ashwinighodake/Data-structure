#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
class Queue
{
    struct node *head;
    struct node *tail;
    int iCnt;
    public:
    Queue()
    {
        head=NULL;
        tail=NULL;
        iCnt=0;
    }
    void Enqueue(int);//insertlast
    int Dequeue(); //deletefirst
    void Display();
    int Count();
};
void Queue::Enqueue(int no)
{
    struct node *newn=NULL;
    newn=new struct node;
    newn->data=no;
    newn->next=NULL;
    
    if((head==NULL)&&(tail==NULL))
    {
        head=newn;
        tail=newn;
    }
    else
    {
        tail->next=newn;
        tail=newn;
    }
    iCnt++;
}
int Queue::Dequeue()
{
    int no=0;
    if((head==NULL)&&(tail==NULL))
    {
        cout<<"\nQueue is Empty!!";
        return 0;
    }
    else
    {
        struct node *temp=head;
        no=head->data;
        delete(head);
        head=temp->next;
        iCnt--;
        return no;
    }
}
void Queue::Display()
{
    struct node *temp=head;
    if((head==NULL)&&(tail==NULL))
    {
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}
int Queue::Count()
{
    return iCnt;
}
int main()
{
    Queue s;
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
                  s.Enqueue(no);
                  break;

           case 2:iRet=s.Dequeue();
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
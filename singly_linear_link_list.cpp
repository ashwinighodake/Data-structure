#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
class SinglyLinear
{
    struct node *head;
    int iCnt;
    public:
    SinglyLinear()
    {
        head=NULL;
        iCnt=0;
    }
    ~SinglyLinear()
    {
        struct node *temp=head;
        if(head!=NULL)
        {
            while(head!=NULL)
            {
                head=head->next;
                delete temp;
                temp=head;
            }
        }
    }
    void InsertFirst(int);
    void Display();
    void InsertLast(int);
    void InsertAtPosition(int,int);
    int Count();
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int);
    
};
void SinglyLinear::InsertFirst(int no)
{
    struct node *newn=NULL;
    newn=new struct node;
    
    if(newn == NULL)
    {
        return;
    }
    newn->data=no;
    newn->next=NULL;
    if(head==NULL)
    {
        head=newn;
    }
    else
    {
        newn->next=(head);
        (head)=newn;
    }
    iCnt++;
}
void SinglyLinear::InsertLast(int no)
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
        struct node *temp=head;
        while(temp->next!=NULL)
        {
           temp=temp->next;
        }
        temp->next=newn;
    }
    iCnt++;

}
void SinglyLinear::InsertAtPosition(int pos,int no)
{
    if((pos<1)||(pos>iCnt+1))
    {
      return;
    }
    if(pos==1)
    {
       InsertFirst(no);
    }
    else if(pos==iCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node *temp=head;
        struct node *newn=NULL;
        newn=new struct node;

        newn->data=no;
        newn->next=NULL; 

        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

        iCnt++;
    }
}
void SinglyLinear::DeleteFirst()
{
    if(head==NULL)
    {
        return;
    }
    else 
    {
        struct node *temp=head;
        head=head->next;
        delete(temp);
    }
    iCnt--;
}
void SinglyLinear::DeleteLast()
{
    if(head==NULL)
    {
        return;
    }
    else if(head->next==NULL)
    {
        delete(head);
        head=NULL;
    }
    else
    {
        struct node *temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete(temp->next);
        temp->next=NULL;
    }
    iCnt--;
}
void SinglyLinear::DeleteAtPosition(int pos)
{
    if((pos<1)||(pos>iCnt))
    {
        cout<<"Invalid position!!";
        return;
    }
    if(pos==1)
    {
        DeleteFirst();
    }
    else if(pos==iCnt)
    {
        DeleteLast();
    }
    else
    {
        struct node *temp1=head;
        struct node *temp2=NULL;
        
        for(int i=1;i<pos-1;i++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp1->next->next;
        delete(temp2);

        iCnt--;

    }
    
}
void SinglyLinear::Display()
{
    struct node *temp=NULL;
    temp=head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}
int SinglyLinear::Count()
{
  return iCnt;
}

int main()
{
    SinglyLinear s1;
    int no=0,pos=0,choice=0,iRet=0;

    char ans='\0';
    do
    {
        cout<<"1.Insert At First Position\n";
        cout<<"2.Insert At Last Postion\n";
        cout<<"3.Insert At specific position\n";
        cout<<"4.Delete At First Position\n";
        cout<<"5.Delete At Last Position\n";
        cout<<"6.Delete At Specific Position\n";
        cout<<"7.Count how many are there in link list\n";
        cout<<"8.Display all elements in the list\n";
        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice)
        {
            case 1:cout<<"\nEnter the element:";
                   cin>>no;
                   s1.InsertFirst(no);
                   s1.Display();
                   break;
            case 2:cout<<"\nEnter the element:";
                   cin>>no;
                   s1.InsertLast(no);
                   s1.Display();
                   break;
            case 3:cout<<"\nEnter position:";
                   cin>>pos;
                   cout<<"\nEnter the element:";
                   cin>>no;
                   s1.InsertAtPosition(pos,no);  
                   s1.Display();

                   break;
            case 4:s1.DeleteFirst();
                   s1.Display();
                   break;
            case 5:s1.DeleteLast();
                   s1.Display();
                   break;
            case 6:cout<<"\nEnter the Position:";
                   cin>>pos;
                   s1.DeleteAtPosition(pos);
                   s1.Display();
                   break;

            case 7:iRet=s1.Count();
                   cout<<"No. of Elements:"<<iRet;
                    break;

            case 8:s1.Display();
                   break;
            default:cout<<"Invalid input!!\n";
                     break;
        }
        cout<<"\nDo you want above operation again(y/n):";
        cin>>ans;

    }while(ans=='Y' || ans=='y');
    return 0;
}
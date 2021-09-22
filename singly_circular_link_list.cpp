#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};
class SinglyCircular
{
    struct node *head;
    struct node *tail;
    int iCnt;
    public:
    SinglyCircular()
    {
        head=NULL;
        tail=NULL;
        iCnt=0;
    }
    ~SinglyCircular()
    {
        if((head!=NULL)&&(tail!=NULL))
        {
            while((head!=NULL)&&(tail!=NULL))
            {
                if(head==tail)
                {
                    delete(head);
                    head=NULL;
                    tail=NULL;
                }
                else
                {
                    head=head->next;
                    delete(tail->next);
                    tail->next=head;
                }
                
            }
        }
    }
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPosition(int,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int);
    
};
void SinglyCircular::InsertFirst(int no)
{
    struct node *newn=NULL;
    newn=new struct node;
    newn->data=no;
    newn->next=NULL;

    if((head==NULL)&&(tail==NULL))
    {
        head=newn;
        tail=newn;

        tail->next=head;
    }
    else
    {
        newn->next=head;
        head=newn;
        tail->next=head;
    }
    iCnt++;
}
void SinglyCircular::InsertLast(int no)
{
    struct node *newn=NULL;
    newn=new struct node;
    newn->data=no;
    newn->next=NULL;

    if((head==NULL)&&(tail==NULL))
    {
        head=newn;
        tail=newn;
        tail->next=head;
    }
    else
    {
        newn->next=head;
        tail->next=newn;
        tail=newn;
    }
    iCnt++;
}
void SinglyCircular::InsertAtPosition(int pos,int no)
{
    if((pos<1)||(pos>iCnt+1))
    {
        cout<<"Invalid Position!!";
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
        struct node *newn=NULL;
        newn=new struct node;
        newn->data=no;
        newn->next=NULL;
        
        struct node *temp=head;

        for(int i=1;i<pos-1;i++)
        {
           temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

        iCnt++;
    }
    

}
void SinglyCircular::DeleteFirst()
{
    if((head==NULL)&&(tail==NULL))
    {
        cout<<"\nThere is no element!!";
        return;
    }
    else if(head==tail)
    {
        delete(head);
        head=NULL;
        tail=NULL;
    }
    else
    {
        head=head->next;
        delete(tail->next);
        tail->next=head;
    }
    iCnt--;

}
void SinglyCircular::DeleteLast()
{
    if((head==NULL)&&(tail==NULL))
    {
        cout<<"\nThere is no element!!";
    
        return;
    }
    else if (head==tail)
    {
        delete(head);
        head=NULL;
        tail=NULL;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        delete(tail);
        tail=temp;
        tail->next=head;
    }
    iCnt--;
    
}
void SinglyCircular::DeleteAtPosition(int pos)
{
    if((pos<1)&&(pos>iCnt))
    {
        cout<<"\nInvalid Position!!";
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

void SinglyCircular::Display()
{
    struct node *temp=head;
    if((head==NULL)&&(tail==NULL))
    {
        return;
    }
    do
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    } while (temp!=head);
    
}
int SinglyCircular::Count()
{
    return iCnt;
}
int main()
{
    SinglyCircular s1;
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
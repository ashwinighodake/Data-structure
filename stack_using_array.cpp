#include<iostream>
using namespace std;

class Stack
{
    int stack[100] ,top,n;
    public:
    Stack()
    {
        top=-1;
        n=100;
    }
    void Push(int);
    void Pop();
    void Display();
};
void Stack::Push(int val)
{
    if(top>=n-1)
    {
        cout<<"Stack is Overflow";
        return;
    }
    else
    {
        top++;
        stack[top]=val;
    }
    
}
void Stack::Pop()
{
   if(top<=-1)
   {
       cout<<"Stack is Underflow!!";
       return;
   }
   else
   {
       cout<<"Poped element is:"<<stack[top];
       top--;
   }
   
}
void Stack::Display()
{
    if(top>=0)
    {
        cout<<"\nStack elements are:";
        for(int i=top;i>=0;i--)
        {
            cout<<stack[i]<<"\t";
            
        }

    }
    else
    {
        cout<<"Stack is Empty";
        return;
    }
    
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
        cout<<"\n3.Display all elements in stack";
        cout<<"\nEnter your choice:";
        cin>>choice;

        switch(choice)
        {
           case 1:cout<<"\nEnter the element:";
                  cin>>no;
                  s.Push(no);
                  break;

           case 2:s.Pop();
                  break;

           case 3:s.Display();
                  break;

           default:cout<<"\nInvalid choice!!";
                   break;
        }
        cout<<"\nDo you want to perform other operation(y/n):";
        cin>>ans;

    } while ((ans=='y')||(ans=='Y'));
 
    return 0;
}
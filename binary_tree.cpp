#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
class Binary_Tree
{
    struct node *head;
    public:
    Binary_Tree()
    {
       head=NULL;
    }
    void Insert(int);
    void Insert(int,node *);
    void Display();
    void Display(node *);
};
void Binary_Tree::Insert(int No)
{
    
    if(head==NULL)
    {
       struct node *newn=NULL;

       newn=new struct node;
       newn->data=No;
       newn->left=NULL;
       newn->right=NULL;

        head=newn;
    }
    else 
    {
       Insert(No,head); 
    }
}
void Binary_Tree::Insert(int No,node *temp)
{
    if(No < temp->data)
    {
        if(temp->left!=NULL)
        {
            Insert(No,temp->left);
        }
        else
        {
            struct node *newn=new struct node;
            newn->data=No;
            newn->left=NULL;
            newn->right=NULL;

            temp->left=newn;
        }
    }
    else if (No >= temp->data)
    {
        if(temp->right!=NULL)
        {
            Insert(No,temp->right);
        }
        else
        {
            struct node *newn=new struct node;
            newn->data=No;
            newn->left=NULL;
            newn->right=NULL;

            temp->right=newn;
        }
    }
    
}
void Binary_Tree::Display()
{
    node* temp=head;
    Display(temp);
}
void Binary_Tree::Display(node *temp)
{
     if(temp!=NULL)
     {
         Display(temp->left);
         cout<<temp->data<<"\t";
         Display(temp->right);
     }
}
int main()
{
    Binary_Tree tobj;
    tobj.Insert(10);
    tobj.Insert(8);
    tobj.Insert(12);
    tobj.Insert(9);
    tobj.Insert(7);
    tobj.Display();
    return 0;
}
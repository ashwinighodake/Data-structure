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
    void Inorder();
    void Inorder(node *);
    void Preorder();
    void Preorder(node *);
    void Postorder();
    void Postorder(node *);
    
    void Search(int);
    void Search(node *,int);
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
void Binary_Tree::Inorder()
{
    Inorder(head);
}
void Binary_Tree::Inorder(node *temp)
{
     if(temp!=NULL)
     {
         Inorder(temp->left);
         cout<<temp->data<<"\t";
         Inorder(temp->right);
     }
}
void Binary_Tree::Preorder()
{
    Preorder(head);
}
void Binary_Tree::Preorder(node *temp)
{
     if(temp!=NULL)
     {
        
        cout<<temp->data<<"\t";
         Preorder(temp->left);
         Preorder(temp->right);
     }

}
void Binary_Tree::Postorder()
{
    Postorder(head);
}
void Binary_Tree::Postorder(node *temp)
{
     if(temp!=NULL)
     {
        
         Postorder(temp->left);
         Postorder(temp->right);
         cout<<temp->data<<"\t";
       
     }

}

void Binary_Tree::Search(int No)
{
    if(head==NULL)
    {
        cout<<"\nThere is no element Found";
        return;
    }
    if(head->data==No)
    {
        cout<<"\nElement Found";
    }
    else
    {
        Search(head,No);
    }
}
void Binary_Tree::Search(node *head,int No)
{
    if(head->data==No)
    {
        cout<<"\nElement Found!";
    }
    else if(No<head->data)
    {
        Search(head->left,No);
    }
    else if(No>head->data)
    {
        Search(head->right,No);
    }
}
int main()
{
    Binary_Tree tobj;
    char ans;
    int choice=0,No=0;
    do
    {
        cout<<"\n1.Insert the Element in to Binary Tree";
        cout<<"\n2.Display elements in Inoder list";
        cout<<"\n3.Display elements in Preoder list";
        cout<<"\n4.Display elements in postorder list";
        cout<<"\n5.Search Specific Element";
        cout<<"\nEnter your choice:";
        cin>>choice;

        switch (choice)
        {
        case 1:cout<<"\n Enter the element to insert into the tree:";
            cin>>No;
            tobj.Insert(No);
            break;

        case 2:tobj.Inorder();
            break;

        case 3:tobj.Preorder();
            break;

        case 4:tobj.Postorder();
            break;


        case 5:cout<<"\n Enter the element to search:";
               cin>>No;
               tobj.Search(No);
               break;

        default: cout<<"\nYou have Entered Invalid choice!!";
            break;
        }
        cout<<"\nDo you want to perform any other operation(y/n):";
        cin>>ans;

    }while(ans=='Y' || ans=='y');
    
    return 0;
}
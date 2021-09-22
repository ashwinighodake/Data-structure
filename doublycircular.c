#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[50];
    int rno;
    struct node *next,*prev;
};

void InsertAtFirst(struct node **first,struct node **last,int no,char arr[])
{
    struct node *newn=NULL;
    newn=(struct node*)malloc(sizeof(struct node));

    strcpy(newn->name,arr);
    newn->rno=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((*first==NULL)&&(*last==NULL))
    {
        *first=newn;
        *last=newn;

        (*first)->prev=(*last);
        (*last)->next=(*first);
    }
    else
    {
        newn->next=(*first);
        (*first)->prev=newn;
        (*first)=newn;

        (*last)->next=(*first);
        (*first)->prev=(*last);
    }
    
}
void Display(struct node *first,struct node *last)
{
    struct node *temp=NULL;
    temp=first;
    if((first==NULL)&&(last==NULL))
    {
        return;
    }

    do
    {
        printf("%s\t",temp->name);
        printf("%d\n",temp->rno);
        temp=temp->next;

    }while(temp!=first);
}
int Count(struct node *first,struct node *last)
{
    int i=0;
    struct node *temp=first;

    if((first==NULL)&&(last==NULL))
    {
        return i;
    }
    do
    {
        i++;
        temp=temp->next;

    } while (temp!=first);

    return i;
}
void InsertAtLast(struct node **first,struct node **last,int no,char arr[])
{
    struct node *newn=NULL;
    newn=(struct node*)malloc(sizeof(struct node));

    strcpy(newn->name,arr);
    newn->rno=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((*first==NULL)&&(*last==NULL))
    {
        *first=newn;
        *last=newn;

        (*last)->next=(*first);
        (*first)->prev=(*last);
    }
    else
    {
        (*last)->next=newn;
        newn->prev=(*last);
        (*last)=newn;

        (*last)->next=(*first);
        (*first)->prev=(*last);
    }
    

}
void InsertAtPos(struct node **first,struct node **last,int no,char arr[],int pos)
{
    int iSize=0;
    int i=0;

    struct node *temp=(*first);
    struct node *newn=NULL;
    newn=(struct node*)malloc(sizeof(struct node));

    strcpy(newn->name,arr);
    newn->rno=no;
    newn->next=NULL;
    newn->prev=NULL;

    iSize=Count(*first,*last);

    if((pos<1)||(pos>(iSize+1)))
    {
        printf("\nInvalid Position\n");
        return;
    }
    if(pos==1)
    {
        InsertAtFirst(first,last,no,arr);
    }
    else if(pos==(iSize+1))
    {
        InsertAtLast(first,last,no,arr);
    }
    else
    {
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
    }
    
}
void DeleteAtFirst(struct node **first,struct node **last)
{
    if((*first==NULL)&&(*last==NULL))
    {
        printf("\nThere is no elements");
        return;
    }
    if((*first)==(*last))
    {
        free(*first);
        *first=NULL;
        *last=NULL;
    }
    else
    {
        (*first)=(*first)->next;
        free((*first)->prev);
        (*last)->next=(*first);
        (*first)->prev=(*last);        
    }
    
}
void DeleteAtLast(struct node **first,struct node **last)
{
    if((*first==NULL)&&(*last==NULL))
    {
       printf("\nThere is no elements\n");
        return;
    }
    if((*first)==(*last))
    {
        free(*first);
        *first=NULL;
        *last=NULL;
    }
    else
    {
        (*last)=(*last)->prev;
        free((*last)->next);
        (*last)->next=(*first);
        (*first)->prev=*last;
    }
    
}
void DeleteAtPos(struct node **first,struct node **last,int pos)
{
    struct node *temp=*first;
    int iSize=0;
    int i=0;

    iSize=Count(*first,*last);

    if((pos<1)||(pos>(iSize)))
    {
        printf("\nInvalid Position\n");
        return;
    }
    if(pos==1)
    {
       DeleteAtFirst(first,last);
    }
    else if(pos==iSize)
    {
        DeleteAtLast(first,last);
    }
    else
    {
        for(i=1;i<(pos-1);i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        free(temp->next->prev);
        temp->next->prev=temp;
    }
    
}
int main()
{
    struct node *head=NULL;
    struct node *tail=NULL;
    char name[50];
    int choice=0;
    int rno=0;
    int pos=0;
    char ans;
    do
    {
        printf("\n1.Insert at first\n2.Insert at position\n3.Insert at last\n4.Delete at first\n5.Delete at position\n6.Delete at last");
        printf("\nEnter the choice:");
        scanf("%d",&choice);
        

        switch(choice)
        {
            case 1:
                    printf("\nEnter the student name:");
                    fgets(name,50,stdin);
                    scanf("%[^\n]%*c",name);


                    printf("\nEnter the student roll no:");
                    scanf("%d",&rno);

                    InsertAtFirst(&head,&tail,rno,name);

                    Display(head,tail);
                    break;

            case 2:
                    printf("\nEnter the student name:");
                    fgets(name,50,stdin);
                    scanf("%[^\n]%*c",name);


                    printf("\nEnter the student roll no:");
                    scanf("%d",&rno);

                    printf("\nEnter the required position:");
                    scanf("%d",&pos);

                    InsertAtPos(&head,&tail,rno,name,pos);

                    Display(head,tail);
 
                   break;
            case 3:
                    printf("\nEnter the student name:");
                    fgets(name,50,stdin);
                    scanf("%[^\n]%*c",name);


                    printf("\nEnter the student roll no:");
                    scanf("%d",&rno);

                    InsertAtLast(&head,&tail,rno,name);

                    Display(head,tail);
                  
                   break;

            case 4:

     
                    DeleteAtFirst(&head,&tail);

                    printf("\nFirst element Deleted successfully\n");

                    Display(head,tail);
                   break;
                   
            case 5:
                    printf("\nEnter the position:");
                    scanf("%d",&pos);

                    DeleteAtPos(&head,&tail,pos);

                    printf("\nRequired position element Deleted successfully\n");

                    Display(head,tail);
                   break;
            case 6:
                   
                   DeleteAtLast(&head,&tail);
                   
                   printf("\nLast element Deleted successfully\n");

                   Display(head,tail);
                   
                   break;
        }
        printf("\nDo you want to perform any other operation(y/n):");
        scanf("%c",&ans);
        scanf("%c",&ans);

    }while((ans=='y')||(ans=='Y'));
    return 0;
}
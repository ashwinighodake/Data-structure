#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char name[50];
    int rno;
    struct node *next,*prev;
};

void Display(struct node *first)
{
    struct node *temp=NULL;
    temp=first;

    if(first==NULL)
    {
        return;
    }
    while(temp!=NULL)
    {
        printf("%s\t",temp->name);
        printf("%d\n",temp->rno);
        temp=temp->next;
    }
    
}
int Count(struct node *first)
{
    int i=0;
    int iSize=0;
    struct node *temp=first;

    if(first==NULL)
    {
        return i;
    }
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    return i;
}
void InsertAtFirst(struct node **first,int no,char arr[])
{
    struct node *newn=NULL;

    newn=(struct node*)malloc(sizeof(struct node));

    strcpy(newn->name,arr);
    newn->rno=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((*first)==NULL)
    {
        *first=newn;
    }
    else
    {
        newn->next=(*first);
        (*first)->prev=newn;
        (*first)=newn;
    }



 }
void InsertAtLast(struct node **first,int no,char arr[])
{
    struct node *temp=*first;
    struct node *newn=NULL;

    newn=(struct node*)malloc(sizeof(struct node));

    strcpy(newn->name,arr);
    newn->rno=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(*first==NULL)
    {
        *first=newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
    
}
void InsertAtPos(struct node **first,int no,int pos,char arr[])
{
    int iSize=0;
    int i=0;
    struct node *temp=*first;
    struct node *newn=NULL;

    newn=(struct node*)malloc(sizeof(struct node));

    strcpy(newn->name,arr);
    newn->rno=no;
    newn->next=NULL;
    newn->prev=NULL;

    iSize=Count(*first);
    
    if((pos<1)||(pos>(iSize+1)))
    {
        printf("\nInvalid position\n");
        return;
    }
    if(pos==1)
    {
        InsertAtFirst(first,no,arr);
    }
    else if(pos==(iSize+1))
    {
        InsertAtLast(first,no,arr);
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
void DeleteAtFirst(struct node **first)
{
    if(*first==NULL)
    {
        printf("\nThere is no elements\n");
        return;
    }
    else if((*first)->next==NULL)
    {
        free(*first);
        *first=NULL;
    }
    else
    {
        (*first)=(*first)->next;
        free((*first)->prev);
    }
    
}
void DeleteAtLast(struct node **first)
{
    struct node *temp=NULL;
    temp=*first;

    if(*first==NULL)
    {
        return;
    }
    else if((*first)->next==NULL)
    {
        free(*first);
        *first=NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }    
        free(temp->next);
        temp->next=NULL;
    }
    
    
}
void DeleteAtPos(struct node **first,int pos)
{
    struct node *temp=*first;

    int iSize=0;
    int i=0;
    iSize=Count(*first);
    
    if((pos<1)||(pos>iSize))
    {
        printf("\nInvalid Position\n");
        return;
    }
    if(pos==1)
    {
        DeleteAtFirst(first);
    }
    else if(pos==iSize)
    {
        DeleteAtLast(first);
    }
    else
    {
        for(i=1;i<pos-1;i++)
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
    char name[30];
    struct node *head = NULL;
    

     int choice = 0;
     int rno=0;
     int pos=0;
     char ans;
     
   do
    {
        printf("\n1.Insert at first\n2.Insert at position\n3.Insert at Last\n4.Delete first\n5.Delete at Position\n6.Delete Last");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
       
        switch(choice)
        {
            case 1:
                  printf("Enter the student name:");
    
                  fgets(name,50,stdin);
                  scanf("%[^\n]%*c",name);

                  printf("Enter the student roll number:");
                  scanf("%d",&rno);

                  InsertAtFirst(&head,rno,name);
        
                  Display(head);
                  break;
            
            case 2:
                  printf("Enter the student name:");
                  fgets(name,50,stdin);
                                    
                  scanf("%[^\n]%*c",&name);

                  printf("Enter the student roll number:");
                  scanf("%d",&rno);

                  printf("Enter the Position where you want to insert:");
                  scanf("%d",&pos);

                  InsertAtPos(&head,rno,pos,name);
            
                  Display(head);
                  
                   break;

            case 3:
                  printf("Enter the student name:");
                  fgets(name,50,stdin);
                  
                  scanf("%[^\n]%*c",&name);

                  printf("Enter the student roll number:");
                  scanf("%d",&rno);

                  InsertAtLast(&head,rno,name);
                  
                  Display(head);
                   
                   break;

            case 4:
                   DeleteAtFirst(&head);
                  
                   Display(head);
                  
                   break;
                   
            case 5:
                    printf("Enter the Position which you want to Delete:");
                    scanf("%d",&pos);

                    DeleteAtPos(&head,pos);
                   
                    Display(head);
                  
                    break;
            
            case 6:
                    DeleteAtLast(&head);
                    
                    Display(head);
                  
                    break;
        }
              
        printf("\nDo you want to perform any other operation(y/n):");
        scanf("%c",&ans);
        scanf("%c",&ans);
        


    }while((ans=='Y')||(ans=='y'));

    return 0;
}
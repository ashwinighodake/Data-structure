#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[50];
    int rno;
    struct node *next;
};
void Display(struct node *first,struct node *last)
{
    struct node *temp=NULL;

    temp=(first);
    
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

void InsertAtFirst(struct node **first,struct node **last,int no,char arr[])
{
    struct node *newn=NULL;
    
    newn=(struct node*)malloc(sizeof(struct node));

    strcpy(newn->name,arr);
    newn->rno=no;
    newn->next=NULL;

    if((*first==NULL)&&(*last==NULL))
    {
        *first=newn;
        *last=newn;

        (*last)->next=*first;

    }
    else
    {
        newn->next=(*first);
        (*first)=newn;

        (*last)->next=*first;
     }
    
}
void InsertAtLast(struct node **first,struct node **last,int no,char arr[])
{
    struct node *newn=NULL;

    newn=(struct node*)malloc(sizeof(struct node));

    strcpy(newn->name,arr);
    newn->rno=no;
    newn->next=NULL;

    if((*first==NULL)&&(*last==NULL))
    {
        *first=newn;
        *last=newn;

        (*last)->next=(*first);
    }
    else
    {
        (*last)->next=newn;
        (*last)=newn;

        (*last)->next=(*first);
    }
}

void InsertAtPos(struct node **first,struct node **last,int no,int pos,char arr[])
{
    int iSize=0;

    struct node *newn=NULL;
    struct node *temp=NULL;
    temp=*first;

    iSize=Count(*first,*last);

    newn=(struct node*)malloc(sizeof(struct node));

    strcpy(newn->name,arr);
    newn->rno=no;
    newn->next=NULL;

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
        for(int i=1;i<(pos-1);i++)
        {
           temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
    
}
void DeleteAtFirst(struct node **first,struct node **last)
{
    if((*first==NULL)&&(*last==NULL))
    {
        printf("\nThere is no element\n");
        
        return;
    }
    else if(*first==*last)
    {
        free(*first);
        (*first)=NULL;
        (*last)=NULL;
    }
    else
    {
        (*first)=(*first)->next;
        free((*last)->next);

        (*last)->next=(*first);
    }
    
}
void DeleteAtLast(struct node **first,struct node **last)
{
    struct node *temp=NULL;
    temp=*first;

    if((*first==NULL)&&(*last==NULL))
    {
        printf("\nThere is no element\n");
        return;
    }
    else if(*first==*last)
    {
        free(*first);
        *first=NULL;
        *last=NULL;
    }
    else
    {
        while(temp->next!=(*last))
        {
            temp=temp->next;
        }

        free(temp->next);
        (*last)=temp;

        (*last)->next=(*first);
        
    }
    
   
}

void DeleteAtPos(struct node **first,struct node **last,int pos)
{
    int iSize=0;
    int i=0;

    struct node *temp=NULL;
    struct node *target=NULL;

    temp=*first;
    iSize=Count(*first,*last);
    if((pos<1)||(pos>iSize))
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
        target=temp->next;
        temp->next=target->next;
        free(target);
        
    }
    
}


int main()
{
    char name[30];
    struct node *head = NULL;
    struct node *tail = NULL;

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

                  InsertAtFirst(&head,&tail,rno,name);
        
                  Display(head,tail);
                  break;
            
            case 2:
                  printf("Enter the student name:");
                  fgets(name,50,stdin);
                                    
                  scanf("%[^\n]%*c",&name);

                  printf("Enter the student roll number:");
                  scanf("%d",&rno);

                  printf("Enter the Position where you want to insert:");
                  scanf("%d",&pos);

                  InsertAtPos(&head,&tail,rno,pos,name);
            
                  Display(head,tail);
                  
                   break;

            case 3:
                  printf("Enter the student name:");
                  fgets(name,50,stdin);
                  
                  scanf("%[^\n]%*c",&name);

                  printf("Enter the student roll number:");
                  scanf("%d",&rno);

                  InsertAtLast(&head,&tail,rno,name);
                  
                  Display(head,tail);
                   
                   break;

            case 4:
                   DeleteAtFirst(&head,&tail);
                  
                   Display(head,tail);
                  
                   break;
                   
            case 5:
                    printf("Enter the Position which you want to Delete:");
                    scanf("%d",&pos);

                    DeleteAtPos(&head,&tail,pos);
                   
                    Display(head,tail);
                  
                    break;
            
            case 6:
                    DeleteAtLast(&head,&tail);
                    
                    Display(head,tail);
                  
                    break;
        }
              
        printf("\nDo you want to perform any other operation(y/n):");
        scanf("%c",&ans);
        scanf("%c",&ans);
        


    }while((ans=='Y')||(ans=='y'));
    
 
     return 0;
}
//c program for storing student information name,roll no with singly linear link list.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    char name[50];
    int rno;
    struct student *next;
};

int Count(struct student *first)
{
    int iSize=0;

    while(first!=NULL)
    {
        iSize++;
        first = first->next;
    }
    return iSize;

}
void InsertAtFirst(struct student **first,int no,char value[50])
{
    
    struct student *newn=NULL;

    newn=(struct student*)malloc(sizeof(struct student));
    

    newn->rno=no;
    newn->next=NULL;

    strcpy(newn->name,value);
    

    if(*first==NULL)
    {
        *first=newn;
    }
    else
    {
        newn->next=(*first);
        (*first)=newn;
    }
    
}
void InsertAtLast(struct student **first,int no,char value[50])
{
    struct student *newn = NULL;
    struct student *temp = NULL;
        

    newn=(struct student*)malloc(sizeof(struct student));
 
    newn->rno = no;
    newn->next = NULL;

    strcpy(newn->name,value);

    if(*first==NULL)
    {
       *first=newn;
    }
    else
    {
        temp=(*first);
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    

}

void InsertAtPos(struct student **first,int no,int pos,char value[50])
{

    int iSize = 0,i=0;

    iSize=Count(*first);

    if((pos<1)||(pos>(iSize+1)))
    {
        return;
    }
    if(pos == 1)
    {
        InsertAtFirst(first,no,value);
    }
    else if(pos==iSize+1)
    {
        InsertAtLast(first,no,value);
        
    }
    else
    {
           struct student *temp=NULL;
           temp=*first;

            struct student *newn = NULL;
            newn =(struct student*)malloc(sizeof(struct student));

            newn->rno = no;
            newn->next = NULL;

            strcpy(newn->name,value);

           for(i=1;i<(pos-1);i++)
           {
               temp=temp->next;
           }
           newn->next=temp->next;

           temp->next=newn;
    }
    

}

void DeleteAtFirst(struct student **first)
{
    struct student *temp=NULL;
    
    if(*first!=NULL)
    {
        temp=*first;

        (*first)=(*first)->next;
        free(temp);
    }
}

void DeleteAtLast(struct student **first)
{
    struct student *temp=NULL;
    temp=*first;

    if(*first==NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
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
void DeleteAtPos(struct student **first,int pos)
{
    int iSize=0,i=0;
    iSize=Count(*first);

    struct student *temp=NULL;
    struct student *target=NULL;

    if((pos<1)||(pos>iSize))
    {
        return;
    }

    if(*first==NULL)
    {
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
        temp=*first;
        for(i=1;i<pos-1;i++)
        {
           temp=temp->next;
        }
        target=temp->next;

        temp->next=temp->next->next;
        free(target);
    }
    
} 

void Display(struct student *first)
{
    printf("\n");
    while(first!=NULL)
    {
        printf("%s\t",first->name);
      printf("%d\t",first->rno);
      first=first->next;
    }
}

int main()
{
    char name[30];
    struct student *head = NULL;
    int iRet=0;
   
  
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

#include<stdio.h>
#include<stdlib.h>
#include<process.h>
 struct node
    {
        int info;
        struct node* link;
    }*start=NULL;
void create();
void traverse();
 void insert_at_first();
 void after_given_node();
  void insert_at_end();
int main()
{
    int k;
    int p;
    printf("Welcome...\n");
    printf("please create a link list\n");
    create();
    printf("_______________WELCOME TO LINK LIST OPERATION_________________\n");
   while(1){ printf("\n MENU \n");
    printf("1.TRAVERSING\n");
    printf("2.INSERTION\n");
    printf("3.DELETION\n");
    printf("Please Enter Your Choice: ");
    scanf("%d",&k);
    switch(k)
    {
    case 1:
        traverse();
        break;
    case 2:
        printf("  (1).Insertion at beginning of list\n");
         printf("  (2).Insertion after a Given node\n");
         printf("  (3).Insertion at the end\n");
           printf("Please Enter Your Choice From Above: ");
           scanf("%d",&p);
           switch(p)
           {
           case 1:
          insert_at_first();
                   break;
           case 2:
            after_given_node();
            break;
           case 3:
            insert_at_end();
            break;
           default:
            printf("wrong choice");
            exit(0);
           }
           break;
        }
   } }
void create()
{
   struct node *temp,*ptr;
   int item;
   char ch='y';
   while (ch=='Y' || ch=='y')
   {
       temp=(struct node*)malloc(sizeof(struct node));
       if(temp==NULL)
       {
           printf("overflow\n");
           return;
       }
       else{
       printf("enter item:");
       scanf("%d",&item);
       temp->info=item;
       temp->link=NULL;
       if(start==NULL)
           start=temp;
       else
       {
           ptr=start;///doubt clear
           while(ptr->link!=NULL)
               ptr=ptr->link;
               ptr->link=temp;
       }
       printf("Do you want to add more items please give answer only Y or y:\t");
       /*for cleaning buffer*/  fflush(stdin);
       scanf("%c",&ch);
       }
   }
}
void traverse()
{
  struct node*ptr;
  if(start==NULL)
    printf("list is empty");
  else
  {
      ptr=start;
       printf("the items are:-");
      while(ptr!=NULL)
      {
          printf("\t%d",ptr->info);
      ptr=ptr->link;
      }
  }
}
void  insert_at_first()
{
   struct node *temp,*ptr;
   int item;
   temp=(struct node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
   start=temp;
    }
   else
   {
       ptr=start;
       printf("Enter item:");
       scanf("%d",&item);
     temp->info=item;
     temp->link=start;
     start=temp;
   printf("\t**node successfully added at first in list**\n");
   }
   printf("\tPlease check your list through traversing option for your confirmation\n");

}
void after_given_node()
{
    int loc,item,i;
    struct node *ptr,*temp;
       temp=(struct node*)malloc(sizeof(struct node));
      if(start==NULL)
    {
   start=temp;
    }
    else
   {ptr=start;
       printf("\n Please Enter a item for insert in list:");
    scanf("%d",&item);
    printf("Enter a location on which you want to add node after that:");
scanf("%d",&loc);
for(i=1;i<loc;i++)
{
    ptr=ptr->link;
}
temp->link=ptr->link;
temp->info=item;
ptr->link=temp;
   }
   printf("\tnew node successfully added after at given position\n");
  printf("\tPlease check your list through traversing option for your confirmation\n");
}
void  insert_at_end()
{
    struct node *temp,*ptr;
    int item;
    printf("Please enter item for insert in list:");
    scanf("%d",&item);
      temp=(struct node*)malloc(sizeof(struct node));
           temp->info=item;
           temp->link=NULL;
       if(start==NULL)
    {
   start=temp;
    }
    else
    {
        ptr=start;
        while (ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;

    }
printf("\n voila!item successfully inserted.....|");
printf("for your confirmation check list through traverse option");
}



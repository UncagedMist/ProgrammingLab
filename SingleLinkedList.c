#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void transverse();

struct node
{
 int data;
 struct node *link;
}*first = NULL;

void main()
{
 int choice;
 while(1)
  {
   printf("Linked List Operation \n");
   printf("1.Insertion \n2.Deletion \n3.Transverse \n4.Exit \n");
   scanf("%d",&choice);
   switch(choice)
    {
     case 1: insert();
             break;
     case 2: delete();
             break;
     case 3: transverse();
             break;
     case 4: exit(0);
             break;
     default : printf("Enter a valid choice \n");
    }
  }
}

void insert()
{
 struct node *ptr,*loc = NULL,*locp = NULL;
 int pos,item;
 struct node *temp;
 printf("Enter the position : \n");
 scanf("%d",&pos);
 printf("Enter the item to be inserted : \n");
 scanf("%d",&item);
 temp = (struct node*)malloc(sizeof(struct node*));
 temp->data = item;
 int count = 1;
 if(pos == 1)
  {
   loc = first;
  }
 else
  {
   ptr = first;
   while(count < pos - 1 && ptr -> link != NULL)
    {
     ptr = ptr-> link;
     count++;
    }
    loc = ptr;
  }
 if(loc == NULL)
  {
   temp -> link = first;
   first = temp;
  }
 else
  {
   temp->link = loc->link;
   loc->link = temp;
  }
}

void delete()
{
 int pos;
 struct node *temp,*loc,*locp;
 printf("Enter the position : \n");
 scanf("%d",&pos);
 if(pos == 1)
  {
   locp = NULL;
   loc = first;
  }
 else
  {
   locp = first;
   loc = first->link;
   int n = 2;
   while(n!= pos)
   {
    locp = loc;
    loc = loc->link;
    n++;
  }
}
   temp = loc;
   if(locp == NULL)
    { 
     first = loc->link;
   }
  else
   {
    locp -> link = loc->link;
   }
   free(temp); 
}

void transverse()
{
 struct node *ptr;
 ptr = first;
 while(ptr != NULL)
  {
   printf("%d\n",ptr->data);
   ptr = ptr->link;
  }
}

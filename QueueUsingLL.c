#include<stdio.h>
#include<stdlib.h>
#define max 5

struct node
{
 int data;
 struct node *link;
}*front = NULL, *rear = NULL;

void insert(int item);
void delete();
void display();

int count  = 0;

void main()
{
 int choice,item;
 while(1)
  {
   printf("1.Insert \n2.Delete \n3.Display \n4.Exit \n");
   scanf("%d",&choice);
   switch(choice)
    {
     case 1 : insert(item);
	      break;
     case 2 : delete();
	      break;
     case 3 : display();
              break;
     case 4 : exit(0);
              break;
     default : printf("Invalid Choice \n");
    }
  }
}

void insert(int item)
{
 if(count == max)
  {
   printf("Queue is full \n");
  }
 else
  {
   struct node *newnode;
   newnode = (struct node *)malloc(sizeof(struct node *));
   printf("Enter a new element : \n");
   scanf("%d",&item);
   newnode -> data = item;
   if(front == NULL)
    {
     front = newnode;
     rear = newnode;
    }
   else
    {
     rear -> link = newnode;
     rear = newnode;
    }
   rear -> link = NULL;
   printf("Item Inserted \n");
   count++;
  }
}

void delete()
{
 struct node *temp;
 if(count == 0)
  {
   printf("Queue is Empty \n");
  }
 else if(count == 1)
  {
   temp = front;
   printf("Item Deleted \n");
   front = NULL;
   rear = NULL;
   free(temp);
   count--;
  }
 else
  {
   temp = front;
   printf("Item Deleted \n");
   front = front -> link;
   free(temp);
   count--;
  }
}

void display()
{
 struct node *ptr;
 ptr = front;
 while(ptr != NULL)
  {
   printf("%d \n",ptr->data);
   ptr = ptr -> link;
  }
}

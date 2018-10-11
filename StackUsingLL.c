#include<stdio.h>
#include<stdlib.h>
#define max 5

void push(int data);
void pop();
void display();

struct node
{
 int data;
 struct node *link;
}*top = NULL;

void main()
{
 int choice;
 while(1)
  {
   printf("1.Push \n2.Pop \n3.Display \n4.Exit \n");
   scanf("%d",&choice);
   switch(choice)
    {
     case 1 : push();
	      break;
     case 2 : pop();
	      break;
     case 3 : display();
              break;
     case 4 : exit(0);
              break;
     default : printf("Invalid Choice \n");
    }
  }
}

void push(int item)
{
 if(count == max)
  {
   printf("Stack is full \n");
  }
 else
  {
   struct node *newnode;
   newnode = (struct node *)malloc(sizeof(struct node *));
   newnode -> data = item;
   if(top == NULL)
    {
     newnode -> link = NULL;
    }
   else
    {
     newnode -> link = top;
    }
   top = newnode;
  }
 count++;
}

void pop()
{
 if(count == 0)
  {
   printf("Stack is empty \n");
  }
 else
  {
   struct node *temp;
   temp  = top;
   printf("deleted \n");
   top = top -> link;
   free(temp);
  }
 count--;
}

void display()
{
 printf("Display \n");
}

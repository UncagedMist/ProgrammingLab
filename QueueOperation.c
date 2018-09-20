#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

void enqueue(int);
void dequeue();
void display();

int isFull(int);
int isEmpty(int);

int queue[MAXSIZE];
int front = 0, rear = -1;

void main()
{
  int choice,data;
  while(1)
   {
    printf("Queue Operation \n");
    printf("1.Enqueue \n2.Dequeue \n3.Display \n4.Exit \n");
    scanf("%d",&choice);
    switch(choice)
     {
      case 1 : printf("Enter an element : \n");
               scanf("%d",&data);
               enqueue(data);
	       break;
      case 2 : dequeue();
               break;
      case 3 : display();
               break;
      case 4 : exit(0);

      default : printf("Invalid Option \n");
     }
   }
}

void enqueue(int data)
{
 int x;
 if(isFull(x))
  {
   printf("Queue is full \n");
  }
 else
  {
   rear++;
   queue[rear] = data;
  }
}

void dequeue()
{
 int x;
 if(isEmpty(x))
  {
   printf("Queue is empty \n");
  }
 else
  {
   front++;
  }
}

void display()
{
 for(int i = front; i <= rear; i++)
  {
   printf("%d\n",queue[i]);
  }
}

int isFull(int size)
{
 size = 9;
 if(front == size)
  {
   return 1;
  }
 else
  {
   return 0;
  }
}

int isEmpty(int size)
{
 size = -1;
 if(front == size)
  {
   return 1;
  }
 else
  {
   return 0;
  }
}

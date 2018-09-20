#include<stdio.h>
#include<stdlib.h>

#define size 10

void enqueue(int);
void dequeue();
void display();

int queue[size];
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
 if(front == 9)
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
 if(front == -1)
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
   printf("%d",queue[i]);
  }
  printf("\n");
}

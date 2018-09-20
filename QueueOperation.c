#include<stdio.h>
int queue[10];
int front=0,rear=-1;
void enqueue(int);
void dequeue();
void display();
void enqueue(int ele)
{
 if(rear==9)
 {
  printf("Queue is full\n");
 }
 else
 {
  rear++;
  queue[rear]=ele;
 }
}
void dequeue()
{
 if(rear==-1)
 {
  printf("Queue is empty\n");
 }
 else
 {
  front++;
 }
}
void display()
{
 for(int i=front;i<=rear;i++)
 {
  printf("%d  ",queue[i]);
 }
 printf("\n");
}
void main()
{
 int ele,ch;
 x:
 printf("Enter 1 for enqueue, 2 for dequeue, 3 for display\n");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1: printf("Enter an element\n");
          scanf("%d",&ele);
          enqueue(ele);
          goto x;
  case 2: dequeue();
          goto x;
  case 3: display();
          goto x;
  default: printf("Invalid");
 }
}

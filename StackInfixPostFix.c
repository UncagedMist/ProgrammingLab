#include<stdio.h>
#include<string.h>

#define MAXSIZE 1000

int isEmpty();
int isFull();
int peek();
int pop();
int push(int);

int stack[MAXSIZE],data;
int top = -1,len,res,d1,d2;
char s[100];

int isEmpty()
{
  if(top == -1)
   {
    return 1;
   }
  else
   {
    return 0;
   }
}

int isFull()
{
  if(top == MAXSIZE)
   {
    return 1;
   }
  else
   {
    return 0;
   }
}

int peek()
{
  return stack[top];
}

int pop()
{
  int data;
  if(!isEmpty())
   {
    data = stack[top];
    top = top-1;
    return data;
   }
  else
   {
    printf("underflow \n");
   }
}

int push(int data)
{
  if(!isFull())
   {
    top = top + 1;
    stack[top] = data;
   }
  else
   {
    printf("Overflow \n");
   }
}

void main()
{
  scanf("%s",s);
  len = strlen(s);
  for(int i = 0; i < len; i++)
   {
    if((int)s[i]<58 && (int)s[i] > 47)
     {
       data = s[i] - '0';
       push(data);
     }
    else
     {
       if(s[i] == '+')
        {
         d1 =  pop();
         d2 = pop();
         res = d2+d1;
         push(res);
        }
       else if(s[i] == '-')
        {
         d1 = pop();
         d2 = pop();
         res= d2-d1;
         push(res);
        }
      else if(s[i] == '*')
       {
        d1 = pop();
        d2 = pop();
        res = d2 * d1;
        push(res);
       }
       else if(s[i] == '/')
       {
        d1 = pop();
        d2 = pop();
        res = d2 / d1;
        push(res);
       }
     }
   }
  while(!isEmpty())
  {
   int data = pop();
   printf("%d\n",data);
  }
}

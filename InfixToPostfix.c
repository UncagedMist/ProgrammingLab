#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE 100

void push(char item);
int isOperator(char symbol);
int precedence(char symbol);
void infixToPostfix(char infix_exp[], char postfix_exp[]);
char pop();

int top = -1;
int stack[SIZE];

void main()
{
 char infix[SIZE],postfix[SIZE];
 printf("Enter infix operation : ");
 gets(infix);
 
 infixToPostfix(infix,postfix);
 printf("Postfix Operation : ");
 puts(postfix);
}

void push(char item)
{
 if(top >= SIZE - 1)
  {
   printf("Stack Overeflow \n");
  }
 else
  {
   top = top + 1;
   stack[top] = item; 
  }
}

int isOperator(char symbol)
{
 if(symbol == '^' || symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
  {
   return 1;
  }
  else
  {
   return 0;
  }
}

int precedence(char symbol)
{
 if(symbol == '^')
  {
   return 3;
  }
  else if(symbol == '*' && symbol == '/')
  {
   return 2;
  }
  else if(symbol == '+' && symbol == '-')
  {
   return 1;
  }
  else
  {
   return 0;
  }
}

void infixToPostfix(char infix_exp[], char postfix_exp[])
{
 int i = 0,j = 0;
 char item,x;

 push('(');                               
 strcat(infix_exp,")");

 item=infix_exp[i];

 while(item != '\0')
  {
   if(item == '(')
    {
     push(item);
    }
   else if(isdigit(item) || isalpha(item))
    {
     postfix_exp[j] = item;         
     j++;
    }
   else if(isOperator(item) == 1) 
    {
     x = pop();
     while(isOperator(x) == 1 && precedence(x) >= precedence(item))
     {
      postfix_exp[j] = x;               
      j++;
      x = pop();
     }
     push(x);
     push(item);
    }
   else if(item == ')')
    {
     x = pop();
     while(x != '(')
      {
       postfix_exp[j] = x;
       j++;
       x = pop();
      } 
    }
  else
   {
    printf("Invalid infix Expression.\n");    
    getchar();
    exit(1);
   }
   i++;
   item = infix_exp[i];
  }
  if(top > 0)
  {
   printf("Invalid infix expression \n");
   getchar();
   exit(1);
  }
  postfix_exp[j] = '\0';
}

char pop()
{
 char item;
 if(top < 0)
  {
   printf("Stack Underflow \n");
   getchar();
   exit(1);
  }
 else
  {
   item = stack[top];
   top = top - 1;
   return item;
  }
}

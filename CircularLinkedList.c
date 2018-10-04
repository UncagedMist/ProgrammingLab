#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int coef,exp;
 struct node *link;
}poly;

poly *read();
poly *add(poly *p1, poly *p2);
void display(poly *p);

void main()
{
 int i,c,e,n;
 poly *p1,*p2,*p3;
 
   printf("Enter the 1st polynomial in the decreasing order of exponent \n");
   p1 =read();
   printf("Ente the 2nd polynomial : \n");
   p2 = read();
   printf("1st Polynomial \n");
   display(p1);
   printf("2nd Polynomial : \n");
   display(p2);
   p3 =add(p1,p2);
   printf("Sum of polynomal : \n");
   display(p3);
  
}

poly *read()
{
 poly *temp,*last,*h;
 int c,e,i,n;
 printf("Enter no. of terms : \n");
 scanf("%d",&n);
 h = (poly *)malloc(sizeof(poly *));
 h->coef = 0;
 h->exp =-1;
 last = h;
 for(i = 0;i<n;i++)
  {
   temp = (poly *)malloc(sizeof(poly *));
   printf("Enter coefficients and 2 exponents of them : \n");
   scanf("%d%d",&c,&e);
   temp -> coef = c;
   temp -> exp = e;
   last -> link = temp;
   last = temp;
  }
 last -> link = h;
 return h;
}

poly *add(poly *p1, poly *p2)
{
 poly *temp,*last,*c;
 c = (poly *)malloc(sizeof(poly *));
 c -> coef = 0;
 c -> exp = -1;
 last = c;
 p1 = p1->link;
 p2 = p2->link;
 while(1)
  {
   temp = (poly *)malloc(sizeof(poly *));
   if(p1->exp == p2->exp)
    {
     if((p1->exp == -1) && (p2->exp == -1))
      {
       free(temp);
       break;
      }
     else
      {
       temp -> coef = p1->coef+p2->coef;
       temp -> exp = p1->exp;
       p1 = p1->link;
       p2 = p2->link;
      }
    }
  else if(p1 -> exp > p2 -> exp)
   {
    temp -> coef = p1 -> coef;
    temp -> exp = p1 -> exp;
    p1 = p1->link;
   }
  else
   {
    temp -> coef = p2 -> coef;
    temp -> exp = p2 -> exp;
    p2 = p2->link;
   }
  last -> link = temp;
  last = temp;
 }
 last -> link = c;
 return c;
}

void display(poly *p)
{
 poly *temp;
 temp = p->link;
 while(temp != p)
  {
   printf("%dx^%d",temp->coef,temp->exp);
   temp =  temp -> link;
   if(temp != p)
    {
     printf(" + ");
    }
  }
 printf("\n");
}

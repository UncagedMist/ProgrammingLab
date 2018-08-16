#include<stdio.h>
void mAddition(int add[100][100],int first[100][100],int second[100][100]);
void mSubstraction(int subs[100][100],int first[100][100],int second[100][100]);
void mMultiplication(int mult[100][100],int first[100][100],int second[100][100]);
int m,n,p,q,choice;
void main()
{
int first[100][100],second[100][100],add[100][100],subs[100][100],mult[100][100];
printf("Enter the no. of rows and columns of 1st matrix \n");
scanf("%d%d",&m,&n);
printf("Enter the elements of 1st matrix \n");
for(int i = 0;i<m;i++)
{
for(int j = 0;j<n;j++)
{
scanf("%d",&first[i][j]);
}
}
printf("Select the Following operation which u want to perform on the given matrix (Enter 1, 2 Or 3): \n");
printf("1. Addition \n2. Substraction \n3. Multiplication \n");
scanf("%d",&choice);
switch(choice)
{
case 1 :
{
printf("Enter the no. of rows and columns of 2nd matrix \n");
scanf("%d%d",&p,&q);
printf("Enter the elements of 2nd matrix \n");
for(int i = 0;i<p;i++)
{
for(int j = 0;j<q;j++)
{
scanf("%d",&second[i][j]);
}
}
mAddition(add,first,second);
break;
}
case 2 :
{
printf("Enter the no. of rows and columns of 2nd matrix \n");
scanf("%d%d",&p,&q);
printf("Enter the elements of 2nd matrix \n");
for(int i = 0;i<p;i++)
{
for(int j = 0;j<q;j++)
{
scanf("%d",&second[i][j]);
}
}
mSubstraction(subs,first,second);
break;
}
case 3 :
{
printf("Enter the no. of rows and columns of 2nd matrix \n");
scanf("%d%d",&p,&q);

if(m == p)
{
printf("Enter the elements of 2nd matrix \n");
for(int i = 0;i<p;i++)
{
for(int j = 0;j<q;j++)
{
scanf("%d",&second[i][j]);
}
}
mMultiplication(mult,first,second);
}
else
{
printf("Both Matrix can't be multiplied \n");
}
break;
}
default : 
{
printf("Enter a valid option \n");
break;
}
}
}

void mAddition(int add[100][100],int first[100][100],int second[100][100])
{
printf("Matrix Result \n");
for(int i = 0; i < m; i++)
{
for(int j = 0;j<q; j++)
{
add[i][j] = first[i][j] + second[i][j];
printf("%d ",add[i][j]);
}
printf("\n");
}
}

void mSubstraction(int subs[100][100],int first[100][100],int second[100][100])
{
printf("Matrix Result \n");
for(int i = 0; i < m; i++)
{
for(int j = 0;j<q; j++)
{
subs[i][j] = first[i][j] - second[i][j];
printf("%d ",subs[i][j]);
}
printf("\n");
}
}

void mMultiplication(int mult[100][100],int first[100][100],int second[100][100])
{
int sum = 0;
for(int i = 0;i<m;i++)
{
for(int j= 0; j <q; j++)
{
for(int k = 0; k < p; k++)
{
sum = sum + first[i][k] * second[k][j];
}
mult[i][j] = sum;
sum = 0;
}
}
printf("Matrix Result \n");
for(int i = 0 ; i< m; i++)
{
for(int j = 0; j < q; j++)
{
printf("%d ",mult[i][j]);
}
printf("\n");
}
}

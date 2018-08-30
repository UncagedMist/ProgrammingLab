#include <stdio.h>

int compareStrings(char [], char []); 

int main()
{
    char str[100],str2nd[100];
    
    printf("Enter 1st string : \n");
    gets(str);
    
    printf("Enter 2nd String : \n");
    gets(str2nd);
    
    if (compareStrings(str, str2nd) == 0)
      printf("Both Strings are equal \n");
   else
      printf("Both Strings are not equal \n");
      
    return 0;
}


int compareStrings(char str[], char str2nd[])
{
   int i = 0;
 
   while (str[i] == str2nd[i]) {
      if (str[i] == '\0' || str2nd[i] == '\0')
         break;
      i++;
   }
 
   if (str[i] == '\0' && str2nd[i] == '\0')
      return 0;
   else
      return -1;
}

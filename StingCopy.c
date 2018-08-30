#include <stdio.h>

int main()
{
    char str[100],copyStr[100];
    int i;
    
    printf("Enter any string : \n");
    gets(str);
    
    for (i = 0; str[i] != '\0'; i++) {
        copyStr[i] = str[i];
    }
    copyStr[i] = '\0';
    printf("Copied String : %s\n",copyStr);
    printf("total no. of character got copied : %d \n",i);
    return 0;
}

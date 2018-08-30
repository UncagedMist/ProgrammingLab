#include <stdio.h>

int main()
{
    char str[100],str2nd[100];
    int i,j;
    
    printf("Enter 1st string : \n");
    gets(str);
    
    printf("Enter 2nd String : \n");
    gets(str2nd);
    
    for (i = 0; str[i] != '\0' ; i++);
    for (j = 0; str2nd[j] != '\0'; j++,i++) {
        str[i] = str2nd[j];
    }
    str[i] = '\0';
    
    printf("Both String after concatenate = %s \n",str);
    
    return 0;
}

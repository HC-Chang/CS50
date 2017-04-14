#include <stdio.h>

// Initials-Less
// 姓名縮寫
int main()
{
    printf("\nInitials-Less\n");
    
    int size = 50;
    char arrays[size];
    char *s = arrays;
    char display[size];
     
    scanf("%[^\n]", s);
    
    int a = 0;
    int d = 1;
    
    while (*s != '\0')
    {
		// 轉大寫
        arrays[a] = toupper(*s);
		
		// 判斷字首
        if(arrays[a-1] == ' ' && ( arrays[a] != '\n' || arrays[a] != '\0'))
        {
            display[d] = arrays[a];
            d++;
        }
        s++;
        a++;
    }
    
	// 第一個字元
    display[0] = arrays[0];
    
    printf("%s\n",arrays);
    
	// 顯示縮寫字元
    int i;
    for(i=0;i<d;i++)
    { 
        printf("%c",display[i]);
    }
    printf("\n");

    
    return 0;
}
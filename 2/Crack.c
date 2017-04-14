#include <stdio.h>

#define _XOPEN_SOURCE
#include <unistd.h>

// Crack
// ¯}¸Ñ crypt (¥[±K¨ç¼Æ)
int main(int argc, char *argv[])
{
	
    if(argc == 2)
    {
        printf("\nCrack\nHash:%s\n",argv[1]);
    
       return 0;
    }
    
	else
	{
		printf("Error !!!\n");
		return 1;
	}
}

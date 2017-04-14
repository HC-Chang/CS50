/**
 * Prompts user for as many as MAX values until EOF is reached, 
 * then proceeds to search that "haystack" of values for given needle.
 *
 * Usage: ./find needle
 *
 * where needle is the value to find in a haystack of values
 */

// Find - Less
// 產生隨機數字並排序
 
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

// maximum amount of hay
const int MAX = 65536;

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./find needle\n");
        return -1;
    }

    // remember needle
    int needle = atoi(argv[1]);

    // fill haystack
    int size;
    int haystack[MAX];
	printf("\nGenerate & Find\n\nUnsorted:\n");
    for (size = 0; size < MAX; size++)
    {
        // wait for hay until EOF
		int straw = GetInt();
        
        if (straw == INT_MAX)
        {
            break;
        }
     
        // add hay to stack
        haystack[size] = straw;
		printf("haystack[%i] = ", size);       
		printf("%i\n",straw);
    }
    printf("\n");

	
    // sort the haystack
    sort(haystack, size);
	printf("Sorted:\n");
	int i;
	for(i = 0;i<size;i++)
	{
		printf("%i --- %i\n",i,haystack[i]);
	}
	
    // try to find needle in haystack
    if (search(needle, haystack, size))
    {
        printf("\nFound needle in haystack!\n\n");
        return 0;
    }
    else
    {
        printf("\nDidn't find needle in haystack.\n\n");
        return 1;
    }
	

}
